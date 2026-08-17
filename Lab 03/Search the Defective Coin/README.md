## Problem Statement

Binary search divides a sorted list into two nearly equal parts and continues searching in the half that may contain the required element.

Ternary search divides a sorted list into three nearly equal parts and continues searching in the one interval that may contain the required element.

The objective is to implement both **Binary Search** and **Ternary Search** in C and compare their performance to validate which search method is better.

---

## Objectives

- Implement binary search for a sorted array.
- Implement ternary search for the same sorted array.
- Search for a user-provided element `x`.
- Count the number of comparisons made by each algorithm.
- Compare their performance for different input sizes.
- Determine whether binary search is better than ternary search.

---

## Algorithms

### Binary Search

Binary search works by repeatedly dividing the search range into two parts.

1. Find the middle element.
2. If the middle element is equal to `x`, the search is successful.
3. If `x` is smaller, search the left half.
4. If `x` is larger, search the right half.
5. Repeat until the element is found or the search range becomes empty.

### Ternary Search

Ternary search divides the search range into three parts using two middle positions.

1. Calculate two middle positions.
2. Compare `x` with both middle elements.
3. If `x` matches either middle element, the search is successful.
4. Otherwise, determine which of the three intervals can contain `x`.
5. Repeat until the element is found or the search range becomes empty.

---

## Complexity Analysis

| Algorithm | Best Case | Average Case | Worst Case |
|---|---:|---:|---:|
| Binary Search | O(1) | O(log₂ n) | O(log₂ n) |
| Ternary Search | O(1) | O(log₃ n) | O(log₃ n) |

At first glance, ternary search appears better because:

`log₃(n) < log₂(n)`

However, each ternary-search iteration performs more comparisons than a binary-search iteration.

For binary search, one iteration generally requires about **one key comparison** to decide which half to continue with.

For ternary search, one iteration can require **two key comparisons** because there are two middle elements.

Therefore, the number of iterations alone does not determine the actual performance.

---

## Why Binary Search Is Better

Binary search is generally more efficient than ternary search for searching a sorted array because it performs fewer comparisons per iteration.

For example, suppose the array contains `1,000,000` elements:

- Binary search needs roughly `log₂(1,000,000) ≈ 20` iterations.
- Ternary search needs roughly `log₃(1,000,000) ≈ 13` iterations.

Although ternary search uses fewer iterations, each iteration can require two comparisons. Its comparison count can therefore be roughly:

`2 × log₃(n)`

while binary search requires roughly:

`log₂(n)`

For large `n`:

- Binary: approximately 20 comparisons.
- Ternary: approximately 26 comparisons.

Hence, binary search generally performs fewer comparisons and is usually faster in practice.

---

## Experimental Validation

The program can validate the result by testing both algorithms on the same sorted arrays.

### Suggested Test Cases

| Array Size | Search Element | Expected Result |
|---:|---:|---|
| 10 | Present | Both should find it |
| 10 | Absent | Both should report not found |
| 100 | Present | Compare comparisons |
| 1,000 | Present | Compare comparisons |
| 10,000 | Present | Compare comparisons |
| 100,000 | Present | Compare comparisons |
| 1,000,000 | Present | Compare comparisons |

For every test:

1. Use the same sorted array.
2. Search for the same element.
3. Count comparisons performed by binary search.
4. Count comparisons performed by ternary search.
5. Compare the results.

The algorithm requiring fewer comparisons can be considered more efficient for that test.

---

## Expected Observation

As the size of the sorted array increases, both algorithms remain logarithmic.

However, binary search generally performs fewer comparisons because it makes only one major partition decision per iteration, whereas ternary search needs to examine two partition points.

Therefore, the experimental results should support the conclusion:

> **Binary search is generally better than ternary search for searching a sorted array because it performs fewer comparisons per iteration.**
---