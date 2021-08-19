#include <stdio.h>
int D[1000010];
int main(){
    int t,tc,i,n,m,s;
    for(i=2;i<=1e6;++i)D[i]=(i%2?D[(i+1)/2]+1:D[i/2])+1;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(s=0,i=n;i<=m;++i)s+=D[i];
        printf("Case #%d\n%d\n",t,s);
    }
    return 0;
}