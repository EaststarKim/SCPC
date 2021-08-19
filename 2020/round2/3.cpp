#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e7;
int a[200010],s[200010],bit[M+10];
int getsum(int k){
    int s=0;
    for(;k;k-=k&-k)s+=bit[k];
    return s;
}
void update(int k,int v){for(;k<=M;k+=k&-k)bit[k]+=v;}
int mid(int k){
    int l=1,r=M,m;
    while(l<=r){
        m=(l+r)/2;
        if(getsum(m)<k)l=m+1;
        else r=m-1;
    }
    return l;
}
int main(){
    int t,i,tc,n,k,q,x,y,sum;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d",&n,&k,&q);
        sum=0;
        for(i=1;i<=n;++i){
            scanf("%d",a+i);
            sum+=a[i];
            if(i>=k){
                sum-=a[i-k];
                update(s[i]=sum,1);
            }
        }
        printf("Case #%d\n%d ",t,mid((n-k+1)/2+1));
        for(;q--;){
            scanf("%d%d",&x,&y);
            for(i=x;i<x+k&&i<=n;++i)if(i>=k)update(s[i],-1);
            for(i=x;i<x+k&&i<=n;++i)if(i>=k)update(s[i]+=y-a[x],1);
            a[x]=y;
            printf("%d ",mid((n-k+1)/2+1));
        }
        for(i=k;i<=n;++i)update(s[i],-1);
        puts("");
    }
    return 0;
}