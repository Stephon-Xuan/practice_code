#include<iostream>
#include<string> 
#include<cstdlib>
using namespace std;

struct Node{
	
	int key;
	Node *right,*left,*parent;
};



Node *root,*NIL;

//二叉树搜索树-搜索
Node *find(Node *u,int k){
	while(u!=NIL&&k!=u->key){
		if(k< u->key){
			u = u->left;
		}else{
			u = u->right;
		}
	}
	return u;
} 




//二叉搜索树-插入
void insert(int k){
	
	Node *y = NIL;
	Node *x = root;
	Node *z = new Node();
	
	//z = (Node *)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;
	
	//从根结点往下遍历
	//寻找合适的位置 
	while(x!=NIL){
		y = x;
		 // z比x小， 则从x的左侧遍历
        // z比x大， 则从x的右侧遍历
		if(z->key < x->key){
			x = x->left;
		}else{
			x = x->right;
		}
	}
	//决定z的位置，并放入 
	z->parent = y;
	// 没有父结点的是root
	if(y == NIL){
		root = z;
	}else{
		//z比y小,则在y的左侧
        //z比y大,则在y的右侧
		if(z->key < y->key){
			y->left = z;
		}else{
			y->right = z;
		}
	}
} 

 
//中序遍历
void inParse(Node *u){
	
	if(u==NIL){
		return;
	}
	inParse(u->left); 
	cout <<" "<< u->key;
	inParse(u->right);
}



//前序遍历 
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
		if(com[0]=='f'){
			cin >> key;
			Node *t = find(root,key);
			if(t!=NIL){
				cout <<"yes"<<endl;
			}else{
				cout <<"no"<<endl;
			}
		}
		else if(com == "insert"){
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
