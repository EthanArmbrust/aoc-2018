#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

struct Point{
    char id;
    pair<int, int> point;
};

int total_dist(int x, int y, vector<Point> &points){
    int total = 0;
    for(auto &p : points){
         total += abs(p.point.first - x) + abs(p.point.second - y);
    }
	return total;
}

int main(){

	ifstream infile("input/6.txt");
	string s;

	vector<Point> points;
    int id_count = 0;

	while(getline(infile, s)){
		int x, y;
		sscanf(s.c_str(), "%d, %d", &x, &y);
		points.push_back({char('A' + id_count), {x,y}});
        id_count++;
	}

	int minx = INT_MAX, miny = INT_MAX, maxx = 0, maxy = 0;
	for(auto &p : points){
		if(p.point.first < minx){
			minx = p.point.first;
		}
		if(p.point.first > maxx){
			maxx = p.point.first;
		}
		if(p.point.second < miny){
			miny = p.point.second;
		}
		if(p.point.second > maxy){
			maxy = p.point.second;
		}
	}

    vector<vector<int>> grid; 
    for(int y = 0; y <= maxy - miny; y++){
        vector<int> row;
        for(int x = 0; x <= maxx - minx; x++){
            row.push_back(total_dist(x + minx, y + miny, points));
        }
        grid.push_back(row);
    }

	int total_sum = 0;

	for(auto row : grid){
		for(int i : row){
			if(i < 10000){
				total_sum++;
			}
		}
	}
	cout << total_sum << endl;

	return 0;
}
