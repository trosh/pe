#include <stdio.h>
#include <stdlib.h>
#define u 10000
int i,j,k,l,m,n[u],p,q;int Q(int r){for(m=2;m<r;m++)if(!(r%m))return 0;return 1;}int main(){for(i=2;i<u;i++)for(l=i;l;l/=10){q=1;for(p=l%10;p;p--)q*=10;n[i]+=q;}for(i=9;i<u;i++)if(Q(i))for(j=2;(q=(p=i+j)+j)<u;j++)if(Q(q)&&Q(p)&&n[i]==n[q]&&n[i]==n[p])printf("%d%d%d\n",i,q,p);return 0;}
