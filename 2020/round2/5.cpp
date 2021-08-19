#include <bits/stdc++.h>
using namespace std;
struct Point{
    int i;
    long long x,y;
    void input(){scanf("%lld%lld",&x,&y);}
    Point operator-(Point &r){return {i,x-r.x,y-r.y};}
    Point operator+(Point &r){return {i,x+r.x,y+r.y};}
    long long operator*(Point &r){return x*r.y-r.x*y;}
    bool operator<(const Point&r){
        if(y*r.y<0)return y>r.y;
        if(!y)return x>0?1:r.y<0;
        if(!r.y)return r.x<0?y>0:0;
        return x*r.y>r.x*y;
    }
}a[310],b[610];
int ccw(Point s,Point e,Point t){
    e=e-s,t=t-s;
    long long x=e*t;
    return x?(x>0?1:-1):0;
}
int f(int n){return n<5?n/4:f((n+1)/2)+2;}
int chk[310][310],D[310][310],E[310][310];
int main(){
    int t,i,j,k,tc,n,m,ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d",&n);
        for(i=0;i<n;++i)a[i].input(),a[i].i=i;
        a[n]=a[0];
        memset(chk,0,sizeof chk);
        for(i=0;i<n;++i){
            chk[i][(i+1)%n]=chk[i][(i-1+n)%n]=1;
            for(j=m=0;j<n;++j)if(i!=j)b[m++]=a[j]-a[i];
            sort(b,b+m);
            for(j=0;j<m;++j)b[m+j]=b[j]=b[j]+a[i];
            for(j=0;j<m;++j)if(b[j].i==(i+1)%n)break;
            for(;b[++j].i!=(i-1+n)%n;){
                for(k=0;k<n;++k)if(ccw(a[i],b[j],a[k])*ccw(a[i],b[j],a[k+1])<0){
                    if(ccw(a[k],a[k+1],a[i])*ccw(a[k],a[k+1],b[j])<0)break;
                }
                if(k==n)chk[i][b[j].i]=1;
            }
        }
        for(i=0;i<n;++i){
            for(j=0;j<n;++j)D[i][j]=E[i][j]=1e9;
            D[i][i+1]=E[i][i+1]=0;
        }
        D[n-1][0]=E[n-1][0]=0;
        for(i=2;i<n;++i){
            for(j=0;j<n;++j)if(chk[j][(j+i)%n]){
                for(k=1;k<i;++k)if(chk[j][(j+k)%n]&&chk[(j+k)%n][(j+i)%n]){
                    D[j][(j+i)%n]=min(D[j][(j+i)%n],max(D[j][(j+k)%n],D[(j+k)%n][(j+i)%n])+1);
                    E[j][(j+i)%n]=min(E[j][(j+i)%n],max(max(E[j][(j+k)%n],E[(j+k)%n][(j+i)%n]),D[j][(j+k)%n]+D[(j+k)%n][(j+i)%n]));
                }
            }
        }
        ans=1e9;
        for(i=0;i<n;++i){
            for(j=0;j<n;++j)ans=min(ans,max(max(E[i][j],E[j][i]),D[i][j]+D[j][i]-1));
        }
        for(i=0;i<n;++i){
            for(j=0;j<n;++j)if(i!=j&&!chk[i][j])break;
            if(j<n)break;
        }
        if(ans<f(n))ans=f(n);
        printf("Case #%d\n%d\n",t,ans);
    }
    return 0;
}