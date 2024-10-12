## The idea

The idea of a loop is to take a task that would otherwise require dozens, hundreds or thousands of hard-coded[^1] lines and boil them down to just a couple, with the help of repetition logic.

For instance, if we wanted to print all the numbers from 1 through 10 in the console, we _could_ write this:
```
int main(){
    std::print("1\n");
    std::print("2\n");
    std::print("3\n");
    std::print("4\n");
    std::print("5\n");
    std::print("6\n");
    std::print("7\n");
    std::print("8\n");
    std::print("9\n");
    std::print("10\n");
}
```
But, even with copy-pasting each line and altering the number, this very quickly becomes not just slow to write, but also unreadable and just prone to typos.

Alternatively, let's write a loop.
```
int main(){
    for (i = 1; i < 11; ++i){
        
    }
}
```

## Types of Loops & use cases

## Performance

## Infinite Loops

### Loop Unrolling

Loop unrolling is the basic idea of reducing the amount of times that a looping overhead is produced when running through many iterations of a loop. For example, instead of this basic C++ loop:
```
for (int i = 0; i != 1000; ++i){
    a[i] = a[i] + v;
}
```
where we're taking the `i`th element in an array and adding the value `v` to it.
The code in the loop executes 3 processor instructions. `LW`, for loading the value, `ADD` for adding to it, `SW` for storing it. The loop itself executes 2 instructions, `ADDI` for moving the pointer and `BNE` for checking if we should end the loop. This is what we call a looping overhead; it takes additional instructions to use the looping mechanism.

We could, however write the loop as such:
```
for (int i = 0; i != 1000; i = i + 2){
    a[i] = a[i] + v;
    a[i-1] = a[i-1] + v;
}
```
And this seems on the surface to achieve the same result. We loop through all the elements in the array, adding the value `v` to them. Except now we're tackling two elements at a time. The looping overhead is now executed every two iterations of our adding procedure. In our first loop, the total instruction count is 5000, because one iteration of the loop takes 5 instructions (`LW`, `ADD`, `SW`, `ADDI` and `BNE`) times the 1000 times that we're looping. But unrolling once has cut that down to 4000, since we now have 8 instructions (`LW` x2, `ADD` x2, `SW` x2, `ADDI` and `BNE`) but we're looping only 500 times.
So, by just doing what's called `unrolling once`, we've decreased the amount of instructions that have to be sent to the CPU by getting rid of one overhead per loop iteration. This is increased by unrolling further, for example.
```
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

[^1] From [Wikipedia](https://en.wikipedia.org/wiki/Hard_coding): Hard coding (also hard-coding or hardcoding) is the software development practice of embedding data directly into the source code of a program or other executable object, as opposed to obtaining the data from external sources or generating it at runtime. 