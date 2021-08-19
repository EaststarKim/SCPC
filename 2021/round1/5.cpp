#include <bits/stdc++.h>
using namespace std;
struct Data{int p,d,rnk,cf;}a[100010];
pair<int,int> seek(int n,int s){
    if(!a[n].p)return {n,s};
    return seek(a[n].p,s+a[n].d);
}
void uf(int x,int y,int d){
    int xd,yd;
    tie(x,xd)=seek(x,0);
    tie(y,yd)=seek(y,0);
    if(x==y){
        if(xd-yd!=d)a[x].cf=1;
        return;
    }
    if(a[x].rnk<a[y].rnk){
        a[y].cf=max(a[x].cf,a[y].cf);
        a[x].p=y;
        a[x].d=yd-xd+d;
    }
    else{
        if(a[x].rnk==a[y].rnk)++a[x].rnk;
        a[x].cf=max(a[x].cf,a[y].cf);
        a[y].p=x;
        a[y].d=xd-yd-d;
    }
}
int main(){
    int t,tc,i,n,m,w,x,y,z,xd,yd;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        printf("Case #%d\n",t);
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof a);
        for(;m--;){
            scanf("%d%d%d",&w,&x,&y);
            if(w<2){
                scanf("%d",&z);
                uf(x,y,z);
            }
            else{
                tie(x,xd)=seek(x,0);
                tie(y,yd)=seek(y,0);
                if(x!=y)puts("NC");
                else{
                    if(a[x].cf)puts("CF");
                    else printf("%d\n",xd-yd);
                }
            }
        }
    }
    return 0;
}