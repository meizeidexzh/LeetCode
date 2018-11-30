#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void dfs(vector<int>& nums, int pos, vector<int>& path, vector<vector<int> >& result){
	if(pos == nums.size()) return;
	for(int i=pos; i<nums.size(); i++){
		path.push_back(nums[i]);
		result.push_back(path);
		dfs(nums, i+1, path, result);
		path.pop_back();
	}
}

vector<vector<int> > Solution(vector<int>& nums){
	vector<vector<int> > result;
	vector<int> path;
	result.push_back(path);
	if(nums.empty()) return result;
	dfs(nums, 0, path, result);
	return result;
}

vector<vector<int> > Solution2(vector<int>& nums){
	vector<vector<int> > res(1);
	int i, j, len = nums.size();
	for(i=0; i<len; i++){
		int size = res.size();
		for(j=0; j<size; j++){
			res.push_back(res[j]);
			res[j+size].push_back(nums[i]);
		}
	}
	return res;
}

vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    vector<vector<int> > res(1);
    int i, j, len = nums.size();
    for(i=0; i<len; i++){
        int size = res.size();
        for(j=0; j<size; j++){
            vector<int> temp = res[j];
            temp.push_back(nums[i]);
            int flag = 1;
            for(int k=0; k<res.size(); k++)//²éÖØ
                if(res[k] == temp){
                	cout << "falg changed" << endl;
                    flag = 0; break;
            }
            if(flag == 1) res.push_back(temp);
        }
    }
    return res;
}

int main(){
	int arr[] = {1, 2, 3}, n=3;
	vector<int> nums(arr, arr+n);
	subsetsWithDup(nums);
	
	return 0;
}
