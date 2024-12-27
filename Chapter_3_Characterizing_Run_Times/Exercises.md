
### 3.1 - 1:
p. 52 describes an example of the worst case runtime for insertion sort:
> For a value to end up to the right of where it started, it must have been moved in
line 6. In fact, for a value to end up k positions to the right of where it started,
line 6 must have executed k times. Let’s assume that n is
a multiple of 3 so that we can divide the array A into groups of n=3 positions.
Suppose that in the input to INSERTION-SORT, the n/3 largest values occupy the
first n/3 array positions A[i:n/3] (It does not matter what relative order they
have within the first n/3 positions.) Once the array has been sorted, each of these
n/3 values ends up somewhere in the last n/3 positions A[2n/3+1:n] For that
to happen, each of these n/3 values must pass through each of the middle n/3
positions A[n/3+1:2n/3]. Each of these n/3 values passes through these middle n/3 positions one position at a time, by at least n/3 executions of line 6. Because
at least n/3 values have to pass through at least n/3 positions, the time taken by
INSERTION-SORT in the worst case is at least proportional to (n/3)(n/3) = n^2/9, which is Θ(n^2).

Then we are asked, 
> Modify the lower-bound argument for insertion sort to handle input sizes that are
not necessarily a multiple of 3.

Rather than break the array up into equal n/3 chunks, lets say the largest values occupy the first **_l_** array positions. 
* Then, these values will end up in the last **_l_** positions.
* Each of these **_l_** values pass through the middle _**m**_ positions
* 2*l + m = n
* Example: [9,8,1,4,3,5] (**_l_** is 2, and these two values need to end up in the last 2 positions. There are **_m = 4_** current values in the middle.
* Each of these **_l_** values must pass through the **_m_** positions, one position at a time -- by at least **m*** executions
* Then, the time taken by INSERTION-SORT is then proportional to (**_l_** * **_m_**)
* = ([**_n_** - **_m_**]/2)([**_n_**-**_l_**]/2), expanding to (**_n_**-**_m_**)(**_n_**-**_l_**)/4, or (**_n_**^2 - **_mn_** - **_ln_** + **_ml_**)
* This is on Θ(n^2)
