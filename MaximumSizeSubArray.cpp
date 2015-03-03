#include<iostream>

using namespace std;


int min(int x, int y, int z){
	int min = 999999;
	if(x<min)
		min =x;
	if(min < y)
		min =y;
	if(min < z)
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

int findMaximumSizeSubArray(int *inputmat,int row, int column){

	int size = row * column;
	int *auxArray = new int(size);
	for(int i = 0 ; i<size ; i++ )
		*(auxArray + i) =0;

	for(int i=0;i<column;i++)
		*(auxArray + 0*column + i) = *(inputmat + 0*row + i);

	for( int i=0 ; i<row ; i++)
		*(auxArray + i*column + 0) = *(inputmat + i*row + 0);

	for(int i=1;i<row;i++){
		for(int j=1 ; j< column ; j++){
			if(*(inputmat + i*column + j) == 1){
				*(auxArray + i*column + j) = min( *(inputmat + (i-1)*column + j) , *(inputmat + (i-1)*column + (j -1)) ,*(inputmat + i*column + (j -1))) + 1;
			}else{
				*(auxArray + i*row + j) = 0;
			}
		}
	}
	printArray(auxArray,row,column);
}




int main(){
	int row = 6;
	int column = 5;
 	int arr[30] = { 0,1,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0};
 	findMaximumSizeSubArray(arr,row,column);
}
