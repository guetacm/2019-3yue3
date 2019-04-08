#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char head[10005];
char endd[10005];
int vis[10005];
int n;
int check;

void dfs(int start){
    //cout<<"下标为："<<start<<"头为："<<head[start]<<"尾为："<<endd[start]<<endl;
    if(endd[start]=='m'){
        check=1;
        return;
    }
    for(int i=0; i<n; i++){
        if(head[i]==endd[start]&&vis[i]==0){
            vis[i]=1;
            dfs(i);
            vis[i]=0;
        }
    }
}

int main(){
    for(int i=1; i<=3; i++){
        string a;
        n=0;
        while(cin>>a){
            if(a[0]=='0') break;
            head[n]=a[0];
            endd[n]=a[a.length()-1];
            //cout<<"n= "<<n<<" "<<head[n]<<" "<<endd[n]<<endl;
            n++;
        }
        memset(vis,0,sizeof(vis));
        check=0;
        for(int i=0; i<n; i++){
            if(head[i]=='b'){
                vis[i]=1;
                dfs(i);
                vis[i]=0;
            }
            if(check==1) break;
        }
        if(check==0) cout<<"No."<<endl;
        if(check==1) cout<<"Yes."<<endl;
    }
    return 0;
}