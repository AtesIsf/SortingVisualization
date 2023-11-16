#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

#include "menu.h"
#include "definitions.h"

void menuUpdate(data_t *vars)
{
	Vector2 mouse_pos;

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		mouse_pos = GetMousePosition();

		if (CheckCollisionPointRec(mouse_pos, vars->menu_buttons[0]))
			vars->state = BUBBLE;

		if (CheckCollisionPointRec(mouse_pos, vars->menu_buttons[1]))
			vars->state = SELECTION;

		if (CheckCollisionPointRec(mouse_pos, vars->menu_buttons[2]))
			vars->exit = 1;	
	}
}

void menuDraw(data_t *vars)
{
	DrawText("Main Menu", 300, 80, 75, RAYWHITE);
	
	for (int i = 0; i < 3; i++)
		DrawRectangleLinesEx(vars->menu_buttons[i], 1, RAYWHITE);

	DrawText("Bubble", vars->menu_buttons[0].x + 48, vars->menu_buttons[0].y + 10, 60, RAYWHITE);
	DrawText("Selection", vars->menu_buttons[1].x + 12, vars->menu_buttons[1].y + 10, 60, RAYWHITE);
	DrawText("Exit", vars->menu_buttons[2].x + 96, vars->menu_buttons[2].y + 10, 60, RAYWHITE);
}

