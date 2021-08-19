#include <bits/stdc++.h>
using namespace std;
struct data{
    int y,h;
    bool operator<(const data&r)const{
        return y<r.y;
    }
}a[10010];
int D[10010];
int main(){
    int t,i,j,tc,n;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d%d%d",&a[i].y,&a[i].y,&a[i].h),D[i]=0;
        sort(a+1,a+n+1);
        int ans=0,s;
        for(i=1;i<=n;++i){
            s=a[i].y,++D[i];
            for(j=i+1;j<=n;++j){
                if(s+a[j].h<=a[j].y)D[j]=max(D[j],D[i]);
                else if(s<=a[j].y)++D[i];
                s+=a[j].h;
            }
            ans=max(ans,D[i]);
        }
        printf("Case #%d\n%d\n",t,n-ans);
    }
    return 0;
}