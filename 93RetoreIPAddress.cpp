#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

bool IsPro(string s){
    int m = atoi(s.c_str());
    if(m >=0 && m <= 255) return true;
    return false;
}

bool IsZero(string s){
    if(s[0] == '0' && s.size() > 1) return false;
    return true;
}

bool Valid(string s, vector<int> temp){
    string tmp;
    tmp = s.substr(0, temp[0]); if(!IsPro(tmp) || !IsZero(tmp)) return false;
    tmp = s.substr(temp[0], temp[1]-temp[0]); if(!IsPro(tmp) || !IsZero(tmp)) return false;
    tmp = s.substr(temp[1], temp[2]-temp[1]); if(!IsPro(tmp) || !IsZero(tmp)) return false;
    tmp = s.substr(temp[2], s.size()-temp[2]+1); if(!IsPro(tmp) || !IsZero(tmp)) return false;
    return true;
}

string ToString(string s, vector<int> temp){
    string res; int j = 0;
    for(int i=0; i<s.size(); i++){
        if(i == temp[j]){
            res += '.'; j++;
        }
        res += s[i];
    }
    return res;
}

void dfs(vector<string>& res, vector<int>& temp, string s, int pos){
    if(temp.size() == 3){
        if(Valid(s, temp)) res.push_back(ToString(s, temp));
        return;
    }
    
    if(pos == temp.size()) return;
    
    for(int i=pos; i<s.size(); i++){
        if(i >= pos+3) break;
        temp.push_back(i);
        dfs(res, temp, s, i+1);
        temp.pop_back();  
    }
}

vector<string> Solution(string s) {
    vector<string> res;
    if(s.size() < 4) return res;
    vector<int> temp; int pos = 1;
    dfs(res, temp, s, pos);
    return res;
}

int main(){
	string s = "25525511135";
	vector<string> res = Solution(s);
	for(int i=0; i<res.size(); i++) cout << res[i] << endl;
	return 0;
}
