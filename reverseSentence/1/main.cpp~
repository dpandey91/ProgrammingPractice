#include <sstream>
#include <iostream>
using namespace std;

int main(){
 
  string line;
  getline(cin, line);
  stringstream ss(line);
  
  string finalStr;
  string token;

  while(getline(ss, token, ' ')){
    token = token + " "; 
    finalStr.insert(0, token);
  }

  cout << "Final String is: " << endl;
  cout << finalStr << endl;

  return 0;
}
