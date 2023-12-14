# push_swap

### Usage
Git clone the repository and cd into it. Then use make to compile.

Then run it with :

./push_swap <numbers>
The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

The program can be checked with the provided checker, like this :

`ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker_OS $ARG`

### Rules
The program is only allowed two stacks to work with, stack A and stack B. All the numbers are initially added to stack A, and B is empty.

The possible actions are:

|  Operation             | Description                                                                                     |
|  --------------------  | ----------------------------------------------------------------------------------------------  |
|`pa (push A)`           | Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.    |
|`pb (push B)`           | Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.    |
|`sa (swap A)`           | Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.|
|`sb (swap B)`           | Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.|
|`ss`                    | sa and sb at the same time.                                                                     |
|`ra (rotate A)`         | Shift all elements of stack A up by 1. The first element becomes the last one.                  |
|`rb (rotate B)`         | Shift all elements of stack B up by 1. The first element becomes the last one.                  |
|`rr`                    | ra and rb at the same time.                                                                     |
|`rra (reverse rotate A)`| Shift all elements of stack A down by 1. The last element becomes the first one.                |
|`rrb (reverse rotate B)`| Shift all elements of stack b down by 1. The last element becomes the first one.                | 
|`rrr`                   | rra and rrb at the same time.`                                                                  |


### Grades
The grade depends on how efficient the program's sorting process is.

* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 700 actions
  * 4 points for less than 900
  * 3 points for less than 1100
  * 2 points for less than 1300
  * 1 point for less than 1500
  
* Sorting 500 values: rating from 1 to 5 points depending on the number of actions:
  * 5 points for less than 5500 actions
  * 4 points for less than 7000
  * 3 points for less than 8500
  * 2 points for less than 10000
  * 1 point for less than 11500

# Compilation
Compile checker: `make checker`

Compile push_swap: `make push_swap`

Compile both: `make`

# Exection
### Valid Input Examples:
3 Numbers:

`./push_swap 3 1 2`

5 Numbers:

`./push_swap 5 1 4 2 3`

100 Numbers:

`./push_swap 84 29 56 37 61 9 45 79 92 51 6 24 2 68 83 70 47 96 16 74 64 39 55 13 1 90 5 58 76 28 88 31 72 87 94 20 77 40 97 63 19 23 80 44 12 81 60 95 69 66 25 85 21 98 53 78 30 10 18 49 71 41 3 86 14 75 38 91 34 26 62 11 99 7 22 42 50 67 32 48 15 89 36 59 27 8 43 65 54 33 93 4 17 73 46 57 35 82 52 100`

### Invalid Input Examples
Non-Numeric Values:

`./push_swap three one two`

Alpha-numeric Values:

`./push_swap 1 3dh 75 21 9 gh`

Values Greater/Less than MAXINT/MININT:

`./push_swap -3274823478 2356234782686 2346736221`
