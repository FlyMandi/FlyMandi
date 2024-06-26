# What is Recursion?

Recursion within a function can be understood as the ability to call itself. The easiest example for this is a [factorial](https://en.wikipedia.org/wiki/Factorial). ```5!``` would be ```5 * 4!```, which would be ```5 * 4 * 3!``` and so on and so forth, until we arrive at ```0!```, of which the value is 1.[^factorial]

[^factorial]: According to the convention of an [empty product](https://en.wikipedia.org/wiki/Empty_product), ```0!``` is considered to be 1. For this example, it just made sense to use 0 as the starting case.

In C++ we would write:
```
int factorial(const int& x){
    if (x == 0){ return 1; }
    else{ return (x * factorial(x - 1)); }
}
```

In F#, one such function would be:
```
let rec factorial (x: int): int = 
    if (x = 0) then 1
    else x * (factorial (x - 1))
```

We can see, a recursive function is one that, by definition needs to call itself. Usually, there's a base case that you need to arrive at, in this example the number 0. Since you're taking positive, natural numbers and subtracting by 1 every time you call the function, eventually, you will arrive at 0. You need to arrive at this base case at some point, else you'll have yourself an infinite loop.

## Peano vs Leibniz

The previous example has been written with the peano recursion template, which subtracts the parameter by 1 every time we call our function, until we arrive at 0 and we use the base case. This template is widely applicable to all sorts of functions, including loops. There is one primary concern with this template though, and that is _complexity_. We are recursively calling our function as many times as our parameter is big. This is known as a complexity of O(n) or linear time.

The Leibniz recursion template is not as widely applicable and you might need to re-write your code to fit it, sometimes. However, this can have huge advantages in runtime complexity. The idea behind the Leibniz template is simply to use division instead of subtraction. 
Here's a function that takes every digit in a number and returns the sum of the individual digits. For example: ```sum_digits 123``` would return 6, while ```sum_digits 54``` would return 9.

We're not calling our function anymore as many times as our parameter is big, because we're only calling it once for every digit. This is known as a complexity of O(log n) or logarithmic time.
```
let rec sum_digits (n: int): int =
    if (n = 0) then 0
    else (sum_digits(n / 10) + n % 10)
```

## Complexity

### Big O notation

Big O notation is a quick way of knowing how time-efficient a program will be when scaled infinitely. As you can see in this graph, it can be categorized pretty well.

![](https://miro.medium.com/v2/resize:fit:4800/format:webp/1*dWet_YU-5072Kcko7LzsuQ.jpeg)
[image source](https://blog.stackademic.com/how-to-calculate-big-o-notation-time-complexity-5504bed8d292)

Big O notation is not precise, but it's still very important, because it allows a good idea of the runtime when scaled. What does that mean? 
Let's say, every time your program runs, you have to do 1000 function calls and operations, even for the simplest of inputs. Compared to a program that has to do 10 calculations, that seems like a very inefficient program. However, what if your program ran on linear time and the other one on quadratic time? This would mean that for ```n = 1000```, your computations will be 2000, while theirs will be 1,000,010. See how those 1000 computations don't really matter? What matters most for a scalable program is the big O time complexity.
This is why big O is presented as just big O, not a precise runtime calculation. 
O(n + 1) is still O(n) and so is O(n + 999,999,999).

In practice, when writing anything that's supposed to be even slightly scalable, you should try to get the least complexity you can. If there's a way of writing it with O(log n), but it'll take you a bit of extra effort compared to O(n), it's always worth it. And, of course, you should try to avoid quadratic (or worse) times, if possible.
