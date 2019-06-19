class PuzzleBoard {
private:
// your choice
public:
// Subpoint (b)
PuzzleBoard(int boardSize, int[][] fields = null);
/* constructor should create the
graph (as you defined it in subpoint (a) with the values from fields.
If fields is null, then initialize the fields of the board with
random values between 1 and boardSize-1. */
bool makeMove(int direction);
/* makes the move (if valid), direction is 0 for up, 1
for right, 2 for down, 3 for left. Returns true if the move was
valid, false otherwise. */
bool getResult();
/* Returns false if game is not over yet, true if puzzle was solved */
std::ostream &operator<<(std::ostream &os, PuzzleBoard const &m);
/* in Python, this is the __str__ method. */
// Subpoint (c)
int solve();
/* returns the minimum number of moves needed to solve the puzzle,
and -1 if it is not solvable. */
}