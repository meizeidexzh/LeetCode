#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<string>& res, string& temp, vector<int>& index, vector<int>& nums){
    if(temp.size() == nums.size()){
        res.push_back(temp); return;
    }
    
    for(int i=0; i<index.size(); i++)
        if(index[i] == 1){
            temp += (nums[i]+'0'); index[i] = 0;
            dfs(res, temp, index, nums);
            temp.erase(temp.size()-1); index[i] = 1;
        }
    
}

string Solution(int n, int k) {
    vector<string> res;
    string temp;
    vector<int> index;
    vector<int> nums;
    for(int i; i<n; i++){
        nums.push_back(i+1); index.push_back(1);
    }
    dfs(res, temp, index, nums);
    return res[k-1];
}


int main(){
	string s = Solution(3, 3);
	cout << s;
	return 0;
}
