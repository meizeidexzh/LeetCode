#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int Solution(int n){
	int res[n+1];
	memset(res, 0, sizeof(res));
	res[0] = res[1] = 1;
	for(int i=2; i<=n; i++)
		for(int j=0; j<=i-1; j++) res[i] += res[j]*res[i-1-j];
	return res[n]; 
}


int main(){
	cout << Solution(3) << endl;
	
	return 0;
}
