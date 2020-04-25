#include<iostream>


using namespace std;
#define MAX 10000
#define NIL -1 

struct Node{
	int parent,left,right;
};

struct Node Tree[MAX];

//前序遍历
void preParse(int u){
	if(u== NIL) return;
	cout <<" "<<u;
	preParse(Tree[u].left);
	preParse(Tree[u].right);
} 
//中序遍历
void inParse(int u){
	if(u== NIL) return;
	
	inParse(Tree[u].left);
	cout <<" "<<u;
	inParse(Tree[u].right);
	
}
//后序遍历 
void postParse(int u){
	if(u== NIL) return;
	 postParse(Tree[u].left);
	postParse(Tree[u].right);
	cout <<" "<<u;
}




int main(){
	int n,id,parent,left,right,root;
	
	cin >> n;
	for(int i = 0;i<n;i++){//所有结点没有父结点,没有连成树 
		Tree[i].parent = NIL;
	}
	
	//生成二叉树 
	for(int i = 0;i<n;i++){
		
		cin >> id >> left >> right;
		
		Tree[id].left = left;
		Tree[id].right = right;
		
		if(Tree[id].left!= NIL){
			Tree[left].parent = id;
		}
		if(Tree[id].right!= NIL){
			Tree[right].parent = id;
		}
	}
	//找到根结点
	for(int i= 0;i<n;i++){
		
		if(Tree[i].parent == NIL){
			root = i;
		}
	}
	
	//排序结果 
	cout <<"Preorder"<<endl;
	preParse(root); 
	cout << endl;
	 
	cout <<"Inorder"<<endl;
	inParse(root); 
	cout << endl;
	
	cout <<"Postorder"<<endl;
	postParse(root); 
	cout << endl;	
	return 0;
} 
