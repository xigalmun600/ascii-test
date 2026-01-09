#include <math.h>
#include <stdio.h>
#include "drawlib.h"

#define ASPECT_Y 0.5

struct winsize get_screen_size(void) {
    struct winsize ws;
    ioctl(1, TIOCGWINSZ, &ws);
    return ws;
}

void put_pixel(int x, int y) {
    printf("\033[%d;%dH█", (int)(y * ASPECT_Y + 0.5), (int)(x + 0.5));
}

void draw_line(vec2d a, vec2d b) {
    double dx = b.x - a.x, dy = b.y - a.y;
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    if (steps == 0) return;

    double x = a.x, y = a.y;
    for (int i = 0; i <= steps; i++) {
        put_pixel(x, y);
        x += dx / steps;
        y += dy / steps;
    }
}

void rotate3D(vec3d p, vec3d *out, double angleX, double angleY) {
    double radX = angleX * M_PI / 180.0;
    double radY = angleY * M_PI / 180.0;
    vec3d t = p;

    // X-Axis Rotation
    double y = t.y * cos(radX) - t.z * sin(radX);
    double z = t.y * sin(radX) + t.z * cos(radX);
    t.y = y; t.z = z;

    // Y-Axis Rotation
    double x = t.x * cos(radY) + t.z * sin(radY);
    t.z = -t.x * sin(radY) + t.z * cos(radY);
    t.x = x;

    *out = t;
}

vec2d project(vec3d p, int width, int height) {
    double factor = (width * 0.5) / (p.z + 100.0);
    return (vec2d){ (p.x * factor) + (width / 2.0), (p.y * factor) + (height / 2.0) };
}

void clear_screen(void) { printf("\033[2J"); }
void show_cursor(void) { printf("\033[?25h"); }
void hide_cursor(void) { printf("\033[?25l"); }