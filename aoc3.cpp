#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void drawRectangle(vector<string> &s, vector<vector<vector<int>>> &v, int claim, int s_l, int s_t, int w, int h);

int main(){

    ifstream infile("input3.txt");
    string line(1000, '.');
    vector<string> sheet(1000, line);
    vector<vector<int>> rows(1000);
    vector<vector<vector<int>>> claims(1000,rows);
    vector<int> claimNums;

    string s;
    while(getline(infile,s)){
        vector<string> temp;
        string word;
        stringstream ss(s);
        while(ss >> word){
            temp.push_back(word);
        }
        int claimNum = stoi(temp[0].substr(1));
        claimNums.push_back(claimNum);

        string start = temp[2];
        start.pop_back();
        int com = start.find(',');
        int start_left = stoi(start.substr(0, com));
        int start_top = stoi(start.substr(com + 1));

        string dim = temp[3];
        int x = dim.find('x');
        int width = stoi(dim.substr(0, x));
        int height = stoi(dim.substr(x + 1));

        drawRectangle(sheet, claims, claimNum, start_left, start_top, width, height);

    }

    int xCount = 0;
    for(auto str : sheet){
        for(char c : str){
            if(c == 'X'){
                xCount++;
            }
        }
    }
    cout << xCount << endl;

    for(auto v : claims){
        for(auto v2 : v){
            if(v2.size() > 1){
                for(auto n : v2){
                    auto f = find(claimNums.begin(), claimNums.end(), n);
                    if(f != claimNums.end()){
                        claimNums.erase(f);
                    }
                }
            }
        }
    }

    cout << "Claim " << claimNums[0] << endl; 

    return 0;
}

void drawRectangle(vector<string> &s, vector<vector<vector<int>>> &v, int claim, int s_l, int s_t, int w, int h){
    for(int i = s_t; i < s_t + h; i++){
        for(int j = s_l; j < s_l + w; j++){
            if(s[i][j] == '.'){
                s[i][j] = 'o';
            }
            else{
                s[i][j] = 'X';
            }
            v[i][j].push_back(claim);
        }
    }
}
