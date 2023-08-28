# What
True random string generator with an ncurses TUI, using RDRAND.
# Prerequisites
You need either Clang or GCC, and GNU Make, NASM, ncurses, and a CPU that supports the RDRAND instruction.
Acquire the aforementioned packages from the package manager of your chosen distro.

You may test if your CPU supports RDRAND with
```
grep --color=always rdrand /proc/cpuinfo | head -n1
```
if supported, the output should be a bunch of flags with RDRAND highlighted.

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
