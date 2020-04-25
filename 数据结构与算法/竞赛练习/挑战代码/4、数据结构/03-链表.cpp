#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//˫������Ľ��ṹ��
struct Node{
	
	int key;//ֵ
	Node *prev,*next;//�ֱ�ָ��ǰһ����ַ����һ����ַ 
}; 

//��ʼ��һ��ͷ���
Node *nil;
void init(){
	nil = (Node *)malloc(sizeof(Node));//��̬����ָ����С�Ŀռ�
	//ָ���Լ���->��ָ��������ʳ�Ա�����������Ϊ��ͷ������� 
	nil->next = nil;
	nil->prev = nil;
} 
//��������(ͷ�巨)
void insert(int key){
	Node *x = (Node *)malloc(sizeof(Node));
	x->key = key;
	
	x->next = nil->next;
	nil->next->prev = x;
	
	nil->next = x;
	x->prev = nil; 
} 
//������� 
Node *listSearch(int key){
	
	Node *cur = nil->next;//��ͷ�����濪ʼ����
	while(cur !=nil &&cur->key!=key){
		cur = cur->next; 
	} 
	return cur;
} 

//ɾ��Ԫ��
void deleteNode(Node *t){
	if(t == nil) return;//t��Ϊͷ���ʱ��������
	t->prev->next = t->next;
	t->next->prev = t->prev;
	free(t);//�ͷ��ڴ� 
} 


void deleteFirst(){
	deleteNode(nil->next);//ɾ��ͷ������һ�� 
}

void deleteLast(){
	deleteNode(nil->prev);//ɾ��ͷ����ǰһ�� 
} 

void deleteKey(int key){
	
	deleteNode(listSearch(key));//ɾ���������Ľ�� 
} 


//��ӡ���
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
		scanf("%s%d",com,&key);//ʹ��Ч�ʸߵ����뺯��
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
