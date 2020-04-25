#include<iostream>
#include<cstdio>
#define LEN 100005//足够的空间 

using namespace std;


/* 代表任务的结构题*/
typedef struct pp{
	char name[100];
	int t;
}P;


P Q[LEN];
int head,tail,n;


//进队
void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
} 

//出队 
P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int min(int a, int b) {/*返回最小值*/
 	return a < b ? a : b; 
 } 


int main(){
	
	
	int n,q;//示任务数的整数n与表示时间片的整数q(固定的)
	P u;//暂存结构体 
	
	int elaps = 0, c;//elaps是累计时间片时间，c是选择最小时间片（最大是100）执行的时间 
	
	scanf("%d %d",&n,&q);
	
	/* 按 顺 序 将 所 有 任 务 添 加 至 队 列 */
	for(int i=0;i<n;i++){
		
		scanf("%s", Q[i].name);
		scanf("%d" , &Q[i].t );	
	}
	
	head = 0;tail = n;
	
	/* 模 拟 */
	while(head!=tail){//队列不为空的时候,不断出队入队 
		
		u = dequeue();
		c = min(q,u.t);/* 执行时间片 q 或所需时间 u.t 的处理 */
		u.t -=c;/* 计算剩余的所需时间 */
		elaps += c; /* 累计已经过的时间*/
		
		if(u.t>0){//将剩余时间入队 
			enqueue(u); 
		}else{
			printf("%s %d\n",u.name,elaps);
		}			
	}
	return 0;
} 
