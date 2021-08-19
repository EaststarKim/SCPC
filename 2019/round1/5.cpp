#include <bits/stdc++.h>
using namespace std;
struct Data{
    long long x,y;
    void input(){scanf("%lld%lld",&x,&y),x*=2,y*=2;}
    bool operator<(const Data&r)const{return x<r.x;}
}a[100010];
int main(){
    int t,tc,i,n;
    long long s,e,l,r,m,p;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%lld%lld%d",&s,&e,&n);
        s*=2,e*=2;
        for(i=1;i<=n;++i)a[i].input();
        sort(a+1,a+n+1);
        l=1,r=4e12;
        while(l<=r){
            m=(l+r)/2;
            for(p=s,i=1;i<=n;++i)if(abs(a[i].y)<m){
                if(p>a[i].x-m)p=max(p,a[i].x+m);
                else break;
            }
            if(p>e)r=m-1;
            else l=m+1;
        }
        printf("Case #%d\n%lld\n",t,r);
    }
    return 0;
}