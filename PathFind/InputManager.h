#pragma once
#include <vector>
#include <functional>

class InputManager
{
	std::vector<std::function<void()>> OnInputPressed;
	void InputPressed();
public:
	InputManager();
	void SubscribeToOnInputPressed(std::function<void()> toCall);
	template<typename T, typename U>
	void SubscribeToOnInputPressed(std::function<U> toCall, T ref);
	bool PressInput();
};


inline InputManager::InputManager()
{
}

inline void InputManager::SubscribeToOnInputPressed(std::function<void()> toSubscribe)
{
	OnInputPressed.push_back(toSubscribe);
}



inline void InputManager::InputPressed()
{
	for (int i = 0; i < OnInputPressed.size(); ++i)
	{
		OnInputPressed[i]();
	}
}

inline bool InputManager::PressInput()
{
	InputPressed();
	return false;
}

template<typename T, typename U>
inline void InputManager::SubscribeToOnInputPressed(std::function<U> toCall, T ref)
{

	std::function<void()> toAdd = std::bind(&toCall, ref);
	OnInputPressed.push_back(toCall);
}
