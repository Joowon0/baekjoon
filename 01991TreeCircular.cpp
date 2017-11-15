#include <iostream>

using namespace std;

// 0 - left child
// 1 - right child
int alpha[27][2];
int caseNum;

void print() {
  for (int i = 0; i < 26; i++)
    cout << (char)(i+'A') << " : "
	 << (char)(alpha[i][0]+'A') << " "
	 << (char)(alpha[i][1]+'A') << endl;
}

void preCir(int index) {
  cout << (char)(index+'A');
  if (alpha[index][0] != -1)
    preCir(alpha[index][0]);
  if (alpha[index][1] != -1)
    preCir(alpha[index][1]);
}

void midCir(int index) {
  if (alpha[index][0] != -1)
    midCir(alpha[index][0]);
  cout << (char)(index+'A');
  if (alpha[index][1] != -1)
    midCir(alpha[index][1]);
}

void postCir(int index) {
  if (alpha[index][0] != -1)
    postCir(alpha[index][0]);
  if (alpha[index][1] != -1)
    postCir(alpha[index][1]);
  cout << (char)(index+'A');
}

int main() {
  cin >> caseNum;

  for (int i = 0; i < 26; i++)
    alpha[i][0] = alpha[i][1] = -1; // sign of not using

  char temp1, temp2, temp3;
  for (int i = 0; i < caseNum; i++) {
    cin >> temp1 >> temp2 >> temp3;
    if (temp2 != '.')
      alpha[temp1 -'A'][0] = temp2-'A';
    if (temp3 != '.')
      alpha[temp1 -'A'][1] = temp3-'A';
  }

  preCir(0);
  cout << endl;
  midCir(0);
  cout << endl;
  postCir(0);
  cout << endl;

  //print();
    
  
  return 0;
}
