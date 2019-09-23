#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct guard{
    int id;
	int sl_am;
    vector<pair<int,int>> sleep_times;
};

bool compare_slams(guard &a, guard &b){
	return a.sl_am < b.sl_am;
}

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
			if(guard_idx >= 0){
				guard &g = guards[guard_idx];
				g.sleep_times.push_back(make_pair(latest_sleep, min));
				g.sl_am += min - latest_sleep;
			}
			else{
				vector<pair<int,int>> sleeps;
				sleeps.push_back(make_pair(latest_sleep, min));
				guard g = {current_guard, min - latest_sleep, sleeps};
				guards.push_back(g);
			}
		}
	}

	int min, guard, freq = 0;

	for(auto &g : guards){
		vector<int> minute_freq(60, 0);
		for(auto p : g.sleep_times){
			for(int i = p.first; i <= p.second; i++){
				minute_freq[i]++;
			}
		}
		int minute = max_element(minute_freq.begin(), minute_freq.end()) - minute_freq.begin();
		int frequency = *max_element(minute_freq.begin(), minute_freq.end());
		if(frequency > freq){
			freq = frequency;
			min = minute;
			guard = g.id;
		}
	}

	cout << guard * min << endl;

    return 0;
}
