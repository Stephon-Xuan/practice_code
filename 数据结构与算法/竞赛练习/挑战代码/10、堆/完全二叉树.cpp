#include<iostream>

using namespace std;


//分别求出结点i的父结点，左子结点、右子结点
int parent(int i){
	return i/2;
}

int left(int i){
	return i*2; 
}

int right(int i){
	return 2*i+1;
}



int main(){
	
	int n;
	cin >> n;
	int A[n+1];//数组为1起点,所以要加1
	
	//输入 
	for(int i = 1;i<=n;i++){
		cin >> A[i];
	} 
	//输出
	for(int i = 1;i<=n;i++){
		
		cout << "node" << i << ": key = " << A[i] <<", ";
		
		if(parent(i)>=1){
			cout <<"parent key = "<<A[parent(i)] << ", ";
		}
		if(left(i)<=n){
			
			cout <<"left key = "<<A[left(i)]<<", ";
		}
		if(right(i)<=n){
			cout <<"right key = "<<A[right(i)]<<", ";
		
		}
		cout << endl;	
	} 
	return 0;
} 
