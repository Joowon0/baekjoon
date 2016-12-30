#include <stdio.h>
#include <stdlib.h>

int parS();
int parB();

char par[30];
int i;

// for ()
int parS() { 
  if (par[i+1] == ')') { // start with ()
    i++;
    return 2;
  }
  else {
    int maxIn = 0, temp;
    while (par[i+1] != ')') {
      if (par[i+1] == '(') { // start with ((
        i++;
	temp = parS();
      }
      else if (par[i+1] == '[') { // start with ([
        i++;
	temp = parB();
      }
      else  { // wrong input;
	printf("0\n");
	exit(EXIT_FAILURE);
      }

      maxIn += temp;
    }
    i++;
    
    return maxIn * 2;
  }
}

// for []
int parB() {
  if (par[i+1] == ']') { // start with []
    i++;
    return 3;
  }
  else {
    int maxIn = 0, temp;
    while (par[i+1] != ']') {
      if (par[i+1] == '(') { // start with [(
	i++;
	temp = parS();
      }
      else if (par[i+1] == '[') { // start with [[
	i++;
	temp = parB();
      }
      else  { // wrong input;
	printf("0\n");
	exit( EXIT_FAILURE);
      }

      maxIn += temp;
    }
    i++;

    return maxIn * 3;
  }
}



int main() {
  
  scanf("%s", par);

  i = -1;
  int maxIn = 0, temp;
  while (par[i+1] == '(' || par[i+1] == '[') {
    if (par[i+1] == '(') {
      i++;
      temp = parS();
    }
    else if (par[i+1] == '[') {
      i++;
      temp = parB();
    }
    else  { // wrong input;
      printf("0\n");
      return 0;
    }

    maxIn += temp;
  }

  printf("%d\n", maxIn);
  
  return 0;
}
