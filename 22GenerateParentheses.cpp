#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void dfs(vector<string>& res, string& temp, int& L, int& R, int n){
	//L�� �����ŵ������� R �����ŵ����� 
    if(L == n && R == n){
        res.push_back(temp);
        return;
    }
    
    if(L < n){//ֻҪ�����ŵ�����С��n�� �Ϳ��Բ��������� 
    	temp += "("; L ++;
    	dfs(res, temp, L, R, n);
    	temp.erase(temp.size()-1); L --;
    	if(R < L){//ֻ�������ŵ�����С�������ţ� ���ܲ��������� 
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
