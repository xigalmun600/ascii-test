#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#include "drawlib.h"

#define ASPECT_Y 0.5

struct winsize get_screen_size(void) {
  struct winsize ws;
  ioctl(1, TIOCGWINSZ, &ws);
  return ws;
}

void put_pixel(int x, int y) {
  int px = (int)(x + 0.5);
  int py = (int)(y * ASPECT_Y + 0.5);
  printf("\033[%d;%dH█", py, px);
}

void draw_line(vec2d a, vec2d b) {
  double dx = b.x - a.x;
  double dy = b.y - a.y;
  double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

  if (steps == 0)
    return;

  double stepX = dx / steps;
  double stepY = dy / steps;

  double x = a.x;
  double y = a.y;

  for (int i = 0; i <= steps; i++) {
    put_pixel(x, y);
    x += stepX;
    y += stepY;
  }
}

void draw_polyline(vec2d points[], int size) {
  for (int i = 0; i < size - 1; i++) {
    draw_line(points[i], points[i + 1]);
  }
}

void draw_polygon(vec2d points[], int size) {
  for (int i = 0; i < size - 1; i++) {
    draw_line(points[i], points[i + 1]);
  }
  draw_line(points[size - 1], points[0]);
}

void rotate2D(vec2d points[], vec2d out[], int size, int deg) {
  double rad = (double)deg * M_PI / 180.0;

  double cx = 0, cy = 0;
  for (int i = 0; i < size; i++) {
    cx += points[i].x;
    cy += points[i].y;
  }

  cx /= size;
  cy /= size;

  for (int i = 0; i < size; i++) {
    double arrx = points[i].x - cx;
    double arry = points[i].y - cy;

    out[i].x = cos(rad) * arrx - sin(rad) * arry + cx;
    out[i].y = sin(rad) * arrx + cos(rad) * arry + cy;
  }
}

void clear_screen(void) { printf("\033[2J"); }
void show_cursor(void) { printf("\033[?25h"); }
void hide_cursor(void) { printf("\033[?25l"); }
