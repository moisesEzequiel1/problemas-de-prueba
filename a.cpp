#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std; 


class Scoreboard {
  public: 
    int aux = 0 ; 
    int puntosjugador1 = 0 ; 
    int puntosjugador2 = 0; 
    vector<int> lider1puntuaje, lider2puntuaje; 
    void solve(int n1, int n2); 
    void printresult();

}; 

void Scoreboard::solve(int n1, int n2) { 
  puntosjugador1 += n1;
  puntosjugador2 += n2;
  int aux = puntosjugador1 - puntosjugador2; 
  if (aux > 0){
    lider1puntuaje.push_back(aux); 
  }else if ( aux < 0 ){
    lider2puntuaje.push_back(abs(aux)); 
  }
}
void Scoreboard::printresult () { 
  int ventajajugador1 = *max_element(lider1puntuaje.begin(), lider1puntuaje.end());
  int ventajajugador2 = *max_element(lider2puntuaje.begin(), lider2puntuaje.end());
  if (ventajajugador1 > ventajajugador2){
    cout << "1 " << ventajajugador1 <<endl;
  }else{ 
    cout << "2 " << ventajajugador2 <<endl;
  }

}
int main(int argc, char** argv) { 
  string inFile = "";
  if( argc == 2 ) {
    inFile = argv[1];
  }else{
      cout << "uso: ./a  nombre_de_archivo_de_texto" << endl;
      return 1;
  }
  FILE* fp = fopen(inFile.c_str(),"r");
  if (fp == NULL)
	exit(EXIT_FAILURE);

  Scoreboard scoreboard;
  char* line = NULL;
  size_t len = 0;
  int v1, v2;

  int index = 0;
  while ((getline(&line, &len, fp)) != -1) {
	if (index > 0){
     stringstream lineStream(line); 
     lineStream >> v1;
     lineStream >> v2;
     scoreboard.solve(v1, v2);
	}
    index++; 
  }
  scoreboard.printresult();
}




