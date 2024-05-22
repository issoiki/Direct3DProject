#pragma once
#include <chrono>

class IssoTimer
{
public:
	IssoTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point last;
};

