# Non attacking queens Game (aka. n-queens game)
this (or the n-queens game) is a 2 players game, in which each turn, one person places a queen into a board on an unattacked tile. Player who can't move when it's their turn is the loser.

# Files
### nAQ_Winner.cpp
Using brute-force to calculate all possible games on a N\*N board, take N as input, output the winner. (if they play optimally obviously)

### BMP.h
just a header that allows me to edit .BMP files easily
[Here is where i got it from](https://github.com/sol-prog/cpp-bmp-images/blob/master/BMP.h)

### nAQ_Play.cpp
A program allows you to play against an optimally CPU player. (with visual assistance through writing image onto hard drive. this is convenient because most image viewers reload itself if its image file changes)

If the CPU cant win it will state that it's moving randomly. Good luck.

# Postscript
After letting a no-brainer's terribly-written, poorly-designed brute-force running about half an hour

Here is the result. First column is **N**, second column is the winner of the board size **N\*N** (normal text is First player, Bold text is Second player), third column is the optimal First move, last collumn is runtime.

It is quite interesting to see Second player starting to have a chance when it reaches *N = 10*.

![Data](https://github.com/nvatuan/nonAttackingQueensGame_mytake/blob/master/dat.png)

Also there is an optimal strategy for First player to always win on board given **N is an odd number**. Placing in the middle first then mirror Second player's move (through the center). 

So we know First player will win more than half of the time.
