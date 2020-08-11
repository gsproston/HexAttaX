# HexAttaX

A simple two player game 

## Rules

Each player takes turns selecting a hexagonal tile on the grid.

Once selected, a blank tile becomes a player's level 1 tile. 

If a player selects a tile they already own, it levels up. 

Tiles have a maximum level of 3.

Level 3 tiles cannot be selected.

A player cannot select the other player's tile.

If a player levels up a tile they own, this propogates to the surrounding tiles.

Propogation allows a player to take the other player's tiles.

Propogation only happens to the surrounding tiles that are exactly one level below the newly selected one.

For example, if a player levels up a tile they own to level 3, all surrounding level 2 tiles become owned by that player, even if they weren't before. The same then happens to all level 1 tiles surrounding the level 2 tiles.

A player's points are equal to all the cumulative levels of the tiles they own.

For example, if a player owns a level 3 tile and a level 2 tile, they have 5 points.

The game ends when there are no more blank tiles on the board.

## License
[MIT](https://choosealicense.com/licenses/mit/)
