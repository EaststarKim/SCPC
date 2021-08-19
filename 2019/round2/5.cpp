#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,y;
    bool operator<(const Data&r)const{return x<r.x;}
}a[500010];
int x[500010],y[500010],t[500010];
struct ST{
    int t[1<<20];
    void init(){fill(t+1,t+(1<<20),2e9);}
    void update(int n,int s,int e,int k,int v){
        if(e<k||k<s)return;
        if(s==e){
            t[n]=min(t[n],v);
            return;
        }
        int l=n*2,r=l+1,m=(s+e)/2;
        update(l,s,m,k,v);
        update(r,m+1,e,k,v);
        t[n]=min(t[n],v);
    }
    int query(int n,int s,int e,int si,int ei){
        if(e<si||ei<s)return 1e9;
        if(si<=s&&e<=ei)return t[n];
        int l=n*2,r=l+1,m=(s+e)/2;
        return min(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
    }
}st;
int main(){
    int t,tc,i,j,p,n,k;
    long long s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&k,&n);
        if(n>50000){
            printf("Case #%d\n%lld\n",t,0);
            continue;
        }
        for(i=1;i<=n;++i)scanf("%d%d",&a[i].x,y+i),a[i].y=y[i];
        sort(a+1,a+n+1);
        sort(y+1,y+n+1);
        st.init();
        s=0;
        for(i=p=n;i;--i){
            if(a[p].x!=a[i].x){
                for(;p>i;--p)st.update(1,1,n,a[p].y,a[p].x);
            }
            int l=1,r=k-max(a[i].x,a[i].y),m;
            a[i].y=lower_bound(y+1,y+n+1,a[i].y)-y;
            while(l<=r){
                m=(l+r)/2;
                j=lower_bound(y+1,y+n+1,y[a[i].y]+m)-y-1;
                if(a[i].x+m>st.query(1,1,n,a[i].y+1,j))r=m-1;
                else l=m+1;
            }
            s+=r;
        }
        printf("Case #%d\n%lld\n",t,s);
    }
    return 0;
}