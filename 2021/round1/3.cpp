#include <bits/stdc++.h>
using namespace std;
struct Edge{int s,e;}u[2010];
struct al{int e,nx;}a[4010];
int st[510],cnt;
void make_al(int s,int e){a[++cnt]={e,st[s]},st[s]=cnt;}
int chk[510];
int cycle(int n){
    int i;
    if(chk[n])return chk[n]>0;
    chk[n]=1;
    for(i=st[n];i;i=a[i].nx)if(cycle(a[i].e))return 1;
    chk[n]=-1;
    return 0;
}
int main(){
    int t,tc,i,j,n,m,k,x,y;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        printf("Case #%d\n",t);
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;++i)st[i]=0;
        cnt=0;
        for(i=1;i<=m;++i){
            scanf("%d%d",&x,&y);
            make_al(x,y);
        }
        for(i=1;i<=k;++i){
            scanf("%d%d",&x,&y);
            make_al(x,y);
            for(j=1;j<=n;++j)chk[j]=0;
            for(j=1;j<=n;++j)if(!chk[j]&&cycle(j))break;
            if(j>n)printf("0");
            else{
                printf("1");
                st[x]=a[cnt--].nx;
                make_al(y,x);
            }
        }
        puts("");
    }
    return 0;
}