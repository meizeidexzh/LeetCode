#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;




int main(){
	vector<pair<int, int> > tmp;
	tmp.push_back(make_pair(1, 5)); tmp.push_back(make_pair(7, 7)); tmp.push_back(make_pair(3, 4));
	sort(tmp.begin(), tmp.end(), [](const pair<int,int>& x, const pair<int,int>& y) -> int{
	return x.first < y.first;});
	
	return 0;
}
