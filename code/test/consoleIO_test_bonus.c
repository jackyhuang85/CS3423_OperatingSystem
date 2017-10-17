#include "syscall.h"

int main(void){
  int n;
  
  for (n = -5; n < 0; n++){
    PrintInt(n);
  }
  Halt();
}
