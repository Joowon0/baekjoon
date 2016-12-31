#include <iostream>
#include <string.h>

using namespace std;

class Queue {
private:
  int queue[10000];
  int f, r;
public:
  Queue() : f(0), r(0) {}
  
  void push(int x) {
    queue[r++] = x;
  }
  int pop() {
    if (f == r)
      return -1;
    else {
      f++;
      return queue[f - 1];
    }
  }
  int size() {
    return r - f;
  }
  int empty() {
    if (f == r)
      return 1;
    else
      return 0;
  }
  int front() {
    if (empty())
      return -1;
    else
      return queue[f];
  }
  int back() {
    if (empty())
      return -1;
    else
      return queue[r-1];
  }
};

int main() {
  Queue* q = new Queue();
  int casenum;
  char instruc[5];
  int newVal;

  cin >> casenum;

  while(casenum--) {
    cin >> instruc;
    
    if (!strcmp(instruc, "push")) {
      cin >> newVal;
      q->push(newVal);
    }
    else if (!strcmp(instruc, "pop")) {
      cout << q->pop() << endl;
    }
    else if (!strcmp(instruc, "size")) {
      cout << q->size() << endl;
    }
    else if (!strcmp(instruc, "empty")) {
      cout << q->empty() << endl;
    }
    else if (!strcmp(instruc, "front")) {
      cout << q->front() << endl;
    }
    else if (!strcmp(instruc, "back")) {
      cout << q->back() << endl;
    }
  }
  
  return 0;
}
