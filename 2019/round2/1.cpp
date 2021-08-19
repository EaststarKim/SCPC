#include <bits/stdc++.h>
using namespace std;
int p[30010],d[30010];
int main(){
    int t,tc,i,j,a,b;
    p[2]=d[2]=1;
    for(i=3;i<3e4;i+=2){
        for(j=3;j*j<=i;++j)if(p[j]&&i%j==0)break;
        if(j*j>i){
            p[i]=1;
            for(j=1;i/j;j*=10)d[i]=max(d[i],d[i/j/10*j+i%j]+1);
        }
    }
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&a,&b);
        a=d[a],b=d[b];
        printf("Case #%d\n%d\n",t,1+(a<=b)+(a==b));
    }
    return 0;
}