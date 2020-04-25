/*

*/ 
# include <iostream>
using namespace std;

//冒泡排序
int bubbleSort(int A[],int N){
	int i,j;
	bool flag = 1; // 存在顺序相反的相邻元素
	i = 0; //未排序部分的起始下标
	int  swapNum = 0; //交换次数 
	while(flag){
		flag = 0;
		for(j = N-1;j>=i+1;j--){
			if(A[j] < A[j-1]){//若后一个元素比前一个元素小，则交换 
				swap(A[j], A[j- 1]);// 交换相邻元素
				flag =1; 
				swapNum ++; 
			}
			
		}
		i++; 
	}
	
	return swapNum; 
} 
 




int main (){
	
	int N;
	cin >> N;
	int A[N];
	for(int i = 0; i<N;i++){
		cin >> A[i];
	}
	int swapNum = bubbleSort(A,N);
	for(int i = 0; i<N;i++){
		cout << A[i] << " ";
	}
	
	cout << endl << swapNum;
	return 0;
}
