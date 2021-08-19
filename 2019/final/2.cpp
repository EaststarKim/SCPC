#include <bits/stdc++.h>
using namespace std;
struct P{
    long long x,y;
    long long sz(){return x*x+y*y;}
    bool operator<(const P&r)const{return x==r.x?y<r.y:x<r.x;}
}a[110];
P genvec(P s,P e){return {e.x-s.x,e.y-s.y};}
long long cp(P u,P v){return u.x*v.y-v.x*u.y;}
bool cmp(P x,P y){
    P u=genvec(a[1],x),v=genvec(a[1],y);
    return cp(u,v)>0;
}
int st[110],chk[110];
int main(){
    int t,tc,i,n,m;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        memset(chk,0,sizeof chk);
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%lld%lld",&a[i].x,&a[i].y);
        sort(a+1,a+n+1);
        if(a[n-1].x==a[n].x)swap(a[n-1],a[n]);
        st[0]=n;
        st[m=1]=1;
        for(i=2;i<=n;++i)if(i==n||(a[n].y-a[1].y)*(a[i].x-a[1].x)>(a[i].y-a[1].y)*(a[n].x-a[1].x)){
            while(cp(genvec(a[st[m-1]],a[st[m]]),genvec(a[st[m-1]],a[i]))<0)chk[st[m--]]=0;
            st[++m]=i;
            chk[i]=1;
        }
        for(i=n;--i>1;)if(!chk[i])st[++m]=i;
        printf("Case #%d\n%d\n",t,m);
        for(i=1;i<=m;++i)printf("%lld %lld\n",a[st[i]].x,a[st[i]].y);
    }
    return 0;
}