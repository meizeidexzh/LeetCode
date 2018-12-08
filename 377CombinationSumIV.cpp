#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//回溯算法求解 
void dfs(int& res, vector<int>& temp, vector<int>& nums, int& target){
    if(target <= 0){
        if(target == 0) res ++;
        return;
    }
    
    for(int i=0; i<nums.size(); i++){
        temp.push_back(nums[i]); target -= nums[i];
        dfs(res, temp, nums, target);
        temp.pop_back(); target += nums[i];
    }
}

int Solution(vector<int>& nums, int target) {
    int res = 0; vector<int> temp;
    dfs(res, temp, nums, target);
    return res;
}

//递推，动态规划
 

int main(){
	int arr[] = {4, 2, 1}, n = 3, target = 32;
	vector<int> nums(arr, arr+n);
	cout << Solution(nums, target) << endl;
	
	return 0;
}



