/*
yash gautam -- 2010991346
test-02
program to sort a map based on values 
*/
#include <bits/stdc++.h>
using namespace std;

bool camp(pair<int, int> a, pair<int, int> b){
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

vector<pair<int, int>> sortbymap(unordered_map<int, int>& mp){
    vector<pair<int, int>> vect;              // vector vect is intialized to perform sorting
    
    for(auto& p: mp)
        vect.push_back(p);
        
    sort(begin(vect), end(vect), camp);
    return vect;
}

int main()
{
    unordered_map<int, int> map;
    
    int n;                                             // n used to define size
    cin>>n ;
    int x, y;
    for(int i=0; i<n; i++){
        cin>>x>>y;
        map[x] = y;
    }
    
    vector<pair<int, int>> ans = sortbymap(map);      //function named sortbymap is called..
    for(auto& z: ans){
        cout<<z.first<<" "<<z.second<<endl;           //value is going to be printed  that has been entered by users..
    }
    
    return 0;
}
