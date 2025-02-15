# so_long

A 2D game project developed as part of the 42 school curriculum, where players navigate through a map collecting items before reaching the exit.

## Project Structure
```
so_long/
├── assets/
│   ├── door.xpm
│   ├── floor.xpm
│   ├── open_door.xpm
│   ├── player_on_door.xpm
│   ├── player.xpm
│   └── wall.xpm
├── ft_printf/
│   ├── ft_hexprint.c
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ft_printptr.c
│   ├── ft_printunsigned.c
│   ├── ft_putchar.c
│   ├── ft_putint.c
│   └── Makefile
├── gnl/
│   ├── get_next_line_utils.c
│   ├── get_next_line.c
│   └── get_next_line.h
├── maps/
│   └── map2.ber
└── src/
    ├── check_map.c
    ├── functions_needed.c
    ├── graphics.c
    ├── so_long.c
    ├── so_long.h
    └── Makefile
```

## Prerequisites
- CC compiler
- Make
- MinilibX library
- X11 development files (for Linux)

## Installation & Compilation
1. Clone the repository:
```bash
git clone [repository-url] so_long
cd so_long
```

2. Compile the project:
```bash
cd src
make
```

3. Run the game:
```bash
./so_long ../maps/map2.ber
```

## Game Elements
- `1`: Walls
- `0`: Empty spaces
- `P`: Player starting position
- `C`: Collectibles
- `E`: Exit

## Controls
- `W` or `↑`: Move up
- `S` or `↓`: Move down
- `A` or `←`: Move left
- `D` or `→`: Move right
- `ESC`: Close game

## Map Requirements
- Must have `.ber` extension
- Must be rectangular
- Must be surrounded by walls (`1`)
- Must contain:
  - One player (`P`)
  - At least one collectible (`C`)
  - One exit (`E`)
- Must have a valid path to all collectibles and exit

## Components Description
- `assets/`: Contains all game sprites in XPM format
- `ft_printf/`: Custom printf implementation
- `gnl/`: Get Next Line implementation for map reading
- `maps/`: Contains game maps
- `src/`: Main game logic and source files

## Utilities
- `ft_printf`: Custom printf implementation for output handling
- `get_next_line`: File reading utility for map parsing

## Error Handling
The game validates:
- Map format and content
- File existence and permissions
- Memory allocation
- MinilibX initialization
- Input parameters

## Memory Management
- All allocated memory is properly freed
- No memory leaks during gameplay
- Clean exit on game completion or error

## Development Notes
- Built using MinilibX library
- Compliant with 42 school norms
- Handles window events properly
- Includes move counter display

## Troubleshooting
If you encounter issues:
1. Verify map file path is correct
2. Check map format follows requirements
3. Ensure MinilibX is properly installed
4. Verify all dependencies are present

## Resources
- MinilibX Documentation
- 42 School Project Page
- XPM File Format Documentation

## License
This project is part of the 42 school curriculum.
