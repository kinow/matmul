# Optimize a simple matrix multiplication code

## 0. Benchmarking: we are going to fill out a table with execution times

    ------------------------------------------------------------------------
                       O0       O1       O2       O3       O3m       Ofastm

    matmul_ijk
    matmul_ijk_op1
    matmul_ijk_op2
    ------------------------------------------------------------------------
- We will use GCC 10.1.0 in FT3 for this benchmark
- We will perform matrix multiplication for 2048x2048 size matrices.
  Matrix size is a parameter in the code (eg. ./matmul_ijk 2048 is executing the
  code for 2048x2048 matrices).

## 1. git clone https://gitlab.citic.udc.es/emilio.padron/matmul

   + 3 complete matrix multiplication kernels: `ijk`, `ijk_op1` & `ijk_op2`
   + 3 skeleton codes to replicate the previous ones using a `ikj` access pattern

## 2. make O=-O0

   + Compiles with no optimization `ijk`, `ijk_op1` & `ijk_op2`

## 3. Execute the three codes and write down the results in the table

   + Column **O0**

## 4. make O=-O1

   + Now, we enable some compiler optimizations

## 5. Execute the new binaries and write down the results

   + Column **O1**

   How they compare to the previous execution times?
   What conclussion can you obtain?

## 6. make O=-O2

   + Even more compiler optimizations are included

## 7. Execute the new binaries and, again, write down the results

   + Column **O2**

## 8. make O=-O3

   + This is usually the 'standard' optimization level most of the times

## 9. Execute the new binaries and, again, write down the results

   + Column **O3**

## 10. make O="-O3 -march=native -mtune=icelake-server"

   Just `make` also does the same, as this is the default in the makefile

   + Now we tailored the binaries for the destination platform

## 11. Execute the new binaries and, again, write down the results.

   + Column **O3m**

## 12. make O="-Ofast -march=native -mtune=icelake-server"

    + This is usually the top optimization level in GCC

## 13. Execute the new binaries and, again, write down the results

   + Column **Ofastm**

## 14. Create a naive ikj version in mutmal_ikj.c

## 15. Compile this new version with no optimization at all

   - Write down your results in the table, creating a new `ikj` row
   - Compare the results with the non-optimized naive ijk version.
   - Do you see any increase in performance? What do you think is the
    main reason?

## 16. Compile the ikj version with the different optimization levels

   - Write down the execution times for the different runs.
   - Compare the results with the analogous ijk versions.

## 17. Code a ikj_op1 version in mutmal_ikj_op1.c, analogous to mutmal_ijk_op1.c

## 18. Compile ikj_op1 again for the whole battery of compiler options we used in the previous cases

  - Write down your results in a new `ikj_op1` row.

## 19. Code a ikj_op2 version in mutmal_ikj_op2.c, analogous to mutmal_ijk_op2.c

## 20. Compile ikj_op2 again for the whole battery of compiler options we used in the previous cases

  - Write down your results in a new `ikj_op2` row.
  - Any relevant difference?
