## The idea

The idea of a loop is to take a task that would otherwise require dozens, hundreds or thousands of hard-coded[^1] lines and boil them down to just a couple, with the help of repetition logic.

For instance, if we wanted to print all the numbers from 1 through 10 in the console, we _could_ write this:
```cpp
std::printf("1\n");
std::printf("2\n");
std::printf("3\n");
std::printf("4\n");
std::printf("5\n");
std::printf("6\n");
std::printf("7\n");
std::printf("8\n");
std::printf("9\n");
std::printf("10\n");
```
But, even with copy-pasting each line and altering the number, this very quickly becomes not just slow to write, but also unreadable and just prone to typos.

Alternatively, we can write a loop.
```cpp
for (int i = 1; i < 11; ++i){
    std::printf("%d \n", i);
}
```

It might look a little weirdly written at first, but we'll look at the anatomy of a `for(){}` loop in a bit. More importantly, these two examples will both output the same result, but I think even intuitively you can tell why loops are a thing. Loops are almost infinitely faster to write and to read than hard-coding very big blocks of code. They're also faster to compile and come with _almost_ no performance downgrade. There are other types of loops, not just the `for(){}` one we've just looked at.

## Types of Loops & use cases

### For Loop

Here's our for loop example, once again:
```cpp
for (int i = 1; i < 11; ++i){
    std::printf("%d \n", i);
}
```

A C++ `for(){}` loop takes three arguments: a condition and two lines of code. In fact, if you have an eye for C++ Syntax you might have noticed that these aren't traditional arguments. They're functional lines of code, separated by a `;`. So, you can replace them with anything else, if needed. Anyhow, the first line of code is executed _once_ in the beginning, in this case `int i = 1`, which we use to [initialize](../02.5%20-%20Language%20Specifics/C++/Basics.md#c++-variables) our variable `i`. The second line is the condition which is checked against, every time the loop is run. In this case, `i < 11`, or in words, "is `i` smaller than 11?" So, if we were to have `i` be bigger than (or equal to) 11 to begin with, the loop would execute 0 times. The last line is what's executed at the end of the loop, before beginning the next instance. So, `i` gets increased to a value of 2 before the second pass.

Other implementations of the for loop differ in their anatomy, but have the same use cases. For example, a Python for loop looks like this:
```py
for i in range(1, 11):
    print(i)
```
And again, produces the same result as all other previous examples.

### While Loop

A `while(){}` loop takes a single argument: a condition. This means that the code portion written in `{}` will be executed for as long as the condition in `()` is true.
```cpp
int i = 1;
while(i < 11){
    std::printf("%d \n", i);
    ++i;
}
```
Note: `++i` just increases the value of `i` by 1.

All we did here was write our loop in a different way, you say. And yes, this does achieve the same result as [this for loop](Loops.md#for-loop). But, while loops do have a justification for existing. Say you want to run a line of code until something happens. 

If we don't know how many times we want to loop something, not even in relation to a variable, then all we'd end up writing is this:
```cpp
for(; condition_check; ){
    //code
}
```
Because we can't rely on our counter `i` this time. And doesn't that ever look ugly. Why not write:
```cpp
while(condition_check){
    //code
}
```
Note: both loops will continue until our [boolean](Basics.md#booleans) value `condition_check` is `false`. They are functionally the same, but the former example is just... ugly. Also, not every language is like C++ and would let you write a for loop that is functionally a while loop, so in those cases you're forced to use `while(){}`.

### Do-While Loop

## Performance

## Infinite Loops

### Loop Unrolling

Loop unrolling is the basic idea of reducing the amount of times that a looping overhead is produced when running through many iterations of a loop. For example, instead of this basic C++ loop:
```cpp
for (int i = 0; i != 1000; ++i){
    a[i] = a[i] + v;
}
```
where we're taking the `i`th element in an array and adding the value `v` to it.
The code in the loop executes 3 processor instructions. `LW`, for loading the value, `ADD` for adding to it, `SW` for storing it. The loop itself executes 2 instructions, `ADDI` for moving the pointer and `BNE` for checking if we should end the loop. This is what we call a looping overhead; it takes additional instructions to use the looping mechanism.

We could, however write the loop as such:
```cpp
for (int i = 0; i != 1000; i = i + 2){
    a[i] = a[i] + v;
    a[i-1] = a[i-1] + v;
}
```
And this seems on the surface to achieve the same result. We loop through all the elements in the array, adding the value `v` to them. Except now we're tackling two elements at a time. The looping overhead is now executed every two iterations of our adding procedure. In our first loop, the total instruction count is 5000, because one iteration of the loop takes 5 instructions (`LW`, `ADD`, `SW`, `ADDI` and `BNE`) times the 1000 times that we're looping. But unrolling once has cut that down to 4000, since we now have 8 instructions (`LW` x2, `ADD` x2, `SW` x2, `ADDI` and `BNE`) but we're looping only 500 times.
So, by just doing what's called `unrolling once`, we've decreased the amount of instructions that have to be sent to the CPU by getting rid of one overhead per loop iteration. This is increased by unrolling further, for example.
```cpp
for (int i = 0; i != 1000; i = i + 5){
    a[i] = a[i] + v;
    a[i-1] = a[i-1] + v;
    a[i-2] = a[i-2] + v;
    a[i-3] = a[i-3] + v;
    a[i-4] = a[i-4] + v;
}
```
Now, we only have the looping overhead every 5 iterations of the loop and have reduced our instruction count to 3400. (`LW` x5, `ADD` x5, `SW` x5, `ADDI` and `BNE`) times 200. See reference explanation [here](https://www.youtube.com/watch?v=2efeXxcYBPs).

There are, however, further benefits. For example, that of reducing CPI (Cycles per Instruction). We can use the advantages of processor scheduling and branch prediction to re-order these instructions, effectively taking less processor cycles and therefore less time for the same amount of instructions. See reference explanation [here](https://www.youtube.com/watch?v=2nx0ZCg5D9g) and [here](https://www.youtube.com/watch?v=LTmE21VmzIk).

By both reducing the amount of instructions and the amount of processor cycles necessary to execute those instructions, loop unrolling can reap a significant performance benefit.

[^1]: From [Wikipedia](https://en.wikipedia.org/wiki/Hard_coding): Hard coding (also hard-coding or hardcoding) is the software development practice of embedding data directly into the source code of a program or other executable object, as opposed to obtaining the data from external sources or generating it at runtime. 