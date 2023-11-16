#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <raymath.h>

#include "include/definitions.h"
#include "include/menu.h"
#include "include/bubble.h"
#include "include/selection.h"

void shuffleBlocks(block_t *blocks)
{
	int i, j;
	float temp;

	for (i = 0; i < N_BLOCKS - 1; i++)
	{
		j = i + rand() / (RAND_MAX / (N_BLOCKS - i) + 1);	
		
		temp = blocks[i].box.x;
		blocks[i].box.x = blocks[j].box.x;
		blocks[j].box.x = temp;
	}
}

data_t * init()
{
	InitWindow(980, 640, "Sorting Visualization");
	SetTargetFPS(60);
	SetExitKey(0);
	srand(0);

	data_t *vars = (data_t *) malloc(sizeof(data_t));
	vars->state = MENU;

	int i;
	for (i = 0; i < 3; i++)
	{
		vars->menu_buttons[i].x = 340;
		vars->menu_buttons[i].y = 200 + (100 * i);
		vars->menu_buttons[i].width = 300; 
		vars->menu_buttons[i].height = 80;

		vars->bubble_buttons[i].x = 50 + (120 * i);
		vars->bubble_buttons[i].y = 50;
		vars->bubble_buttons[i].width = 100;
		vars->bubble_buttons[i].height = 40;

		vars->sel_buttons[i].x = 50 + (120 * i);
		vars->sel_buttons[i].y = 50;
		vars->sel_buttons[i].width = 100;
		vars->sel_buttons[i].height = 40;
	}

	for (i = 0; i < N_BLOCKS; i++)
	{
		vars->blocks[i].col = RAYWHITE;
		vars->blocks[i].val = i;
		vars->blocks[i].box.x = 40 + (9 * i);
		vars->blocks[i].box.y = 600 - (5 * (i + 1)); // blocks will go from h = 5 to h = 500
		vars->blocks[i].box.width = 9;
		vars->blocks[i].box.height = 5 * (i + 1);
		vars->blocks[i].freq = 0; // TODO: may add that frequency thing later
	}

	return vars;
}

void deinit(data_t *vars)
{
	CloseWindow();
	free(vars);
}

void update(data_t *vars)
{
	// Update selected scene
	switch (vars->state) 
	{
		case MENU:	
			menuUpdate(vars);
			break;

		case BUBBLE:
			bubbleUpdate(vars);
			break;

		case SELECTION:
			selUpdate(vars);
			break;

		default:
			vars->exit = 1;
			break;
	}

}

void draw(data_t *vars)
{
	BeginDrawing();

	// Generic border
	ClearBackground(BLACK);
	DrawRectangleLines(40, 40, 900, 560, RAYWHITE);
	
	// Guiding Lines
	// DrawRectangleLines(300, 0, 380, 640, RED);
	// DrawRectangleLines(340, 0, 300, 640, RED);

	// Draw selected scene
	switch (vars->state) 
	{
		case MENU:	
			menuDraw(vars);
			break;

		case BUBBLE:
			bubbleDraw(vars);
			break;

		case SELECTION:
			selDraw(vars);
			break;

		default:
			vars->exit = 1;
			break;
	}

	EndDrawing();
}

int main()
{
	data_t *vars = init();
	
	while (!(vars->exit) && !WindowShouldClose())
	{
		update(vars);

		draw(vars);
	}

	deinit(vars);
	return 0;
}
