#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,y;
    void input(){scanf("%d%d",&x,&y);}
    int dis(Data a){return abs(a.x-x)+abs(a.y-y);}
}a[8];
int c[8];
int dx[]={0,0,1,2,3,3,2,1},dy[]={0,1,2,2,1,0,-1,-1};
int main(){
    int t,tc,i,k,x,y;
    long long ans,s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&k);
        ans=1e18;
        for(i=0;i<8;++i)a[i].input();
        int p[8]={0,1,2,3,4,5,6,7};
        do{
            for(i=0;i<8;++i)c[i]=a[p[i]].x-dx[i]*k;
            sort(c,c+8);
            x=c[3];
            for(i=0;i<8;++i)c[i]=a[p[i]].y-dy[i]*k;
            sort(c,c+8);
            y=c[3];
            for(i=s=0;i<8;++i)s+=abs(a[p[i]].x-x-dx[i]*k)+abs(a[p[i]].y-y-dy[i]*k);
            ans=min(ans,s);
        }while(next_permutation(p,p+8));
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}