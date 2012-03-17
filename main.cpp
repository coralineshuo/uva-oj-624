#include <iostream>
#include <stdio.h>
#include <string.h>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int d[21][10000];
int seq[21];
int N;
int dp(int i,int j)
{
    if(d[i][j]>0) return d[i][j];
    if(i==0||j==0) return 0;
    d[i][j]=dp(i-1,j);
    if(j>=seq[i])
    {
        int temp=dp(i-1,j-seq[i])+seq[i];
        if(temp>d[i][j]) d[i][j]=temp;
    }
    return d[i][j];
}
void print_ans(int i,int j)
{
    if(i==0||j==0) return;
    if(d[i][j]==d[i-1][j])
    {
        print_ans(i-1,j);
    }
    else if(j>=seq[i]&&d[i][j]==d[i-1][j-seq[i]]+seq[i])
    {
        print_ans(i-1,j-seq[i]);
        cout<<seq[i]<<" ";
    }
}
int main()
{

    freopen("out.txt","r",stdin);
    while(cin>>N)
    {
        memset(d,0,sizeof(d));
        memset(seq,0,sizeof(seq));
        int num;
        cin>>num;
        for(int i=1;i<=num;i++) cin>>seq[i];
        dp(num,N);
        print_ans(num,N);
        cout<<"sum:"<<d[num][N]<<endl;
    }
    return 0;
}
