#include <iostream>

using namespace std;

int main() {
  int caseNum;
  int line, num;
  char temp[12];

  cin >> caseNum;

  while( caseNum--) {
    cin >> line >> num;

    for (int i = 0; i < line; i++) {
      for (int j = 0; j < num; j++)
	cin >> temp[j];
      for (int j = num-1; j >=0; j--)
	cout << temp[j];
      cout << endl;
    }
  }
  
  return 0;
}
