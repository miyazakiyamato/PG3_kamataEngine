#pragma once
class InputManager{
private:
	char keys_[256]{};
	char preKeys_[256]{};
	InputManager() {}
	~InputManager() {}
public:
	InputManager(const InputManager& obj) = delete;
	InputManager& operator=(const InputManager& obj) = delete;
	static InputManager* GetInstance();
	char* GetKeys() { return keys_; };
	char* GetPreKeys() { return preKeys_; };

};

