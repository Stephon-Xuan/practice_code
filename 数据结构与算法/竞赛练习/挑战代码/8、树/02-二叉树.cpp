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




//��������� 
void getDepth(int u,int depth){
	if(u ==NIL )return;//û���κν���ʱ�� 
	Depth[u] = depth;//������������� 
	
	if(Tree[u].right != NIL){//�ӽ������ֵܻ��У�����ͬ����� 
		getDepth(Tree[u].right,depth);
	}
	if(Tree[u].left != NIL){//���ӽ�㣬���+1 
		getDepth(Tree[u].left,depth+1);
	}
	
} 

//�����ĸ߶� 
int getHeight(int u){
	int h1 = 0,h2 = 0;
	if(Tree[u].left != NIL){
		h1 = getHeight(Tree[u].left)+1;//�������������� 
	}
		
	if(Tree[u].right != NIL){
		h2 = getHeight(Tree[u].right)+1;//�������ҽ������ 
	}
	return Height[u] = (h1>h2 ? h1:h2);
} 

//���ؽ����ֵܽ��
int getSibling(int u){
	if(Tree[u].parent == NIL){//����Ǹ� 
		return NIL;
	} 
		
	if(Tree[Tree[u].parent].left != u&&Tree[Tree[u].parent].left != NIL){//�ҽ��������ֵ�
		return Tree[Tree[u].parent].left;
	}
	if(Tree[Tree[u].parent].right != u&&Tree[Tree[u].parent].right != NIL){//����������ֵ�
		return Tree[Tree[u].parent].right;
	} 
	return NIL;
} 

//��ӡ
//��ӡ��node id: parent =p,sibling =s,degree = deg, depth = dep, height = h, type
//����p ��ʾ�����ı�ţ�����㲻����ʱ���� - 1��s ��ʾ�ֵܽ��ı�ţ��ֵܽ�㲻����ʱ���� -1��
//deg��dep��h�ֱ��ʾ�ӽ��������� ���ߡ�type ��ʾ�������ͣ��� root ( �� ����internal node ( �ڲ���� ����leaf ( Ҷ �������ַ�����ѡ����һ��
void print(int u){
	
	printf("node %d: ",u);
	printf("parent = %d: ",Tree[u].parent);
	printf("sibling = %d: ",getSibling(u));
	
	int deg = 0;
	if(Tree[u].left!=NIL){//�������У��ȼ�һ 
		deg++; 
	}
	
	if(Tree[u].right!=NIL){//���ҽ���У��ȼ�һ 
		deg++;
	}
	
	printf("degree %d: ",deg);
	printf("depth = %d: ",Depth[u]);
	printf("height = %d: ",Height[u]);
	
	if(Tree[u].parent == NIL){//�� 
		printf("root\n");
	}else if(Tree[u].left == NIL && Tree[u].right ==NIL){//Ҷ�ӽ�� 
		printf("leaf\n");
	}else{
		printf("internal node\n");//�ڲ���� 
	}
} 

int main(){
	int n,id,left,right,root=0;
	cin >> n;
	for(int i = 0;i<n;i++){//��ʼ�����н�� 
		Tree[i].parent = NIL;
	}
	
	for(int i = 0;i<n;i++){
		
		cin >> id >> left >> right;
		//��������ӽ�� 
		Tree[id].left = left;
		Tree[id].right = right;
		
		//�ӽ�������ڵ� 
		if(left!=NIL){
			Tree[left].parent = id;
		}
		if(right!=NIL){
			Tree[right].parent = id;
		}
	}
	
	//�ҵ����ڵ� 
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
