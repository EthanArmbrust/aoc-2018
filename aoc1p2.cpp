#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){

    ifstream infile("input1.txt");
    vector<int> input;
    string s;
    while(getline(infile,s)){
        input.push_back(stoi(s));
    }
 
    vector<int> v;
    int num = 0;
    v.push_back(num);
    bool found = false;

    while(!found){ 
        for(int i : input){
            num += i;
            if(find(v.begin(), v.end(), num) != v.end()){
                cout << num << endl;
                found = true;
                return 0;
            }
            v.push_back(num);
        }
    }

    return 0;
}
