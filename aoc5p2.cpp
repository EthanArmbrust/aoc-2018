#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){

	ifstream infile("input5.txt");

	string original;
	getline(infile,original);
	int diff = 'a' - 'A';

    int smallest = INT_MAX;

    for(char a = 'a'; a <= 'z'; a++){

        string s = original;
        s.erase(remove(s.begin(), s.end(), a), s.end());
        s.erase(remove(s.begin(), s.end(), a - diff), s.end());

        for(int i = 0; i < s.length() - 1; i++){
            char a = s[i];
            char b = s[i+1];
            if(a - b == diff || b - a == diff){
                s.erase(i, 2);
                i = 0;
            }
        }
        if(s.length() < smallest){
            smallest = s.length();
        }
    }

	cout << smallest << endl;

	
	return 0;
}
