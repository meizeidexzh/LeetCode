#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<string> Break(string s){
    vector<int> temp; temp.push_back(-1); 
    for(int i=0; i<s.size(); i++)
        if(s[i] == ' ') temp.push_back(i);
    temp.push_back(s.size());
    vector<string> res;
    for(int i=0; i<temp.size()-1; i++){
        int start = temp[i]+1, len = temp[i+1]-temp[i]-1;
        if(len > 0) res.push_back(s.substr(start, len));
    }
    return res;
}


int main(){
	string s = "this apple is sweet";
	vector<string> res = Break(s);
	for(int i=0; i<res.size(); i++) cout << res[i] << endl;
	
	return 0;
}
