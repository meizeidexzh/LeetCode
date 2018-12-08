#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;






int main(){
	vector<vector<int> > m(3, vector<int>(4, 0));
	cout << m.size() << " " << m[0].size() << endl;
	
	return 0;
}
