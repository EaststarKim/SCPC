#include <bits/stdc++.h>
using namespace std;
struct Data{
    int x,y,z;
    void input(){scanf("%d%d%d",&x,&y,&z);x*=2,y*=2,z*=2;}
}a[15010];
int main(){
    int t,tc,n,x,y,z,i;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)a[i].input();
        if(n>25){
            printf("Case #%d\n%d\n",t,0);
            continue;
        }
        int ans=2e9;
        for(x=-20;x<21;++x){
            for(y=-20;y<21;++y){
                for(z=-20;z<21;++z){
                    int mx=0,mn=2e9;
                    for(i=1;i<=n;++i){
                        int d=max(max(abs(a[i].x-x),abs(a[i].y-y)),abs(a[i].z-z));
                        mx=max(mx,d);
                        mn=min(mn,d);
                    }
                    if(ans>mx-mn){
                        ans=min(ans,mx-mn);
                    }
                }
            }
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}