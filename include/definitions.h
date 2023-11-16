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
	block_t blocks[N_BLOCKS]; // 100 * 9px
	
	Rectangle menu_buttons[3];
	Rectangle bubble_buttons[3];
	Rectangle sel_buttons[3];
} data_t;

void shuffleBlocks(block_t *blocks);

#endif
