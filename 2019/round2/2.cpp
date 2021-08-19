#include <bits/stdc++.h>
using namespace std;
int a[5010],b[5010],s[5010],D[5010][5010];
int main(){
    int t,tc,i,j,n,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",a+i);
        for(i=1;i<=n;++i)scanf("%d",b+i);
        for(i=1;i<=n;++i)s[i]=s[i-1]+(a[i]==b[i]);
        for(i=1;i<=n;++i)D[i][i]=(a[i]==b[i]);
        for(i=1;i<n;++i){
            for(j=1;j+i<=n;++j)D[j][j+i]=D[j+1][j+i-1]+(a[j]==b[j+i])+(a[j+i]==b[j]);
        }
        ans=0;
        for(i=1;i<=n;++i){
            for(j=i;j<=n;++j)ans=max(ans,s[i-1]+s[n]-s[j]+D[i][j]);
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}