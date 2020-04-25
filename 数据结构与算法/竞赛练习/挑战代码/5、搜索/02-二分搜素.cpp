#include <iostream>

using namespace std;


//ÏßĞÔËÑË÷
int binarySearch(int A[],int n,int key){
	int left = 0; 
	int right = n;
	int mid;
	while(left<right){
		mid = (left+right)/2;
		if(A[mid]==key)
			return 1;
		else if(key<A[mid]){
			right = mid;
		}else{
			left = mid+1;
		}
		
	}
	return 0;
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
		if(binarySearch(A,n,key))
		sum++;
	}
	
	cout << sum;
	return 0;
} 
