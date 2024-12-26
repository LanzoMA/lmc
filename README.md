# Little Man Computer (LMC)

* A simple CLI Little Man Computer (LMC) emulator.

# Prerequisites

* Git (recommended)
* GCC (or any C++ compiler)
* CMake

## Example Commands on Linux to Install Prerequisites

### Debian Based Distros (Debian, Ubuntu, Linux Mint etc.)

``` Bash
sudo apt install git g++ cmake build-essential
```

### Arch Based Distros (Arch, Manjaro etc.) 

``` Bash
sudo pacman -S git base-devel cmake
```

# Build Instructions

* Open a terminal.
* Go to a directory where you want clone this repo.
* Create a build directory to build using CMake.

* The commands for this are listed below.
* Enter these commands one by one.

```
git clone https://github.com/LanzoMA/lmc.git
cd lmc/
mkdir build/
cd build/
cmake ../
```

# How to Use

* Inside `examples/` there are example programs to run:

![Example LMC Code](assests/example-code.png)

* This is code for adding two numbers and outputting their total.
* To run this program, run the lmc program with the file path to the code as the first argument. e.g.

```
./lmc examples/add_two_numbers.lmc
```

## *Very Important*

**Labels, opcodes and operands must have a single space between them.** e.g. 

``` LMC
loop BRP end
```

# Limitations

* This emulator is NOT a good tool for explaining LMC and the basics of assembly.
* No vizualizations of the registers.
* Not currently able to change the 'clock speed' to slow down execution.
* The accumulator, MDR, MAR and RAM locations can store numbers larger than 3 digits.

