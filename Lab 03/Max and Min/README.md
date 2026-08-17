## Problem Statement

Using the **Divide and Conquer (D&C)** approach, develop an algorithm to find the maximum and minimum elements in an array of size `n` such that the number of comparisons is bounded by:

\[
\frac{3n}{2} - 2
\]

Implement the algorithm in C and validate the result.

---

## Objective

The objective is to find both the minimum and maximum elements of an array efficiently using recursion and divide and conquer.

Instead of separately scanning the array for the minimum and maximum, the array is divided into smaller parts and the results are combined.

---

## Divide and Conquer Approach

The algorithm follows three steps:

### 1. Divide

Divide the array into two approximately equal halves.

For example:

```text
12  45  2  78 | 34  8  99  1