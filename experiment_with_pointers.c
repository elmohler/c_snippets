#include <stdio.h>
#include <string.h>

int main(void)
{
  // pointer to char
  char A = -72;
  char *pA = &A;

  printf("A   = %d\n", A);   // Here's variable sitting somewhere in memory...
  printf("&A  = %p\n", &A);  // Oh! Here's where it is in memory!
  printf("pA  = %p\n", pA);  // Oh Look! Same thing!!

  printf("*pA = %d\n", *pA); // And here it dereferenced;
                             // which means the value of entity being pointed to.
                             // Since ptr_a is pointing to char a ptr_a's dereferenced
                             // value is -72.

  A = 33;
  printf("*pA = %d\n", *pA);  // Look. A new value

  printf("--------------------------------------------\n");

  // pointer to an array of chars
  char B[5] = { -67, -48, 0, 17, 39 };
  char *pB = &B[0];

  for(int i = 0; i < 5; i++)
  {
    printf("B[%d]   = %d\n", i, B[i]);
  }

  printf("\n ~or~ \n\n");
  
  for(int i = 0; i < 5; i++)
  {
    printf("*(pB + %d)   = %d\n", i, *(pB + i));    
  }

  printf("--------------------------------------------\n");

  char C[] = "hello from the other side of the universe!";



  
  printf("%c", C[0]);
  printf("%c", C[1]);
  printf("%c", C[2]);
  printf("%c", C[3]);
  printf("%c", C[4]);

  // Get it?
  // Notice we're starting the loop where the brute force approach left off...
  //          |
  //          V
  for(int i = 5; i < sizeof(C); i++)
  {
    printf("%c", C[i]);
  }
  printf("\n");

  printf("--------------------------------------------\n");

  // Same thing - just a different style
  char *D = "hello from the other side of the universe!";

  printf("%c", *(D+0));
  printf("%c", *(D+1));
  printf("%c", *(D+2));
  printf("%c", *(D+3));
  printf("%c", *(D+4));

  for(int i = 5; i < strlen(D); i++)
  {
    printf("%c", *(D+i));
  }
  
  printf("\n");
  printf("--------------------------------------------\n");

  // But wait - there's more!!
  char E[] = {'h','e','l','l','o',' ','f','r','o','m',' ','t','h','e',' ','o','t','h','e','r',' ','s','i','d','e',' ','o','f',' ','t','h','e',' ','u','n','i','v','e','r','s','e','!','\0'};

  printf("%s\n", E);


  printf("--------------------------------------------\n");

  // Next step is a pointer to an array of structures...
 

  
  return 0;
}
