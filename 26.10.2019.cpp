//последовательность Де Брёйна
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;

map<string,set<string>> g;
set <string> w;
vector <char> a;
int l,n;
string h;

void in(string temp){
  if(temp.size()==l){
    w.insert(temp);
    return;
  }
  for(int i=0;i<n;i++){
    h=temp+a[i];
    in(h);
    h.clear();
  }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>l>>n;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    string k;
    in(k);
    string p,s;
    for(auto& x : w){
      for(int i=0;i<x.length();i++){
        if(i!=x.length()-1)p+=x[i];
        if(i!=0)s+=x[i];
      }
      g[p].insert(s);
      p.clear(),s.clear();
    }
    for(auto& x:g){
      cout<<x.first<<" : ";
      for(auto& y:x.second) cout<<y<<" ";
      cout<<'\n';
    }
}
