#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

	ifstream infile("input/6.txt");
	string s;

	vector<pair<int,int>> points;

	while(getline(infile, s)){
		int x, y;
		sscanf(s.c_str(), "%d, %d", &x, &y);
		points.push_back({x,y});
	}

	int minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0;
	for(auto p : points){
		if(p.first < minx){
			minx = p.first;
		}
		if(p.first > maxx){
			maxx = p.first;
		}
		if(p.second < miny){
			miny = p.second;
		}
		if(p.second > maxy){
			maxy = p.second;
		}
	}
	cout << minx << endl;
	cout << miny << endl;
	cout << maxx << endl;
	cout << maxy << endl;

	return 0;
}
