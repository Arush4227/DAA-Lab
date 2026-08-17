## Problem Statement

Write a C program to multiply two square matrices of size `n × n` using **Strassen's Matrix Multiplication** method based on the Divide and Conquer approach.

---

## Objective

The objective is to implement matrix multiplication using Strassen's method and demonstrate how Divide and Conquer can reduce the number of recursive matrix multiplications.

---

## Divide and Conquer Approach

For two matrices `A` and `B`, each of size `n × n`, the matrices are divided into four submatrices:

```text
A = | A11  A12 |
    | A21  A22 |

B = | B11  B12 |
    | B21  B22 |