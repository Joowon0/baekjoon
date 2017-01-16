#include <iostream>
#include <string>

using namespace std;

int main() {
  string str;
  int al[26];

  cin >> str;

  for (int i = 0; i < 26; i++)
    al[i] = 0;

  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') { // lower case
      al[str[i]-'a']++;
    }
    else { // uppper case
      al[str[i]-'A']++;
    }
  }
  /*
  for (int i = 0; i < 26; i++)
    cout << al[i] << " ";
    cout << endl;
  */

  int m = 0;
  char mc;

  for (int i = 0; i < 26; i++) {
    if (m < al[i]) {
      m = al[i];
      mc = i + 'A';
    }
  }
  

  for (int i = 0; i < 26; i++) {
    if ((m == al[i]) && (mc != i+'A')) {
      cout << "?" << endl;
      return 0;
    }
  }
  
  cout << mc << endl;
  
  
  return 0;
}
