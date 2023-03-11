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

## Debugging and profiling
sudo apt-get install gdb valgrind kcachegrind

To use valgrind to analyse and profile the application:
`valgrind --tool=callgrind ./maze <path-to-maze>`

Then view and evaluate the results with kcachegrind:
`kcachegrind callgrind.out.<pid>`

## Performance

| Version | 42x60_16793.dat | 400x566_11860.dat |
|---------|-----------------|-------------------|
| v0.1.0  |         20.172s |               N/A |
| v0.2.0  |          0.028s |           43.691s |
| v0.3.0  |          0.007s |            0.366s |
