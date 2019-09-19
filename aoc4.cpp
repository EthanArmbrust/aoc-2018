#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct guard{
    int id;
    vector<pair<int,int>> sleep_times;
};

int main(){

    ifstream infile("input/4.txt");
    string s;
	vector<string> input;
	vector<guard> guards;

	int current_guard, latest_sleep;
	

    while(getline(infile, s)){
		input.push_back(s);
    } 

	sort(input.begin(), input.end());

	for(string s : input){
		stringstream ss(s);
		vector<string> line;
		string t;
		while(ss >> t){
			line.push_back(t);
		}
		if(line[2] == "Guard"){
			current_guard = stoi(line[3].substr(1));
		}
		else if(line[2] == "falls"){
			int hour, min;
			sscanf(line[1].c_str(), "%d:%d]", &hour, &min);
			latest_sleep = min;
		}
		else{
			int hour, min;
			sscanf(line[1].c_str(), "%d:%d]", &hour, &min);
			min--;
			int guard_idx = -1;
			for(int i = 0; i < guards.size(); i++){
				if(current_guard == guards[i].id){
					guard_idx = i;
					break;
				}
			}
			if(guard_idx > 0){
				guard &g = guards[guard_idx];
				g.sleep_times.push_back(make_pair(latest_sleep, min));
			}
			else{
				vector<pair<int,int>> sleeps;
				sleeps.push_back(make_pair(latest_sleep, min));
				guard g = {current_guard, sleeps};
				guards.push_back(g);
			}
		}
	}

	int max_guard;
	int max_sleep = 0;
	guard gu;

	for(auto &g : guards){
		int sleep_sum = 0;
		for(auto p : g.sleep_times){
			sleep_sum += p.second - p.first;
		}
		if(sleep_sum > max_sleep){
			max_guard = g.id;
			max_sleep = sleep_sum;
			gu = g;
		}
	}

	vector<int> minutes;
	for(auto p : gu.sleep_times){
		minutes.push_back(p.first);
		minutes.push_back(p.second);
	}

	int highest_min, latest_val = -1;
	int high_count = 0;
	int latest_count = 0;

	for(int i = 0; i < minutes.size(); i++){
	}

	

	cout << max_guard << endl;

    return 0;
}
