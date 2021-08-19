#include <bits/stdc++.h>
using namespace std;
struct Data{
    int l,r,h;
    void input(){scanf("%d%d%d",&l,&r,&h);}
}a[1010];
const double PI=3.1415926535897932384626433832795028841971693993;
int main(){
    int t,tc,i,r,s,e,n,h;
    double ans;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d%d%d",&r,&s,&e,&n);
        for(i=1;i<=n;++i)a[i].input();
        for(ans=0,i=1;i<=n;++i){
            h=a[i].h;
            if(h<r){
                ans-=sqrt(double(2*r*h-h*h))*2;
                ans+=r*acos(1-(double)h/r)*2;
            }
            else{
                ans-=(r*2-h)*2;
                ans+=PI*r;
            }
        }
        printf("Case #%d\n%.12f\n",t,ans+e-s);
    }
    return 0;
}