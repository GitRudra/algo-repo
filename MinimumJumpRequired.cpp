#include<iostream>
#include<climits>

using namespace std;

int findMinJumpRequired(int* inmat, int n){

	int *jump = new int (n);
	*(jump+0) = 0;
	
	for(int i=1;i<n;i++){
		*(jump + i) = INT_MAX;
		for(int j=0 ; j<i ; j++){
			if(( i <= j + *(inmat + j) ) && *(jump + j) != INT_MAX){
				*(jump+i) = *(jump+j) + 1;
				break;
			}
		}
	}
	return *( jump + n-1);
}


int main(){
	int arr[]= {1, 3, 6, 1, 0, 9};
    int size=sizeof(arr)/sizeof(int);
    cout<<"Minimum number of jumps to reach end is  "<< findMinJumpRequired(arr,size);
    return 0;
}
