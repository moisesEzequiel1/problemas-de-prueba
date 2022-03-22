#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std; 

string removeDuplicates(string &s){
   int n = s.length();
   string str;
   if (n == 0)
     return str;
 
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            str+=s[i];
        }
    }
   str.push_back(s[n-1]);
   return str;   
}
string trimfnc(string str) {
  const char* whitespaces = " \t\n\r\f\v";
  str.erase(str.find_last_not_of(whitespaces) + 1);
  str.erase(0,str.find_first_not_of(whitespaces));
  return str;
}
string checkmsg(string &crypt_msg, string &msg ) {
  if (crypt_msg.find(msg) != string::npos) {
	return	"Si" ;
  }else{ 
	return	"No";
  }
}

int main(int argc, char** argv) { 
  string inFile = "";
  if( argc == 2 ) {
    inFile = argv[1];
  }else{
      cout << "uso: ./b  nombre_de_archivo_de_texto" << endl;
      return 1;
  }
  FILE* fp = fopen(inFile.c_str(),"r");
  if (fp == NULL)
	exit(EXIT_FAILURE);

  vector<string> allmsg;
  char* line = NULL;
  size_t len = 0;
  int i = 0; 
  while ((getline(&line, &len, fp)) != -1) {
	if (i>0){
	  allmsg.push_back(line);
	}
	i++;
  }

  for (int b = 0; b < allmsg.size();b++){ 
    allmsg[b] = trimfnc(allmsg[b]);

  }
  string aux = removeDuplicates(allmsg.back()); 
	
  for (int z = 0; z < allmsg.size()-1; z++){
    cout<< checkmsg(aux, allmsg[z]) <<endl;
  }
  return 0;
}



