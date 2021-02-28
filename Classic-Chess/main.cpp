#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/timer.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include "ChessBoard.h"

#define SCREEN_HEIGHT 1024
#define SCREEN_WIDTH 1024

const float FPS = 60.0;


int setup();

int main() {
	ALLEGRO_DISPLAY* display = nullptr;
	ALLEGRO_DISPLAY_MODE disp_data;
	ALLEGRO_TIMER* timer = nullptr;
	ALLEGRO_EVENT_QUEUE* event_queue = nullptr;

	bool exit = false;

	if (setup()) {
		fprintf(stderr, "There was an error in the setup process");
		return -1;
	}

	ChessBoard chessBoard;

	//Create the timer (FPS = 60)
	timer = al_create_timer(1.0 / FPS);

	//Verify that the timer was created without fault
	if (!timer) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create a timer!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	//Create the event queue
	event_queue = al_create_event_queue();

	//Verify that the event queue was created without fault
	if (!event_queue) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create a event_queue!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	//Get the display information for the current PC
	al_get_display_mode(al_get_num_display_modes() - 1, &disp_data);

	//Set the display to Windowed mode
	al_set_new_display_flags(ALLEGRO_WINDOWED);

	//Create the display															
	display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!display) {
		al_show_native_message_box(display, "Error", "Error", "Failed to create a display!", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		al_destroy_display(display);
		al_destroy_timer(timer);
		al_destroy_event_queue(event_queue);
		return -1;
	}

	//Register events to the event queue
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_clear_to_color(al_map_rgb(0, 255, 0));
	al_flip_display();

	//Start the timer
	al_start_timer(timer);

	//Start of the game loop
	while (!exit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {

			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_ESCAPE:
				exit = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES) ///check if the mouse moved
		{
			//if ((ev.mouse.x >= ButtonX) && (ev.mouse.x <= ButtonX + ButtonWidth) &&
			//	(ev.mouse.y >= ButtonY) && (ev.mouse.y <= ButtonY + ButtonHeight))
			//{
			//	OverButton = true;
			//}

			//else
			//{
			//	OverButton = false;
			//}
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) ///check if a mouse button was clicked
		{
			float y = ev.mouse.y;
			float x = ev.mouse.x;
			fprintf(stderr, "X: %f Y: %f \n", x, y);
			chessBoard.playerClicked(ev.mouse.x, ev.mouse.y);
			//if (OverButton == true)
			//{
			//	Exit = true;
			//}
		}




		if (al_is_event_queue_empty(event_queue)) {
			al_clear_to_color(al_map_rgb(0, 0, 0));

			// Draw here
			chessBoard.DrawBoard();

			al_flip_display();
		}
	}
}



int setup() {
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_init_image_addon()) {
		fprintf(stderr, "failed to image addon!\n");
		return -1;
	}

	if (!al_install_keyboard()) {
		fprintf(stderr, "failed to install keyboard!\n");
		return -1;
	}

	if (!al_install_audio()) {
		fprintf(stderr, "failed to install audio!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize acodec addon!\n");
		return -1;
	}

	if (!al_reserve_samples(1)) {
		fprintf(stderr, "failed to reserve sample!\n");
		return -1;
	}

	if (!al_init_font_addon()) {
		fprintf(stderr, "failed to initialize font addon!\n");
		return -1;
	}

	if (!al_init_ttf_addon()) {
		fprintf(stderr, "failed to initialize true text format addon!\n");
		return -1;
	}
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitive  addon!\n");
		return -1;
	}
	if (!al_install_mouse())
	{
		al_show_native_message_box(NULL, "Error!", "Failed to install mouse.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}

	return 0;
}
