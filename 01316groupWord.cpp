#include <iostream>
#include <string>

using namespace std;

int main() {
  int caseNum, c = 0;
  string str;
  bool alpha[26]; // check if used
  char b4;
  bool ifGroup;

  cin >> caseNum;

  while(caseNum--) {
    cin >> str;

    for (int i = 0; i < 26; i++)
      alpha[i] = 0;

    ifGroup = 1;

    b4 = str[0];
    alpha[str[0]-'a'] = 1;
    for (int i = 1; i < str.length(); i++) {
      if (b4 == str[i]) // skip
	;
      else {
	//cout << str[i] << " " << (str[i]-'a') << " " << alpha[str[i]-'a'] << endl;
	if (alpha[str[i]-'a'] == 1) { // break
	  //cout << "asdfasdf" << endl;
	  ifGroup = 0;
	  break;
	}
	else { // new alphabet
	  b4 = str[i];
	  alpha[str[i]-'a'] = 1;
	}
      }
    }

    if (ifGroup == 1)
      c++;
  }
  
  cout << c << endl;
  
  return 0;
}
