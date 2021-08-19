#include <bits/stdc++.h>
using namespace std;
struct data{
    long long x,y;
}a[200010],b[200010];
int main(){
    int t,i,j,tc,L,n,k;
    long long x,y;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&L,&n,&k);
        L*=2;
        for(i=0;i<=n;++i)scanf("%lld%lld",&x,&y),a[i]={x*2,y*2};
        if(a[0].x>a[1].x)reverse(a,a+n+1);
        int p,cnt;
        long long e,l=0,r=2e12,m,ans=-1;
        while(l<=r){
            m=(l+r)/2;
            p=0;
            for(i=0;i<n;++i){
                if(a[i].y<a[i+1].y){
                    if(a[i].y>m)continue;
                    if(a[i+1].y>m)b[++p]={a[i].x+m-a[i].y,m};
                    else b[++p]=a[++i];
                }
                else{
                    if(a[i+1].y>m)continue;
                    if(a[i].y<m)b[++p]=a[i];
                    else b[++p]={a[i].x+a[i].y-m,m};
                    if(a[i+1].y==m)++i;
                }
            }
            e=cnt=0;
            for(i=0;;i=j){
                if(cnt==k)break;
                for(j=i+1;j<=p;++j)if(b[j].x-b[j].y>e)break;
                if(--j==i)break;
                e=b[j].x+b[j].y,++cnt;
            }
            if(e<L)l=m+1;
            else r=m-1,ans=m;
        }
        if(ans<0)printf("Case #%d\n-1\n",t);
        else printf("Case #%d\n%lld %lld\n",t,ans%2?ans:ans/2,1+ans%2);
    }
    return 0;
}