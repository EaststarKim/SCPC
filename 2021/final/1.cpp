#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int t,tc,i,n,m,k,q,mn,md,mx,x,l,r,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&m,&k,&q);
        scanf("%d%d%d",&mn,&md,&mx);
        n=2*m*k+1;
        for(i=1;i<=n;++i)scanf("%d",a+i);
        a[n+1]=0;
        sort(a+1,a+n+1);
        printf("Case #%d\n",t);
        for(;q--;){
            scanf("%d",&x);
            ans=1e9;
            l=lower_bound(a+1,a+n+1,x)-a;
            r=upper_bound(a+1,a+n+1,x)-a-1;
            if(a[l]!=x);
            else if(m==1){
                if(l==1)ans=mn;
                if(r==n)ans=min(ans,mx);
                if(l<=k+1&&r>k)ans=min(ans,md);
            }
            else if(min(min(mn,md),mx)==mn){
                if(l==1)ans=m*mn;
                else if(min(md,mx)==mx||l>n-k)ans=(m-1)*mn+mx;
                else ans=(m-1)*mn+md;
            }
            else if(min(min(mn,md),mx)==md){
                if(r<=k)ans=(m-1)*md+mn;
                else if(l>n-k)ans=(m-1)*md+mx;
                else ans=m*md;
            }
            else{
                if(r==n)ans=m*mx;
                else if(min(mn,md)==mn||r<=k)ans=(m-1)*mx+mn;
                else ans=(m-1)*mx+md;
            }
            printf("%d ",ans<1e9?ans:-1);
        }
        puts("");
    }
    return 0;
}