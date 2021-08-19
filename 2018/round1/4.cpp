#include <bits/stdc++.h>
using namespace std;
int x[1010],y[1010],p[110],ans[110];
int main(){
    int t,i,j,tc,n,m;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i)p[i]=i;
        for(i=1;i<=m;++i)scanf("%d%d",x+i,y+i);
        int mn=1e9;
        if(n<11){
            do{
                int s=0;
                for(i=1;i<=m;++i)s+=abs(p[x[i]]-p[y[i]]);
                if(s<mn){
                    mn=s;
                    for(i=0;i<n;++i)ans[p[i]]=i;
                }
            }while(next_permutation(p,p+n));
        }
        else{
            mn=0;
            for(i=1;i<=m;++i)mn+=abs(p[x[i]]-p[y[i]]);
            for(i=1;i<1000001;++i){
                int r1,r2,s=0;
                r1=rand()%n;
                r2=rand()%n;
                swap(p[r1],p[r2]);
                for(j=1;j<=m;++j)s+=abs(p[x[j]]-p[y[j]]);
                if(s<mn)mn=s;
                else swap(p[r1],p[r2]);
            }
            for(i=0;i<n;++i)ans[p[i]]=i;
        }
        printf("Case #%d\n%d\n",t,mn);
        for(i=0;i<n;++i)printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}