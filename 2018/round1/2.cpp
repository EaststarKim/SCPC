#include <bits/stdc++.h>
using namespace std;
int a[200],D[10010],l;
int main(){
    int t,i,j,tc,n;
    for(i=1;i<10;++i)a[++l]=i;
    for(i=1;i<10;++i)a[++l]=i*11;
    for(i=1;i<10;++i){
        for(j=0;j<10;++j)a[++l]=i*101+j*10;
    }
    for(i=1;i<10;++i){
        for(j=0;j<10;++j)a[++l]=i*1001+j*110;
    }
    for(i=1;i<10001;++i){
        D[i]=1e9;
        for(j=1;j<=l&&a[j]<=i;++j)D[i]=min(D[i],D[i-a[j]]+1);
    }
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        printf("Case #%d\n%d",t,D[n]);
        for(i=l;i;--i)if(a[i]<=n&&D[n]==D[n-a[i]]+1)printf(" %d",a[i]),n-=a[i];
        puts("");
    }
    return 0;
}