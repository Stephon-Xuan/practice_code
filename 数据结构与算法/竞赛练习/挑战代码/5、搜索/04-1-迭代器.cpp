#include <iostream>
#include <vector>

using namespace std;


void print(vector<int> v){
	//��������ͷ˳�η���
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
	
	print(v);//��ӡ 
	
	
	vector<int>::iterator it = v.begin();
	*it = 3;//��3��ֵ����ͷԪ��v[0]
	it++;//ǰ��һ��λ��
	(*it)++;//v[1]��Ԫ�ؼ�1
	
	print(v); 
	return 0;
} 
