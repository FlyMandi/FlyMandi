# Setting up F#

//TODO

# F# functions

//TODO

# F# value Types

//TODO

# F# values vs. mutables, "variables"

//TODO

# F# Datatypes

//TODO

# F# Operators

The equality operator is ```=``` and the assignment operator is ```<-```. The latter can only be used on a mutable value.

# Matching
Pattern matching is one of the most fun things you can do in F#.
Matching is defined as follows:
```f#
match variable with
|base_case -> output_base_case
|variable_case_1 when condition_1 -> output_case_1
|variable_case_1 -> output_case_2
|_ -> rest_cases
```
The ```|``` operator can be read as "case" when pattern matching. Left of the ```->``` operator is the input pattern, while right of it is what the matching will output.

The word ```when``` takes a boolean expression and can be read as ```input Case A when (expression) is true -> output Case A```. 
Putting the same pattern again below with no ```when``` can be read as ```input Case A when (expression) is false```.

**This might look a little convoluted**, so here's an example:

This is a recursive function that doubles every element in a list of integers:

```f#
let rec double (x: List<int>): List<int> =
    match x with 
    |[] -> []
    |head::rest -> (2 * head)::(double rest)
```
However, matching doesn't have to be this simple.
What if we only wanted the elements that are divisible by 2 or 3? oh, and if something is divisible by 2 _and_ 3, we add a 0 to the list?
```f#
let rec filter (x: List<int>): List<int> =
    match x with 
    |[] -> []
    |head::rest when (head % 2 = 0 && head % 3 = 0) -> head::0::(filter rest)
    |head::rest when (head % 2 = 0 || head % 3 = 0) -> head::(filter rest)
    |head::rest -> filter rest
```
As you can see, there's lots you can do with pattern matching. Not just in lists and not just in this way. 
In this case, after ```->``` could come a whole code block, provided it's indented correctly and the last line of the block corresponds with the return type of the function. 
Like so:
```f#
let rec double (x: List<int>): List<int> =
    match x with 
    |[] -> []
    |head::rest ->  print ("I have now doubled the number " + show head)
                    print ("\nHello world lmao\n")
                    (2 * head)::(double rest)
```


This is _all_ of the code this function needs to run. I don't have to define the words ```head```, ```rest``` or anything I put in a matching case. This means you can save a lot of time by writing something as a pattern match, if you do it correctly. 