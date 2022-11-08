# so_long
![Project illustration](./illustration.png "")<br>
This project is the 7th of the 42 School cursus.<br>

# Description
In this project, we must implement our own 2D game, using the miniLibX library.<br>
The rules of the game are as followed:<br>
- Maps must be stored in files, and the extension must be ".ber".<br>
- Maps must be composed of only 9 possible characters:<br>
  - 0 for an empty space<br>
  - 1 for a wall<br>
  - P for the player's starting position<br>
  - C for a collectible item<br>
  - E for an exit<br>
  - n for a north-facing enemy<br>
  - w for a west-facing enemy<br>
  - s for a south-facing enemy<br>
  - e for an east-facing enemy<br>
- The map must be closed/surrounded by walls.<br>
- The player must collect all the collectible items, then go to the exit to win the game.<br>
- The player can move using the W, A, S and D keys, or the arrow keys.<br>
- The player can quit the game by pressing the ESC key, or by clicking the top-right cross.<br>
- If the player touches an enemy, the game is over.<br>
- The game must display the number of moves the player has made.<br>
