//#CF round 387
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+7;
vector<int> isprime(N,1);
vector<int> prime;
void sieve(int n){
    for(int i = 2;i<=n;i++){
        if(isprime[i] == 1){
            prime.push_back(i);
            for(int j = i*i;j<=n;j+=i){
                isprime[j] = 0;
            }
        }
    }
}
void solve(int arr[],int n){
    unordered_set<int>st;
    for(int i = 0;i<n;i++){
        int temp = arr[i];
        for(int j = 0;j<prime.size();j++){
            if(temp%prime[j] == 0){
                if(!st.empty()){
                    if(st.find(prime[j]) != st.end()){
                        cout<<"YES"<<endl;
                        return;
                    }
                }
                st.insert(prime[j]);
            }
            while(temp%prime[j] == 0){
                temp = temp/prime[j];
            }
            if(temp != 1){
                if(!st.empty()){
                    if(st.find(temp) != st.end()){
                        cout<<"YES"<<endl;
                        return;
                    }
                }else{
                    st.insert(temp);
                    temp = 1;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    sieve(sqrt(1e9));
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
    }
    return 0;
}
