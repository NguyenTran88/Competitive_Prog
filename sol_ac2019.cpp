#include <iostream>  

int numTest; 
int n, D; 
char a[20][20];                 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> D >> n;
    D = 15;
    std::cout << D << ' ' << D << std::endl;     
    for (int i = 1; i <= D; i++) {
      for (int j = 1; j <= D; j++) {
        a[i][j] = 'C';
        if (j % 4 == 1) {
          a[i][j] = 'A';
        } 
      } 
    }
    for (int i = 2; i < D; i++) {
      for (int j = 2; j <= D; j += 2) {
        if (n >= 3) {
          a[i][j] = 'B';
          n -= 3;  
        }
      }
    }
    for (int j = 2; j <= D; j += 2) {
      if (n > 0) {
        a[1][j] = 'B';
        n--;
      }
      if (n > 0) {
        a[D][j] = 'B';
        n--;
      }
    }
    for (int i = 1; i <= D; i++) {
      for (int j = 1; j <= D; j++) {
        std::cout << a[i][j];
      }
      std::cout << std::endl; 
    }
  }
  return 0; 
}