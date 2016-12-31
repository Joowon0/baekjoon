#include <iostream>

using namespace std;


int main() {
  int caseNum, docNum, wantToknow;
  int docs[10000][2], front, rear;
  int countPrint;

  cin >> caseNum;

  while(caseNum--) {
    // get input
    cin >> docNum >> wantToknow;

    for (int i = 0; i < docNum; i++) {
      docs[i][0] = i;
      cin >> docs[i][1];
    }

    front = 0; rear = docNum ;
    countPrint = 0;

    while (1) {
      /*
      cout << "front : " << front << "\trear : " << rear<< endl;
      for (int i = front; i < rear; i++)
	cout << docs[i][0] << " " << docs[i][1] << endl;
      cout << endl;
      */
      int printFlag = 0;
      // need to go back
      for (int i = front; i < rear; i++) {
	if (docs[i][1] > docs[front][1]) {
	  //cout << "move back" << endl;
	  docs[rear][0] = docs[front][0];
	  docs[rear][1] = docs[front][1];
	  front++; rear++;

	  printFlag = 1;
	  break;
	}
      }
      if (printFlag == 1)
	continue;

      // if not go back
      // check if it is answer
      if (docs[front][0] == wantToknow) {
	cout << countPrint + 1 << endl;
	//cout << "end case" << endl << endl;
	break;
      }
      //print
      front++;
      countPrint++;
    }
  }
  
  return 0;
}
