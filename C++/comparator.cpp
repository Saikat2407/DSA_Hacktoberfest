#include <stdio.h>
#include <stdlib.h>
  
// This function is used in qsort to decide the relative order
// of elements at addresses p and q.
int comparator(const void *p, const void *q)
{
    // Get the values at given addresses
    int l = *(const int *)p;
    int r = *(const int *)q;
  
    // both odd, put the greater of two first.
    if ((l&1) && (r&1))
        return (r-l);
  
    // both even, put the smaller of two first
    if ( !(l&1) && !(r&1) )
        return (l-r);
  
    // l is even, put r first
    if (!(l&1))
        return 1;
  
    // l is odd, put l first
    return -1;
}
