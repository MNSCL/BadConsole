#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50;
int n;
int top;
int v[maxn];
char s[maxn], c[maxn];
void Push(int x, int flag)
{
    if(! flag) c[++top]=x;
    else v[top]=x;
}
int Pow(int x, int n)
{
    
    int sum=1;
    for(int i=1; i<=n;i++) sum*=x;
    return sum;
}
void Pop()
{
    if(c[top]=='+') v[top-1]+=v[top];
    if(c[top]=='-') v[top-1]-=v[top];
    if(c[top]=='*') v[top-1]*=v[top];
    if(c[top]=='/') v[top-1]/=v[top];
    if(c[top]=='^') v[top-1]=Pow(v[top-1],v[top]);
    
    --top;
}
int Opr(char x)
{
    if(x=='+'|| x=='-') return 0;
    if(x=='*'|| x=='/') return 1;
    if(x=='^') return 2;
    
    return-1;
}
bool Cheek(char x)
{
    if(Opr(x)<=Opr(c[top])) return true;
    return false;
}
int main()
{
    scanf("%s",s);
    n=strlen(s);
    s[n]=')';
    Push('(',0);
    for(int i=0;i<=n;i++)
    {
        while(s[i]=='(') Push(s[i++],0);
        int x=0;
        while(isdigit(s[i]))
        x=x*10+s[i++]-'0';
        Push(x,1);
        while(true)
        {
            if(s[i]==')')
            {
                while(c[top]!='(') Pop();
                v[top-1]=v[top--];
            }
            else
            {
                while(Cheek(s[i])) Pop();
                Push(s[i],0);
                break;
            }
            i++;
            if(i>n) break;
        }
    }
    printf("%d\n",v[0]);
    return 0;
}

