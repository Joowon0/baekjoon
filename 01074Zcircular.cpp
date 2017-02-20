#include <stdio.h>
#include <math.h>

long long int circular(int x, int y, int size) {
  if (size == 1)
    return 0;

  int sizeX = size / (x+1);
  int sizeY = size / (y+1);

  //cout << x << " " << y << " " << size << " : " << sizeX << " " << sizeY << "   ";

  // up
  if (sizeX >= 2) {
    //cout << "U ";
    // left
    if (sizeY >= 2) {
      //cout << "L" << endl;
      return circular(x, y, size/2);
    }
    // right
    else {
      //cout << "R + " << size * size / 4 << endl;
      return circular(x, y - size/2, size/2) + (long long int) size * size / 4;
    }
  }
  // down
  else {
    //cout << "D ";
    // left
    if (sizeY >= 2) {
      //cout << "L + " << size * size / 2 << endl;
      return circular(x - size/2, y, size/2) + (long long int) size * size / 2;
    }
    // right
    else {
      //cout << "R + " << size * size * 3 / 4 << endl;
      return circular(x - size/2, y - size/2, size/2) + (long long int) size * size * 3 / 4;
    }
  }
}

int main() {
  int size, inX, inY;
  
  //cin >> size >> inX >> inY;
  //cout << circular(inX, inY, pow(2,size)) << endl;

  while(scanf("%d %d %d", &size, &inX, &inY)!=EOF)
    printf("%lld\n", circular(inX, inY, pow(2,size)));
  
  return 0;
}
