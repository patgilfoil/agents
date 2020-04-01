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
#include "Agent.h"
#include "Transition.h"
#include "KeyboardBehavior.h"
#include "ScreenEdgeBehavior.h"
#include "WanderBehavior.h"
#include "SeekBehavior.h"
#include "PursuitBehavior.h"
#include "FiniteStateMachine.h" 
#include "IdleState.h"
#include "AttackState.h"
#include "WithinRangeCondition.h"
#include "DecisionTreeBehavior.h"
#include "BooleanDecision.h"
#include "BehaviorDecision.h"

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
	player->setSpeed(300.0f);
	KeyboardBehavior* keyboardBehavior = new KeyboardBehavior();
	player->addBehavior(keyboardBehavior);
	ScreenEdgeBehavior* screenEdgeBehavior = new ScreenEdgeBehavior();
	player->addBehavior(screenEdgeBehavior);

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

	//Leaves
	WanderBehavior* wanderBehavior = new WanderBehavior();
	BehaviorDecision* wanderDecision = new BehaviorDecision(wanderBehavior);
	SeekBehavior* seekBehavior = new SeekBehavior();
	seekBehavior->setTarget(player);
	BehaviorDecision* seekDecision = new BehaviorDecision(seekBehavior);
	PursuitBehavior* pursuitBehavior = new PursuitBehavior();
	pursuitBehavior->setTarget(player);
	BehaviorDecision* pursuitDecision = new BehaviorDecision(pursuitBehavior);
	//Branches
	WithinRangeCondition* canSeeCondition = new WithinRangeCondition(player, 500);
	BooleanDecision* canSeeDecision = new BooleanDecision(pursuitDecision, seekDecision, canSeeCondition);
	WithinRangeCondition* canHearCondition = new WithinRangeCondition(player, 1000);
	BooleanDecision* canHearDecision = new BooleanDecision(canSeeDecision, wanderDecision, canHearCondition);
	//Enemy decision tree
	DecisionTreeBehavior* enemyDecisionTree = new DecisionTreeBehavior(canHearDecision);
	enemy->addBehavior(enemyDecisionTree);
	enemy->addBehavior(screenEdgeBehavior);

	//enemy->addBehavior(enemyFSM);
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