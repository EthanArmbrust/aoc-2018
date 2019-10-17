#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct rule{
    string pattern;
    char result;
};

int main(){
    
    ifstream infile("input/12.txt");
    vector<string> input;
    vector<rule> rules;
    string s;

    while(getline(infile, s)){
        input.push_back(s);
    }

    char initial[100];
    sscanf(input[0].c_str(), "initial state: %s", initial);
    string init(initial);

    for(int i = 2; i < input.size(); i++){
        char pattern[5];
        char result;
        sscanf(input[i].c_str(), "%s => %c", pattern, &result);
        rule r = {string(pattern), result};
        rules.push_back(r);
    }

    int padding = 5;
    init = string(padding, '.') + init + string(padding, '.');

    for(int gen = 0; gen < 20; gen++){
        if(init.substr(0, 5).find("#") != string::npos || 
           init.substr(init.length() - 5).find("#") != string::npos){
            padding += 5;
            init = string(5, '.') + init + string(5, '.');
        }
        string new_init = init;
        for(int i = 2; i < init.length() - 2; i++){
            string sub = init.substr(i - 2, 5);
            for(auto &r : rules){
                if(sub == r.pattern){
                    new_init[i] = r.result;
                    break;
                }
            }
        }
        init = new_init;
    }
    int sum = 0; 
    for(int i = 0; i < init.length(); i++){
        if(init[i] == '#'){
            sum += (i - padding);
        }
    }

    cout << sum << endl;

}
