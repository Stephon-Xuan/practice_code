#include<iostream>

using namespace std;

const int MAX = 100005;
const int NIL = -1;

struct Node{
	int parent,left,right; //right为右兄弟 
};


Node Tree[MAX];//树 
int Depth[MAX]; //深度 


//递归地求深度
int rec(int u,int parent){
	Depth[u] = parent;
	if(Tree[u].right != NIL){
		rec(Tree[u].right,parent);//右侧兄弟设置为相同深度
	}
	if(Tree[u].left != NIL){
		rec(Tree[u].left,parent+1);//最左侧子结点的深度设置为自己的深度 + 1
	}
}

//打印
void print(int u){
	int i,c;
	
	cout << "node" << u << ":";// 结点编号 
	cout << "parent = " << Tree[u].parent << ":";//父结点编号 
	cout << "depth = " << u << ":";
	
	if(Tree[u].parent == NIL){
		cout << "root, ";//根 
	}else if(Tree[u].left == NIL){
		cout << "leaf, ";//叶子 
	}else{
		cout << "internal node, ";//内部结点 
	}
	
	cout << "[";
	// 从子结点的最左边开始遍历
	for(i = 0,c = Tree[u].left;c!=NIL;i++,c = Tree[c].right){// 跳到子结点右侧紧邻的兄弟结点
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
	//全部结点初始化未NIL 
	for(int i = 0;i<n;i++){
		Tree[i].parent = Tree[i].left = Tree[i].right = NIL; 
	}
	
	for(int i = 0;i<n;i++){
		cin >> id >> k;//输入结点编号id、度k 
		for(int j = 0;j <k;j++){
			cin >> c;
			//设置最左侧结点 和 紧邻右侧兄弟结点
            // pre记录的是上一个结点，将当前的结点设置为pre的紧邻右侧结点
			if(j==0){
				Tree[id].left = c;
			}else{
				Tree[pre].right = c;//子结点的右兄弟 
			}
			pre = c;
			Tree[c].parent = id;
		}
	}
	//找出根节点 
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
