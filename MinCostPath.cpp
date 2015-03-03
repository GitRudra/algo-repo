#include<iostream>
using namespace std;

/**
 * return maximum of three numbers
*/
int min(int x, int y, int z){
	int min = 999999;
	if(x<min)
		min =x;
	if(min > y)
		min =y;
	if(min > z)
	    min  = z;
	 return min;
}

void printArray(int *mat,int row, int col){

	cout<<"\n Displaying Matrix : \n";
	for(int i=0;i<row;i++){
		cout<<endl;
		for(int j=0 ; j< col ; j++){
			cout<<*(mat + i*col + j)<<"  ";
		}
	}
}

int findMinCostPath(int* inmat, int row, int column,int endr,int endc){

	int *auxvalue = new int( row * column );
	*(auxvalue + 0*column + 0) = *(inmat + 0*column + 0);

	for(int i=1 ; i<endc ; i++){
		*(auxvalue + 0*column + i) = (*(auxvalue + 0*column + i-1) + *(inmat + 0*column + i));
	}

	for(int i=1 ; i<endr ; i++){
		*(auxvalue + i*column + 0) = (*(auxvalue + (i-1)*column + 0) + *(inmat + i*column + 0));
	}

	int minval;
	for(int i=1 ; i<endr;i++){
		for(int j = 1 ; j< endc ; j++){
			minval = min( *(auxvalue + (i-1)*column +j) , *(auxvalue + (i-1)*column + (j-1)) , *(auxvalue + i*column + (j-1)));
			*(auxvalue + i*column + j) = minval + *(inmat + i*column + j);
		}
	}
	//printArray(auxvalue,row,column);
	return *(auxvalue + (endr-1)*column + (endc-1));
}

int main(){
	int row = 3;
	int column =3;
	int arr[9] = {1,2,3,4,8,2,1,5,3};
	cout<<" Min cost : "<< findMinCostPath(arr,row,column,3,3);
}
