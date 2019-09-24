#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    ifstream infile("input/7.txt");
    vector<string> inputList;

    string s;
    while(getline(infile,s)){
        inputList.push_back(s);
    }

    int f_index = 5;
    int s_index = 36;

    map<char, string> dep;
    vector<string> deps(26, "");

    for(auto str : inputList){
        dep[str[s_index]] += str[f_index];
        deps[str[s_index] - 'A'] += str[f_index];
    }

    vector<char> uncompleted;
    for(char letter = 'A'; letter <= 'Z'; letter++){
        uncompleted.push_back(letter);
    }
    string completed = "";

    for(int k = 0; k < uncompleted.size(); k++){
        char key = uncompleted[k];
        if(deps[int(key - 'A')] == ""){
            completed += key;
            cout << "Removing " << key << endl;
            uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), key), uncompleted.end());
            k--;
        }
    }
    for(int i = 0; i < deps.size(); i++){
        cout << char('A' + i) << " depends on " << deps[i] << endl;
    }

    cout << uncompleted.size() << endl;
    while(uncompleted.size() != 0){
        for(int i = 0; i < uncompleted.size(); i++){
            char key = uncompleted[i];
            bool unmet_dep = false;
            for(auto c : deps[key - 'A']){
                if(find(uncompleted.begin(), uncompleted.end(), c) != uncompleted.end()){
                    unmet_dep = true;
                }
            }
            if(!unmet_dep){
                completed += key;
                cout << "Removing " << key << endl;
                uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), key), uncompleted.end());
                i--;
            }
        }
    }

    cout << completed << endl;
    cout << "string length: " << completed.length() << endl;

    return 0;
}
