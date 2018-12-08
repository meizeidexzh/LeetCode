#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool IsValid(vector<int> temp){
	if(temp.size() <= 1) return true;
	for(int i=0; i<temp.size(); i++)
		for(int j=i+1; j<temp.size(); j++)
			if(abs(i-j) == abs(temp[i] - temp[j])) return false;
	return true;
}

void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int>& index, vector<int>& nums){
	if(temp.size() == nums.size()){
		res.push_back(temp); return;
	}
	
	for(int i=0; i<index.size(); i++)
		if(index[i] == 1){
			temp.push_back(nums[i]); index[i] = 0;
			if(IsValid(temp)) dfs(res, temp, index, nums);
			temp.pop_back(); index[i] = 1;
		}
}

void Solution(int n){
	vector<vector<int> > res;
	vector<int> temp;
	vector<int> index; vector<int> nums;
	for(int i=0; i<n; i++){
		nums.push_back(i); index.push_back(1);
	}
	dfs(res, temp, index, nums);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
}



int main(){
	Solution(4);
	
	return 0;
}
