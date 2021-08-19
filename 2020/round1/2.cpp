#include <bits/stdc++.h>
using namespace std;
int a[3010],b[3010],D[3010][3010];
int main(){
    int t,i,j,k,l,tc,n,m,s,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)scanf("%d",a+i),a[i]+=a[i-1];
        for(i=1;i<=n;++i)scanf("%d",b+i),b[i]+=b[i-1];
        ans=0;
        for(i=0;i<=n;++i){
            for(l=0;a[i]-a[l]>m;++l);
            for(j=k=s=0;j<=n;++j){
                for(;b[j]-b[k]>m;++k)s-=D[i][k];
                D[i][j]=!((i?D[i-1][j]-(l?D[l-1][j]:0):0)|(j?s:0));
                if(!i&&!j)D[0][0]=0;
                ans+=D[i][j],s+=D[i][j];
            }
            if(i)for(j=0;j<=n;++j)D[i][j]+=D[i-1][j];
        }
        printf("Case #%d\n%d %d\n",t,(n+1)*(n+1)-ans,ans);
    }
    return 0;
}