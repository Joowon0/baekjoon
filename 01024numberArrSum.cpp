#include <iostream>

using namespace std;

int sums (int start, int end) {
  /*
  cout << start << " " << end << " : "
       << (end - start + 1) << " " << (end + start) << " "
       << (end - start + 1) * ((end + start) / 2) << endl;
  */
  return (long long int) (end - start + 1) * (end + start) / 2;
}

int main() {
  int sum, minLen;
  int a =  -1, b = 1000000001;
  int l;

  cin >> sum >> minLen;


  for (int m = minLen; m <= 100; m++) {
    // the start num doesn't go over average - length
    l = sum / m - m;

    if (l < 0)
      l = 0;

    //cout << "length : " << m << " start index : " << l << endl;
    
    // search
    for (int i = l; i <= sum; i++) {
	int s = sums(i, i + m - 1);
	
	//cout << "memo[" << i << "][" << i + m - 1 << "] = " << s << endl;
	
	// find match
	if (s == sum ) {
	  a = i; b = i + m;
	  break; // no more match in the row
	}
	// search other row
	else if (s > sum)
	  break;

    }

    // found
    if (a != -1 && b != 1000000001) {
      for (int i = a; i < b; i++)
	cout << i << " ";
      cout << endl;
      return 0;;
    }
    
  }
 
  cout << -1 << endl;
  
  
  return 0;
}
