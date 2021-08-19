#include <bits/stdc++.h>
using namespace std;
const int SZ=500000;
int D[SZ]={0,1,2},st[1<<20];
void init(int n,int s,int e){
    if(s==e){
        st[n]=D[s];
        return;
    }
    int l=n*2,r=l+1,m=(s+e)/2;
    init(l,s,m);
    init(r,m+1,e);
    st[n]=max(st[l],st[r]);
}
int query(int n,int s,int e,int si,int ei){
    if(ei<s||e<=si)return 0;
    if(si<=s&&e<=ei)return st[n];
    int l=n*2,r=l+1,m=(s+e)/2;
    return max(query(l,s,m,si,ei),query(r,m+1,e,si,ei));
}
int main(){
    int t,tc,i,j,ans;
    long long x,y;
    for(i=3,j=2;i<5e5;++i){
        if((j+1)*(j+2)/2==i)++j;
        D[i]=min(D[i-j*(j+1)/2]+j,D[i-(j-1)*j/2]+j-1);
    }
    init(1,1,SZ-1);
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%lld%lld",&x,&y);
        ans=0;
        if(x<SZ){
            if(y<SZ){
                printf("Case #%d\n%d\n",t,query(1,1,SZ-1,x,y));
                continue;
            }
            ans=query(1,1,SZ-1,x,SZ-1);
            x=SZ;
        }
        for(i=1;;++i){
            long long tmp=1ll*i*(i+1)/2;
            if(tmp>y)break;
            if(tmp+i<x)continue;
            long long l=max(1ll*0,x-tmp),r=min(1ll*i,y-tmp);
            if(!l)ans=max(ans,i),++l;
            if(l>r)continue;
            ans=max(ans,query(1,1,SZ-1,l,r)+i);
        }
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}