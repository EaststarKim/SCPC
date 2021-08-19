#include <bits/stdc++.h>
using namespace std;
int g[100010],rnk[100010],sz[100010];
int seek(int n){return g[n]==n?n:g[n]=seek(g[n]);}
void uf(int a,int b){
    a=seek(a),b=seek(b);
    if(a==b)return;
    if(rnk[a]<rnk[b])g[a]=b,sz[b]+=sz[a];
    else{
        if(rnk[a]==rnk[b])++rnk[a];
        g[b]=a,sz[a]+=sz[b];
    }
}
int main(){
    int t,tc,i,n,k,cnt;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)g[i]=i,rnk[i]=0,sz[i]=1;
        for(i=1;i<=n;++i){
            scanf("%d",&k);
            if(i+k>n)continue;
            uf(i,i+k);
        }
        for(i=1,cnt=0;i<=n;++i)cnt+=(seek(i)==i);
        printf("Case #%d\n%d\n",t,cnt);
    }
    return 0;
}