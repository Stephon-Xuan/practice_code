/*

*/ 
# include <iostream>
using namespace std;

//ð������
int bubbleSort(int A[],int N){
	int i,j;
	bool flag = 1; // ����˳���෴������Ԫ��
	i = 0; //δ���򲿷ֵ���ʼ�±�
	int  swapNum = 0; //�������� 
	while(flag){
		flag = 0;
		for(j = N-1;j>=i+1;j--){
			if(A[j] < A[j-1]){//����һ��Ԫ�ر�ǰһ��Ԫ��С���򽻻� 
				swap(A[j], A[j- 1]);// ��������Ԫ��
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
