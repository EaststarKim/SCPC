#include <bits/stdc++.h>
using namespace std;
struct edge{
    int s,e,t;
    bool operator<(const edge&r)const{
        return t<r.t;
    }
}a[200010];
long long D[200010],E[200010];
struct al{
    int i,nx;
}b[200010];
int st[100010],j[100010],cnt;
void make_al(int s,int i){b[++cnt]={i,st[s]},st[s]=cnt;}
struct data{
    int s;
    long long d;
    bool operator<(const data&r)const{
        return d>r.d;
    }
};
priority_queue<data> q;
int main(){
    int t,i,tc,n,m,x,y,z;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=1;i<=m;++i)scanf("%d%d%d",&x,&y,&z),a[i*2-1]={x,y,z},a[i*2]={y,x,z};
        m*=2;
        sort(a+1,a+m+1);
        cnt=0;
        for(i=1;i<=n;++i)st[i]=0;
        for(i=m;i;--i)make_al(a[i].s,i);
        for(i=1;i<=n;++i)j[i]=st[i];
        for(i=2;i<=n;++i)D[i]=1e18;
        priority_queue<data>().swap(q);
        for(i=1;i<=m;){
            do{q.push({a[i].s,D[a[i].s]});}while(a[i++].t==a[i].t);
            while(!q.empty()){
                data p=q.top();q.pop();
                if(p.d!=D[p.s])continue;
                for(;j[p.s]&&a[b[j[p.s]].i].t==a[i-1].t;j[p.s]=b[j[p.s]].nx)if(D[a[b[j[p.s]].i].e]>p.d+a[b[j[p.s]].i].t)q.push({a[b[j[p.s]].i].e,D[a[b[j[p.s]].i].e]=p.d+a[b[j[p.s]].i].t});
            }
        }
        for(i=1;i<=n;++i)j[i]=st[i];
        E[n]=0;
        for(i=1;i<n;++i)E[i]=1e18;
        priority_queue<data>().swap(q);
        for(i=1;i<=m;){
            do{q.push({a[i].s,E[a[i].s]});}while(a[i++].t==a[i].t);
            while(!q.empty()){
                data p=q.top();q.pop();
                if(p.d!=E[p.s])continue;
                for(;j[p.s]&&a[b[j[p.s]].i].t==a[i-1].t;j[p.s]=b[j[p.s]].nx)if(E[a[b[j[p.s]].i].e]>p.d+a[b[j[p.s]].i].t)q.push({a[b[j[p.s]].i].e,E[a[b[j[p.s]].i].e]=p.d+a[b[j[p.s]].i].t});
            }
        }
        long long ans=1e18;
        for(i=1;i<=n;++i)ans=min(ans,D[i]+E[i]);
        printf("Case #%d\n%lld\n",t,ans<1e18?ans:-1);
    }
    return 0;
}