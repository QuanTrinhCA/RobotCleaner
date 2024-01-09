# [Problem E: Robot Cleaner](https://nbhspc21.kattis.com/contests/nbhspc21/problems/nbhspc21.robotcleaner)

You have a robot that can clean your floor, but you have to give it a sequence of commands directing its movements. The floor is mapped as a grid, and each command contains distance (number of cells) moved followed by one word for the direction (up, down. left, or right). For example, assuming that the robot is in position (2,3), here are the places it would go based on the command indicated (always starting from (2,3)):

- 2 up -> (2,5)
- 1 down -> (2,2)
- 1 left -> (1,3)
- 3 right -> (5,3)

There is some juice spilled on the floor, covering all cells for which the two coordinates are the same, for the entire floor surface. For example, on a floor that is of dimension 3 by 4, the cells with spilled juice would be (1,1), (2,2) and (3,3). You want to make sure that the robot manages to go to each of these cells on that diagonal. You also want to make your robot stop as soon as all dirty cells have been covered, even if it did not manage to cover the entire floor.

## Input
The input starts with one line containing 2 positive integers smaller than 20, representing the dimension of the floor (maximum value for x first, followed by maximum value for y). The integers are separated by a single space.

The second line contains the initial position for the robot (x value, a space, then y value), within the range of the grid size specified on the first line of input.

Then the third line has a positive integer n (smaller than 50) indicating the number of moves programmed for your robot. Finally, you have n lines, one per move, each one first indicating the number of cells the robot should move (as a positive integer) and then the direction of that move (as one of the four words above). It is guaranteed that all moves will be valid (i.e., will stay within the boundary of the floor grid).

## Output
You should follow the moves of the robot, and print its location (x coordinate, then y coordinate) at the end of each move. Take note if, as the robot moved, it went over one of the dirty cells. Once all dirty cells have been cleaned, stop the robot (i.e., do not make it continue with the sequence of moves).

For the first example below, the cell (1,1) is covered by the initial position, the cell (3,3) is covered by the second move, and the cell (2,2) is covered by the fourth move. Then all remaining moves are not done.

For the second example below, the movements are the same, but since the grid is larger, the dirty cell (4,4) is never covered, so the result of all moves are listed in the output.

## Sample Input 1
```
3 4
1 1
7
2 up
2 right
1 down
2 left
1 down
2 right
3 up
```

## Sample Output 1
```
1 3
3 3
3 2
1 2
```

## Sample Input 2
```
4 4
1 1
7
2 up
2 right
1 down
2 left
1 down
2 right
3 up
```

## Sample Output 2
```
1 3
3 3
3 2
1 2
1 1
3 1
3 4
```
