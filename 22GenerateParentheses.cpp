#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<string>& res, string& temp, int& L, int& R, int n){
	//L， 左括号的数量， R 右括号的数量 
    if(L == n && R == n){
        res.push_back(temp);
        return;
    }
    
    if(L < n){//只要做括号的数量小于n， 就可以插入左括号 
    	temp += "("; L ++;
    	dfs(res, temp, L, R, n);
    	temp.erase(temp.size()-1); L --;
    	if(R < L){//只有右括号的数量小于左括号， 才能插入右括号 
    		temp += ")"; R ++;
    		dfs(res, temp, L, R, n);
    		temp.erase(temp.size()-1); R --;
		}
	}
	else{
		temp += ")"; R++;
		dfs(res, temp, L, R, n);
		temp.erase(temp.size()-1); R --;
	}
}

vector<string> Solution(int n) {
    vector<string> res; string temp; int L, R; L = R = 0;
    dfs(res, temp, L, R, n);
    return res;
}

int main(){
	vector<string> res = Solution(3);
	for(int i; i<res.size(); i++) cout << res[i] << endl;
	return 0;
}
