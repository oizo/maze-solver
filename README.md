# Maze solver

Maze solver is a learning project, focused on learning new technology - in this case c++.

## Build

The instructions make the assumption that you are on a Debian-based distribution, e.g. Ubuntu or Linux Mint. You will need to install a couple of packages to easily build the maze solver.

### Install dependencies
sudo apt-get install build-essential gdb cmake

### Build with cmake

```bash
cmake .;
cmake --build ./
```

## Run maze solver

`maze <path-to-maze>`

## Debugging, performance and profiling
sudo apt-get install gdb valgrind kcachegrind

To use valgrind to analyse and profile the application:
`valgrind --tool=callgrind ./maze <path-to-maze>`

Then view and evaluate the results with kcachegrind:
`kcachegrind callgrind.out.<pid>`
