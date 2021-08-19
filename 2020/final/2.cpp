#include <bits/stdc++.h>
using namespace std;
struct Data{
    int s,e;
    void input(){scanf("%d%d",&s,&e);}
}edge[10010];
struct al{int e,nx;}a[10010],b[10010];
int sta[1010],stb[1010],ta,tb;
void make_al(al *a,int *st,int &t,int s,int e){a[++t]={e,st[s]},st[s]=t;}
int chk[1010],g[1010],st[1010],cnt[1010],t,gn;
void dfs1(int n){
    chk[n]=1;
    for(int i=sta[n];i;i=a[i].nx)if(!chk[a[i].e])dfs1(a[i].e);
    st[++t]=n;
}
void dfs2(int n){
    g[n]=gn,++cnt[gn];
    for(int i=stb[n];i;i=b[i].nx)if(!g[b[i].e])dfs2(b[i].e);
}
int d1[1010][1010],d2[1010][1010],ecnt[1010][1010];
void bfs(al *a,int *st,int n){
    int i,q[1010],f=0,r=1;
    d1[n][n]=d2[n][n]=1,q[1]=n;
    while(f<r){
        int t=q[++f];
        for(i=st[t];i;i=a[i].nx)if(!d1[n][a[i].e])q[++r]=a[i].e,d1[n][a[i].e]=d2[a[i].e][n]=1;
    }
}
void init(){
    memset(chk,0,sizeof chk);
    memset(st,0,sizeof st);
    memset(sta,0,sizeof sta);
    memset(stb,0,sizeof stb);
    memset(d1,0,sizeof d1);
    memset(d2,0,sizeof d2);
    memset(ecnt,0,sizeof ecnt);
    t=ta=tb=0;
}
int main(){
    int tn,tc,i,j,n,m,x,s,e,y,ans;
    scanf("%d",&tc);
    for(tn=1;tn<=tc;++tn){
        scanf("%d%d",&n,&m);
        init();
        for(i=1;i<=m;++i){
            edge[i].input();
            make_al(a,sta,ta,edge[i].s,edge[i].e);
            make_al(b,stb,tb,edge[i].e,edge[i].s);
        }
        gn=0;
        memset(g,0,sizeof g);
        memset(cnt,0,sizeof cnt);
        for(i=1;i<=n;++i)if(!chk[i])dfs1(i);
        for(i=t,t=0;i;--i)if(!g[st[i]])++gn,dfs2(st[i]);
        for(i=1,x=0;i<=n;++i)x=max(x,cnt[i]);
        ans=0;
        init();
        for(i=1;i<=m;++i)if(g[edge[i].s]!=g[edge[i].e]){
            ++ecnt[g[edge[i].s]][g[edge[i].e]];
            make_al(a,sta,ta,g[edge[i].s],g[edge[i].e]);
        }
        for(i=1;i<=gn;++i)bfs(a,sta,i);
        for(i=1;i<=m;++i)if(g[edge[i].s]!=g[edge[i].e]){
            for(j=1,y=0;j<=gn;++j)if(d1[g[edge[i].s]][j]&&d2[g[edge[i].e]][j])y+=cnt[j];
            if(y==cnt[g[edge[i].s]]+cnt[g[edge[i].e]]&&ecnt[g[edge[i].s]][g[edge[i].e]]<2)y=0;
            if(x<y)ans+=y;
        }
        printf("Case #%d\n%d\n",tn,ans);
    }
    return 0;
}