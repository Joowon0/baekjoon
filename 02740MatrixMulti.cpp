#include <iostream>

using namespace std;

int main() {
  int Ar, Ac, A[100][100];
  int Br, Bc, B[100][100];
  int temp;

  // get inputs
  cin >> Ar >> Ac;
  for (int i = 0; i < Ar; i++)
    for (int j = 0; j < Ac; j++)
      cin >> A[i][j];

  cin >> Br >> Bc;
  for (int i = 0; i < Br; i++)
    for (int j = 0; j < Bc; j++)
      cin >> B[i][j];

  // multiply
  // for every column for result
  for(int i = 0; i < Ar; i++) {
    for(int j = 0; j < Bc; j++) {
      temp = 0;

      //cout << endl << "For result [" << i << "][" << j << "]" << endl;
      
      // calculate
      for(int a = 0; a < Ac; a++) {
	//cout << "A[" << i << "][" << a << "] * B[" << a << "][" << j << "] : "
	//     << A[i][a] << " * " << B[a][j] << " = " << (A[i][a] * B[a][j]) << endl;
	temp += A[i][a] * B[a][j];
       
      }

      cout << temp << " ";
    }
    cout << endl;
  }
  
  return 0;
}
