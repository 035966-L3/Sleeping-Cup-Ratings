# Sleeping Cup's Ratings

## What is Sleeping Cup?

This one: <http://8.136.99.126/>

## How do you calculate the rating?

Please refer to this: <http://8.136.99.126/blog/3/667ed5d1bfb9bd49c48885eb>

## How do I read the data?

### Contest List

The filename should be `list.txt`.

e.g. (filename: `list.txt`)

```plain
Sleeping Cup #1
Sleeping Cup #2
Sleeping Cup #3
*
Sleeping Cup #4
Sleeping Cup #5
!
```

In this example, $5$ contests are numbered:

| ID | Contest Name |
| -: | :- |
| $1$ | Sleeping Cup #1 |
| $2$ | Sleeping Cup #2 |
| $3$ | Sleeping Cup #3 |
| $4$ | **(No such contest)** |
| $5$ | Sleeping Cup #4 |
| $6$ | Sleeping Cup #5 |

### Rankings

The filename should be `rank.txt`.

e.g. (filename: `rank.txt`)

```plain
1 7 525
2 11 343
2 12 343
4 8 0
4 9 0
4 10 0
-1 -1 -1
```

In this example, $6$ users are ranked:

| Rank | User ID | Rating |
| -: | -: | -: |
| $1$ | $7$ | $525$ |
| $2$ | $11$ | $343$ |
| $2$ | $12$ | $343$ |
| $4$ | $8$ | $0$ |
| $4$ | $9$ | $0$ |
| $4$ | $10$ | $0$ |

### Contest Results

The filename should be `contest/N.txt`, where $N$ is the contest ID.

e.g. (filename: `contest/7.txt`)

```plain
1 19 1000 343 328 671
2 13 465 900 -40 860
2 14 465 525 3 528
0 18 -1 1144 -9999 0
-1 -1 -1 -1 -1 -1
```

The example shows the result of the contest with an ID of $7$.

In this example, there are $3$ participants (cheaters excluded):

| Rank | User ID | Performance | Old Rating | New Rating | Rating Change | Status |
| -: | -: | -: | -: | -: | -: | :- |
| $1$ | $19$ | $1000$ | $343$ | $671$ | $\color{green}+328$ | Everying is fine. |
| $2$ | $13$ | $465$ | $900$ | $860$ | $\color{red}-40$ | Everying is fine. |
| $2$ | $14$ | $465$ | $525$ | $528$ | $\color{green}+3$ | Everying is fine. |
| - | $18$ | - | $1144$ | $0$ | - | **He cheated. His rating is set to $\bf{0}$.** |

### Participant Competition History

To be updated.
