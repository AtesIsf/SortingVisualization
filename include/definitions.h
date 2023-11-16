#ifndef VIS_DEF_H
#define VIS_DEF_H

#include <raylib.h>

#define N_BLOCKS 100

typedef enum Scene 
{
	MENU,
	BUBBLE,
	SELECTION
} scene_t;

typedef struct SortData
{
	int i;
	int j;
} sort_data_t;

typedef struct Block
{
	Rectangle box;
	Color col;
	unsigned int val;
	unsigned int freq;
} block_t;

typedef struct Data
{
	scene_t state;
	char exit;
	char sorting;
	sort_data_t *s_data;
	block_t blocks[N_BLOCKS]; // 100 * 9px
	
	Rectangle menu_buttons[3];
	Rectangle bubble_buttons[3];
	Rectangle sel_buttons[3];
} data_t;

void swapBlocks(block_t *blocks, int x, int y);

void shuffleBlocks(data_t *vars);

#endif
