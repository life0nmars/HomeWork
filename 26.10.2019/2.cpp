#include <iostream>
#include <vector>
using namespace std;
vector <int> le1,le2;
vector <vector<bool>>am;
vector <vector<int>> g;
vector <vector<bool>> im; 
void le_to_am(int n,int m){
  am.resize(n); 
  for(int i=0;i<n;i++)am[i].resize(n);
  for(int i=0;i<m;i++){ 
    am[le1[i]][le2[i]]=1;
    am[le2[i]][le1[i]]=1;
  }
}

void le_to_g(int n,int m){
  g.resize(n); 
  for(int i=0;i<m;i++){
    g[le1[i]].push_back(le2[i]);
    g[le2[i]].push_back(le1[i]); 
  }
}
void le_to_im(int n,int m){ 
  im.resize(n); 
  for(int i=0;i<n;i++)im[i].resize(m); 
  for(int i=0;i<m;i++){ 
    im[le1[i]][i]=1;
    im[le2[i]][i]=1; 
  }
}
void am_to_g(int n,int m){
  g.resize(n); 
  for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
      if(am[i][j])g[i].push_back(j),g[j].push_back(i); 
      }
    }
 } void am_to_im(int n,int m){
    im.resize(n);
    for(int i=0;i<n;i++)im[i].resize(m);
    int k=0; 
    for(int i=0;i<n && k<m;i++){
      for(int j=i;j<n;j++){ 
        if(am[i][j]){ 
          im[i][k]=1; 
          im[j][k]=1;
          k++; 
        }
      }
    }
  }
  void am_to_le(int n,int m){
    le1.resize(m),le2.resize(m); 
    int k=0; for(int i=0;i<n;i++){ 
      for(int j=i;j<n;j++){ 
      if(am[i][j]){ 
        le1[k]=i;
        le2[k]=j;
        k++;
      }
    }
  }
 }
 void g_to_am(int n,int m){ 
  am.resize(n);
  for(int i=0;i<n;i++)am[i].resize(n);
  for(int i=0;i<n;i++){
   for(int j=0;j<g[i].size();j++){ 
    am[i][g[i][j]]=1;
    am[g[i][j]][i]=1; 
   }
  }
 } 
 void g_to_le(int n,int m){
  le1.resize(m),le2.resize(m);
  g_to_am(n,m);
  am_to_le(n,m);
 }
 void g_to_im(int n,int m){
  g_to_am(n,m);
  am_to_im(n,m);
 } 
 void im_to_le(int n,int m){
 le1.resize(m),le2.resize(m);
 int k=0; for(int i=0;i<m;i++){
 bool flag = 0;
 for(int j=0;j<n;j++){
 if(im[j][i] && !flag){
 le1[k]=j; flag = 1;
 }
 else if(im[j][i] && flag){
 le2[k]=j; k++; flag = 0;
 }
 }
 }
 }
 void im_to_am(int n,int m){
 am.resize(n);
 for(int i=0;i<n;i++)am[i].resize(n);
 for(int i=0;i<m;i++){
 for(int j=0;j<n;j++){
 if(im[j][i]){
 cout«j«" ";
 for(int k=j+1;k<n;k++){
 if(im[k][i]){
 cout«k«'\n';
 am[j][k]=1;
 am[k][j]=1;
 j = k;
 break; 
 }
 }
 break; 
 }
 }
 }
 }
 void im_to_g(int n,int m){
 g.resize(n); 
 for(int i=0;i<m;i++){
 for(int j=0;j<n;j++){
 if(im[j][i]){
 for(int k=j+1;k<n;k++){
 if(im[k][i]){
 g[j].push_back(k);
 g[k].push_back(j);
 }
 }
 }
 }
 }
 }
 int main() { 
 ios_base::sync_with_stdio(false),cin.tie(0);
 int n,m; 
 cin>>n>>m; 
 le1.resize(m),le2.resize(m);
 for(int i=0;i<m;i++){
 int x,y;
 cin>>x>>y;
 x--,y--;
 le1[i]=x,le2[i]=y;
 }
 }
