#include<stdio.h>
#include<math.h> 
int main(){
	//#define PI 3.14159265358979323
	//#define PI atan(1.0)*4 
	int a;
	double b,PI;
	PI = atan(1.0)*4;
	scanf("%d",&a);
	b = PI*a*a;
	printf("%0.7f",b);
	return 0;
}

//�����ȸ�������Ч����8λ��˫���ȸ�������Ч����16λ,float�ڼ����л��Զ�ת����double����
//����ʹ�ó�������ʾ�У�����PI=3.14159265358979323��Ҳ����ʹ����ѧ��ʽ����У�����PI=atan(1.0)*4��
