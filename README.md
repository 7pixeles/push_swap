*This project has been created as part
of the 42 curriculum by ayucarre.*

# Push_swap
## Description
**push_swap** is an algorithmic project whose goal is to sort a stack of integers using a
limited set of operations and the smallest possible number of moves.

The project works with two stacks, commonly named **A** and **B**, and a predefined set
of allowed operations (swap, push, rotate, reverse rotate). The program receives a list
of integers as input and outputs a sequence of operations that will sort the numbers in
ascending order in stack A.

The challenge is not simply to sort the data, but to design an efficient algorithm that
minimizes the number of operations, taking into account both correctness and performance.
This project encourages a strong understanding of data structures, algorithmic complexity,
and problem decomposition.


### Sorting results and points:

#### **Maximum project validation:**
Input size | Maximun Operations allowed | Max points
 --------- | -------------------------- | ----------
 **100** | 700 | **100%**
 **500** | 5500 | **100%**

#### **Minimal project validation:**
 Input size | Maximun Operations allowed | Max points
 --------- | -------------------------- | ----------
 Option 1 |
 100 | 1100 | **80%**
 500 | 8500 | **80%**
 Option 2 
 100 | 700 | **80%**
 500 | 11500 | **80%**
 Option 3
 100 | 1300 | **80%**
 500 | 5500 | **80%**

## Instructions

### Compilation

To compile the project, run:

```bash
make
```


This will generate the executable push_swap.

To remove compiled files:

```bash
make clean
```

To remove all compiled files and the executable:
```bash
make fclean
```
To recompile the project from scratch:
```bash
make re
```

## Execution

Run the program by passing a list of integers as arguments:
```bash
ARG=$(seq -500 800 | shuf -n 100 | tr '\n' ' ')
./push_swap $ARG
```
The program will output a list of operations, one per line. When these operations are
applied in order, they will sort the numbers in ascending order in stack A.

You can also run the `tester.sh` script, which will execute a series of consecutive chained tests, checking the number of operations and validating that they remain within the allowed range.

## Rules and Constraints

- Input numbers must be valid integers.

- Duplicate numbers are not allowed.

- If the input is already sorted, the program must produce no output.

- On invalid input, the program must display Error followed by a newline.

## Algorithm Overview

This implementation uses a **chunk-based sorting strategy**.

The input values are first indexed (coordinate compression) so that their relative order
can be handled more easily. The indexed range is then divided into several contiguous
groups called *chunks*.

The algorithm works as follows:
- Values belonging to the current chunk are pushed from stack A to stack B.
- During this process, rotations are applied to keep stack B partially ordered.
- Once all chunks have been processed, elements are pushed back from stack B to stack A
  in descending order, ensuring that stack A ends up sorted in ascending order.

The chunk size depends on the number of elements and is chosen as a compromise between
simplicity and operation count. Smaller chunks increase precision but may add overhead,
while larger chunks reduce control and may increase total moves.

This approach scales well for large inputs and offers a good balance between performance
and implementation complexity.

## AI Usage Disclosure

AI tools were used as a support resource, not as an automatic solution generator.

Specifically, AI was used for:

- Clarifying algorithmic concepts (e.g. complexity trade-offs, common strategies).

- Reviewing explanations and documentation wording for clarity.

- Identifying potential edge cases during design.

AI was not used to generate final source code automatically. All algorithmic decisions,
data structures, and implementations were designed, written, and validated by me.