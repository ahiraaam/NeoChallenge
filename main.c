#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include <time.h>
#include <math.h>
#include <gmp.h>
#include <stdbool.h>


bool digitsSum(int n){  
    int temp = n;
    int module;
    int sum = 0;
    while(temp!=0)
      {
          module = temp % 10;
          sum = sum + module;
          temp= temp / 10;
      } 
    if(sum < 8 ){
      return true;
    }
    return false;
}
bool isPalindrome(int n){
  int temp = n;
  int module;
  int palindrome = 0;
   while(temp!=0)
   {
      module = temp%10;
      palindrome = palindrome*10+module;
      temp/=10;
   } 
  if(n == palindrome){
    return true;
  }
  return false;
}



void smithsAlgorithm(int m ,int p,node_t **inicio, node_t ** fin){
   

    printf("\nNeo is still alive \\(._.)/\n");

    printf("m value: %d \n",m);

    printf("p value: %d \n",p);

    char arrayPrueba[200];

    sprintf(arrayPrueba, "%f", pow(m, p));
    //printf("\nARRAY NORMAL: %s ", arrayPrueba);

    printf("\nAGENTS\n");
    for(int i=0; i<sizeof(arrayPrueba); i++){
      if (arrayPrueba[i] == '.'){
        return;

      }else{
          //append(atoi(arrayPrueba[i]),inicio,fin);
          //printf("\n\n%c", arrayPrueba[i]);

          // char to int
        int ia = arrayPrueba[i] - '0';
        //printf("\n%d", ia);

        append(ia, inicio, fin);
      }
    
    }

}

int main(void) {
  node_t * inicio =   NULL;
  node_t * fin =   NULL;

  // Cambia la semilla
  srand(time(NULL));

  // Condición de Neo
  bool neoDeath = false;
  int randomNeo= 0;
  int count = 1;
  //printf("Neo is = %d \n",neo);
  while(neoDeath==false){
    int  m = rand() % 100;
    int  p = rand() % 100;
    printf("\n\nROUND -> %d\n", count++);
    smithsAlgorithm(m,p,&inicio, &fin);
    print(inicio);
    printf("\n");
    clear(&inicio,&fin);
    randomNeo = rand() % 10000;
    //printf("\n %d", randomNeo);
    if( isPalindrome(randomNeo)){
      neoDeath = true;
    }else if(digitsSum(randomNeo)){
      neoDeath = true;
    }else{
      neoDeath = false;
    }
  }
  if(isPalindrome(randomNeo)){
    printf("\n\nNeo died \\(x_x)/");
  }
  else if(digitsSum(randomNeo)){
    printf("\n\nNeo flies >+o");
  }
    

  
  return 0;
}