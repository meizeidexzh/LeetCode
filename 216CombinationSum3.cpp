#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& res, vector<int>& nums, vector<int>& temp, int index, int n, int k){
    if(temp.size() == k-1){
    	int sum = 0, x;
        for(int i=0; i<temp.size(); i++){
        	sum += temp[i]; 
        	cout << temp[i] << " ";
		}
		
        x = n-sum;
        if(x > temp.back() && x <=9){
        	cout << "true"; 
        	temp.push_back(x); res.push_back(temp);
        	temp.pop_back();
		}
		cout << endl;
        cout << endl;
        return;
    }
    
    if(index == nums.size()) return;
    
    for(int i=index; i<nums.size(); i++){
        temp.push_back(nums[i]);
        dfs(res, nums, temp, i+1, n, k);
        temp.pop_back();
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<vector<int> > res;
    vector<int> temp;
    vector<int> nums;
    for(int i=1; i<=9; i++) nums.push_back(i);
    dfs(res, nums, temp, 0, n, k);
    return res;
}

int main(){
	vector<vector<int> > res = combinationSum3(3, 7);
	return 0;
}
    
    
