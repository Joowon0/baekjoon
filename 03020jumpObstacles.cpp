#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int length, height, temp;
  cin >> length >> height;

  
  int halfLen = length / 2;
  vector<int> up(height + 1), down(height + 1);
  for (int i = 0; i < halfLen; i++) {
    cin >> temp;
    up[temp]++;
    
    cin >> temp;
    down[temp]++;
  }

  vector<int> lanes(height + 1);
  int cnt = halfLen;
  for (int i = 1; i < height; i++) {
    lanes[i] += cnt;
    cnt -= up[i];
  }
  //for (int i = 1; i <= height; i++)
  //  cout << i << " "<< up[i] << " " << lanes[i] << endl;
  //cout << endl;

  
  cnt = halfLen;
  for (int i = 1; i < height; i++) {
    lanes[height - i + 1] += cnt;
    cnt -= down[i];
  }
  //for (int i = 1; i <= height; i++)
  //  cout << i << " "<< down[i] << " " << lanes[i] << endl;
  //cout << endl;

  
  sort(lanes.begin(), lanes.end());
  
  int min = lanes[1];
  int i = 2;
  int times = 1;
  while(lanes[i] == min && i <= height) {
    times++;
    i++;
  }

  cout << min << " " << times << endl;
  
  return 0;
}
