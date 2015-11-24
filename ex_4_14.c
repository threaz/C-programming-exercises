#include <stdio.h>

#define swap(t,x,y) {t temp = x; x = y; y = temp;}
#define valPrint(x, y) printf(#x " = %d\n" #y " = %d\n", x, y)

int main(){
  
  int x = 10, y = 20;
  int temp = 111;
  valPrint(x, y);
  swap(int, y, x);
  valPrint(x, y);
  
  return 0;
}
