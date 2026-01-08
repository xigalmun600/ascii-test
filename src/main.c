#include "drawlib.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
  vec2d square[] = {{30, 30}, {60, 30}, {60, 60}, {30, 60}};
  int size = sizeof(square) / sizeof(vec2d);

  hide_cursor();

  // animation
  vec2d tranformed[size];
  for (int i = 0; i < 360; i++) {
    clear_screen();
    rotate2D(square, tranformed, size, i);
    draw_polygon(tranformed, size);
    fflush(stdout);
    usleep(30000);
  }

  show_cursor();
  return 0;
}