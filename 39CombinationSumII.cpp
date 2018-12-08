#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int>& candidates, int& target, int index){
	if(target == 0){
		res.push_back(temp); return;
	}
	else if(target < 0) return;
	
	for(int i=index; i<candidates.size(); i++){
		temp.push_back(candidates[i]); target -= candidates[i];
		dfs(res, temp, candidates, target, i);
		temp.pop_back(); target += candidates[i];
	}
}

void Solution(vector<int> candidates, int target){
	vector<vector<int> > res; vector<int> temp;
	dfs(res, temp, candidates, target, 0);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
		
}


int main(){
	int arr[] = {2, 3, 6, 7}, n=4;
	vector<int> candidates(arr, arr+n);
	Solution(candidates, 7);
	
	return 0;
}
