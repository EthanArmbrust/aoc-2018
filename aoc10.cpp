#include <iostream>
#include <vector>
#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

struct point{
    int xpos;
    int ypos;
    int xvel;
    int yvel;
};

int minX = INT_MAX, minY = INT_MAX;
int maxX = INT_MIN, maxY = INT_MIN;

bool compare_points(const point &p, const point &q){
	if(p.ypos == q.ypos){
		return p.xpos < q.xpos;
	}
	else return p.ypos < q.ypos;
}

void tick_forward(vector<point> &ps){
    for(auto &p : ps){
        p.xpos += p.xvel;
        p.ypos += p.yvel;
    }
}
void tick_backward(vector<point> &ps){
    for(auto &p : ps){
        p.xpos -= p.xvel;
        p.ypos -= p.yvel;
    }
}

long long bb_area(vector<point> &ps){
 	minX = INT_MAX, minY = INT_MAX;
    maxX = INT_MIN, maxY = INT_MIN;
    for(auto &p : ps){
        if(p.xpos < minX){
            minX = p.xpos;
        }
        if(p.xpos > maxX){
            maxX = p.xpos;
        }
        if(p.ypos < minY){
            minY = p.ypos;
        }
        if(p.ypos > maxY){
            maxY = p.ypos;
        }
    }
    return (long long)(maxX - minX) * (long long)(maxY - minY);
}

void draw_points(vector<point> &ps){
	string line(maxX - minX + 1, ' ');
	vector<string> grid(maxY - minY + 1, line);
	for(auto &p : ps){
		grid[p.ypos - minY][p.xpos - minX] = '#';
	}
	for(auto &l : grid){
		cout << l << endl;
	}
}

int main(){
    
    ifstream infile("input/10.txt"); 
    vector<point> points;
    string s;
    while(getline(infile,s)){
        int xpos, ypos, xvel, yvel;
        sscanf(s.c_str(), "position =<%d, %d> velocity=<%d, %d>", &xpos, &ypos, &xvel, &yvel);
        point p = {xpos, ypos, xvel, yvel};
        points.push_back(p);
    }

    long long prev_area = LONG_MAX;
    long long bb_area_l = bb_area(points);
	
	int step = 0;

    while(bb_area_l < prev_area){
        tick_forward(points);
		prev_area = bb_area_l;
        bb_area_l = bb_area(points);
		step++;
    }
	tick_backward(points);
	bb_area_l = bb_area(points);
	cout << endl;

	sort(points.begin(), points.end(), compare_points);
	draw_points(points);
	cout << --step << endl;

    cout << "done" << endl;

    return 0;
}
