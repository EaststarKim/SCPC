#include <bits/stdc++.h>
int main(){
    int t,tc;
    long long i,j,n,s;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%lld",&n);
        s=n;
        for(i=1;i<n;++i){
            j=n*n-i*i-1;
            if(j>=0)s+=int(sqrt(j))*2+1;
        }
        s=s*2-1;
        printf("Case #%d\n%lld\n",t,s);
    }
    return 0;
}