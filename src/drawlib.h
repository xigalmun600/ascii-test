#pragma once
#include <sys/ioctl.h>

typedef struct { double x, y; } vec2d;
typedef struct { double x, y, z; } vec3d;
typedef struct { int a, b; } Edge;

// Core Engine
struct winsize get_screen_size(void);
vec2d project(vec3d p, int width, int height);
void rotate3D(vec3d p, vec3d *out, double angleX, double angleY);

// Drawing
void put_pixel(int x, int y);
void draw_line(vec2d a, vec2d b);

// Screen Control
void clear_screen(void);
void show_cursor(void);
void hide_cursor(void);