# What is Distributed and Concurrent Programming and why do we need it?

In essence, the idea behind Distributed and Concurrent Programming is to allocate more resources to a given computational task. This can be in form of allocating a process to multiple threads on the same CPU or multiple Computers in the same cluster (like in a Datacenter). The challenges arise in breaking up a process (like a computer application) and distributing (duh) those chunks accross the available resources. Think of it as company management, the process being an end product that can be broken down into various different jobs accross various different offices distributed amongst various different people that have to communicate with each other.

## What's an event and what's an action?

An event is a single, non-repeatable occurrence. An action is a layer of abstraction.
To illustrate: 
- event: Tom crossed the street at 1731607608 (unix time).
- corresponding action: crossing the street.

Tom can cross the street many more times, it can be the same street, the same direction, even the same place his feet hit the road but _never_ is it the same event, because it happened at a particular point in time. Tom can never cross the exact same street at that exact same time, unless he's a darn time traveler. Anybody can cross the same street and they can even cross other streets, but that would still be considered the same action, that of crossing the street.

## What's a Process?

# Communication

## Synchronized vs Asynchronous communication

//TODO

## Clocks

To keep distributed processes synchronized, we need to be able to keep track of time. For that, we've got clocks. But not ordinary clocks like a watch or even unix time, but instead, custom clocks that keep track of events in a process. We need this layer of abstraction because if we'd take something like a unix clock (seconds) or even one that worked in nanoseconds, the amount of events that happens in a given amount of seconds is not only indetermined, but also irrelevant. We just need to keep track of what happens before/after what, not when exactly in (human) time that is.

#### The Snapshot Problem

//TODO

#### Lamport Clocks

In a Lamport Clock, every process has its own counter. It simply counts the amount of events. $e_1$ in $p_1$ ticks the clock in $p_1$ to `1`, $e_2$ in $p_2$ to `2`, and so on. The complexity arises when processes communicate asynchronously. For this, when receiving a message, the process clocks to the 

#### Vector Clocks

A vector clock is made up of Lamport Clocks in `n` dimensions, represented in a vector (hence the name).