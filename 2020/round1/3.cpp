#include <bits/stdc++.h>
using namespace std;
int x[2010],y[2010],D[1510][1510];
int main(){
    int t,i,j,tc,n,m,q,a,b,s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)D[i][j]=1e9;
            D[i][i]=0;
        }
        for(i=1;i<=m;++i){
            for(j=1;j<=n;++j){
                int tmp=min(D[x[i]][j]+1,D[y[i]][j]);
                D[y[i]][j]=min(D[y[i]][j]+1,D[x[i]][j]);
                D[x[i]][j]=tmp;
            }
        }
        for(s=0;q--;){
            scanf("%d%d",&a,&b);
            s+=D[b][a]<1e9?D[b][a]:-1;
        }
        printf("Case #%d\n%d\n",t,s);
    }
    return 0;
}