#include <bits/stdc++.h>
using namespace std;
int c[50010],a[50010],b[50010],sa[50010],cnt[50010],lcp[50010];
int main(){
    int t,i,j,k,len,n,x,p,tc;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&x);
        memset(cnt,0,sizeof cnt);
        memset(b,0,sizeof b);
        memset(lcp,0,sizeof lcp);
        k=256;
        for(i=1;i<=n;++i)scanf("%d",c+i),++cnt[a[i]=c[i]];
        for(i=1;i<k;++i)cnt[i]+=cnt[i-1];
        for(i=n;i;--i)sa[cnt[a[i]]--]=i;
        for(p=len=1;p<n;k=++p,len*=2){
            for(i=n-len,p=0;i++<n;)b[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>len)b[++p]=sa[i]-len;
            memset(cnt,0,sizeof cnt);
            for(i=1;i<=n;++i)++cnt[a[b[i]]];
            for(i=1;i<k;++i)cnt[i]+=cnt[i-1];
            for(i=n;i;--i)sa[cnt[a[b[i]]]--]=b[i];
            for(i=1;i<=n;++i)swap(a[i],b[i]);
            a[sa[1]]=p=0;
            for(i=2;i<=n;++i)a[sa[i]]=(sa[i-1]+len<=n&&sa[i]+len<=n&&b[sa[i-1]]==b[sa[i]]&&b[sa[i-1]+len]==b[sa[i]+len]?p:++p);
        }
        for(i=1;i<=n;++i)a[sa[i]]=i;
        for(i=1,p=0;i<=n;lcp[a[i++]]=p){
            for(p?--p:0,j=sa[a[i]-1];c[i+p]==c[j+p];++p);
        }
        int l=1,r=n,m,s,ans=0;
        while(l<=r){
            m=(l+r)/2;
            s=1;
            for(i=2;i<=n;++i){
                if(s==x)break;
                if(lcp[i]<m)s=1;
                else ++s;
            }
            if(s==x)l=m+1,ans=m;
            else r=m-1;
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}