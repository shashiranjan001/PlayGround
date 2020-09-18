#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

int main(){
    IOS;
    ull t, n;
    cin>>t;
    // cout<<"t = "<<t<<endl;
    while(t--){
        cin>>n;
        // cout<<"n = "<<n<<endl;
        vector<ull> arr(n);
        for(ull i=0; i<n; i++) cin>>arr[i];

        vector<pair<ull, ull>> margins;
        for(ull i=0; i<n; i++) margins.push_back({0,0});
        stack<pair<ull, ull>> sl, sr;

       
        margins[0].first = 0;
        sl.push({arr[0], 0});
        
        for(ull i=1; i<n; i++){
            while(sl.size() && sl.top().first>arr[i]) sl.pop();
            if(sl.size())   margins[i].first = i-sl.top().second-1;
            else margins[i].first = i;
            sl.push({arr[i], i});
        }
        

        margins[n-1].second = 0;
        sr.push({arr[n-1], n-1});

        for(ull i=n-2; i>=0; i--){
             while(sr.size() && sr.top().first>arr[i]) sr.pop();
             if(sr.size()) margins[i].second = sr.top().second-i-1;
             else margins[i].second = n-1-i;
             sr.push({arr[i], i});
        }

        unsigned long long ans =0;
        // for(ull i=0; i<n; i++){
        //     cout<<margins[i].first<<" "<<margins[i].second<<endl;
        // }

        for(ull i=0; i<n; i++){
            ans += 1ULL*arr[i]*(margins[i].first+1)*(margins[i].second+1);
        }
        cout<<ans<<endl;
    }
}