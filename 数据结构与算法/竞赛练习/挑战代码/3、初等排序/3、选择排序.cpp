#include <iostream>
using namespace std;

//—°‘Ò≈≈–Ú
int selectionSort(int A[],int N){
	int i,j,minj,swapNum=0;
	for(i = 0; i<N;i++){
		minj = i;
		for(j =i+1;j < N;j++){
			if(A[j]<A[minj]){
				minj = j;
				
			}
		}
		if(i!=minj){
			swap(A[i],A[minj]),swapNum++;
		}
	}
	return swapNum;	
} 



int main(){
	
	int N;
	cin >> N;
	
	int A[N];
	
	for(int i = 0;i < N;i++){
		cin >> A[i];
	}
	
	int swapNum = selectionSort(A,N);
	
	for(int i = 0;i < N;i++){
		if(i){
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << swapNum;
	return 0;
} 
