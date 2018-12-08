#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

bool IsPalindrome(string s){
	int i=0, j = s.size()-1;
	while(i < j){
		if(s[i] != s[j]) return false;
		i ++; j --;
	}
	return true;
}

void dfs(vector<vector<string> >& res, vector<string>& path, string s, int start){
	if(start == s.size()){
		res.push_back(path);
	}
	
	for(int i=start; i<s.size(); i++){
		if(IsPalindrome(s.substr(start, i-start+1))){
			path.push_back(s.substr(start, i-start+1));
			dfs(res, path, s, i+1);
			path.pop_back();
		}
	}
}

vector<vector<string> > Solution(string s){
	vector<vector<string> > res;
	if(s.size() == 0) return res;
	vector<string> path;
	dfs(res, path, s, 0);
	return res;
}

int main(){
	string s = "aab";
	vector<vector<string> > res;
	res = Solution(s);
	int i, j;
	for(i=0; i < res.size(); i++){
		for(j=0; j<res[i].size(); j++) cout << res[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
