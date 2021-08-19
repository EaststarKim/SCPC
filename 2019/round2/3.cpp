#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,h;
    bool operator<(const Data&r)const{return x<r.x;}
}c[200010],f[200010],p[400010],d;
int ub[200010],lb[200010];
struct ST{
    int t[1<<19];
    void init(){fill(t+1,t+(1<<19),-1e9);}
    void update(int n,int s,int e,int k,int v){
        if(e<k||k<s)return;
        if(s==e){
            t[n]=v;
            return;
        }
        int l=n*2,r=l+1,m=(s+e)/2;
        update(l,s,m,k,v);
        update(r,m+1,e,k,v);
        t[n]=max(t[n],v);
    }
    int query(int n,int s,int e,int si,int ei){
        if(e<si||ei<s)return -1e9;
        if(si<=s&&e<=ei)return t[n];
        int l=n*2,r=l+1,m=(s+e)/2;
        return max(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
    }
}cst,fst;
int main(){
    int t,tc,i,j,k,l,n,m,a,b,r,w,h,s,e;
    long long ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&w,&s,&e);
        memset(c,0,sizeof c);
        memset(f,0,sizeof f);
        memset(p,0,sizeof p);
        memset(ub,0,sizeof ub);
        memset(lb,0,sizeof lb);
        cst.init();
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d%d",&c[i+1].x,&c[i].h),c[i].x+=c[i-1].x,cst.update(1,1,n,i,-c[i].h);
        c[i].x=w;
        fst.init();
        scanf("%d",&m);
        for(i=1;i<=m;++i)scanf("%d%d",&f[i+1].x,&f[i].h),f[i].x+=f[i-1].x,fst.update(1,1,m,i,f[i].h);
        f[i].x=w;
        h=s,a=b=r=0;
        for(i=j=1;i<=n||j<=m;){
            if(c[i].x<=f[j].x){
                if(h>c[i].h)p[++r]=c[i],h=c[i].h,ub[++a]=r;
                ++i;
            }
            else{
                if(h<f[j].h)p[++r]=f[j],h=f[j].h,lb[++b]=r;
                ++j;
            }
        }
        if(h>e)p[++r]={w,e},ub[++a]=r;
        else p[++r]={w,e},lb[++b]=r;
        ub[++a]=lb[++b]=r+1;
        d={0,s};
        ans=0;
        for(i=j=k=l=1;d.x<w;){
            if(ub[k]<lb[l]){
                int ei=upper_bound(f+1,f+m+1,p[lb[l]-1])-f-1;
                ans+=max(0ll,1ll*(min(c[i+1].x,f[j+1].x)-d.x)*(d.h-max(fst.query(1,1,m,j,ei),p[lb[l]-1].h)));
            }
            else{
                int ei=upper_bound(c+1,c+n+1,p[ub[k]-1])-c-1;
                ans+=max(0ll,1ll*(min(c[i+1].x,f[j+1].x)-d.x)*(min(-cst.query(1,1,n,i,ei),p[ub[k]-1].h)-d.h));
            }
            d.x=min(c[i+1].x,f[j+1].x);
            if(d.x==c[i+1].x)++i;
            if(d.x==f[j+1].x)++j;
            if(d.x==p[ub[k]].x)d.h=p[ub[k++]].h;
            if(d.x==p[lb[l]].x)d.h=p[lb[l++]].h;
        }
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}