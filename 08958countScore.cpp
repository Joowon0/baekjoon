#include <iostream>
#include <string>

using namespace std;

int main() {
  int caseNum;
  string str;
  int temp, sum;

  cin >> caseNum;

  while(caseNum--) {
    cin >> str;

    sum = 0; temp = 0;
    for (int i = 0; i < str.length(); i++) {
      //cout << str[i];
      if (str[i] == 'O') {
	temp++;
	sum += temp;
      }
      else {
	temp = 0;
      }
    }
    cout << sum << endl;
  }
  
  return 0;
}
