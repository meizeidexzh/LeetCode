#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int Solution(vector<vector<int> >&triangle){
	int i, j;
	for(i=triangle.size()-2; i>=0; i--)
		for(j=0; j<triangle[i].size(); j++)
			triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
	return triangle[0][0];
}



int main(){
	vector<vector<int> > triangle;
	vector<int> temp;
	temp.push_back(2); triangle.push_back(temp); temp.clear();
	temp.push_back(3); temp.push_back(4); triangle.push_back(temp); temp.clear();
	temp.push_back(6); temp.push_back(5); temp.push_back(7); triangle.push_back(temp); temp.clear();
	temp.push_back(4); temp.push_back(1); temp.push_back(8); temp.push_back(3); 
	triangle.push_back(temp); temp.clear();
	cout << Solution(triangle) << endl;
	
	return 0;
}
