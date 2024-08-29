#include<iostream>
using namespace std;
int n, m;
int path[10]; 

void run(int lev, int start){
    if(lev==m){
        for(int i=0; i<lev; i++){
            cout << path[i] <<" "; 
        }        
        cout << "\n"; 
        return; 
    }
    
    for(int i=start; i<=n;i++){
        path[lev]=i; 
        run(lev+1, i); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cin>>n>>m; 
    
    run(0,1); 
    return 0; 
}