#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<string> Chars;

void Initialize(){
	string arr[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; int n=10;
	for(int i=0; i<n; i++) Chars.push_back(arr[i]);
}

void dfs(vector<string>& res, string& temp, string digits, int pos, int len){
	if(temp.size() == len){
		res.push_back(temp); return;
	}
	
	string s = Chars[digits[pos]-'0'];
	int size = s.size();
	for(int i=0; i<size; i++){
		temp += s[i];
		dfs(res, temp, digits, pos+1, len);
		temp.erase(temp.size()-1);
	}
}

vector<string> Solution(string digits){
	vector<string> res;
	string temp;
	Initialize();
	int len = digits.size();
	dfs(res, temp, digits, 0, len);
	return res;
}

int main(){
	string s = "23";
	vector<string> res = Solution(s);
	int i;
	for(i=0; i<res.size(); i++) cout << res[i] << " "; cout << endl;
	
	
}
