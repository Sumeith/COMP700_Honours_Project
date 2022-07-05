#pragma once

#define SCREEN_WIDTH_MENU 700
#define SCREEN_HEIGHT_MENU 600
#define TITLE_MENU "Main Menu"

#define SCREEN_WIDTH_7x6 700
#define SCREEN_HEIGHT_7x6 600
#define TITLE_7x6 "Connet 4 on a 7x6 board"

#define SCREEN_WIDTH_4x4 400
#define SCREEN_HEIGHT_4x4 400
#define TITLE_4x4 "Connet 4 on a 4x4 board"

#define SCREEN_WIDTH_21x18 1050
#define SCREEN_HEIGHT_21x18 900
#define TITLE_21x18 "Connet 4 on a 21x18 board"

#define TRANSITION_TIME 10

#define MAIN_MENU_BACKGROUND_PATH "Resourses\\grid.png"
#define GAME_BOARD_PATH "Resourses\\grid.png"
#define PLAYER_ONE_DISC_PATH "Resourses\\red_disc.png"
#define PLAYER_ONE_DISC_SMALL_PATH "Resourses\\red_disc_small.png"
#define PLAYER_TWO_DISC_PATH "Resourses\\blue_disc.png"
#define PLAYER_TWO_DISC_SMALL_PATH "Resourses\\blue_disc_small.png"
#define EMPTY_DISC_PATH "Resourses\\empty_disc.png"
#define EMPTY_DISC_SMALL_PATH "Resourses\\empty_small_disc.png"

#define PLAYER_ONE_WINS 1000
#define PLAYER_TWO_WINS - PLAYER_ONE_WINS

#define IN_PROGRESS 200
#define GAME_OVER - IN_PROGRESS

enum Discs
{
	PLAYER_ONE_DISC = 1,
	PLAYER_TWO_DISC = -1,
	EMPTY_DISC = 0
};

#define HEIGHT_7x6 6
#define WIDTH_7x6 7

typedef struct Board_7x6 {
	Discs _grid[HEIGHT_7x6][WIDTH_7x6];
};

#define HEIGHT_4x4 4
#define WIDTH_4x4 4

typedef struct Board_4x4 {
	Discs _grid[HEIGHT_4x4][WIDTH_4x4];
};

#define HEIGHT_21x18 18
#define WIDTH_21x18 21

typedef struct Board_21x18 {
	Discs _grid[HEIGHT_21x18][WIDTH_21x18];
};