# Making-Change
C++ program that implements a greedy algorithm.

This program solves the problem of making change. Given input of a set of coin dnominations, the program implements a greedy algorithm to find the minimum number of coins required to make up a certain amount.

For example: Given a set of coins C = {1, 2, 5, 10, 20, 50, 100}, what is the minimum number of coins to make the amount 83?
In this case we would use  1x50 + 1x20 + 1x10 + 1x2 + 1x1. So the minimum number of coins needed is 5.

INPUT:
- The first line of input is N, the number of coin denominations. N denominations follow, each
separated by a space. You may assume that the denominations are sorted in ascending order.
The next line begins with the integer M, the number of test cases to follow. M integers
K1...KM follow, each separated by a space.

OUTPUT:
- For each test case i, the output is the minimum number of coins needed to make change for amount
Ki.
