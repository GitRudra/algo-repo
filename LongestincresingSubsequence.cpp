#include<iostream>
using namespace std;

int findLIS(int* arr, int length){

	int *lis = new int(length);

	*(lis+0) = 1;

	int max = 0;

	for(int i=1;i<length;i++){
		max= 0;
		for(int j=0 ; j<i ; j++){
			if( arr[j] < arr[i] && *(lis + j) > max ){
				max = *(lis +j);
			}
		}
		*(lis+i) = 1+ max;
	}

	max = 0;

	for(int i=0 ; i<length ; i++){
		if( *(lis + i) >max){
			max = *(lis+i);
		}
	}
	return max;
}

int main(){
	int length = 9;
	int arr[9] = {10,22,9,33,21,50,41,60,80};
	cout<<" Length of Longest Incresing Subsequence : "<<findLIS(arr,length);
}
