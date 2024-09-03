Algorithm
For the stacks with size less than 6 I wrote a simple sort which can be found in the src folder.

In this project I used Radix sort as the main algorithm. Radix sort is an efficient algorithm to sort non-negative integers with time complexity O (n). For example, we can sort following list of integers with this algorithm

87 487 781 100 101 0 1
Imagine there are 10 boxes labeled 0, 1, 2, …, 9

Start from the least significant digit (which is the digit in 1’s place), we put each number into the box which its digit corresponds to.

In the example, 87 has 7 in 1’s place, hence we put it in box 7. 487 also has 7 in 1’s place, so it should be placed in box 7 too (right behind 87) … And we repeat this process until every number is in one of the boxes.

box 0    100    0
box 1    781    101    1
box 2
box 3
box 4
box 5
box 6
box 7     87    487
box 8
box 9
After that, we connect every number according to the order of boxes.

100 0 781 101 1 87 487
As we can see, the numbers are sorted according to the digit in 1’s place. For those with the same digit in 1’s place, they’re sorted according to their order in the original list.

We repeat this procedure n times, whiere n is the number of digits of the largest number in the array (In this case 783 => n = 3).

After doing it n times and connecting numbers after each cycle we will have array sorted.

Simplify numbers
Instead of dealing with potentially large or negative integers, we assign each number an index based on its relative size. This process is often called "coordinate compression" or "discretization".

For example, if we have [-5, 100, 2, -10], we'd simplify it to [1, 3, 2, 0].

Base-2 representation: After simplification, we represent each number in binary (base-2). This allows us to sort using only two stacks, which we'll call A and B.

Radix sort adaptation: We perform a radix sort, but instead of using 10 buckets (for base-10), we use 2 stacks (for base-2).

Sorting process:

We start from the least significant bit (rightmost) and move towards the most significant bit (leftmost).
For each bit position:
If the bit is 0, we move the number to stack B (pb - push to B).
If the bit is 1, we rotate stack A (ra - rotate A), keeping the number in A.
After processing all numbers for a bit, we move all numbers from B back to A (pa - push to A).
We repeat this process for each bit.
Performance of the Algorithm
My push_swap sorts

3 numbers with maximum 3 instructions,
4 numbers with maximum 7 instructions,
5 numbers with maximum 11 instructions,
100 numbers with maximum 1084 instructions => 3 points,
500 numbers with maximum 6785 instructions => 4 points.
The algorith is good enought to pass the project. If the Bonus part is also done the project could get more than 105%.
