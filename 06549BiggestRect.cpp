#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int caseNum;
  int hTemp;
  
  while(1) {
    cin >> caseNum;
    
    //end case
    if (caseNum == 0)
      return 0;

    vector <int> h, h2; // h2 is the checking points
    
    for (int i = 0; i < caseNum; i++) {
      cin >> hTemp;
      h.push_back(hTemp);
      h2.push_back(hTemp);
    }

    std::sort (h2.begin(), h2.end());
    h2.erase (std::unique(h2.begin(), h2.end()), h2.end());

    /*
    // print for test
    for (vector<int>::iterator i = h.begin(); i != h.end(); i++)
      cout << *i << " ";
    cout << endl;
    for (vector<int>::iterator i = h2.begin(); i != h2.end(); i++)
      cout << *i << " ";
    cout << endl;
    */
    
    // calculate
    int c = 0, m = 0, m2 = 0;
    for (vector<int>::iterator i = h2.begin(); i != h2.end(); i++) {
      for (vector<int>::iterator j = h.begin(); j != h.end(); j++) {
	if (*j >= *i)
	  c++;
	else {
	  if (m < c)
	    m = c;
	  c = 0;
	}
      }
      // check the last one
      if (m < c)
	m = c;

      // update with actual width
      if (m2 < m * (*i))
	m2 = m * (*i);
      m = 0;
      c = 0;
    }

    cout << m2<< endl;
  }

  
  
  return 0;
}
