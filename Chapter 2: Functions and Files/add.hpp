// // header guard for add.h, preventing ODR violations
// #ifndef ADD_H
// #define ADD_H

// int add(int x, int y);

// #endif

// this leaves the responsibility of guarding the header up to the compiler (i.e. implementation specific)
#pragma once

int add(int x, int y);
