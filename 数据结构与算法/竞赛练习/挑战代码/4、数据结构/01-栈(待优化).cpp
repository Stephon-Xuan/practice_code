/*ʵ��ջ�Ĺ���*/
#include<iostream>
#include<cstdio>
#include<cstdlib> 
using namespace std;

// ʵ��ջ�Ĺ���

// top��ָ��ջ����ָ�룬 s��ʵ��ջ�ṹ������
int top, S[1000];

// ��xѹ��ջ�Ĳ���
void push(int x) {
    // top��1֮��Ԫ�ز��뵽top��ָ��λ��
    S[++top] = x;
}

// ��ջ��Ԫ�ط��ز�ɾ��
int pop() {
    top--;
    return S[top + 1];
}

// �ַ�ת����
int CharToInt(char s[]) {
    int ans = 0, i = 0;
    while (s[i] != '\0') {
        ans = ans * 10 + s[i] - '0';
        i++;
    }
    return ans;
}
int main() {
    char s[1000];
    int a, b;
    // ���ջ
    top = 0; 
    while(scanf("%s",s)!=EOF){//�س���һ��crtl z���� 
            if (s[0] == '+') {
                b = pop();a = pop();
                push(a + b);
            }else if (s[0] == '-') {
                b = pop(); a = pop();
                push(a - b);
            }else if (s[0] == '*') {
                b = pop(); a = pop();
                push(a * b);
            }else {
                push(CharToInt(s));
               //push(atoi(s));//���ñ�׼����ַ���ת���� 
            }
    }
    printf("%d\n",pop());

    return 0;
}
