#include "InputManager.h"

enum GameInputs { UP, DOWN, LEFT, RIGT, ENTER, ESCAPE, LAST };


void InputManager::SetPlayerInputState(int player, GameInputs input, InputState state) {
	if (player >= playerInputs.size()) { return; }
	if (playerInputs[player])
}

InputState InputManager::GetPlayerInputState(int player, GameInputs input) {
	InputState state;
	if (player >= )
}