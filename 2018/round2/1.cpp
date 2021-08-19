#include <bits/stdc++.h>
using namespace std;
int a[200010],b[200010];
int main(){
    int t,i,tc,n;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
        sort(b+1,b+n+1);
        int mx=0,ans=0;
        for(i=1;i<=n;++i){
            if(mx<a[i]&&(lower_bound(b+1,b+n+1,a[i])-b)==i)++ans;
            mx=max(mx,a[i]);
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}