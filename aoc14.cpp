#include <iostream>
#include <vector>

using namespace std;

int main(){

	vector<int> rec = {3, 7};
	int elf1 = 0;
	int elf2 = 1;
	int input = 554401;

	int output = 0;

	while(rec.size() <= input + 10){

		if(output < 18){
			for(auto x : rec){
				cout << x << " ";
			}
			cout << endl;
			output++;
		}
		
		int newDrink = rec[elf1] + rec[elf2];
		if(newDrink >= 10){
			rec.push_back(1);
		}
		rec.push_back(newDrink % 10);
		elf1 = (elf1 + 1 + rec[elf1]) % rec.size();
		elf2 = (elf2 + 1 + rec[elf2]) % rec.size();
	}

	string ans = "";
	for(int i = input; i < input + 10; i++){
		ans += to_string(rec[i]);
	}
	cout << ans << endl;

	return 0;
}
