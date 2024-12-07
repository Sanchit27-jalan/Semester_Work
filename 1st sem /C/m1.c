#include <stdio.h>
#include "allegro.h"

// all the drawing logic
// see drawing primitives (https://liballeg.org/a5docs/trunk/primitives.html)
// for all the shapes that can be drawn
// with specifications of various functions
void draw() {
    al_clear_to_color(al_map_rgb(0, 0, 0)); // sets background to black
    // draws a green triangle with vertices at particular 3 points
    al_draw_filled_triangle(35, 350, 85, 375, 35, 400, al_map_rgb_f(0, 1, 0)); 
    // draws a transparent blue rectangle, with diagonal opposite vertices at specified points
    al_draw_filled_rectangle(240, 260, 340, 340, al_map_rgba_f(0, 0, 0.5, 0.5));
    al_draw_circle(450, 370, 30, al_map_rgb_f(1, 0, 1), 2);
    al_draw_line(440, 110, 460, 210, al_map_rgb_f(1, 0, 0), 1);
    al_draw_line(500, 220, 570, 200, al_map_rgb_f(1, 1, 0), 1);

    al_flip_display();  // Outputs the picture drawn to the screen
}

int main() {

    allegro_init();
    
    ALLEGRO_EVENT event;

    draw();

    // wait for some event to enter the queue.
    // In this case, it is only the event for closing the window
    al_wait_for_event(queue, &event);
    allegro_close();

    return 0;
}