#include <bits/stdc++.h>
using namespace std;
struct D{
    int x,idx;
    bool operator<(const D&r)const{return x<r.x;}
}p[310];
int a[10010],b[310],c[310],tmp[310];
int main(){
    int t,i,j,tc,n,m,k,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&n,&m,&k);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        for(i=1;i<=m;++i)scanf("%d",&p[i].x),p[i].idx=i;
        sort(p+1,p+m+1);
        for(i=1;i<=m;++i)c[p[i].idx]=i;
        ans=0;
        for(i=1;i<=n-m+1;++i){
            for(j=1;j<=m;++j)b[c[j]]=a[i+j-1];
            fill(tmp+1,tmp+m+1,1e9);
            for(j=1;j<=m;++j)*upper_bound(tmp+1,tmp+m+1,b[j])=b[j];
            ans+=(lower_bound(tmp+1,tmp+m+1,1e9)-tmp>m-k);
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}