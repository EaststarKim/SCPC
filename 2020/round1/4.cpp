#include <bits/stdc++.h>
using namespace std;
char c[50010];
int a[50010],b[500010],m,q,ans;
struct Tree{
    struct Data{int mx,s;}t[1<<20];
    void init(){memset(t,0,sizeof t);}
    void update(int n,int s,int e,int si,int ei,int v){
        if(ei<s||e<si)return;
        if(si<=s&&e<=ei){
            t[n].s+=v;
            return;
        }
        int l=n*2,r=l+1,m=(s+e)/2;
        t[l].s+=t[n].s,t[r].s+=t[n].s,t[n].s=0;
        update(l,s,m,si,ei,v);
        update(r,m+1,e,si,ei,v);
        t[n].mx=max(t[l].mx+t[l].s,t[r].mx+t[r].s);
    }
    int getmx(){return t[1].mx+t[1].s;}
}seg;
void update(int k,int v){
    int l,r;
    l=lower_bound(b+1,b+m+1,k-q)-b;
    r=lower_bound(b+l,b+m+1,k)-b;
    seg.update(1,1,m,l,r,v);
}
int main(){
    int t,i,j,x,tc,n,k,s,l,r;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&n,&k,&q);
        scanf("%s",c+1);
        for(s=0,i=1;i<k;++i)s=s*10+c[i]-48;
        for(m=0;i<=n;++i){
            s=s*10+c[i]-48;
            b[++m]=a[i]=s;
            for(j=0,x=1;j<k;++j,x*=10)b[++m]=s-s/x%10*x+x;
            s%=x/10;
        }
        sort(b+1,b+m+1);
        seg.init();
        for(i=k;i<=n;++i)update(a[i],1);
        ans=seg.getmx();
        for(i=1;i<=n;++i){
            for(j=i,x=1;j<i+k&&j<=n;++j,x*=10)if(j>=k){
                update(a[j],-1);
                s=a[j]-a[j]/x%10*x+x;
                update(s,1);
            }
            ans=max(ans,seg.getmx());
            for(j=i,x=1;j<i+k&&j<=n;++j,x*=10)if(j>=k){
                update(a[j],1);
                s=a[j]-a[j]/x%10*x+x;
                update(s,-1);
            }
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}