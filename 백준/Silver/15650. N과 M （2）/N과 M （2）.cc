#include<iostream>
using namespace std;
int n, m;
int path[10]; 
int used[10]; 

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
        run(lev+1, i+1);
    }
}

int main(){
    cin>>n>>m; 
    
    run(0,1); 
    return 0; 
}