#include<iostream>
#include<string> 
#include<cstdlib>
using namespace std;

struct Node{
	
	int key;
	Node *right,*left,*parent;
};



Node *root,*NIL;

//����������-����
void insert(int k){
	Node *y = NIL;
	Node *x = root;
	Node *z = new Node();
	//z = (Node *)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;
	//�Ӹ�������±���
	//Ѱ�Һ��ʵ�λ�� 
	while(x!=NIL){
		y = x;
		 // z��xС�� ���x��������
        // z��x�� ���x���Ҳ����
		if(z->key < x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	//����z��λ�ã������� 
	z->parent = y;
	// û�и�������root
	if(y == NIL){
		root = z;
	}else{
		//z��yС,����y�����
        //z��y��,����y���Ҳ�
		if(z->key < y->key){
			y->left = z;
		}else{
			y->right = z;
		}
	}
} 
 
//�������
void inParse(Node *u){
	
	if(u==NIL){
		return;
	}
	inParse(u->left); 
	cout <<" "<< u->key;
	inParse(u->right);
}



//ǰ����� 
void preParse(Node *u){
	if(u==NIL){
		return;
	}
	cout <<" "<< u->key;
	preParse(u->left); 
	preParse(u->right);
}


int main(){
	
	int n,key;
	string com;
	
	cin >> n;
	
	for(int i = 0;i<n;i++){
		cin >> com;
		if(com == "insert"){
			cin >> key;
			insert(key);
		}else if(com == "print"){
			inParse(root);
			cout << endl;
			preParse(root);
			cout << endl; 
		}	
	} 
	return 0;
} 
