#pragma once
#include <sys/ioctl.h>

typedef struct {
  double x;
  double y;
} vec2d;

typedef struct {
  double x;
  double y;
  double z;
} vec3d;

struct winsize get_screen_size(void);
void put_pixel(int x, int y);
void draw_line(vec2d a, vec2d b);
void draw_polyline(vec2d points[], int size);
void rotate2D(vec2d points[], vec2d out[], int size, int deg);
void clear_screen(void);
void show_cursor(void);
void hide_cursor(void);