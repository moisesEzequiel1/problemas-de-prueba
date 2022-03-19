#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std; 

int aux, p1, p2, m[100], n, lider = 0;
int i = 0;
void solve(int n1, int n2) { 
  aux = n1 - n2;
  if ( aux > 0){ 
    p1 += aux;
    m[i] = aux; 
    ++i; 

  }
  if(aux < 0){
    p2 += abs(aux); 
    m[i] = abs(aux); 
    ++i; 
  }
  n = sizeof(m) / sizeof(m[0]);
}
void printresult( int p1, int p2 ){ 
  int winner; 
  winner = p1 - p2; 
  if (winner > 0){
    cout << 2 << " "<< *max_element(m, m + n) << endl;
  }else { 
    cout << 1 <<" "<< *max_element(m, m+n) << endl;
  }

}
void evalFile(string filename){
  FILE* fp = fopen(filename.c_str(),"r");
  if (fp == NULL)
	exit(EXIT_FAILURE);

  char* line = NULL;
  size_t len = 0;
  int v1, v2;

  int index = 0;
  while ((getline(&line, &len, fp)) != -1) {
	if (index>0){
     stringstream lineStream(line); 
     lineStream >> v1;
     lineStream >> v2;
       cout<< v1 << " " << v2 << endl;
       solve(v1, v2);
	}
    index++; 
  }

}

int main(int argc, char** argv) { 
  string inFile = "";
  if( argc == 2 ) {
    inFile = argv[1];
  }else{
      cout << "uso: ./c  nombre_de_archivo_de_texto" << endl;
      return 1;
  }
  evalFile(inFile); 
  printresult(p1, p2); 
}




