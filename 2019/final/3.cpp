#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
const int MM=5e8+4;
int p[100010],c[100010][2],lev[100010],spt[100010][17],chk[100010];
long long ans,s;
int dfs(int n){
    int i;
    long long tmp=1;
    spt[n][0]=p[n];
    for(i=1;i<17;++i)spt[n][i]=spt[spt[n][i-1]][i-1];
    for(i=0;i<2;++i)if(c[n][i])lev[c[n][i]]=lev[n]+1,tmp=(tmp*dfs(c[n][i]))%M;
    tmp=tmp*2%M;
    if(!c[n][0])tmp=1;
    return tmp;
}
int get_lca(int x,int y){
    int i;
    if(lev[x]>lev[y])swap(x,y);
    for(i=17;i--;)if(lev[x]<=lev[spt[y][i]])y=spt[y][i];
    if(x==y)return x;
    for(i=17;i--;)if(spt[x][i]!=spt[y][i])x=spt[x][i],y=spt[y][i];
    return p[x];
}
int main(){
    int t,tc,i,j,n,m,root,x,y;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        memset(lev,0,sizeof lev);
        memset(chk,0,sizeof chk);
        memset(spt,0,sizeof spt);
        memset(c,0,sizeof c);
        for(i=1;i<=n;++i){
            scanf("%d",p+i);
            if(!p[i]){
                root=i;
                continue;
            }
            if(c[p[i]][0])c[p[i]][1]=i;
            else c[p[i]][0]=i;
        }
        lev[root]=1;
        ans=dfs(root);
        s=ans;
        int flag=1;
        for(i=1;i<=m;++i){
            scanf("%d%d",&x,&y);
            if(!flag)continue;
            int lca=get_lca(x,y);
            if(x==lca){
                for(j=17;j--;)if(lev[spt[y][j]]>lev[lca])y=spt[y][j];
                if(y==c[lca][0]){
                    if(chk[lca]==0)ans=(ans*MM)%M;
                    if(chk[lca]==1){flag=0;continue;}
                    chk[lca]=2;
                }
                else{
                    if(chk[lca]==0)ans=(ans*MM)%M;
                    if(chk[lca]==2){flag=0;continue;}
                    chk[lca]=1;
                }
            }
            else{
                for(j=17;j--;)if(lev[spt[x][j]]>lev[lca])x=spt[x][j];
                if(x==c[lca][0]){
                    if(chk[lca]==0)ans=(ans*MM)%M;
                    if(chk[lca]==2){flag=0;continue;}
                    chk[lca]=1;
                }
                else{
                    if(chk[lca]==0)ans=(ans*MM)%M;
                    if(chk[lca]==1){flag=0;continue;}
                    chk[lca]=2;
                }
            }
            s=(s+ans)%M;
        }
        printf("Case #%d\n%d\n",t,s);
    }
    return 0;
}