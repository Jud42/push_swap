# push_swap
## Introduction
push_swap is an exercise in sorting algorithms, you have at your disposal a set of ***integers***, ***two stacks*** and a set of ***instructions*** to manipulate them.
The goal of this project is to understand the complexity of algorithms and sort the stacks using the minimum amount of instructions possible.

>**Program name** | push_swap
**Files to render** | Makefile, \*.h, \*.c
**Makefile** | NAME, all, clean, fclean, re
**Arguments** | stack a: a list of integers
**External functions allowed** | read, write, malloc, free,  exit, ft_printf and any equivalent that we coded
**Libft allowed** | yes
**Descriptions** | Sort the stacks

### Integers
give randomly
### Stacks
at the beginning:
1.  **stack a**
	contains a random amount of negative and/or positive numbers
	which cannot be duplicated.
2. **stack b**
	is empty.

### Instructions
The goal of the game is to sort the numbers in **stack a** in ascending order. For this
do, we have the following instructions:

**Instructions** |                          **Actions**
---- | ----
**sa (swap a)** | swaps the first 2 items on top of the **stack a**. Does nothing if there is only one or none.
**sb (swap b )** | swaps the first 2 items on top of the **stack b**. Does nothing if there is only one or none.
**ss** | **sa** and **sb** at the same time.
**pa (push a)** | takes the first element at the top of **b** and puts it on **a**. Does nothing if **b** is empty.
**pb (push b)** | takes the first element at the top of **a** and puts it on **b**. Does nothing if **a** is empty.
**ra (rotate a)** | Shifts up one position all the elements of **stack a**. The first element becomes the last.
**rb (rotate b)** | Shifts up one position all the elements of **stack b**. The first element becomes the last.
**rr** | **ra** and **rb** at the same time.
**rra (reverse rotate a)** | shifts down one position all the elements of **stack a**. The last element becomes the first.
**rrb (reverse rotate b)** | shifts down one position all the elements of **stack b**. The last element becomes the first.
**rrr** | **rra** and **rrb** at the same time.
#### Instruction limits

1. To sort ***3 numbers***, no more than 2 instructions
2.  To sort ***5 numbers***, no more than 12 instructions
3. To sort ***100 numbers***:
    -   less than 700 instructions = 5 points.
    -   between 700 - 900 instructions = 4 points.
    -   between 900 - 1100 instructions = 3 points.
    -   between 1100 - 1300 instructions = 2 points.
    -   between 1300 - 1500 instructions = 1 point.
4. To sort ***500 numbers***, points are as followings
    -   less than 5500 instructions = 5 points.
    -   between 5500 - 7000 instructions = 4 points.
    -   between 7000 - 8500 instructions = 3 points.
    -   between 8500 - 10000 instructions = 2 points.
    -   between 10000 - 11500 instructions = 1 point.

## Illutstration & data structure
### instruction
![Alt text](https://github.com/Jud42/push_swap/blob/main/.png/Illustration%20push_swap_instruction.png?raw=true)

### data structure
![Alt text](https://github.com/Jud42/push_swap/blob/main/.png/Illustration%20push_swap_data_structure%201.png?raw=true)
## sort
#### small_data (small_numbers)
Most functions take a flag as arguments, which correspond to the stack to be processed. A || B
*small_data()* handles if size is below 6
* if (size <= 3) **uno_dos_tres()** function is called. It is composed of 3 sub-functions: 
	* In the case  **flag**  = **A** (*stack a*)
		* if size == 3
			*three_mng_a()* is called:
			we recover max_value and min_value.
			1. if head->value == min_value we call la fonction *head_min()*
				* if head->next->value == max_value
					* if flag A => `sa`, `rra`
					* if flag = B => `rrb`
			2. if head->next->value == min_value we call *mid_min()*
				1. if head->value == max_value
					* flag A => `rra` || flag B => `rb`, `sb`
				2. else
					* flag A => `sa` || flag B => `ra`
			3. if last->val == min_value we call *last_min()*
				1. if head->value == max_value
					* flag A => `rra`, `sa` || flag b = pa pa pa
* if (size == 5)
    In the case **flag** = **A**,  **five_mng_a()** function is called.
	we start by retrieving the middle with *mid_five_sort()*, then we send the two smaller than middle to stack B, we call the *three_mng_a* function to sort stack A, we check stack B, making sure that the largest value  is at the top of the list before pushing on A.
In the case where the **flag** is equal to **B** , the procedures are somewhat similar but we put the values in **descending** order in the **stack B**.

##### find_middle & max_min_value (in file appointed utils) 
fuction for size less than 6
###### max_value()
we go through the list from the head to the last by comparing the position (if a < b then a = b; if (a < c , a = c ...)) until we find the largest value.
###### min_value()
inverse of max_value() (if a > b then a = b so on...)
###### mid_five_sort()
I put the first 5 sizes in a temporary array and I call *mid_value()* to find the middle
###### mid_value
if value x > value x + 1
	stock = value x + 1
	value x + 1 = value x
	Value x = stock
else if value x < value x + 1
	we advance to value x + 1 and we compare with value x + 2 and so on...
###### illustration
![Alt text](https://github.com/Jud42/push_swap/blob/main/.png/Illustration%20push_swap_mid.png?raw=true)

#### large_numbers
We initialize the middle(pivot) like this:
>pivot stack A = MAX_VALUE A / 2
pivot stack B = mid A / 2

***sort_a()***
We call the function *part_a()* to make the partition,
all values smaller than **pivot stack A** are pushed into *stack B*(**pb**) and values larger than **pivot stack B** are pushed to *B* at the bottom with **rb** and we put it back on top later by doing **rrb** the same number of times as **rb**...
*And we repeat the same process by calling **sort_a()** recursively until the size ==stack A== is less than 6, as an argument the number of times the **ra** is called becomes ==size==.

==pseudo_code== **part_a()**:
```c
i = size; //number of element to process
while (i--){
if (a->head->pos > op->piv)
{
	rotate_stack(a, A);
	op->ra++;
}
else
{
	push_stack(a, b, B);
	op->pb++;
	if (b->head->pos > op->piv_b)
	{
		rotate_stack(b, B);
		op->rb++;
	}
}
}
```

***sort_b()***
we call the function ***sort_b()*** we give as argument as size the number of times that **rb** has been called.
We initialize the **pivot** again, we call the ***part_b()*** function to make the partition in **stack B**, everything larger than **pivot stack B** we push them into *stack A*(**pa**)
and in **A**, all numbers less than or equal to **pivot stack A** is the **ra**
==pseudo_code== **part_b()**:
```c
i = size;
while (i--){
if (b->head->pos <= op->piv_b)
{
	rotate_stack(b, B);
	op->rb++;
}
else
{
	push_stack(b, a, A);
	op->pa++;
	if (a->head->pos <= op->piv)
	{
		rotate_stack(a, A);
		op->ra++;
	}
}
}
```
once out of part_b(), we call **sort_a()** to sort what was sent in **A**, giving as size the number of (**pa**-**ra**)
And if there are more **ra** than **rb** we do **rra** **stack A** otherwise **rrb** in **stack B**
We send to the function **sort_a** as size the **ra** and after we do the same thing by calling **sort_b** sends **rb** as size in argument,
so **sort_b** repeats the same process calling itself until the size is below 6...

#### illustration part_a()
![Alt text](https://github.com/Jud42/push_swap/blob/main/.png/Illustration%20part_a%20pivot.png?raw=true)

...
