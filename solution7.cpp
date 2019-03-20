#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <deque>
#include <vector>

using namespace std;

map<char, set<char>> readConditions(){
	map<char,set<char>> result;

	char base, requirement;
	for(string line;getline(cin, line);){
		sscanf(line.c_str(), "Step %c must be finished before step %c can begin.", &requirement, &base);
		result[base].insert(requirement);
		result[requirement];
	}

	return result;
}

deque<char> getAllAvailableSteps(map<char, set<char>> &conditions){
	deque<char> result;

	for(auto &conditions_pr : conditions){
		if(conditions_pr.second.empty()){
			result.push_back(conditions_pr.first);
		}
	}

	return result;
}

string solvePartOne(map<char, set<char>> conditions){
	string result;
	do{
		auto available = getAllAvailableSteps(conditions);
		char first = available.front();
		for(auto &cond_pr : conditions) cond_pr.second.erase(first);
		result.push_back(first);
		conditions.erase(first);
	} while(!conditions.empty());
	return result;
}

struct worker{
	bool m_idle = true;
	char m_workingOn = 0;
	int m_time_to_finish = 0;
};

int solvePartTwo(map<char, set<char>> conditions, int numWorkers, int extraTime){
	int currentSecond = -1;
	vector<worker> workers(numWorkers);

	bool allIdle;
	do{
		currentSecond++;
		allIdle = true;
		for(auto &worker : workers){
			if(!worker.m_idle){
				worker.m_time_to_finish--;
				if(worker.m_time_to_finish == 0){
					worker.m_idle = true;
					for(auto &cond_pr : conditions) cond_pr.second.erase(worker.m_workingOn);
				}
			}
		}

		auto available = getAllAvailableSteps(conditions);
		
		for(auto &worker : workers){
			if(worker.m_idle){
				if(!available.empty()){
					worker.m_workingOn = available.front();
					available.pop_front();
					worker.m_time_to_finish = extraTime + (int)(worker.m_workingOn-'A'+1);
					worker.m_idle = false;
					conditions.erase(worker.m_workingOn);
				}
			}
			allIdle &= worker.m_idle;
		}

	} while(!conditions.empty() || !allIdle);

	return currentSecond;
}

int main(){
	auto conditions = readConditions();
	cout << "Part 1: '" << solvePartOne(conditions) << "'" << endl;
	cout << "Part 2: " << solvePartTwo(conditions,5,60) << endl;
	return 0;
}











