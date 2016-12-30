#include <iostream>
#include <string.h>

using namespace std;

int main() {
  char par[30];
  int val[30], checkpoint[30], chtmp = 0;

  cin >> par;

  for (int i = 0; i < strlen(par); i++) {
    if (par[i] == '(' || par[i] == '[') {
      val[i] = 0;
      checkpoint[chtmp++] = i;
    }
    
    else if (par[i] == ')') {
      if (val[i-1] == 0)
	val[i] = 2;
      else
	val[i] = val[i-1] * 2;
    }
    
    else if (par[i] == ']') {
      if (val[i-1] == 0)
	val[i] = 3;
      else
	val[i] = val[i-1] * 3;
    }
  }
  checkpoint[chtmp++] = strlen(par);

  int resultMax = val[checkpoint[0]-1];
  for (int i = 1; i < chtmp; i++) {
    if (resultMax < val[checkpoint[i]-1])
      resultMax = val[checkpoint[i]-1];
  }

  for (int i = 0; i < strlen(par); i++)
    cout << i << " : " << val[i] << endl;
    

  //cout << resultMax << endl;
  
  return 0;
}
