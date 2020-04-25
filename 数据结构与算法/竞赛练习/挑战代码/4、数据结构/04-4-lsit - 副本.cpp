#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack<int> S;
	
	S.push(3);//压栈 
	S.push(7);
	S.push(1);
	
	cout<<"栈的长度:"<< S.size()<<" "<<endl;//栈的大小 
	 
	S.pop();//栈顶元素出栈 
	
	
	cout<< "出一次栈，栈顶元素为："<<S.top()<<endl;//栈顶元素
	cout<<"栈的长度:"<< S.size()<<" "<<endl;//栈的大小 
	
	return 0;
} 
