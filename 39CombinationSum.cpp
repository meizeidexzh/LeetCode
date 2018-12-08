#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void dfs(vector<vector<int> >& res, vector<int>& temp, vector<int> candidates, int pos, int& target){
	if(pos == candidates.size()) return;
	int a = candidates[pos];
	if(a >= target){
		if(a == target){
			temp.push_back(a); res.push_back(temp); temp.pop_back();
		}
		return;
	}
	
	dfs(res, temp, candidates, pos+1, target);
	
	int n = target/a;
	while(n--){
		temp.push_back(a); target -= a;
		dfs(res, temp, candidates, pos, target);
		temp.pop_back(); target += a;
	}
}

void Solution(){
	int arr[] = {2,3,5}, n=3, target = 8;
	vector<vector<int> > res;
	vector<int> temp;
	vector<int> candidates(arr, arr+n);
	dfs(res, temp, candidates, 0, target);
	for(int i=0; i<res.size(); i++){
		for(int j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
}


int main(){
	Solution();
	
	return 0;
}
