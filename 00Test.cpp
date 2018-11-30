#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

#define MaxDigit 4
#define Radix 10

struct Node{
	int val;
	struct Node* next;
}; 
typedef struct Node* PtrN;

struct HeadNode{
	struct Node *head, *tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int x, int D){
	int i, pop;
	for(i=1; i<=D; i++){
		pop = x % Radix; x /= Radix;
	}
	return pop;
}

void MSD(int* arr, int L, int R, int D){
	int Di, i, j; Bucket B; PtrN temp, p, List = NULL;
	//stop condition
	if(D == 0) return;
	
	//initialize
	for(Di=0; Di<Radix; Di++) B[Di].head = B[Di].tail = NULL;
	
	//arr->list
	for(i=L; i<=R; i++){
		temp = (PtrN)malloc(sizeof(struct Node));
		temp->val = arr[i]; temp->next = List; List = temp;
	}
	
	//list->bucket
	p = List;
	while(p){
		temp = p; p = p->next; Di = GetDigit(temp->val, D);
		if(B[Di].head==NULL) B[Di].tail = temp;
		temp->next = B[Di].head; B[Di].head = temp; 
	}
	
	//bucket->arr
	i = j = L;
	for(Di=0; Di<Radix; Di++){
		if(B[Di].head){
			p = B[Di].head;
			while(p){
				temp = p; p = p->next;
				arr[j++] = temp->val; free(temp);
			}
			MSD(arr, i, j-1, D-1);
			i = j;
		}
	}
}

void MSDSort(int* arr, int N){
	MSD(arr, 0, N-1, MaxDigit);
}

int main(){
	int arr[] = {9,8,7,6,5,4,3,2,1}, n=9;
	MSDSort(arr, n);
	int i;
	for(i=0; i<n; i++) cout << arr[i] << " "; cout << endl;
	return 0;
}
