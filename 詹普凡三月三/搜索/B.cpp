#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char a[105][105];
int b[105][105];
int h,l;

int dfs(int x,int y,int s){
    b[x][y]=1;
    x=x-1;
    if(a[x][y]=='.'&&b[x][y]==0) s+=dfs(x,y,1);
    x=x+2;
    if(a[x][y]=='.'&&b[x][y]==0) s+=dfs(x,y,1);
    x=x-1;
    y=y-1;
    if(a[x][y]=='.'&&b[x][y]==0) s+=dfs(x,y,1);
    y=y+2;
    if(a[x][y]=='.'&&b[x][y]==0) s+=dfs(x,y,1);
    y=y-1;
    return s;
}

int main(){
    while(cin>>l>>h){
        if(l==0&&h==0) break;
        memset(a,'#',sizeof(a));
        memset(b,0,sizeof(b));
        int k=0;
        int x,y;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    x=i;
                    y=j;
                }
            }
        }
        /*for(int i=1;i<=h;i++){
            for(int j=1;j<=l;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }*/
        cout<<dfs(x,y,1)<<endl;
    }
    return 0;
}