#include <iostream>

using namespace std;

int main() {
	int madeNum, lenCntr = 1, numLen = 0;
	scanf("%d", &madeNum);

	// find out the length of num
	for (int i = 0; i < 7; i++) {
		if (madeNum % lenCntr == 0)
			break;

		lenCntr = lenCntr * 10;
		numLen ++;
	}

	int startNum = madeNum - numLen * 10;
	// for all range
	for (int i = startNum; i <= madeNum; i++) {
		int intoNum = madeNum;
		// for all status
		for (int j = 0; j < numLen; j++)
			intoNum += madeNum 
	}	
	
	return 0;
}
