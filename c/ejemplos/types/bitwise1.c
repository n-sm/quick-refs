#include <limits.h>
#include <stdio.h>

#define ANDPR(x, y) printf( # x " & " # y " es %d\n", (x) & (y))

int main(){


  
printf("\n\
CHAR_BIT %d\n\
CHAR_MAX %d\n\
CHAR_MIN %d\n\
INT_MAX %d\n\
INT_MIN %d\n\
LONG_MAX %ld\n\
LONG_MIN %ld\n\
SCHAR_MAX %d\n\
SCHAR_MIN %d\n\
SHRT_MAX %d\n\
SHRT_MIN %d\n\
UCHAR_MAX %d\n\
UINT_MAX %d\n\
ULONG_MAX %ld\n\
USHRT_MAX %d\n\n\
",
       CHAR_BIT,\
CHAR_MAX,\
CHAR_MIN,\
INT_MAX,\
INT_MIN,\
LONG_MAX,\
LONG_MIN,\
SCHAR_MAX,\
SCHAR_MIN,\
SHRT_MAX,\
SHRT_MIN,\
UCHAR_MAX,\
UINT_MAX,\
ULONG_MAX,\
       USHRT_MAX);

 ANDPR(130, 128);
  return 0;
}
