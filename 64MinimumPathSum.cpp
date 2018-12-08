#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;


int dp(int x, int y, vector<vector<int> >& grid, int X, int Y){//µ›πÈΩ‚Ã‚ 
    if(x == X){
        int sum = 0;
        for(int i=y; i<=Y; i++) sum += grid[X][i];
        return sum;
    }
    if(y == Y){
        int sum = 0;
        for(int i=x; i<=X; i++) sum += grid[i][Y];
        return sum;
    }
    
    return min(dp(x+1, y, grid, X, Y)+grid[x][y], dp(x, y+1, grid, X, Y)+grid[x][y]);
}

int minPathSum(vector<vector<int> >& grid) {
    int X, Y; X = grid.size()-1; Y = grid[0].size()-1;
    return dp(0, 0, grid, X, Y);
}

int Solution(vector<vector<int> >& grid){
	int m = grid.size(), n = grid[0].size();
	for(int x=m-1; x>=0; x--)
		for(int y=n-1; y>=0; y--){
			if(x == m-1 && y == n-1){
			}
			else if(x == m-1) grid[x][y] += grid[x][y+1];
			else if(y == n-1) grid[x][y] += grid[x+1][y];
			else grid[x][y] += min(grid[x+1][y], grid[x][y+1]);
		}
	return grid[0][0];
}

int main(){
	vector<vector<int> > grid;
	vector<int> temp(3); 
	temp[0] = 1; temp[1] = 3; temp[2] = 1; grid.push_back(temp);
	temp[0] = 1; temp[1] = 5; temp[2] = 1; grid.push_back(temp);
	temp[0] = 4; temp[1] = 2; temp[2] = 1; grid.push_back(temp);
	cout << Solution(grid) << endl;
	
	
	return 0;
}
