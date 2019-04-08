#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int c[1005]={0};
        int w[1005]={0};
        int dp[1005]={0};
        int N,V;
        cin>>N>>V;
        for(int i=1;i<=N;i++){
            cin>>w[i];
        }
        for(int i=1;i<=N;i++){
            cin>>c[i];
        }
        for(int i=1;i<=N;i++){
            for(int j=V;j>=0;j--){
                if(j<c[i]) break;
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
            }
        }
        cout<<dp[V]<<endl;
    }
    return 0;
}