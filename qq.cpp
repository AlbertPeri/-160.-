#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector < vector<int> > g(n);
   for(int i =0; i < n; i++){
     for(int j = 0; j < n; j++){
       int a;
       cin >>a;
       if(a){
         g[i].push_back(j);
       }
     }
   }
   int st, en;
   cin >> st >> en;
   if(st == en){
     cout << 0;
     return 0;
   }
   st--;
   en--;
   queue< int > q;
   vector <int> used(n);
   used[st] = 1;
   q.push(st);
   vector <int> pred(n);
   pred[st] = -1;
   while(!q.empty()){
     auto e = q.front();
     q.pop();
     if(e == en){
       break;
     }
     for(int i = 0; i < g[e].size(); i++){
       int to = g[e][i];
       if(!used[to]){
         used[to] = 1;
         pred[to] = e;
         q.push(to);
       }
     }
   }
   vector<int> path;
   queue<int> qq;
   qq.push(en);
   if(!used[en]){
     cout << -1;
     return 0;
   }
   while(!qq.empty()){
     auto e = qq.front();
     qq.pop();
     path.push_back(e);
     if(e != st){
       qq.push(pred[e]);
     }
   }
   cout << path.size() - 1<<"\n";
   reverse(path.begin(), path.end());
   if(path.size() == 0){
     cout << 0;
     return 0;
   }
    for(auto e: path){
     cout << e+1<< " ";
   }
}