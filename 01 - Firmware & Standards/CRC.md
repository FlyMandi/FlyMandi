The Cyclic Redundancy Check (CRC) is a very fast and effective technique to detecting errors in a message.
The basic principle is simple. Take a message, interpreted as one big number (polynomial), and perform
modulo division by another number, a generator polynomial. This remainder can then tell us the integrity
of the message.

In practice:
\
We have a message, say `Hello World!`. We want this message to be sent and arrive safely and without corruption
through the network. Let's say I did and the recipient reads `Hallo World!`. How is he to know that I didn't
mean to send `Hallo`, but `Hello`?

Let's look at what happens under the hood:
\
Our message, `Hello World`, is saved as a sequence of binary numbers that represent the symbols to make
up the text message. It looks like this in ASCII:[^1]
```
01001000 01100101 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100
```

The message is now sent, but arrives as following:
```
01001000 01100001 01101100 01101100 01101111 00100000 01010111 01101111 01110010 01101100 01100100
```
Notice the second byte in the message being different, now reading `a` instead of `e`.

We can now answer the question from earlier. How to tell if corruption has taken place, if not immediately
obvious by the data? CRCs.

Before we send the message, we will pick a generator polynomial and make sure the message is divisible by it.
It will be divided upon arrival and if there is a remainder, that is the indicator that corruption has taken
place.

For an easier time, let's just look at the two bytes that differ as being one entire message. The principle
and application, however, scale very well with longer data and generator polynomials. Picking an adequate
generator polynomial is not an easy task, which is why there is usually some standard. For instance,
I'm going to use `CRC-5-EPC` because its simple polynomial of `1001` or `0x09` is long enough for our byte.

So, we'd like to send the message `01100101`. But before we can do that, we have to make sure it's divisible
by `1001` with a remainder of `0`. This is simply done by adding some bits to the end of our message.
We add `k-1` zeroes, `k` being the length of our generator:
```
1100101000
```
We also need to chop off leading 0s.
\
Then, we divide this number and subtract the remainder:
```
1001 | 1100101000
       1001
       ====
       01111
        1001
        ====
        01100
         1001
         ====
         01011
          1001
          ====
          001000
            1001
            ====
            01110
             1001
             ====
             0111
```
\
The remainder is `111`, so now:
```
1100101000 - 111 = 1100100001
```

And if we did the division process for this new number, we get a remainder of 0:
```
1001 | 1100100001
       1001
       ====
       01011
        1001
        ====
        001000
          1001
          ====
          0001001
             1001
             ====
             0000

```

This way, knowing nothing more than the CRC standard (generator polynomial) that the message was sent with,
we can check for this value being 0, and if it isn't, there was an error. If the value is 0 however, that
does not guarantee that the message received is identical to the message sent. CRCs like this can only detect
burst bit errors witha length of up to `k-1` bits. This means that a 4-bit polynomial like ours would detect
errors, provided only a single bit was flipped or it's a burst error with length less than it. If two or more
non-contiguous bits are flipped, the CRC might or might not catch the error, depending on a variety of factors.

CRCs cannot correct errors on their own, as many different types of errors can produce the same remainder.
A CRC with a generator of `1` is also known as a parity bit and is incredibly widespread in hardware, because
of its effectiveness with virtually no computational effort.

It is worth noting that these divisions can of course be carried out in decimal too, if desired. The principle
of Cyclic Redundancy Checks does not apply only to binary numbers, but unless you're doing this by hand, we're
talking about binary anyway.

[^1]: Note the translation of an empty space to the number `00100000` or `32`. There are a myriad of different,
non-visible characters in the ASCII standard, such as tabs, line feeds, separators for files & units, etc...
This is why the printable set of characters starts at `32`, with the empty space.
