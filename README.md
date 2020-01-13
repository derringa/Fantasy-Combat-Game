# Fantasy-Combat-Game #
The simulator contains multiple classes, most of which contain unique abilities, that can be paired into teams to compete in a turn based dice rolling Dungeons and Dragons style fight to the last team standing.

## Game-Play ##
* Two teams of a customizable size and combination of character types each with a unique user input name.
* Character on each team match-up 1v1. The winner goes to the back of the line of their team and the loser moves to the loser pile.
* Dice roles and results fo each attack are displayed for every combat.
* Winner is announced and loser pile can be displayed upon completion.

## Character Types ##
TYPE         | ATTACK |	DEFENSE	| ARMOR |	STRENGTH POINTS
-------------|--------|---------|-------|----------------
Vampire      |	1d12	| 1d6*    |	1	    | 18
Barbarian    |	2d6	  | 2d6	    | 0	    | 12
Blue Men     |	2d10  | 3d6*    | 3	    | 12
Medusa	     |  2d6*  |	1d6	    | 3	    | 8
Harry Potter |	2d6   | 2d6	    | 0	    | 10/20*

* \* Vampire Charm: Rolling a 6 defense results in no damage taken even from special attacks.
* \* Blue Men Mob: For every 4 points of damage taken, Blue Men lose one defense die.
* \* Medusa Glare: Rolling a 12 attack results in an instant kill glare attack (except in cases of vampire charm).
* \* Harry Potter Deathly Hollows: Upon first death Harry is resurrected with 20 strength points.

## Design ##
The emphasis of the game is a build and use our own circular or straight linked queues and linked stack structures holding polymorphic derived class instances. Each class interacts with others independent of their unique characteristics and class types allowing the game to be scalable for new characters without having to revisit previously developed classes.

## Set-Up ##
```
make run
```
