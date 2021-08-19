#include <bits/stdc++.h>
using namespace std;
int a[60][510],r[25010],c[25010];
int countf(int r,int c){
    if(r<1)return -1e9;
    int i,j,s=0;
    for(i=0;i<3;++i){
        for(j=0;j<3;++j)s+=a[r+i][c+j];
    }
    return s;
}
int main(){
    int t,tc,i,j,k,l,n,m,cnt;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i){
            for(j=1;j<=m;++j)scanf("%1d",a[i]+j);
        }
        cnt=0;
        for(j=1;j<=m;++j){
            for(i=1;i<=n;++i)if(a[i][j]){
                r[++cnt]=i,c[cnt]=j;
                int s1=countf(i,j),s2=countf(i-1,j),s3=countf(i-2,j);
                if(max(max(s1,s2),s3)==s2)--r[cnt];
                else if(max(max(s1,s2),s3)==s3)r[cnt]-=2;
                r[cnt]=min(r[cnt],n-2);
                c[cnt]=min(c[cnt],m-2);
                for(k=0;k<3;++k){
                    for(l=0;l<3;++l)a[r[cnt]+k][c[cnt]+l]=0;
                }
            }
        }
        printf("Case #%d\n%d\n",t,cnt);
        for(i=1;i<=cnt;++i)printf("%d %d\n",r[i],c[i]);
    }
    return 0;
}