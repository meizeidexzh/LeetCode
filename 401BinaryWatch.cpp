#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string ToString(int n){//dev不支持to_string函数， 就手写了一个to_string 
	string s; int pop;
	while(n){
		pop = n % 10; n /= 10; s += (pop+'0');
	}
	if(s.size() == 0) s += '0';
	reverse(s.begin(), s.end());
	return s;
}

void dfs(vector<string>& res, vector<int>& temp, int& numone, int num){
    if(temp.size() == 10){
        if(numone == num){
            int sum1, sum2; sum1 = sum2 = 0; string s;
            for(int i=0; i<4; i++)
                if(temp[i] == 1) sum1 += pow(2, 3-i);
            for(int i=4; i<10; i++)
                if(temp[i] == 1) sum2 += pow(2, 9-i);
            if(sum1 <= 11 && sum2 <= 59){ //表的表示是有范围的， 超出范围的要舍弃       
                s += ToString(sum1);
                s += ":";
                if(sum2 < 10) s += "0";
                s += ToString(sum2);
                res.push_back(s);
            }
        }
        return;
    }
    
    if(numone < num){
        temp.push_back(1); numone ++;
        dfs(res, temp, numone, num);
        temp.pop_back(); numone --;//恢复 
        temp.push_back(0);
        dfs(res, temp, numone, num);
        temp.pop_back();//恢复 
    }
    else{
        temp.push_back(0);
        dfs(res, temp, numone, num);
        temp.pop_back();//恢复 
    }
}

vector<string> Solution(int num) {
    vector<string> res; 
    vector<int> temp;
    int numone = 0; //记录1的个数 
    dfs(res, temp, numone, num);
    return res;
}
    
    
int main(){
	vector<string> res = Solution(1);
	for(int i=0; i<res.size(); i++) cout << res[i] << endl;
	
	return 0;
}
