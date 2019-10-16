#include <iostream>
#include <vector>
#include <fstream>
#include <climits>

using namespace std;

struct point{
    int xpos;
    int ypos;
    int xvel;
    int yvel;
};

void tick_forward(vector<point> &ps){
    for(auto &p : ps){
        p.xpos += p.xvel;
        p.ypos += p.yvel;
    }
}

long bb_area(vector<point> &ps){
    int minX = INT_MAX, miny = INT_MAX;
    int maxX = INT_MIN, maxY = INT_MIN;
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
    return (maxX - minX) * (maxY - minY);
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

    long prev_area = LONG_MAX;
    long bb_area_l = bb_area(points);

    while(bb_area_l < pre_area){
        tick_forward(points);
        bb_area_l = bb_area(points);
    }

    cout << "done" << endl;

    return 0;
}
