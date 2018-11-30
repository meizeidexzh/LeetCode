#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& ans, vector<int>& temp, vector<int>& nums, vector<int>& index){
	if(temp.size() == nums.size()){
		ans.push_back(temp); return;
	}
	for(int i=0; i<nums.size(); i++){
		if(index[i] == 0) continue;
		temp.push_back(nums[i]);
		index[i] = 0;
		dfs(ans, temp, nums, index);
		temp.pop_back();
		index[i] = 1;
	}
} 

vector<vector<int> > Solution(vector<int>& nums){
	vector<vector<int> > ans;
	vector<int> temp;
	vector<int> index(nums.size());
	for(int i=0; i<nums.size(); i++) index[i] = 1;
	dfs(ans, temp, nums, index);
	return ans;
}

int main(){
	int arr[] = {1, 2, 3}, n=3;
	vector<int> nums(arr, arr+n);
	vector<vector<int> > res = Solution(nums);
	int i, j;
	for(i=0; i<res.size(); i++){
		for(j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
