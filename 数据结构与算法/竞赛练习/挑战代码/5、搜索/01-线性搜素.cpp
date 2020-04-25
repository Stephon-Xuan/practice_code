#include <iostream>

using namespace std;


//ÏßÐÔËÑË÷
int linearSearch(int A[],int n,int key){
	int i = 0;
	A[n] = key;
	while(A[i]!=key){
		i++;
	}
	return i!=n;
} 



int main(){
	int i,j,n,q,key,sum=0;
	
	cin >> n;
	
	int A[n];
	
	for(i = 0;i<n;i++){
		
		cin >> A[i];
	}
	
	cin >> q;
	
	for(j = 0;j<q;j++){
		cin >>key;
		if(linearSearch(A,n,key))
		sum++;
	}
	
	cout << sum;
	return 0;
} 
