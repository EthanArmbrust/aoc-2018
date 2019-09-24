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

char closest_point(int x, int y, vector<Point> &points){
    int min_dist = INT_MAX;
    Point min_p;
    bool duplicate = true;
    for(auto &p : points){
        int dist = abs(p.point.first - x) + abs(p.point.second - y);
        if(dist < min_dist){
            min_dist = dist;
            duplicate = false;
            min_p = p;
        }
        else if(dist == min_dist){
            duplicate = true;
        }
    }
    if(!duplicate){
        return min_p.id;
    }
    else return '.';
}

int main(){

	ifstream infile("input/6.txt");
	string s;

	vector<Point> points;
    int id_count = 0;

	while(getline(infile, s)){
		int x, y;
		sscanf(s.c_str(), "%d, %d", &x, &y);
		points.push_back({'A' + id_count, {x,y}});
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

    vector<vector<char>> grid; 
    for(int y = 0; y <= maxy - miny; y++){
        vector<char> row;
        for(int x = 0; x <= maxx - minx; x++){
            row.push_back(closest_point(x + minx, y + miny, points));
        }
        grid.push_back(row);
    }
	/*
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j];
        }
        cout << endl;
    }

    cout << endl;
	*/

    vector<char> edges;

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1){
                if(find(edges.begin(), edges.end(), grid[i][j]) == edges.end()){
                    edges.push_back(grid[i][j]);
                }
            }
        }
    }

    map<char, int> plots;
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(find(edges.begin(), edges.end(), grid[i][j]) == edges.end()){
                plots[grid[i][j]] += 1;
            }
        }
    }

    int max_size = 0;
    char max_char;
    for(auto m : plots){
        if(m.second > max_size){
            max_size = m.second;
            max_char = m.first;
        }
    }
    cout << max_char << endl;
    cout << max_size << endl;

	return 0;
}
