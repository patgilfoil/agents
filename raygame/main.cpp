/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "KeyboardBehavior.h"
#include "Transition.h"
#include "IdleState.h"
#include "AttackState.h"
#include "WithinRangeCondition.h"
#include "FiniteStateMachine.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1366;
	int screenHeight = 768;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);

	Agent* player = new Agent();
	player->setPosition({ 100.0f, 100.0f });
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);

	Agent* enemy = new Agent();
	enemy->setPosition({ 500.0f, 500.0f });
	enemy->setSpeed(250.0f);
	enemy->setColor(GRAY);

	FiniteStateMachine* enemyFSM = new FiniteStateMachine();
	IdleState* idleState = new IdleState();
	enemyFSM->addState(idleState);
	AttackState* attackState = new AttackState(player, 250.0f);
	enemyFSM->addState(attackState);
	WithinRangeCondition* enemyRangeCond = new WithinRangeCondition(player, 250.0f);
	enemyFSM->addCondition(enemyRangeCond);
	Transition* toAttackTransition = new Transition(attackState, enemyRangeCond);
	enemyFSM->addTransition(toAttackTransition);
	idleState->addTransition(toAttackTransition);
	enemyFSM->setCurrentState(idleState);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		player->update(GetFrameTime());
		enemy->update(GetFrameTime());
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(DARKGREEN);

		player->draw();
		enemy->draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}