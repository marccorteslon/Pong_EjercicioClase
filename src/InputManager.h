#pragma once

enum GameInputs {UP, DOWN, LEFT, RIGT, ENTER, ESCAPE, LAST};
struct InputState {
	bool pressed = false;
	bool down = false;
	bool released = false;
};

class InputManager
{
	public:
		static InputManager* getInstance();
		~InputManager();

	private:
		InputManager();
		static InputManager* instance;
};

