#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int>& nums, int pos, int k){
	if(temp.size() == k){
		res.push_back(temp); return;
	}
	
	for(int i=pos; i<nums.size(); i++){
		temp.push_back(nums[i]);
		dfs(res, temp, nums, i+1, k);
		temp.pop_back();
	}
	
}

void Solution(vector<int>& nums){
	vector<vector<int> > res;
	vector<int> temp; int pos = 0;
	for(int i=0; i<=nums.size(); i++)
		dfs(res, temp, nums, pos, i);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
}

int main(){
	int arr[] = {1, 2, 3}, n=3;
	vector<int> nums(arr, arr+n);
	Solution(nums);
	return 0;
}
