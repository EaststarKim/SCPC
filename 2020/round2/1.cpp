#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
long long D[200010][4];
int main(){
    int t,i,tc,n;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        for(i=1;i<=n;++i)scanf("%d",b+i);
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        memset(D,0,sizeof D);
        for(i=1;i<=n;++i){
            D[i][0]=D[i-1][0]+abs(a[i]-b[i]);
            D[i][1]=min(D[i-1][1],D[i-1][0])+abs(a[i+1]-b[i]);
            D[i][2]=min(D[i-1][2],D[i-1][0])+abs(a[i]-b[i+1]);
            D[i][3]=min(min(D[i-1][0],D[i-1][3]+abs(a[i]-b[i])),min(D[i-1][1],D[i-1][2]));
        }
        printf("Case #%d\n%lld\n",t,min(D[n][0],D[n][3]));
    }
    return 0;
}