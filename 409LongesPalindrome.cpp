#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int Solution(string s){
	int count[52], size=s.size();
	int i;
	for(i=0; i<52; i++) count[i] = 0;
	for(i=0; i<size; i++){
		if(s[i] >= 'a' && s[i] <= 'z') count[s[i]-'a'] ++;
		else count[s[i]-'A'+26] ++;
	}
	int res, sum; res = sum = 0;
	for(i=0; i<52; i++){
		if(count[i]%2){
			res += count[i]-1; sum += count[i];
		}
		else{
			res += count[i]; sum += count[i];
		}
	}
	return res < sum? res+1 : res;
}


int main(){
	string s = "abccccdd";
	cout << Solution(s);
	
	return 0;
}
