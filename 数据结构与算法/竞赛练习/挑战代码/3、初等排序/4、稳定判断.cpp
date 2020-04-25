#include <iostream>
using namespace std;

struct Card{
	char suit,value;
};

//冒泡排序 
void bubbleSort(struct Card A[],int N){
	int i,j;
	bool flag = 1;
	for(i = 0;flag;i++){
		flag = 0;
		for(j = N-1;j>=i+1;j--){	
			if(A[j].value < A[j-1].value){	
				swap(A[j],A[j-1]);
				flag = 1;
			}
		}
	}
} 


//选择排序
void selectionSort(struct Card A[],int N){
	int i,j,minj;
	
	for(i = 0;i<N;i++){
		
		minj = i;
		
		for(j=N-1;j>i;j--){
			
			if(A[minj].value > A[j].value){	
				minj = j;
			} 
		}
		
		if(i!=minj){
			swap(A[i],A[minj]);
		}	
	}
	
	
	
	
	
	
	
	
	
	
		
} 



//是否稳定
bool isStable(struct Card Cl[], struct Card C2[], int N){//in是原数组，out是输出的数组 
	
	for(int i = 0;i<N;i++){
		if( Cl[i].suit != C2[i].suit) 
		{
			return false;
		}
	}
	return true; 
	
} 

//打印
void print(struct Card A[],int N){
	for(int i = 0;i < N;i++){
		if(i){
			cout << " ";
		}
		cout << A[i].suit << A[i].value;
	}
	
	cout << endl; 
	
} 



int main(){
	
	int N;
	cin >> N;
	
	Card C1[N],C2[N];
	
	for(int i = 0;i < N;i++){
		cin >> C1[i].suit >> C1[i].value;
		C2[i] = C1[i];
	}
	
	bubbleSort(C1,N);
	selectionSort(C2,N);
	
	
	print(C1,N);
	cout << "Stable" << endl;
	
	print(C2,N);
	if ( isStable(C1,C2,N) ) {
		cout << "Stable" << endl;
	}else{
		cout << "Not stable" <<endl; 
	}	
	return 0;
} 
