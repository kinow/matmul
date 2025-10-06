// Matrix multiplication
//
// R[nrowsA][pcolsB] = A[nrowsA][mcolsA] x B[mcolsA][pcolsB]
//

#include "matmul.h"

/* IKJ

          j                   j j j j
        k + + + +           k + + + +
          + + + +             + + + +
          + + + +             + + + +
  k       + + + +     k       + + + +
i * * * * o         i * * * * o o o o
  * * * *             * * * *
  * * * *             * * * *
  * * * *             * * * *

i
 k
  j
   c[i][j] += a[i][k] * b[k][j]
*/

// ikj version: j in inner loop improves locality (i.e. exploits cache lines)

void matmul(const unsigned int nrowsA, const unsigned int mcolsA,
            const unsigned int pcolsB, const basetype arrayA[],
            const basetype arrayB[], basetype arrayR[])
{
  unsigned int i, j, k, ii, kk, iik;

  for(i = 0; i < nrowsA; i++) {
    ii = i*mcolsA; // which row of A?

    for(k = 0; k < mcolsA; k++) {
      kk = k*pcolsB; // which col of B?
      iik = ii+k; // which col of A?

      for(j = 0; j < pcolsB; j++) // advance one by one over cols of B...
        // Computation
        arrayR[ii + j] += arrayA[iik] * arrayB[kk +j];
    }
  }
}
