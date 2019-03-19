#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input2.txt");
	vector<string> inputList;

	string s;
	while(getline(infile,s)){
		inputList.push_back(s);
	}

	int twocount = 0;
	int	threecount = 0;

	for(auto str : inputList){
		bool two = false;
		bool three = false;
		for(char letter = 'a'; letter <= 'z'; letter++){
			size_t n = count(str.begin(), str.end(), letter);
			if(n == 2){
				two = true;
			}
			if(n == 3){
				three = true;
			}
		}
		if(two){
			twocount++;
		}
		if(three){
			threecount++;
		}
	}

	int answer = twocount * threecount;
	cout << answer << endl;


	return 0;
}
