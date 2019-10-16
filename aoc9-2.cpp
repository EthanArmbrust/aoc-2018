#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int input_players = 416;
	int last_marble = 71975 * 100;

	deque<int> marble_circle(1,0); //start out with 0 to get things rolling
	vector<int> elves(input_players, 0); //keeps track of score

	int current_marble = 0;
	int elfo = 0;

	for(int i = 1; i <= last_marble; i++){
		if(i % 23){
            int insert_pos = ((current_marble + 1) % marble_circle.size()) + 1;
			marble_circle.insert(marble_circle.begin() + insert_pos, i);
            current_marble = insert_pos;
		}
		else{
			elves[elfo] += i;
			int remove_idx = current_marble + marble_circle.size();
			while(remove_idx < 7){
				remove_idx += marble_circle.size();
			}
			remove_idx -= 7;
			remove_idx %= marble_circle.size();
			elves[elfo] += marble_circle[remove_idx];
			marble_circle.erase(marble_circle.begin() + remove_idx);
			current_marble = remove_idx % marble_circle.size();
		}
		elfo = (elfo + 1) % input_players;
	}

	sort(elves.begin(), elves.end(), std::greater<int>());
	cout << elves[0] << endl;

	return 0;
}
