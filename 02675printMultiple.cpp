#include <iostream>
#include <string>

using namespace std;

int main() {
  int caseNum, n;
  string str;

  cin >> caseNum;
  
  while(caseNum--) {
    cin >> n >> str;

    for (int i = 0; i < str.length(); i++) {
      for (int j = 0; j < n; j++)
	cout << str[i];
    }
    cout << endl;
  }
  
  return 0;
}
