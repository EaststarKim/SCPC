#include <bits/stdc++.h>
using namespace std;
struct Data{
    int mn[5],l,s;
    void input(){
        int i,j,k;
        for(i=4;i--;)mn[i]=1e9;
        scanf("%d",&l);
        for(i=l;i--;){
            scanf("%d",&k);
            for(j=4;j--;){
                if(mn[j]<=k)break;
                mn[j+1]=mn[j];
            }
            mn[j+1]=k;
        }
        for(i=4,s=0;i--;)s+=mn[i];
        if(l%2)s+=mn[0];
    }
}a[20010];
int main(){
    int t,tc,i,n,m,s,ocnt,ecnt,omx1,omx2,emx1,emx2;
    long long ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        ocnt=ecnt=omx1=omx2=emx1=emx2=ans=0;
        for(i=1;i<=n;++i){
            a[i].input();
            ans+=a[i].s;
            s=a[i].mn[2]+a[i].mn[3];
            if(a[i].l%2){
                ++ocnt;
                if(omx2<s)omx2=s;
                if(omx1<s)omx2=omx1,omx1=s;
            }
            else{
                ++ecnt;
                if(emx2<s)emx2=s;
                if(emx1<s)emx2=emx1,emx1=s;
            }
        }
        s=omx1+omx2;
        if(ocnt==2&&ecnt){
            for(i=1;i<=n&&s>0;++i)if(a[i].l%2==0)s-=a[i].mn[0]+a[i].mn[1];
        }
        s=max(s,max(omx1,emx2)+emx1);
        printf("Case #%d\n%lld\n",t,ans-s);
    }
    return 0;
}