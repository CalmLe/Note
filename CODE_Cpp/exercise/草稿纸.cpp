#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 1010
int n,m,c,p[maxn][maxn],s[maxn][maxn],maxx=-0x7fffffff,xx,yy;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>c;
    for(int i=1;i<=n;++i)
     for(int j=1;j<=m;++j)
      {
          cin>>p[i][j];
          s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+p[i][j];
      }
    
    for(int i=c;i<=n;++i)
     for(int j=c;j<=m;++j)
      {
          if(s[i][j]-s[i-c][j]-s[i][j-c]+s[i-c][j-c]>maxx)
           {
               maxx=s[i][j]+s[i-c][j-c]-s[i-c][j]-s[i][j-c];
               xx=i-c+1;yy=j-c+1;
           }
      }
    printf("%d %d",xx,yy);
    return 0;
}
