#include <bits/stdc++.h>
using namespace std;
char a[2000010],p[510];
int st[26],cnt;
int main(){
    setbuf(stdout, NULL);
    int t,tc,i,j,k,n,m,q,s;
    long long ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&q);
        scanf("%s",a);
        for(i=ans=0;i<n;++i)a[i]-='a';
        for(i=1;i<=q;++i){
            scanf("%s",p);
            m=strlen(p);
            for(j=cnt=0;j<26;++j)st[j]=0;
            for(j=0;j<m;++j){
                p[j]-='a';
                if(!st[p[j]])st[p[j]]=++cnt;
                p[j]=st[p[j]];
            }
            for(j=s=0;j<=n-m;++j){
                for(k=cnt=0;k<26;++k)st[k]=0;
                for(k=j;k<j+m;++k){
                    if(!st[a[k]])st[a[k]]=++cnt;
                    if(st[a[k]]!=p[k-j])break;
                }
                if(k>=j+m)++s;
            }
            ans+=s*i;
        }
        printf("Case #%d\n%lld\n",t,ans);
    }
    return 0;
}