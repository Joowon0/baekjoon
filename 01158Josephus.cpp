#include <iostream>

using namespace std;

int main() {
  int pplNum, cntNum;
  int ppl[2000000], front, rear;
  int tempCnt;

  cin >> pplNum >> cntNum;

  for (int i = 0; i < pplNum; i++)
    ppl[i] = i+1;
  
  front = 0; rear = pplNum;
  /*
  for (int i = front; i < rear; i++)
    cout << ppl[i] << " ";
  cout << endl;
  */
  cout << "<";
  tempCnt = cntNum;
  while(front != rear) {
    tempCnt--;
    
    // erase a person
    if (tempCnt == 0) {
      cout << ppl[front];
      if (rear-front > 1)
	cout << ", ";
      front++;
      tempCnt = cntNum;
      //copy to front
      for (int i = 0; i < rear - front; i++) {
	ppl[i] = ppl[front+i];
      }
      rear = rear-front; front = 0;
    }
    // go over
    else {
      ppl[rear] = ppl[front];
      front++; rear++;
    }
  }
  cout << ">"<< endl;; 
  
  return 0;
}
