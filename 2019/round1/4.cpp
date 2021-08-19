#include <bits/stdc++.h>
using namespace std;
struct Data{
    int i,r;
    bool operator<(const Data&t)const{return r<t.r;}
}a[110];
int b[110];
double x[110],y[110],mx;
int main(){
    int t,tc,i,j,k,n,l,r;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=1;i<=n;++i)scanf("%d",&a[i].r),a[i].i=i;
        sort(a+1,a+n+1);
        for(i=l=1,j=r=n;;){
            b[l++]=i;
            if(++i>j)break;
            b[r--]=i;
            if(++i>j)break;
            b[l++]=j;
            if(i>--j)break;
            b[r--]=j;
            if(i>--j)break;
        }
        printf("Case #%d\n",t);
        x[a[b[1]].i]=0;
        for(i=2;i<=n;++i){
            x[a[b[i]].i]=0;
            for(j=1;j<i;++j)x[a[b[i]].i]=max(x[a[b[i]].i],x[a[b[j]].i]+2*sqrt(1ll*a[b[i]].r*a[b[j]].r));
        }
        mx=x[a[b[n]].i]+a[b[1]].r+a[b[n]].r;
        for(i=2;i<n;++i){
            for(j=i,k=n,l=1,r=n-i+1;;){
                b[l++]=j;
                if(++j>k)break;
                b[r--]=j;
                if(++j>k)break;
                b[l++]=k;
                if(j>--k)break;
                b[r--]=k;
                if(j>--k)break;
            }
            for(j=i;--j;){
                for(k=1;k<n-j;++k)if(sqrt(1ll*a[b[k]].r*a[j].r)+sqrt(1ll*a[b[k+1]].r*a[j].r)<=sqrt(1ll*a[b[k]].r*a[b[k+1]].r)){
                    for(l=n-j;l>k;--l)b[l+1]=b[l];
                    b[k+1]=j;
                    break;
                }
                if(k>=n-j)break;
            }
            if(j)break;
            y[a[b[1]].i]=0;
            for(j=2;j<=n;++j){
                y[a[b[j]].i]=0;
                for(k=1;k<j;++k)y[a[b[j]].i]=max(y[a[b[j]].i],y[a[b[k]].i]+2*sqrt(1ll*a[b[j]].r*a[b[k]].r));
            }
            if(mx>y[a[b[n]].i]+a[b[1]].r+a[b[n]].r){
                mx=y[a[b[n]].i]+a[b[1]].r+a[b[n]].r;
                for(j=1;j<=n;++j)x[j]=y[j];
            }
        }
        for(i=1;i<=n;++i)printf("%.20f\n",x[i]);
    }
    return 0;
}