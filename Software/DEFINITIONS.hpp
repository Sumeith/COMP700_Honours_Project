#pragma once

#define SCREEN_WIDTH_MENU 700
#define SCREEN_HEIGHT_MENU 600
#define TITLE_MENU "Main Menu"

#define SCREEN_WIDTH_4x4 400
#define SCREEN_HEIGHT_4x4 400
#define TITLE_4x4 "Connet 4 on a 4x4 board"

#define SCREEN_WIDTH_7x4 700
#define SCREEN_HEIGHT_7x4 400
#define TITLE_7x4 "Connet 4 on a 7x4 board"

#define SCREEN_WIDTH_4x7 400
#define SCREEN_HEIGHT_4x7 700
#define TITLE_4x7 "Connet 4 on a 4x7 board"

#define SCREEN_WIDTH_7x6 700
#define SCREEN_HEIGHT_7x6 600
#define TITLE_7x6 "Connet 4 on a 7x6 board"

#define SCREEN_WIDTH_6x7 600
#define SCREEN_HEIGHT_6x7 700
#define TITLE_6x7 "Connet 4 on a 6x7 board"

#define SCREEN_WIDTH_8x8 800
#define SCREEN_HEIGHT_8x8 800
#define TITLE_8x8 "Connet 4 on a 8x8 board"

#define SCREEN_WIDTH_14x12 700
#define SCREEN_HEIGHT_14x12 600
#define TITLE_14x12 "Connet 4 on a 14x12 board"

#define SCREEN_WIDTH_12x14 600
#define SCREEN_HEIGHT_12x14 700
#define TITLE_12x14 "Connet 4 on a 12x14 board"

#define TRANSITION_TIME 0

//#define MAIN_MENU_BACKGROUND_PATH "Resourses\\grid.png"
//#define GAME_BOARD_PATH "Resourses\\grid.png"
#define PLAYER_ONE_DISC_PATH "Resourses\\red_disc.png"
#define PLAYER_ONE_DISC_SMALL_PATH "Resourses\\red_disc_small.png"
#define PLAYER_ONE_WIN_DISC_PATH "Resourses\\red_win_disc.png"
#define PLAYER_ONE_WIN_DISC_SMALL_PATH "Resourses\\red_win_disc_small.png"
#define PLAYER_TWO_DISC_PATH "Resourses\\blue_disc.png"
#define PLAYER_TWO_DISC_SMALL_PATH "Resourses\\blue_disc_small.png"
#define PLAYER_TWO_WIN_DISC_PATH "Resourses\\blue_win_disc.png"
#define PLAYER_TWO_WIN_DISC_SMALL_PATH "Resourses\\blue_win_disc_small.png"
#define EMPTY_DISC_PATH "Resourses\\empty_disc.png"
#define EMPTY_DISC_SMALL_PATH "Resourses\\empty_small_disc.png"

#define PLAYER_ONE_WINS INT_MAX
#define PLAYER_TWO_WINS INT_MIN

#define THREE_IN_A_ROW_VALUE 9000
#define TWO_IN_A_ROW_VALUE 5000

#define PLAYER_ONE 1
#define PLAYER_TWO -PLAYER_ONE

#define POS_INF INT_MAX
#define NEG_INF INT_MIN

typedef enum
{
	PLAYER_ONE_DISC = 1,
	PLAYER_TWO_DISC = -1,
	EMPTY_DISC = 0
}Discs;

#define HEIGHT_4x4 4
#define WIDTH_4x4 4

typedef struct {
	Discs _grid[HEIGHT_4x4][WIDTH_4x4];
}Board_4x4;

#define HEIGHT_7x4 4
#define WIDTH_7x4 7

typedef struct {
	Discs _grid[HEIGHT_7x4][WIDTH_7x4];
}Board_7x4;

#define HEIGHT_4x7 7
#define WIDTH_4x7 4

typedef struct {
	Discs _grid[HEIGHT_4x7][WIDTH_4x7];
}Board_4x7;

#define HEIGHT_7x6 6
#define WIDTH_7x6 7

typedef struct {
	Discs _grid[HEIGHT_7x6][WIDTH_7x6];
}Board_7x6;

#define HEIGHT_6x7 7
#define WIDTH_6x7 6

typedef struct {
	Discs _grid[HEIGHT_6x7][WIDTH_6x7];
}Board_6x7;

#define HEIGHT_8x8 8
#define WIDTH_8x8 8

typedef struct {
	Discs _grid[HEIGHT_8x8][WIDTH_8x8];
}Board_8x8;

#define HEIGHT_14x12 12
#define WIDTH_14x12 14

typedef struct {
	Discs _grid[HEIGHT_14x12][WIDTH_14x12];
}Board_14x12;

#define HEIGHT_12x14 14
#define WIDTH_12x14 12

typedef struct {
	Discs _grid[HEIGHT_12x14][WIDTH_12x14];
}Board_12x14;