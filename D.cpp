#include<bits/stdc++.h>
#define pb push_back
#define MAX (int)1e5+1
using namespace std;
struct unionfind {
int p[MAX], r[MAX]; // r contains the population
unionfind() { for(int i=0;i<MAX;i++) p[i] = i, r[i] = 1; }
int find( int x ) { if( p[x] == x ) return x; else return p[x] = find( p[x] ); }
void Union(int x, int y) {
int px = find( x ), py = find( y );
if( px == py ) return; //already joined
if( r[ px ] < r[ py ] ) p[px] = py, r[py] += r[px];
else p[ py ] = px, r[px] += r[py];
}
};
int main(){
    int n,m;
    unionfind u;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;scanf("%d %d",&a,&b);
        a--;b--;
        u.Union(a,b);
    }
    set<int> p;
    for(int i =0;i<n;i++) p.insert(u.find(i));
    cout<<p.size()-1<<endl;
    for(auto i = p.begin();next(i,1)!=p.end();i++){
        printf("%d %d\n",*i+1,1+*next(i,1));
    }


}
