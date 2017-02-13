#include <iostream>
using namespace std;

int getLastMatchPairIndex(const string& str){
  if(str.length() <= 1){
    return -1;
  }

  int matchPair = -1;
  int extraTag = -1;
  for(int i = 0; i < str.length(); i++){
    int a = str[i];
    int b = 0;
    if( i < str.length()-1){
      b = str[i+1];
    }

    if(b-a == 32){
      //matchPair found
      matchPair = i+1;
      i++;
    }
    else{
      if(extraTag < 0){
        extraTag = i;
      }
      else{
        int c = str[extraTag];
        if(a-c == 32){
          matchPair = i; i++;
          extraTag--;
        }
        else{
          break;
        }
      }
    }
  }
  return matchPair;
}


int main(){

  string line;
  while(getline(cin, line)){
    int index = getLastMatchPairIndex(line);
    cout << line << "  " << index << endl;
  }

  return 0;
}
