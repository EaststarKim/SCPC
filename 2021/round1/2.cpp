#include <bits/stdc++.h>
using namespace std;
char b[50010];
int D[50010][2];
int main(){
    int t,tc,i,j,n,k,cnt;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        printf("Case #%d\n",t);
        scanf("%d%d%s",&n,&k,b+1);
        memset(D,0,sizeof D);
        for(i=n;i;--i){
            D[i][0]=D[i][1]=1;
            if(i<=n-k){
                if(b[i+k]=='0')D[i][1]=0;
                else if(i>n-k*2)D[i][0]=0;
                else D[i][0]=D[i+k*2][1];
            }
            if(i>k){
                if(b[i-k]=='0')D[i][1]=0;
                else if(i<=k*2)D[i][0]=0;
            }
        }
        for(i=1;i<=n;++i){
            if(D[i][0]){
                printf("0");
                if(i<=n-k*2&&b[i+k]=='1')D[i+k*2][0]=0;
            }
            else printf("1");
        }
        puts("");
    }
    return 0;
}