#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std; 

int aux, p1, p2, m1[100], m2[100];
int i,j = 0;
void solve(int n1, int n2) { 
  aux = n1 - n2;
  if ( aux > 0){ 
    p1 += aux;
    m1[i]=aux; 
    ++i; 
  }
  if(aux < 0){
    p2 += abs(aux); 
    m2[j] = abs(aux); 
    ++j; 
  }
}
void printresult( int p1, int p2 ){ 
  int n = 0 ;
  int ventaja = p1 - p2 ;
  if (p1 > p2){
    n = sizeof(m1) / sizeof(m1[0]);
    cout <<"Ganador: " <<  1 << " ventaja: " 
      << abs(ventaja) 
      <<  " pts de mejor ronda: "
      << *max_element(m1, m1 + n) 
      << endl;
  }else if (p1 < p2){ 
    n = sizeof(m2) / sizeof(m2[0]);
    cout << "Ganador: "<< 2 << " ventaja: " 
      << abs(ventaja) 
      <<  " pts de mejor ronda: "
      << *max_element(m2, m2+n) 
      << endl;
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




