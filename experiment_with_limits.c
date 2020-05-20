#include <stdio.h>
#include <limits.h>

int main(void)
{
  // This was compiled with gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)
  // This information was obtained on the command line with gcc -v
  // Target: x86_64-linux-gnu which is the "native" machine I compiled on and ran my program on.
  // For most folks the target is the development machine but for embedded developers
  // the cose is compiled & linked on the development "host" and "cross-compiled" to the target
  // that will be actually executing the program. That's why BBB is interesting because it gives
  // you practice to develop and cross compile to a target with some degree of ease. Imagine
  // cross compiling to the air-bag controller in your automobile!!

  // I just compiled with "cc experiment_with_limits.c" and out popped a file called "a.out".
  // It doesn't get much simpler. No linking involved; you'll learn about that later.
  
  unsigned char uCharVal;
  int           sizeofCharBytes;

  unsigned int  uIntVal;
  int           sizeofIntBytes;

  unsigned long uLongVal;
  int           sizeofLongBytes;

  // Floats do not distinguish as signed/unsigned.
  // Floats are always + as well as -
  float         floatVal;
  int           sizeofFloatBytes;

  
  sizeofCharBytes  = sizeof(uCharVal); // unsigned char is an 8  bit quantity. 2^8  = 256. 
  sizeofIntBytes   = sizeof(uIntVal);  // insigned int  is an 32 bit quantity. 2^32 = see below. 
  sizeofLongBytes  = sizeof(uLongVal); // unsigned long is an 64 bit quantity. 2^64 = see below. 
  sizeofFloatBytes = sizeof(floatVal); // float is a 32 bit quantity. I don't know much about the guts of float. 

  // It's worth mentioning that there's also a short. Usually it's 2 bytes but some compilers
  // annoyingly morphed shorts with ints and now things are a mess.
  // Beware of the limits of the primatives (i.e. char, int, etc.) you are using.
  
  printf("Number of bytes in memory consumed by each variable type:\n");
  printf("sizeofCharBytes  = %d byte\n",  sizeofCharBytes); // 8 bits is 1 byte
  printf("sizeofIntBytes   = %d bytes\n", sizeofIntBytes);  // 32 bits is 4 bytes
  printf("sizeofLongBytes  = %d bytes\n", sizeofLongBytes); // etc...
  printf("sizeofFloatBytes = %d bytes\n", sizeofFloatBytes);

  printf("---------------------------------------------------\n");
 
  printf("Notice how uninitialized variables can lead to unpredictable results!!\n");

  printf("uCharVal       = %d\n",  uCharVal);
  printf("uIntVal        = %d\n",  uIntVal);
  printf("uLongVal       = %ld\n", uLongVal);
  printf("floatVal       = %f\n",  floatVal);
  
  uCharVal  = 1;
  uIntVal   = 2;
  uLongVal  = 3;
  floatVal = 3.14;    

  printf("---------------------------------------------------\n");

  printf("Notice how initialized variables now make sense.\n");
  printf("The older ANSI compiler forced you to assign all variables at the top of the function.\n");
  printf("Newer compilers have relaxed some antiquated standards.\n");
  printf("Now we don't get the nonsense we saw with some of the uninitialized values\n");
  printf("above. Uninitialized pointers are particularly bad-news:\n");    

  printf("uCharVal       = %d\n",  uCharVal);
  printf("uIntVal        = %d\n",  uIntVal);
  printf("uLongVal       = %ld\n", uLongVal);
  printf("floatVal       = %f\n",  floatVal);   

  printf("---------------------------------------------------\n");

  uCharVal  = 1;
  printf("uCharVal set to 1          = %d\n",  uCharVal);

  // The Bits and the Meaning seem odd at first glance. The compiler won't complain.
  // It's perfectly legal and sometimes useful but stuff like this is where inexperienced
  // developers can get into trouble... The thing to take away from this is noticing that
  // the meaning of a variable's value and the raw bits they represent can at times diverge
  // and this is where you need to be careful.  
  uCharVal  = -1;
  printf("uCharVal set to -1         = %d\n",  uCharVal);

  uCharVal  = -2;
  printf("uCharVal set to -2         = %d\n",  uCharVal);

  char sCharVal; // plain old char is an implied "signed char"
  //signed char sCharVal; <-This is the formal way but nobody declares signed values this way.

  printf("---------------------------------------------------\n");
    
  sCharVal = 1;
  printf("sCharVal set to 1          = %d\n",  sCharVal);

  sCharVal = -1;
  printf("sCharVal set to -1         = %d\n",  sCharVal);

  sCharVal = -2;
  printf("sCharVal set to -2         = %d\n",  sCharVal);

  printf("...                        ...\n");
  
  // You'll get a compile warning on this. This is bad practice. See what happens.
  sCharVal = -255; 
  printf("sCharVal set to -255       = %d\n",  sCharVal);

  sCharVal = -256; 
  printf("sCharVal set to -256       = %d\n",  sCharVal);

  sCharVal = -257; 
  printf("sCharVal set to -257       = %d\n",  sCharVal);

  sCharVal = -258; 
  printf("sCharVal set to -258       = %d\n",  sCharVal);

  printf("---------------------------------------------------\n");

  // Keep in mind that a (signed) char and unsigned char occupy the same amount of memory 
  printf("  signed char min value    = %d\n",  CHAR_MIN);
  printf("  signed char max value    = %d\n",  CHAR_MAX);
  printf("unsigned char max value    = %u\n",  UCHAR_MAX);

  printf("  signed int min value     = %d\n",  INT_MIN);
  printf("  signed int max value     = %d\n",  INT_MAX);
  printf("unsigned int max value     = %lu\n",  (long)UINT_MAX);

  printf("  signed long min value     = %ld\n",  LONG_MIN);
  printf("  signed long max value     = %ld\n",  LONG_MAX);
  printf("unsigned long max value     = %lu\n",  (long)ULONG_MAX);    

  // Again I don't know much about floats...

  
  return 0;
}

// The        The          Underflowed
// Meaning    Raw Bits     Meaning on Unsigned quantities
// 0          00000000
// 1          00000001
// 2          00000010
// 3          00000011
// 4          00000100
// ...        ...
// 252        11111100     -4
// 253        11111101     -3
// 254        11111110     -2
// 255        11111111     -1
