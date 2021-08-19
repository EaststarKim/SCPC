#include <bits/stdc++.h>
using namespace std;
struct Data{
    long long x,y;
    double p;
    bool operator<(const Data&r)const{
        if(x*r.x<0)return x>r.x;
        if(!x)return y<0?r.x<0:1;
        if(!r.x)return r.y<0?x>0:0;
        return y*r.x>r.y*x;
    }
    long long ccw(Data t){return x*t.y-t.x*y;}
}a[200010];
int main(){
    int t,i,j,tc,n,z;
    double c,s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%lld",&a[i].x);
        for(i=1;i<=n;++i)scanf("%lld",&a[i].y);
        for(i=1;i<=n;++i)scanf("%lf",&a[i].p);
        scanf("%lld%lld",&a[0].x,&a[0].y);
        for(i=1;i<=n;++i)a[i].x-=a[0].x,a[i].y-=a[0].y;
        sort(a+1,a+n+1);
        for(i=1;i<=n;++i)a[n+i]=a[i];
        c=0,z=0;
        for(i=1;i<=n;++i){
            if(a[i].p<1)c+=log(1-a[i].p);
            else ++z;
        }
        s=z?0:exp(c);
        for(i=j=1;i<=n;++i){
            c+=log(a[i].p);
            for(;i==j||(j<n+i&&a[j].ccw(a[i])>0);++j){
                if(a[j].p<1)c-=log(1-a[j].p);
                else --z;
            }
            if(!z)s+=exp(c);
            c-=log(a[i].p);
            if(a[i].p<1)c+=log(1-a[i].p);
            else ++z;
        }
        printf("Case #%d\n%.19f\n",t,1-s);
    }
    return 0;
}