#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct elfo{
    char current_job = '.'; //'.' means not working
    int job_start;
};

int main(){

    ifstream infile("input/7.txt");
    vector<string> inputList;

    string s;
    while(getline(infile,s)){
        inputList.push_back(s);
    }

    int f_index = 5;
    int s_index = 36;

    int bonus_time = 60;

    vector<string> deps(26, "");
    vector<elfo> elves(5);
    vector<char> job_queue;

    for(auto str : inputList){
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
            job_queue.push_back(key);
            cout << "Removing " << key << endl;
            uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), key), uncompleted.end());
            k--;
        }
    }
    int time = 0;
    while(completed.length() < 26){
        //clear out any done jobs
        for(auto &elf : elves){
            if(elf.current_job != '.'){
                if(time - elf.job_start >= int(elf.current_job - 'A') + 1 + bonus_time){
                    //job is done
                    completed += elf.current_job;
                    elf.current_job = '.';
                }
            }
        }
        //Move ready jobs to job queue
        for(int i = 0; i < uncompleted.size(); i++){
            char key = uncompleted[i];
            bool unmet_dep = false;
            for(auto c : deps[key - 'A']){
                if(completed.find(c) == string::npos){
                    unmet_dep = true;
                }
            }
            if(!unmet_dep){
                job_queue.push_back(key);
                cout << "Removing " << key << endl;
                uncompleted.erase(remove(uncompleted.begin(), uncompleted.end(), key), uncompleted.end());
                i--;
            }
        }
        //Assign jobs in queue to elf
        for(int i = 0; i < 


        time++;
    }

    cout << completed << endl;
    cout << "string length: " << completed.length() << endl;
    cout << "Time: " << time << endl;

    return 0;
}
