#include <iostream>

using namespace std;

int caseNum;
int inTemp[10002][2];
int place [10002][2], index=0;
int maxLevel = 1;
// 0 - node num
// 1 - level

void print() {
  for (int i = 1; i <= caseNum; i++)
    cout << i << " : "
	 << inTemp[i][0] << " "
	 << inTemp[i][1] << endl;
}

void print2() {
  for (int i = 0; i < index; i++)
    cout << i << "\tlevel : " << place[i][1] << "\tNum : " << place[i][0] << endl;
}

void getIn(int node, int level){
  if(inTemp[node][0] != -1)
    getIn(inTemp[node][0], level + 1);
  
  place[index][0] = node;
  place[index][1] = level;
  index++;
  if (maxLevel < level)
    maxLevel = level;

  if(inTemp[node][1] != -1)
    getIn(inTemp[node][1], level + 1);
}

int main() {
  cin >> caseNum;
  int temp;
  for (int i = 0; i < caseNum; i++) {
    cin >> temp;
    cin >> inTemp[temp][0] >> inTemp[temp][1];
  }

  //print();

  getIn(1, 1);

  //print2();

  int bigLevel = 1, bigRange = 0;
  // for every level
  for (int l = 1; l <= maxLevel; l++) {
    int min, max;
    // find min Index
    for (int i = 0; i < index; i++)
      if (place[i][1] == l) {
	min = i;
	break;
      }

    // find max Index
    for (int i = index-1; i >= 0; i--)
      if (place[i][1] == l) {
	max = i;
	break;
      }

    int range = max - min + 1;
    // update if largest
    if (bigRange < range) {
      bigLevel = l;
      bigRange = range;
    }

    /*
    cout << "Level : " << l
	 << "\trange : " << max - min + 1
	 << "\tmin : " << min
	 << "\tmax : " << max << endl;*/
  }

  cout << bigLevel << " " << bigRange << endl;
  
  return 0;
}
