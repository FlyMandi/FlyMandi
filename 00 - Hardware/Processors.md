# Introduction to Processors

TODO: write

## Processor Organization

#### Data Storage Hierarchy

You've probably heard the words `RAM`, `Cache`, `L1`, `L2`, `L3` tossed around. I'm going to skip over `RAM`, but you can read up on it [here](Desktops.md#RAM) if needed. To understand the data storage hierarchy, we have to understand the big dilemma that is faced when engineering storage solutions. One can either prioritize speed or size, but not both at the same time - but we need both - which is where the storage hierarchy comes into play.

There are three levels of cache, `L1` being the tiniest, but by far the fastest.

The processor communicates exclusively with `L1` Cache, because it is the only thing it can read. The entirety of `L1` cache is a block that reflects a part of `L2` cache, which in turn is a block of `L3`, which in turn is a block of memory. In order for the CPU to interact with data, it will look for it in L1, turn to L2 if it can't find it, then to L3, then to memory (RAM). When it finds the block of data it's looking for, that has to be loaded from memory into L3, then into L2, then into L1, then can be read. This might seem ridiculous and slow, but combining this system with clever ways to keep track of what data should best be kept in which cache is the best way to achieve maximum processing speed. Loading from Storage into memory is by far the slowest step, but most of that is done when you start a program. Memory is pre-allocated and then only sparsely (in comparison) managed to fit the needs of the program, where as L1-L3 have data constantly flying in and out of them.

But what does L1 actually have space for?

TODO: expand

## Processor Architechture

### x86

### ARM
