# Non attacking queens Game (aka. n-queens game)
Non-attacking queens game or the n-queens game, is a 2-player game, in which at each turn, one person places a queen into a board on an unattacked tile. Player who can't move when it's their turn is the loser.

This was written at first for research purpose only, but I have turned it into a game so that you can play interactively with a CPU player. See below for more information on the files.

## Files
### BMP.h
It is a library, allows me to edit .BMP files easily
[Here is where i got it from](https://github.com/sol-prog/cpp-bmp-images/blob/master/BMP.h)

### nAQ_Winner.cpp
Using brute-force to calculate all possible games on a N\*N board, take N as input, output the winner. (if they play optimally obviously)
Only output results.

### nAQ_Play.cpp
A program allows you to play against an optimal CPU player. The program while running will render data to `dat.png` as you play. Please also open the file while running the program. It is especially convenient if your image viewers reload itself if the image file changes.

If the CPU cant win it will state that it's moving randomly. Good luck.

# Research results
After letting a no-brainer's terribly-written, poorly-designed brute-force running about half an hour

Here is the result. First column is **N**, second column is the winner of the board size **N\*N** (normal text is First player, Bold text is Second player), third column is the optimal First move, last collumn is runtime.

It is quite interesting to see Second player starting to have a chance when it reaches *N = 10*.

![Data](https://github.com/nvatuan/nonAttackingQueensGame_mytake/blob/master/dat.png)

Also there is an optimal strategy for First player to always win on board given **N is an odd number**. Placing in the middle first then mirror Second player's move (through the center). 

So we know First player will win more than half of the time.
