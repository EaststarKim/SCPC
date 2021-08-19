#include <bits/stdc++.h>
using namespace std;
long long a[1810][1810],b[1810][1810];
long long f(int r,int c){
    if(c<1)r+=c-1,c=1;
    return r<1?0:a[r][c];
}
long long g(int r,int c){
    if(r<1||c<1)return 0;
    return b[r][c];
}
int main(){
    int t,tc,i,j,n,m,k;
    long long ans,s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&k);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(i=1;i<=n;++i){
            for(j=1;j<=n;++j)scanf("%lld",a[i]+j);
        }
        m=n+k*2-2;
        for(i=1;i<=m;++i){
            for(j=1;j<=m;++j)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1],b[i][j]=a[i][j];
        }
        for(i=1;i<=m;++i){
            for(j=1;j<m;++j)a[i][j]+=a[i-1][j+1];
            for(j=2;j<=m;++j)b[i][j]+=b[i-1][j-1];
        }
        ans=0;
        for(i=1-k;i<n+k;++i){
            for(j=1-k;j<n+k;++j){
                s=(f(i-1,j-k)-f(i-k-1,j))+(f(i+k-1,j)-f(i-1,j+k));
                s-=(g(i-1,j+k-1)-g(i-k-1,j-1))+(g(i+k-1,j-1)-g(i-1,j-k-1));
                ans=max(ans,s);
            }
        }
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}