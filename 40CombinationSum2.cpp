#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

bool Valid(vector<vector<int> > res, vector<int> temp){
    for(int i=0; i < res.size(); i++) 
        if(res[i] == temp) return false;
    return true;
}

void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int>& candidates, int pos, int target){
    int sum = 0;
    for(int i=0; i<temp.size(); i++) sum += temp[i];
    if(sum >= target){
        if(sum == target && Valid(res, temp)) res.push_back(temp); return;
    }
    
    if(pos > candidates.size()) return;
    
    for(int i=pos; i<candidates.size(); i++){
        temp.push_back(candidates[i]); 
        dfs(res, temp, candidates, i+1, target);
        temp.pop_back();
    }
}


vector<vector<int> > Solution(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int> > res;
    vector<int> temp;
    dfs(res, temp, candidates, 0, target);
    return res;
}

int main(){
	int arr[] = {10, 1, 2, 7, 6, 1, 5}, n = 7, target = 8;
	vector<int> nums(arr, arr+n);
	vector<vector<int> > res = Solution(nums, target);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}
