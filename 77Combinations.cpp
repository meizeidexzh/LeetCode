#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, vector<vector<int> >& res, vector<int>& temp, int index, int k){
	//终止条件有两个， temp的长度达到k， 或者， nums已经遍历完了； 
	if(temp.size() == k){
		res.push_back(temp); return;
	}
	
	if(index == nums.size()) return;
	
	for(int i=index; i<nums.size(); i++){
		temp.push_back(nums[i]);
		dfs(nums, res, temp, i+1, k);
		temp.pop_back();
	}
}

vector<vector<int> > Solution(int n, int k){
	vector<int> nums; int i;
	for(i=1; i<=n; i++) nums.push_back(i);
	vector<vector<int> > res;
	vector<int> temp;
	dfs(nums, res, temp, 0, k);
	return res;
}

void PrintVector(vector<vector<int> > arr){
	int i, j;
	for(i=0; i<arr.size(); i++){
		for(j=0; j<arr[i].size(); j++) cout << arr[i][j] << " ";
		cout << endl;
	}
		
}

int main(){
	vector<vector<int> > res = Solution(4, 2);
	PrintVector(res);
	
	return 0;
}
