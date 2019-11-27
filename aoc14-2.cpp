#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> rec = {3, 7};
	int elf1 = 0;
	int elf2 = 1;
	int input = 554401;
	string last_nums = "";
	string other_last = "";

	int output = 0;

	while(last_nums != to_string(input) && other_last != to_string(input)){
		int newDrink = rec[elf1] + rec[elf2];
		if(newDrink >= 10){
			rec.push_back(1);
		}
		rec.push_back(newDrink % 10);
		elf1 = (elf1 + 1 + rec[elf1]) % rec.size();
		elf2 = (elf2 + 1 + rec[elf2]) % rec.size();
		if(rec.size() >= to_string(input).length()){
			last_nums = "";
			for(int i = to_string(input).length(); i > 0; i--){
				last_nums += to_string(rec[rec.size() - i]);
			}
		}
		if(rec.size() - 1 >= to_string(input).length()){
			other_last = "";
			for(int i = to_string(input).length(); i > 0; i--){
				other_last += to_string(rec[(rec.size() - i) - 1]);
			}
		}

		//cout << "Other last " << other_last << endl;
		//cout << "Last       " << last_nums << endl;
		output++;

	}

	cout << output - last_nums.length() << endl;
	return 0;
}
