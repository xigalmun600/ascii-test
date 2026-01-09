#include "drawlib.h"

#include <math.h>
#include <stddef.h>
#include <stdio.h>

// Terminal control
void set_cursor(bool state) {
  printf("\033[%s", state ? "?25h" : "?25l");
  fflush(stdout);
}

// Pixel draw
void put_pixel(double x, double y) {
  printf("\033[%d;%dH█", (int)(y + 0.5), (int)(x + 0.5));
}

// DDA algorythm
void draw_line(vec2d a, vec2d b) {
  double dx = b.x - a.x;
  double dy = b.y - a.y;

  double step = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);

  // Avoid division by zero
  if (!step) return;

  double stepX = dx / step;
  double stepY = dy / step;

  for (int i = 0; i < step; i++) {
    put_pixel(i * stepX + a.x, i * stepY + a.y);
  }
}

// project and print

void project(vec3d* wireframe, size_t w_size, edge* edge_list, size_t e_size) {
  int focal_length = 20;
  int z_offset = 100;

  vec2d out[w_size];
  for(int i = 0; i < w_size; i++){
    if (wireframe[i].z > -focal_length + 0.001){
      printf("Error");
    }
    out[i].x = wireframe[i].x * focal_length / (focal_length + wireframe[i].z - z_offset);
    out[i].y = wireframe[i].y * focal_length / (focal_length + wireframe[i].z) - z_offset;
  }

  for(int i = 0; i < e_size; i++){
    draw_line(out[edge_list[i].a], out[edge_list[i].b]);
  }

  printf("Working");
}