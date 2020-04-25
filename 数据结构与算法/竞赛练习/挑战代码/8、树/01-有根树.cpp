#include<iostream>

using namespace std;

const int MAX = 100005;
const int NIL = -1;

struct Node{
	int parent,left,right; //rightΪ���ֵ� 
};


Node Tree[MAX];//�� 
int Depth[MAX]; //��� 


//�ݹ�������
int rec(int u,int parent){
	Depth[u] = parent;
	if(Tree[u].right != NIL){
		rec(Tree[u].right,parent);//�Ҳ��ֵ�����Ϊ��ͬ���
	}
	if(Tree[u].left != NIL){
		rec(Tree[u].left,parent+1);//������ӽ����������Ϊ�Լ������ + 1
	}
}

//��ӡ
void print(int u){
	int i,c;
	
	cout << "node" << u << ":";// ����� 
	cout << "parent = " << Tree[u].parent << ":";//������� 
	cout << "depth = " << u << ":";
	
	if(Tree[u].parent == NIL){
		cout << "root, ";//�� 
	}else if(Tree[u].left == NIL){
		cout << "leaf, ";//Ҷ�� 
	}else{
		cout << "internal node, ";//�ڲ���� 
	}
	
	cout << "[";
	// ���ӽ�������߿�ʼ����
	for(i = 0,c = Tree[u].left;c!=NIL;i++,c = Tree[c].right){// �����ӽ���Ҳ���ڵ��ֵܽ��
		if(i){
			cout <<", "; 
		} 
		cout << c;
	}
	cout << "]"<<endl;
} 

int main(){
	
	int n,id,k,c,pre,root;
	cin >> n;
	//ȫ������ʼ��δNIL 
	for(int i = 0;i<n;i++){
		Tree[i].parent = Tree[i].left = Tree[i].right = NIL; 
	}
	
	for(int i = 0;i<n;i++){
		cin >> id >> k;//��������id����k 
		for(int j = 0;j <k;j++){
			cin >> c;
			//����������� �� �����Ҳ��ֵܽ��
            // pre��¼������һ����㣬����ǰ�Ľ������Ϊpre�Ľ����Ҳ���
			if(j==0){
				Tree[id].left = c;
			}else{
				Tree[pre].right = c;//�ӽ������ֵ� 
			}
			pre = c;
			Tree[c].parent = id;
		}
	}
	//�ҳ����ڵ� 
	for(int i = 0;i < n;i++){
		if(Tree[i].parent == NIL){
			root = i;
		} 
	}
	
	rec(root,0);
	
	for(int i = 0; i < n;i++ ){
		print(i);
	}
	
	
	return 0;
} 
