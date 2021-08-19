#include <stdio.h>
#include <string.h>
using namespace std;
struct D{
    int a,b,r,c,x;
}q[10010];
int dice[9],idx[9],po[9][4],x[6][6][3][110];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
int main(){
    int t,i,j,k,n,m,tc,a,b,c,d;
    scanf("%d",&tc);
    for(t=1;t<=tc;++t){
        for(i=0;i<6;++i)scanf("%d",dice+i),idx[dice[i]]=i;
        for(i=1;i<6;++i)if(i!=2)po[i][0]=0,po[i][2]=2;
        po[1][3]=5,po[5][1]=1,po[1][1]=3,po[3][3]=1;
        for(i=3;i<5;++i)po[i][1]=i+1,po[i+1][3]=i;
        po[0][0]=4,po[0][1]=3,po[0][2]=1,po[0][3]=5;
        po[2][0]=1,po[2][1]=3,po[2][2]=4,po[2][3]=5;
        scanf("%d%d%d%d%d%d",&n,&m,&a,&b,&c,&d);
        int f=0,r=1;
        q[1]={a=idx[a],b=idx[b],1,1,1};
        c=idx[c],d=idx[d];
        memset(x,0,sizeof x);
        x[a][b][1][1]=1;
        while(f<r){
            D p=q[++f];
            for(j=0;j<4;++j)if(po[p.a][j]==p.b)break;
            for(k=0;k<4;++k)if(po[p.b][k]==p.a)break;
            for(i=0;i<4;++i){
                int nr=p.r+dx[i],nc=p.c+dy[i],na,nb;
                if(nr<1||nr>n||nc<1||nc>m)continue;
                if(i<1)nb=p.a,na=po[p.a][(j+2)%4];
                else if(i<2)na=p.a,nb=po[p.a][(j+3)%4];
                else if(i<3)na=p.b,nb=po[p.b][(k+2)%4];
                else na=p.a,nb=po[p.a][(j+1)%4];
                if(!x[na][nb][nr][nc])q[++r]={na,nb,nr,nc,x[na][nb][nr][nc]=p.x+1};
            }
        }
        printf("Case #%d\n%d\n",t,x[c][d][n][m]-1);
    }
    return 0;
}