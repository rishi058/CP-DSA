#include<bits/stdc++.h>
using namespace std;

/*
Ways to solve Dining philosopher problem.
1. Binary Semaphore :
Deadlock Avoidance:
Implement a rule (e.g., odd philosophers pick the left fork first, even philosophers pick the right fork first) to avoid cyclic waiting.

2. Counting Semaphore:
The semaphore ensures at least one philosopher is always thinking, breaking the cycle of deadlock.

3. Banker’s Algorithm:

4. Resource Hierarchy:

5. Monitor with Condition Variables:

6. Asymmetric Fork Allocation:

7. Chandy/Misra Solution (Arbitrator):
*/