![C Build](https://github.com/alexvesey/NumericalRecipes/workflows/C%20Build/badge.svg) ![Rusr Build](https://github.com/alexvesey/NumericalRecipes/workflows/Rust%20Build/badge.svg) 
# Numerical Recipes
## Adventues in C and Rust

This Repository is a playground for me to learn both ANSI C and Rust

I will be doing so by following along with the book _Numerical Recepies in C The Art of Scientific Computing Second Edition_

At the beginning of this project (Where we are now) I only have expreience with C++. To learn both languages I will
be following the book and implementing all of the programs in the book as they are given in C. I will then attempt to 
translate these to Rust. An integration and test suite may also come about as a means of comparing the implementations.

## Build Instructions
### C

To build the C source code, create an out-of-souce build directory. So staring in the numerical-recipes folder:
- mkdir ../build/ && cd ../build
- cmake ../numerical-recepies/in_c/
- make

### Rust

The rust code uses cargo. So starting in the numerical-recipes folder:
- cd in_rust
- cargo build

## Test Suite
### C

To run the tests in C first build the project then starting in the numerical-recipes folder:
- cd ../build/bin
- ./Driver

### Rust

To run the tests for the Rust portion, starting in the numerical-recipes folder:
- cd in_rust
- cargo test
