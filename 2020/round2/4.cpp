#include <bits/stdc++.h>
using namespace std;
struct Line{int x,y;}a[200010],b[200010],c[200010];
int x[1200010],m;
void input(Line *a,int n){
    int i;
    for(i=1;i<=n;++i){
        scanf("%d%d",&a[i].x,&a[i+1].y);
        a[i].x+=a[i-1].x;
        a[i+1].y+=a[i].y;
    }
    a[n+1].x=a[n].x;
}
struct SegTree{
    struct Data{int s,mx;}t[1<<22];
    void init(){memset(t,0,sizeof t);}
    void lazy(int n,int l,int r){t[l].s+=t[n].s,t[r].s+=t[n].s,t[n].s=0;}
    void update(int n,int s,int e,int si,int ei,int v){
        if(ei<s||e<si)return;
        if(si<=s&&e<=ei){
            t[n].s+=v;
            return;
        }
        int l=n*2,r=l+1,m=(s+e)/2;
        lazy(n,l,r);
        update(l,s,m,si,ei,v);
        update(r,m+1,e,si,ei,v);
        t[n].mx=max(t[l].mx+t[l].s,t[r].mx+t[r].s);
    }
    int query(int n,int s,int e,int si,int ei){
        if(ei<s||e<si)return 0;
        if(si<=s&&e<=ei)return t[n].s+t[n].mx;
        int l=n*2,r=l+1,m=(s+e)/2,q;
        lazy(n,l,r);
        q=max(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
        t[n].mx=max(t[l].mx+t[l].s,t[r].mx+t[r].s);
        return q;
    }
}ST;
int main(){
    int t,i,j,k,tc,l,r,n,y,ny,lx,rx,s,e,sum,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&l,&r,&n);
        input(a,l);input(b,r);input(c,n);
        y=m=0;
        for(i=j=k=1;i<=l&&j<=r&&k<=n;){
            ny=min(min(a[i+1].y,b[j+1].y),c[k+1].y);
            x[++m]=(a[i].x+c[k].x)/2;
            x[++m]=(b[j].x+c[k].x)/2;
            y=ny;
            if(a[i+1].y==y)++i;
            if(b[j+1].y==y)++j;
            if(c[k+1].y==y)++k;
        }
        sort(x+1,x+m+1);
        ST.init();
        y=0;
        for(i=j=k=1;i<=l&&j<=r&&k<=n;){
            ny=min(min(a[i+1].y,b[j+1].y),c[k+1].y);
            s=lower_bound(x+1,x+m+1,(a[i].x+c[k].x)/2)-x;
            e=lower_bound(x+1,x+m+1,(b[j].x+c[k].x)/2)-x;
            ST.update(1,1,m,s,e,ny-y);
            y=ny;
            if(a[i+1].y==y)++i;
            if(b[j+1].y==y)++j;
            if(c[k+1].y==y)++k;
        }
        y=sum=ans=0;
        for(i=j=k=1;i<=l&&j<=r&&k<=n;){
            ny=min(min(a[i+1].y,b[j+1].y),c[k+1].y);
            if(a[i].x<=c[k].x&&c[k].x<=b[j].x)sum+=ny-y;
            s=lower_bound(x+1,x+m+1,(a[i].x+c[k].x)/2)-x;
            e=lower_bound(x+1,x+m+1,(b[j].x+c[k].x)/2)-x;
            ST.update(1,1,m,s,e,y-ny);
            y=ny;
            if(a[i+1].y==y)++i;
            if(b[j+1].y==y)++j;
            if(c[k+1].y==y){
                lx=c[k].x,rx=c[++k].x;
                if(lx>rx)swap(lx,rx);
                lx=lower_bound(x+1,x+m+1,lx)-x;
                rx=upper_bound(x+1,x+m+1,rx)-x-1;
                ans=max(ans,sum+ST.query(1,1,m,lx,rx));
            }
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}