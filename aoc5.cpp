#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input5.txt");

	string s;
	getline(infile,s);
	int diff = 'a' - 'A';

	for(int i = 0; i < s.length() - 1; i++){
		char a = s[i];
		char b = s[i+1];
		if(a - b == diff || b - a == diff){
			s.erase(i, 2);
			i = 0;
		}
	}
	cout <<  s << endl;

	
	return 0;
}
