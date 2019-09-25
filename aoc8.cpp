#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Node{
	int id;
	int size;
	vector<Node> children;
	vector<int> metadata;
};

int id_counter = 0;

//Returns head node... eventually
Node build_nodes(vector<int> numbers){
	Node n;
	n.id = id_counter++;
	//We can get the size of a node by the size of it's children + size of metadata + 2
	int child_count = numbers[0];
	int metadata_count = numbers[1];
	if(child_count == 0){
		for(int i = 0; i < metadata_count; i++){
			n.metadata.push_back(numbers[i+2]);
		}
		n.size = metadata_count + 2;
	}
	else{
		for(int i = 0; i < child_count; i++){
			int offset = 2;
			for(auto c : n.children){
				offset += c.size;
			}
			n.children.push_back(build_nodes(vector<int>(numbers.begin() + offset, numbers.end())));
		}
		for(auto c : n.children){
			n.size += c.size;
		}
		for(int i = 0; i < metadata_count; i++){
			n.metadata.push_back(numbers[i + n.size + 2]);
		}
		n.size += metadata_count + 2;
		
	}
	return n;
}

int main(){

	ifstream infile("input/test8.txt");
	string s;
	getline(infile, s);

	stringstream ss(s);
	vector<int> numbers;
	string num;
	while(ss >> num){
		numbers.push_back(stoi(num));
	}

	Node head = build_nodes(numbers);


	return 0;
}	
