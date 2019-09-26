#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	int input_players = 9;
	int last_marble = 25;

	vector<int> marble_circle(1,0); //start out with 0 to get things rolling
	vector<int> elves(input_players, 0); //keeps track of score

	int current_marble = 0;
	int elfo = 1;

	for(int i = 1; i <= last_marble; i++){
		if(i % 23){
			marble_circle.insert(marble_circle.begin() + ((current_marble % marble_circle.size()) + 1), i);
			current_marble = (current_marble + 2) % marble_circle.size();
		}
		else{
			elves[elfo] += i;
			int remove_idx = current_marble + marble_circle.size();
			while(remove_idx < 7){
				remove_idx += marble_circle.size();
			}
			remove_idx -= 7;
			remove_idx %= marble_circle.size();
			elves[elfo] = marble_circle[remove_idx];
			marble_circle.erase(marble_circle.begin() + remove_idx);
			current_marble = remove_idx % marble_circle.size();
		}
		elfo = (elfo + 1) % input_players;
	}

	sort(elves.begin(), elves.end());
	cout << elves[0] << endl;

	return 0;
}
