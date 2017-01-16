#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  int al[26];

  cin >> s;

  for (int i = 0; i < 26; i ++)
    al[i] = -1;

  for (int i = 0; i < s.length(); i++) {
    if (al[s[i]-'a'] == -1)
      al[s[i]-'a'] = i;
  }

  for (int i = 0; i < 26; i ++)
    cout << al[i] << " ";
  cout << endl;
  
  return 0;
}
