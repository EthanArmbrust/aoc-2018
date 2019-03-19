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

	for(int i = 0; i < inputList.size(); i++){
		string a = inputList[i];
		for(int j = i + 1; j < inputList.size(); j++){
			string b = inputList[j];
			int diffCount = 0;
			for(int n = 0; n < a.length(); n++){
				if(a[n] != b[n]){
					diffCount++;
				}
			}
			if(diffCount == 1){
				string answer = "";
				for(int n = 0; n < a.length(); n++){
					if(a[n] == b[n]){
						answer += a[n];
					}
				}
				cout << "answer: " << answer << endl;
				return 0;
			}
		}
	}
	
	return 0;
}
