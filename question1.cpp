//
#include <bits/stdc++.h>
using namespace std;

long mean(vector<long> grades){
    return accumulate(begin(grades), end(grades), (long)0)/grades.size();
}

long median(vector<long> grades, int size){
    sort(begin(grades), end(grades));
    
    if(size % 2 != 0){
        return grades[size/2];
    }
    
    int a = size/2;
    int b = a + 1;
    
    return (grades[a] + grades[b])/2; 
}

pair<vector<string>, int> mode(vector<string> names, vector<long> grades){
    unordered_map<int, int> freq;
    
    for(int i=0; i<grades.size(); i++)
        freq[grades[i]]++;
    
    int key, val = 0;
    for(auto& p: freq){
        if(p.second > val)
            key = p.first;
    }
    
    pair<vector<string>, int> ans;
    vector<string> studentsWithMode;
    for(int i=0; i<grades.size(); i++){
        if(grades[i] == freq[key])
            studentsWithMode.push_back(names[i]);
    }
    
    return ans;
}

int main()
{
    vector<string> names; 
    vector<long> grades;
    
    int size; 
    cin>>size;
    
    string name;
    int grade;
    
    for(int i=0; i<size; i++){
        cin>>name>>grade;   // enter name and grades of student

        names.push_back(name);// name is going to be entered in the end of names vector using push ... 
        
        grades.push_back(grade);// grades is going to be entered in the end of grades vector using push ... 
    }
    
    cout<<"mean: "<<mean(grades)<<endl; // calling mean function

    cout<<"median: "<<median(grades, size)<<endl; // calling median  function
    
    pair<vector<string>, int> p = mode(names, grades);
    cout<<"mode: "<<p.second<<endl<<"students with the mode ";
    for(int i=0; p.first.size(); i++){
        cout<<p.first[i]<<" ";
    }
        
    return 0;
}