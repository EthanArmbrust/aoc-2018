#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    ifstream infile("input7.txt");
    vector<string> inputList;

    string s;
    while(getline(infile,s)){
        inputList.push_back(s);
    }

    int f_index = 5;
    int s_index = 36;

    map<char, string> dep;

    for(auto str : inputList){
        dep[str[s_index]] += str[f_index];
    }

    vector<char> uncompleted;
    for(char letter = 'A'; letter <= 'Z'; letter++){
        uncompleted.push_back(letter);
    }
    string completed = "";

    cout << "uncompleted length: " << uncompleted.size() << endl;

    for(int k = 0; k < uncompleted.size(); k++){
        char key = uncompleted[k];
        map<char, string>::iterator it = dep.find(key);
        if(it == dep.end()){
            completed += key;
            cout << "Removing " << key << endl;
            uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), key), uncompleted.end());
            k--;
        }
        /*
        else{
            cout << key << " depends on " << dep.at(key) << endl;
        }
        */
    }

    
    for(auto const& p : dep){
        cout << p.first << " depends on " << p.second << endl;
    }
    
    while(uncompleted.size() != 0){
        //for(int z = 0; z <= dep.size(); z++){
        for(auto const& p : dep){ //for each key in dependancy list
        //for(map<char, string>::iterator p = dep.begin(); p != dep.end(); ++p){
            //map<char, string>::iterator p = dep.begin() + z;
            bool unmet_dep = false;
            for(char c : p.second){ //for each dependancy in the list
                if(completed.find(c) == string::npos){
                    unmet_dep = true;
                }
            }
            if(!unmet_dep){
                completed += p.first;
                cout << "Removing " << p.first << endl;

                map<char, string>::iterator iter = dep.find(p.first);
                dep.erase(iter);
                //--p;
                uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), p.first), uncompleted.end()); 
            }
        }
    }

    cout << completed << endl;
    cout << "string length: " << completed.length() << endl;

    return 0;
}
