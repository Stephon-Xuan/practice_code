#include <iostream>
#include <vector>

using namespace std;


void print(vector<int> v){
	//从向量开头顺次访问
	vector<int>::iterator it;
	for(it = v.begin();it!=v.end();it++){
		cout << *it;
	} 
	cout << endl;
} 


int mian(){
	int N = 4;
	vector<int> v;
	
	for(int i = 0;i< N;i++){
		int x;
		cin >> x;
		v.push_back(x);
		
	}
	
	print(v);//打印 
	
	
	vector<int>::iterator it = v.begin();
	*it = 3;//将3赋值给开头元素v[0]
	it++;//前移一个位置
	(*it)++;//v[1]的元素加1
	
	print(v); 
	return 0;
} 
