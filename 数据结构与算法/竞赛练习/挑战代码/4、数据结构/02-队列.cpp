#include<iostream>
#include<cstdio>
#define LEN 100005//�㹻�Ŀռ� 

using namespace std;


/* ��������Ľṹ��*/
typedef struct pp{
	char name[100];
	int t;
}P;


P Q[LEN];
int head,tail,n;


//����
void enqueue(P x){
	Q[tail] = x;
	tail = (tail + 1) % LEN;
} 

//���� 
P dequeue(){
	P x = Q[head];
	head = (head + 1) % LEN;
	return x;
}

int min(int a, int b) {/*������Сֵ*/
 	return a < b ? a : b; 
 } 


int main(){
	
	
	int n,q;//ʾ������������n���ʾʱ��Ƭ������q(�̶���)
	P u;//�ݴ�ṹ�� 
	
	int elaps = 0, c;//elaps���ۼ�ʱ��Ƭʱ�䣬c��ѡ����Сʱ��Ƭ�������100��ִ�е�ʱ�� 
	
	scanf("%d %d",&n,&q);
	
	/* �� ˳ �� �� �� �� �� �� �� �� �� �� �� */
	for(int i=0;i<n;i++){
		
		scanf("%s", Q[i].name);
		scanf("%d" , &Q[i].t );	
	}
	
	head = 0;tail = n;
	
	/* ģ �� */
	while(head!=tail){//���в�Ϊ�յ�ʱ��,���ϳ������ 
		
		u = dequeue();
		c = min(q,u.t);/* ִ��ʱ��Ƭ q ������ʱ�� u.t �Ĵ��� */
		u.t -=c;/* ����ʣ�������ʱ�� */
		elaps += c; /* �ۼ��Ѿ�����ʱ��*/
		
		if(u.t>0){//��ʣ��ʱ����� 
			enqueue(u); 
		}else{
			printf("%s %d\n",u.name,elaps);
		}			
	}
	return 0;
} 
