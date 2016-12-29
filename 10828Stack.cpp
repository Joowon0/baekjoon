#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
  int stack[10000];
  int ptr;
public:
  Stack() : ptr(0) {}
  // if ptr == 0, nothing is inside
  // memory starts from index 1
  // ptr points the last memory
  
  void push(int x) {
    ptr++;
    stack[ptr] = x;
  }
  int pop () {
    if (empty())
      return -1;
    else {
      ptr--;
      return stack[ptr+1];
    }
  }
  int size() {
    return ptr;
  }
  int empty() {
    if (ptr == 0)
      return 1;
    else
      return 0;
  }
  int top() {
    if (empty())
      return -1;
    else
      return stack[ptr];
  }
};

int main() {
  int caseNum, newVal;
  string inst;
  Stack* s = new Stack();

  cin >> caseNum;
  while(caseNum--) {
    cin >> inst;
    if (!inst.compare("push")) {
      cin >> newVal;
      s->push(newVal);
    }
    else if (!inst.compare("pop")) {
      cout << s->pop() << endl;
    }
    else if (!inst.compare("size")) {
      cout << s->size() << endl;
    }
    else if (!inst.compare("empty")) {
      cout << s->empty() << endl;
    }
    else if (!inst.compare("top")) {
      cout << s->top() << endl;
    }
  }

  return 0;
}
