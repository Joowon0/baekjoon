#include <iostream>

using namespace std;

int main() {
  int nth, isFirst[11] = {0,0,0,0,0,0,0,0,0,0,0};
  cin >> nth;

  if (nth > 1022) {
    cout << -1 << endl;
    return 0;
  }

  for (int s10 = 0; s10 < 10; s10++) {
    int limit9 = s10;
    if (isFirst[10] == 0)
      limit9 = 10;
    for (int s9 = 0; s9 < limit9; s9++) {
      int limit8 = s9;
      if (isFirst[9] == 0)
	limit8 = 10;
      for (int s8 = 0; s8 < limit8; s8++) {
	int limit7 = s8;
	if (isFirst[8] == 0)
	  limit7 = 10;
	for (int s7 = 0; s7 < limit7; s7++) {
	  int limit6 = s7;
	  if (isFirst[7] == 0)
	    limit6 = 10;
	  for (int s6 = 0; s6 < limit6; s6++) {
	    int limit5 = s6;
	    if (isFirst[6] == 0)
	      limit5 = 10;
	    for (int s5 = 0; s5 < limit5; s5++) {
	      int limit4 = s5;
	      if (isFirst[5] == 0)
		limit4 = 10;
	      for (int s4 = 0; s4 < limit4; s4++) {
		int limit3 = s4;
		if (isFirst[4] == 0)
		  limit3 = 10;
		for (int s3 = 0; s3 < limit3; s3++) {
		  int limit2 = s3;
		  if (isFirst[3] == 0)
		    limit2 = 10;
		  for (int s2 = 0; s2 < limit2; s2++) {
		    int limit1 = s2;
		    if (isFirst[2] == 0)
		      limit1 = 10;
		    for (int s1 = 0; s1 < limit1; s1++) {
		      if (nth == 0) {
		      //cout << s10 << s9 << s8 << s7 << s6 << s5 << s4 << s3 << s2 << s1 << endl;
		      cout << (long)s10*1000000000 + s9*100000000 + s8*10000000 + s7*1000000 + s6*100000 + s5*10000 + s4*1000 + s3*100 + s2*10 + s1 << endl;
		      
			return 0;
		      }
		      nth--;

		    }
		    if (isFirst[2]++ == 0)
		      ;
		  }
		  if (isFirst[3]++ == 0)
		    s3 ++;
		}
		if (isFirst[4]++ == 0)
		  s4 += 2;
	      }
	      if (isFirst[5]++ == 0)
		s5 += 3;
	    }
	    if (isFirst[6]++ == 0)
	      s6 += 4;
	  }
	  if (isFirst[7]++ == 0)
	    s7 += 5;
	}
	if (isFirst[8]++ == 0)
	  s8 += 6;
      }
      if (isFirst[9]++ == 0)
	s9 += 7;
    }
    if (isFirst[10]++ == 0) 
      s10 += 8;
  }
  
  return 0;
}
