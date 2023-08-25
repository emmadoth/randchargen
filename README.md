# What
True random string generator with an ncurses TUI, using RDSEED.
# Prerequisites
You need either Clang or GCC, and GNU Make, ncurses, and a CPU that supports the RDSEED instruction.
Acquire the aforementioned packages from the package manager of your chosen distro.

You may test if your CPU supports RDSEED with
```
grep --color=always rdseed /proc/cpuinfo | head -n1
```
if supported, the output should be a bunch of flags with RDSEED highlighted.

# Compile
```
make
```
alternatively the Clang compiler may be used, like so:
```
CC=clang make
```
# Run
Run in a terminal via
```
./chargen
```
and follow the instruction on the creen.
