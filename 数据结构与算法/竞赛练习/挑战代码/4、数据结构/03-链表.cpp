#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//双向链表的结点结构体
struct Node{
	
	int key;//值
	Node *prev,*next;//分别指向前一个地址，后一个地址 
}; 

//初始化一个头结点
Node *nil;
void init(){
	nil = (Node *)malloc(sizeof(Node));//动态申请指定大小的空间
	//指向自己，->是指针变量访问成员的运算符，称为箭头运算符。 
	nil->next = nil;
	nil->prev = nil;
} 
//插入链表(头插法)
void insert(int key){
	Node *x = (Node *)malloc(sizeof(Node));
	x->key = key;
	
	x->next = nil->next;
	nil->next->prev = x;
	
	nil->next = x;
	x->prev = nil; 
} 
//搜索结点 
Node *listSearch(int key){
	
	Node *cur = nil->next;//从头结点后面开始访问
	while(cur !=nil &&cur->key!=key){
		cur = cur->next; 
	} 
	return cur;
} 

//删除元素
void deleteNode(Node *t){
	if(t == nil) return;//t作为头结点时不作处理
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);//释放内存 
} 


void deleteFirst(){
	deleteNode(nil->next);//删除头结点的下一个 
}

void deleteLast(){
	deleteNode(nil->prev);//删除头结点的前一个 
} 

void deleteKey(int key){
	
	deleteNode(listSearch(key));//删除搜索到的结点 
} 


//打印结点
void printfList(){
	int flag = 0;
	Node *cur = nil->next; 
	while(cur!=nil){
		if(flag>0){
			cout << " ";
		}
		cout << cur->key;
		flag++;
		cur = cur->next;
	}
	
}

int main(){
	int key,n;
	int size;
	char com[20];
	scanf("%d",&n);
	
	init(); 
	for(int i = 0;i<n;i++){
		scanf("%s%d",com,&key);//使用效率高的输入函数
		if(com[0]=='i'){
			insert(key);
		
			size++; 
			
		}else{
			if(strlen(com) > 6){
				if(com[6]=='F'){
					deleteFirst();
				} 
				else if(com[6]=='L'){
					 deleteLast();
				}
			}else{
				deleteKey(key);
				
			}
			
			size--;
		} 
	}
	printfList();	
	return 0;
} 
