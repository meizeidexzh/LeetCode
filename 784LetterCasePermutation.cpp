#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector<string> Solution(string S){
	int n = S.size();
	vector<string> res;
	res.push_back("");
	int i, j;
	for(i=0; i<n; i++){
		int len = res.size();
		if(S[i] >= '0' && S[i] <= '9')
			for(j=0; j<len; j++) res[j].push_back(S[i]);
		else{
			for(j=0; j<len; j++){
				res.push_back(res[j]);
				res[j].push_back(tolower(S[i]));
				res[j+len].push_back(toupper(S[i]));
			}
		}
	}
	return res;
}

int main(){
	string s = "a1b2";
	vector<string> res = Solution(s);
	int i, len = res.size();
	for(i=0; i<len; i++) cout << res[i] << " "; cout << endl;
	return 0;
}
