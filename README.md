# push_swap
This is a project from 42 school. The goal is to sort a stack of numbers using two stacks and a limited set of instructions.

## What language is used
- C

## What algorithm is used
- greedy

## What subjects are used
- libft
- get_next_line
- ft_printf

## How to run
- compile with `make` in root folder(`push_swap/`)
- run with `./push_swap [numbers]`
  - ex) ./push_swap 1 2 3 4 5
  - ex) ./push_swap 1 -2 3 -4 5
  - ex) ./push_swap 1 1 3 4 5 => error

### Executable name
- push_swap

### Makefile
- `make`: compile the project in `srcs/` and `libft/` and `ft_printf/`, `get_next_line/`
- `make clean`: remove all .o files
- `make fclean`: remove all .o files and the executable
- `make test`: compile the project and run the test in `test/` folder

## Commands
- sa / sb: Swap the first 2 elements at the top of stack a / b. Do nothing if there is only one or no elements.
- ss: sa and sb at the same time.
- pa / pb: Take the first element at the top of b / a and put it at the top of a / b. Do nothing if b / a is empty.
- ra / rb: Shift up all elements of stack a / b by 1. The first element becomes the last one.
- rr: ra and rb at the same time.
- rra / rrb: Shift down all elements of stack a / b by 1. The last element becomes the first one.
- rrr: rra and rrb at the same time.

## Score
- before evaluation
