#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int nineDwarf[9];

	for (int i = 0; i < 9; i++)
		scanf("%d", &nineDwarf[i]);

	sort(nineDwarf, nineDwarf + 9);

	for (int a = 0; a < 8; a++) {
		for (int b = a + 1; b < 9; b++) {

			// check if sum is 100
			int sum = 0;
			for (int i = 0; i < 9; i++)
				if (i != a && i != b)
					sum += nineDwarf[i];

			// if sum is 100, print and end
			if (sum == 100) {
				for (int i = 0; i < 9; i++)
					if (i != a && i != b)
						printf("%d\n", nineDwarf[i]);
				return 0;
			}
			
		}
	}

	return 0;
}
