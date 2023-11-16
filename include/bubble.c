#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <raylib.h>
#include <raymath.h>

#include "definitions.h"
#include "bubble.h"

void bubbleStep(data_t *vars)
{
	if (! (vars->s_data.j < N_BLOCKS - vars->s_data.i - 1))
	{
		vars->s_data.j = 0;
		vars->s_data.i++;

		if (vars->s_data.i == N_BLOCKS)
		{
			vars->s_data.i = 0;
			vars->s_data.j = 0;
			vars->sorting = 0;
		}
	}

	block_t *pre = &(vars->blocks[vars->s_data.j]);
	block_t *post = &(vars->blocks[vars->s_data.j + 1]);

	if (pre->val > post->val)
		swapBlocks(vars->blocks, vars->s_data.j, vars->s_data.j + 1);

	usleep(10);

	vars->s_data.j++;
}

void bubbleUpdate(data_t *vars)
{
	Vector2 mouse_pos;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		mouse_pos = GetMousePosition();

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[0]))
			vars->state = MENU;

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[1]))
			vars->sorting = 1;	

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[2]))
			shuffleBlocks(vars);	
	}

	if (vars->sorting)
	{
		bubbleStep(vars);
	}
}

void bubbleDraw(data_t *vars)
{
	for (int i = 0; i < 3; i++)
	{
		DrawRectangleLinesEx(vars->bubble_buttons[i], 1, RAYWHITE);
	}

	DrawText("Menu", vars->bubble_buttons[0].x + 18, vars->bubble_buttons[0].y + 8, 26, RAYWHITE);
	DrawText("Start", vars->bubble_buttons[1].x + 16, vars->bubble_buttons[1].y + 8, 26, RAYWHITE);
	DrawText("Shuffle", vars->bubble_buttons[2].x + 4, vars->bubble_buttons[2].y + 8, 26, RAYWHITE);
	DrawText("-- Bubble Sort", 400, 58, 26, RAYWHITE);

	for (int i = 0; i < 100; i++)
		DrawRectangleRec(vars->blocks[i].box, vars->blocks[i].col);
}

