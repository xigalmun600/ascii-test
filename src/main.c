#include "drawlib.h"
#include <stdio.h>
#include <unistd.h>

int main(void) {
    vec3d vertices[] = {
        {-20,-20,-20}, {20,-20,-20}, {20,20,-20}, {-20,20,-20},
        {-20,-20, 20}, {20,-20, 20}, {20,20, 20}, {-20,20, 20}
    };
    Edge edges[] = {
        {0,1}, {1,2}, {2,3}, {3,0}, {4,5}, {5,6}, 
        {6,7}, {7,4}, {0,4}, {1,5}, {2,6}, {3,7}
    };

    double aX = 0, aY = 0;
    hide_cursor();

    while (1) {
        clear_screen();
        struct winsize ws = get_screen_size();
        vec3d rot_v[8];

        for (int i = 0; i < 8; i++) 
            rotate3D(vertices[i], &rot_v[i], aX, aY);

        for (int i = 0; i < 12; i++) {
            draw_line(project(rot_v[edges[i].a], ws.ws_col, ws.ws_row),
                      project(rot_v[edges[i].b], ws.ws_col, ws.ws_row));
        }

        aX += 1.5; aY += 0.8;
        fflush(stdout);
        usleep(30000);
    }
    return 0;
}