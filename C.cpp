#include<bits/stdc++.h>
using namespace std;
map<string,set<string>> lst;
void disp(string s,int level){
    for(int i=0;i<level;i++)cout<<"  ";
    cout<<s;
    if(!lst[s].empty())cout<<":";cout<<endl;
    for(auto i:lst[s])
        disp(i,level+1);
}
int main(){
    int N;cin>>N;getchar();
    vector<string> s(N);
    for(int i =0;i<N;getline(cin,s[i++]));
    set<string> keys;
    for(auto i:s){
        string last;
        stringstream ss(i);
       while(ss.good()) {
            string t;    getline( ss, t, '.' );
            if(!last.empty()) lst[last].insert(t);
            else keys.insert(t);

			last = t;

        }
    }
    for(auto i:keys)disp(i,0);
}
