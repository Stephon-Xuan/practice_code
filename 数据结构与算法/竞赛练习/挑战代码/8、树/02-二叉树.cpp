#include<iostream>
using namespace std;
#include<cstdio>


#define MAX 10000
#define NIL -1


struct Node{
	int parent,left,right;
};
Node Tree[MAX];
int Depth[MAX],Height[MAX];




//各结点的深度 
void getDepth(int u,int depth){
	if(u ==NIL )return;//没有任何结点的时候 
	Depth[u] = depth;//保存各个结点深度 
	
	if(Tree[u].right != NIL){//子结点的右兄弟还有，设置同等深度 
		getDepth(Tree[u].right,depth);
	}
	if(Tree[u].left != NIL){//有子结点，深度+1 
		getDepth(Tree[u].left,depth+1);
	}
	
} 

//各结点的高度 
int getHeight(int u){
	int h1 = 0,h2 = 0;
	if(Tree[u].left != NIL){
		h1 = getHeight(Tree[u].left)+1;//可能有左结点的情况 
	}
		
	if(Tree[u].right != NIL){
		h2 = getHeight(Tree[u].right)+1;//可能有右结点的情况 
	}
	return Height[u] = (h1>h2 ? h1:h2);
} 

//返回结点的兄弟结点
int getSibling(int u){
	if(Tree[u].parent == NIL){//如果是根 
		return NIL;
	} 
		
	if(Tree[Tree[u].parent].left != u&&Tree[Tree[u].parent].left != NIL){//右结点存在左兄弟
		return Tree[Tree[u].parent].left;
	}
	if(Tree[Tree[u].parent].right != u&&Tree[Tree[u].parent].right != NIL){//左结点存在右兄弟
		return Tree[Tree[u].parent].right;
	} 
	return NIL;
} 

//打印
//打印：node id: parent =p,sibling =s,degree = deg, depth = dep, height = h, type
//其中p 表示父结点的编号，父结点不存在时记作 - 1。s 表示兄弟结点的编号，兄弟结点不存在时记作 -1。
//deg、dep、h分别表示子结点数、深度 、高。type 表示结点的类型，从 root ( 根 ）、internal node ( 内部结点 ）、leaf ( 叶 ）三个字符串中选择其一。
void print(int u){
	
	printf("node %d: ",u);
	printf("parent = %d: ",Tree[u].parent);
	printf("sibling = %d: ",getSibling(u));
	
	int deg = 0;
	if(Tree[u].left!=NIL){//若左结点有，度加一 
		deg++; 
	}
	
	if(Tree[u].right!=NIL){//若右结点有，度加一 
		deg++;
	}
	
	printf("degree %d: ",deg);
	printf("depth = %d: ",Depth[u]);
	printf("height = %d: ",Height[u]);
	
	if(Tree[u].parent == NIL){//根 
		printf("root\n");
	}else if(Tree[u].left == NIL && Tree[u].right ==NIL){//叶子结点 
		printf("leaf\n");
	}else{
		printf("internal node\n");//内部结点 
	}
} 

int main(){
	int n,id,left,right,root=0;
	cin >> n;
	for(int i = 0;i<n;i++){//初始化所有结点 
		Tree[i].parent = NIL;
	}
	
	for(int i = 0;i<n;i++){
		
		cin >> id >> left >> right;
		//父结点连子结点 
		Tree[id].left = left;
		Tree[id].right = right;
		
		//子结点连父节点 
		if(left!=NIL){
			Tree[left].parent = id;
		}
		if(right!=NIL){
			Tree[right].parent = id;
		}
	}
	
	//找到根节点 
	for(int i = 0;i<n;i++){
		if(Tree[i].parent == NIL){
			root = i;
		}
	} 
	
	getDepth(root,0);
	getHeight(root);
	
	for(int i = 0;i<n;i++){
		print(i);
	} 
	return 0;
} 
