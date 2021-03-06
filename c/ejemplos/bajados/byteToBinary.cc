//http://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format

#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>     /* strtol */
#include <Rcpp.h>

using namespace Rcpp;

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

// [[Rcpp::export]]
int main(void)
{
    {
        /* binary string to int */

        char *tmp;
        const char *b = "0101";

        printf("%d\n", strtol(b, &tmp, 2));
    }

    {
        /* byte to binary string */

        printf("%s\n", byte_to_binary(5));
    }

    return 0;
}
