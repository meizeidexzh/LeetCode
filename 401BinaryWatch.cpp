#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

string ToString(int n){//dev��֧��to_string������ ����д��һ��to_string 
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
            if(sum1 <= 11 && sum2 <= 59){ //��ı�ʾ���з�Χ�ģ� ������Χ��Ҫ����       
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
        temp.pop_back(); numone --;//�ָ� 
        temp.push_back(0);
        dfs(res, temp, numone, num);
        temp.pop_back();//�ָ� 
    }
    else{
        temp.push_back(0);
        dfs(res, temp, numone, num);
        temp.pop_back();//�ָ� 
    }
}

vector<string> Solution(int num) {
    vector<string> res; 
    vector<int> temp;
    int numone = 0; //��¼1�ĸ��� 
    dfs(res, temp, numone, num);
    return res;
}
    
    
int main(){
	vector<string> res = Solution(1);
	for(int i=0; i<res.size(); i++) cout << res[i] << endl;
	
	return 0;
}
