#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Node{
	int id;
	char letter;
	int size = 0;
	vector<Node> children;
	vector<int> metadata;
};

int id_counter = 0;

Node build_nodes(vector<int> numbers){
	Node n;
	n.id = id_counter++;
	n.letter = n.id + 'A';
	int child_count = numbers[0];
	int metadata_count = numbers[1];
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
		
	return n;
}

int meta_sum(Node head){
	int sum = 0;
	for(auto &n : head.children){
		sum += meta_sum(n);
	}
	for(auto i : head.metadata){
		sum += i;
	}
	return sum;
}

int part_2(Node &head){
	int sum = 0;
	if(head.children.size() == 0){
		for(auto i : head.metadata){
			sum += i;
		}
	}
	else{
		for(auto i : head.metadata){
			if(i <= head.children.size() && i > 0){
				Node &c = head.children[i - 1];
				sum += part_2(c);
			}
		}
	}
	return sum;
}

int main(){

	ifstream infile("input/8.txt");
	string s;
	getline(infile, s);

	stringstream ss(s);
	vector<int> numbers;
	string num;
	while(ss >> num){
		numbers.push_back(stoi(num));
	}

	Node head = build_nodes(numbers);
	int result = meta_sum(head);
	cout << result << endl;
	int part2 = part_2(head);
	cout << part2 << endl;


	return 0;
}	
