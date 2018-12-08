#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class NumArray{
	public:
		vector<int> sums;
		NumArray(vector<int> nums){
			int sum = 0;
			for(int i=0; i<nums.size(); i++){
				sum += nums[i];
				sums.push_back(sum);
			}
		}
		
		int sumRange(int i, int j){
			if(i == 0) return sums[j];
			return sums[j]-sums[i-1];
		}
};

int main(){
	int arr[] = {-2, 0, 3, -5, 2, -1}, n = 6;
	vector<int> nums(arr, arr+n);
	NumArray test(nums);
	cout << test.sumRange(0, 5) << endl;
	
	return 0;
}
