#include <vector>
#include <iostream>
#include <climits>
#include <cassert>

using namespace std;

int power_level(int x,int y, int serial){
    int rack_id = x + 10;
    int power_level = rack_id * y;
    power_level += serial;
    power_level *= rack_id;
    power_level /= 100;
    power_level %= 10;
    power_level -= 5;
    return power_level;
}

int main(){

    int input = 5093;
    vector<vector<int>> grid(301, vector<int>(301, 0));

    for(int i = 1; i < 301; i++){
        for(int j = 1; j < 301; j++){
            grid[i][j] = power_level(j, i, input);
        }
    }

    assert(power_level(3,5,8) == 4);
    assert(power_level(122,79,57) == -5);
    assert(power_level(217,196,39) == 0);
    assert(power_level(101,153,71) == 4);

    int max = INT_MIN;
    int maxx = 1;
    int maxy = 1;
    int maxs = 0;
    for(int size = 1; size <= 300; size++){
        for(int i = 1; i < 301 - (size - 1); i++){
            for(int j = 0; j < 301 - (size - 1); j++){
                int sum = 0;
                for(int p = i; p <= i + (size - 1); p++){
                    for(int q = j; q <= j + (size - 1); q++){
                        sum += grid[p][q];
                    }
                }
                if(sum > max){
                    max = sum;
                    maxx = j;
                    maxy = i;
                    maxs = size;
                }
            }
        }
    }

    cout << max << " " << maxx << "," << maxy << "," << maxs << endl;

    return 0;
}
