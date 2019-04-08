#include<iostream>
#include<cstring>
using namespace std;

int k[22][22][22];

int w(int a,int b,int c){

    if(a>20||b>20||c>20) return 1048576;
    if(a<=0||b<=0||c<=0) return 1;
    if(k[a][b][c]!=-1) return k[a][b][c];
    if(a<b&&b<c) return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}

int main(){
    int a,b,c;
    memset(k,-1,sizeof(k));
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++){
            for(int t=1;t<=20;t++){
                k[i][j][t]=w(i,j,t);
                //cout<<i<<" "<<j<<" "<<t<<" "<<k[i][j][t]<<endl;
            }
        }
    }
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1) break;
        if(a<=0||b<=0||c<=0) cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<1<<endl;
        else if(a>20||b>20||c>20) cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<1048576<<endl;
        else cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<k[a][b][c]<<endl;
    }
    return 0;
}