#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

//这个方法会超时的 
bool Valid(vector<int> temp){
    for(int i=0; i<temp.size(); i++){
        int a = temp[i];
        if(a % (i+1) != 0){
            if(a == 0) return false;
            if(a != 0 && ((i+1)%a != 0)) return false;
        } 
    }
    return true;
}

void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int>& index, vector<int> nums){
	if(temp.size() == nums.size()){
		if(Valid(temp))
			res.push_back(temp); 
		return;
	}
	
	for(int i=0; i<nums.size(); i++){
		if(index[i] == 1){
			temp.push_back(nums[i]); index[i] = 0;
			dfs(res, temp, index, nums);
			temp.pop_back(); index[i] = 1;
		}
	}
}

void Solution(int N){
	vector<vector<int> > res; vector<int> temp; vector<int> index; vector<int> nums;
	for(int i=1; i<=N; i++){
		index.push_back(1); nums.push_back(i);
	}
	dfs(res, temp, index, nums);
}


int main(){
	Solution(11);
	cout << "wanchegn" << endl;
	return 0;
} 
