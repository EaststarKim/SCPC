#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,y;
    bool operator<(const Data&r)const{return x==r.x?y<r.y:x<r.x;}
}a[200010];
int chk[100010];
int main(){
    int t,tc,i,n,m;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)chk[i]=0;
        for(i=1;i<=m;++i){
            scanf("%d%d",&a[i].x,&a[i].y);
            if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
        }
        sort(a+1,a+m+1);
        for(i=1;i<m;++i)if(a[i].x==a[i+1].x&&a[i].y==a[i+1].y)chk[a[i].x]=chk[a[i].y]=1;
        int ans=0;
        for(i=1;i<=n;++i)ans+=!chk[i];
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}