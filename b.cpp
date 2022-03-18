#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
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
string checkmsg(string &crypt_msg, string &msg ) {
  if (crypt_msg.find(msg) != string::npos) {
	return	"Si" ;
  }else{ 
	return	"No";
  }
}

int main() { 
  FILE* fp = fopen("entradaB.txt", "r");
  if (fp == NULL)
	exit(EXIT_FAILURE);

  vector<string> v;
  char* line = NULL;
  size_t len = 0;
  int i = 0; 
  while ((getline(&line, &len, fp)) != -1) {
	if (i>0){
	  v.push_back(line);
	}
	i++;
  }

  for (int b = 0; b < v.size();b++){ 
	v[b].erase(prev(v[b].end()));
  }
  string aux = removeDuplicates(v.back()); 
	
  for (int z = 0; z < v.size()-1; z++){
    cout<< checkmsg(aux, v[z]) << " MSG: "<< v[z] <<endl;
  }


}



