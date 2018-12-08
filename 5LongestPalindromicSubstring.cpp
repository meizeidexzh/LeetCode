#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string Solution(string& str){
	int length = str.size(), maxLength = 1, start=0;
	bool dp[length][length];
	
	for(int i=0; i<length; i++)
		for(int j=0; j<length; j++)
			dp[i][j] = false;
	
	for(int i=0; i<length; i++){
		dp[i][i] = true;
		if(i < length-1 && str[i] == str[i+1]){
			dp[i][i+1] = true; start = i; maxLength = 2;
		}
	}
	
	for(int len=3; len<=length; len++){
		for(int i=0; i<=length-len; i++){
			int j = i+len-1;
			if(dp[i+1][j-1] && str[i] == str[j]){
				dp[i][j] = true; start = i; maxLength = len;
			}
		}
	}
	return str.substr(start, maxLength);
}

int main(){
	string s = "ccc";
	cout << Solution(s) << endl;
	
	return 0;
}
