#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> S;
	
	S.push(3);//ѹջ 
	S.push(7);
	S.push(1);
	
	cout<<"ջ�ĳ���:"<< S.size()<<" "<<endl;//ջ�Ĵ�С 
	 
	S.pop();//ջ��Ԫ�س�ջ 
	
	
	cout<< "��һ��ջ��ջ��Ԫ��Ϊ��"<<S.top()<<endl;//ջ��Ԫ��
	cout<<"ջ�ĳ���:"<< S.size()<<" "<<endl;//ջ�Ĵ�С 
	
	return 0;
} 
