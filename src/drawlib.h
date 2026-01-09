#pragma once
#include <stdbool.h>
#include <stdio.h>

// types
typedef struct {
  double x;
  double y;
} vec2d;

typedef struct {
  double x;
  double y;
  double z;
} vec3d;

typedef struct {
  int a;
  int b;
} edge;

// Terminal control
void set_cursor(bool state);

// Raw draw
void put_pixel(double x, double y);
void draw_line(vec2d a, vec2d b);

// Calculations
void project(vec3d* wireframe, size_t w_size, edge* edge_list, size_t e_size);