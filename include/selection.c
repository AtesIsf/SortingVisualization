#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>
#include <raymath.h>

#include "definitions.h"
#include "bubble.h"

void selUpdate(data_t *vars)
{
	Vector2 mouse_pos;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		mouse_pos = GetMousePosition();

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[0]))
			vars->state = MENU;

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[1]))
		{
			// TODO: Start sim logic
		}

		if (CheckCollisionPointRec(mouse_pos, vars->bubble_buttons[2]))
			shuffleBlocks(vars);	
	}
}

void selDraw(data_t *vars)
{
	for (int i = 0; i < 3; i++)
	{
		DrawRectangleLinesEx(vars->bubble_buttons[i], 1, RAYWHITE);
	}

	DrawText("Menu", vars->sel_buttons[0].x + 18, vars->sel_buttons[0].y + 8, 26, RAYWHITE);
	DrawText("Start", vars->sel_buttons[1].x + 16, vars->sel_buttons[1].y + 8, 26, RAYWHITE);
	DrawText("Shuffle", vars->sel_buttons[2].x + 4, vars->sel_buttons[2].y + 8, 26, RAYWHITE);
	DrawText("-- Selection Sort", 400, 58, 26, RAYWHITE);

	for (int i = 0; i < 100; i++)
		DrawRectangleRec(vars->blocks[i].box, vars->blocks[i].col);
}

