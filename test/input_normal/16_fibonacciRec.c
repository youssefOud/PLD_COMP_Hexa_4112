#include <stdio.h>
#include <string.h>

int fib(int n){
  int a;
  int b;
  if (n < 2){
    return n;
  }
  else{
    a = fib(n-1);
    b = fib(n-2);
    return a + b;
    
  }
}

int main()
{
    int a = 7;
    int nbLapin = fib(a);
    return nbLapin;
}
