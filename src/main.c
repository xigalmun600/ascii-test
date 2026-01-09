#include <stdio.h>
#include <unistd.h>

#include "drawlib.h"

int main() {
  vec3d cube[8] = {// Top face
                   {0, 10, 0},
                   {10, 10, 0},
                   {10, 10, 10},
                   {0, 10, 10},
                   // Bottom face
                   {0, 0, 0},
                   {10, 0, 0},
                   {10, 0, 10},
                   {0, 0, 10}};

  edge edgelist[12] = {// Top face
                       {0, 1},
                       {1, 2},
                       {2, 3},
                       {3, 0},
                       // Bottom face
                       {4, 5},
                       {5, 6},
                       {6, 7},
                       {7, 4},
                       // Middle edges
                       {3, 7},
                       {0, 4},
                       {1, 5},
                       {2, 6}};

  int vertex_size = sizeof(cube) / sizeof(cube[0]);
  int edge_size = sizeof(edgelist) / sizeof(edgelist[0]);

  project(cube, vertex_size, edgelist, edge_size);
  set_cursor(false);
  fflush(stdout);
  pause();
  return 0;
}