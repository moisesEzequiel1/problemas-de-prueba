#include <iostream>
using namespace std; 


int n1, n2, diff[2], lider = 0;

void solve() { 
  cin >> n1 >> n2;  
  diff[0] = n1 - n2;
  if ( diff[0] > 0){ 
    lider = 1; 
    if (diff[1] < diff[0]){
      diff[1] = diff[0];

    }
  }
  if(diff[0] < 0){
    if (diff[1] < abs(diff[0])){
      diff[1] = abs(diff[0]);
      lider = 2;
    }
  }
}

int main() { 
  ios::sync_with_stdio(0); 
  cin.tie(0); 

  int t;

  cin >> t ; 
  while(t--)  {
    solve(); 
  }
  cout << lider << " " << diff[1] << endl;

}



