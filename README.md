# Sleeping Cup's Ratings

## What is Sleeping Cup?

This one: <http://8.136.99.126/>

## Are there any other useful links?

Certainly: <https://github.com/035966-L3/Sleeping-Cup-Testcases>

## How do you calculate the rating?

Please refer to this: <http://8.136.99.126/blog/3/667ed5d1bfb9bd49c48885eb>

## What's the code?

The code is for calculating performances and rating.

Please read `codes/commands.bat` or `codes/commands.sh` for more information.

Note that cheaters have to be added manually.

## How do I read the data?

### Top Rated

The filename should be `TOP_RATED.md`.

I don't think it necessary to give instructions.

### Username List

The filename should be `usernames.txt`.

e.g. (filename: `usernames.txt`)

```plain
Sulfur
Helium
Chlorine
Zinc
Tungsten

// Updated at: 2024-06-28 05:17:30.678123+00:00
```

In this example, $5$ users are listed:

| ID | Username |
| -: | :- |
| $1$ | Sulfur |
| $2$ | Helium |
| $3$ | Chlorine |
| $4$ | Zinc |
| $5$ | Tungsten |

It is self-evident that when this list was last updated.

Note that we have set a workflow that updates this list every Saturday at 23:45 UTC.

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
YES
1 19 1000 343 328 671
2 13 537 900 -40 860
2 14 537 525 3 528
0 18 -1 1144 -9999 0
-1 -1 -1 -1 -1 -1
```

The example shows the result of the contest with an ID of $7$.

In this example, Special Rules are enabled. (according to the first line, `NO` otherwise)

There are $3$ participants (cheaters excluded):

| Rank | User ID | Performance | Old Rating | New Rating | Rating Change | Status |
| -: | -: | -: | -: | -: | -: | :- |
| $1$ | $19$ | $1000$ | $343$ | $671$ | $\color{green}+328$ | Everying is fine. |
| $2$ | $13$ | $537$ | $900$ | $860$ | $\color{red}-40$ | Everying is fine. |
| $2$ | $14$ | $537$ | $525$ | $528$ | $\color{green}+3$ | Everying is fine. |
| - | $18$ | - | $1144$ | $0$ | - | **The user's rating is set to zero because of cheating.** |

### Participant Competition History

The filename should be `user/N.txt`, where $N$ is the user ID.

e.g. (filename: `user/20.txt`)

```plain
671
24 1 1000 343 328 671
17 8 300 325 18 343
16 3 525 125 200 325
15 17 0 150 -25 125
10 7 300 0 150 150
9 14 0 0 0 0
6 0 -1 837 -9999 0
3 1 900 775 62 837
1 1 1100 0 550 550
-1 -1 -1 -1 -1 -1
```

The example shows the competition history of the user with an ID of $20$.

Currently, the rating of the user is $671$. (It will be $-1$ if the user is banned.)

In this example, there are $6$ records (ignored records excluded):

| Contest ID | Contest Rank | Performance | Old Rating | New Rating | Rating Change | Status |
| -: | -: | -: | -: | -: | -: | :- |
| $24$ | $1$ | $1000$ | $343$ | $671$ | $\color{green}+328$ | Everying is fine. |
| $17$ | $8$ | $300$ | $325$ | $343$ | $\color{green}+18$ | Everying is fine. |
| $16$ | $3$ | $525$ | $125$ | $325$ | $\color{green}+200$ | Everying is fine. |
| $15$ | $17$ | $0$ | $150$ | $125$ | $\color{red}-25$ | Everying is fine. |
| $10$ | $7$ | $300$ | $0$ | $150$ | $\color{green}+150$ | Everying is fine. |
| $9$ | $14$ | $0$ | $0$ | $0$ | $\color{gray}0$ | Everying is fine. |
| $6$ | - | - | $837$ | $0$ | - | **The user's rating is set to zero because of cheating.** |
| $3$ | - | - | - | - | - | **This record is ignored because of the punishment for cheating.** |
| $2$ | - | - | - | - | - | **This record is ignored because of the punishment for cheating.** |
| $1$ | - | - | - | - | - | **This record is ignored because of the punishment for cheating.** |
