#include <bits/stdc++.h>
using namespace std;
int st[1000010];
long long a[1000010],b[1000010];
int main(){
    int t,i,tc,n,p;
    long double ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        ans=p=0;
        for(i=1;i<=n;++i){
            scanf("%lld",a+i);
            b[i]=b[i-1]+a[i]*a[i];
            a[i]+=a[i-1];
            while(p&&(a[st[p]]-a[st[p-1]])*(i-st[p])>=(a[i]-a[st[p]])*(st[p]-st[p-1]))ans-=b[st[p]]-b[st[p-1]]-1.0L*pow(a[st[p]]-a[st[p-1]],2)/(st[p]-st[--p]);
            ans+=b[i]-b[st[p]]-1.0L*pow(a[i]-a[st[p]],2)/(i-st[p]);
            st[++p]=i;
        }
        printf("Case #%d\n%.20LF\n",t,ans);
    }
    return 0;
}