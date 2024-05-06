#include "IssoException.h"
#include <sstream>

IssoException::IssoException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* IssoException::what() const noexcept {
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* IssoException::GetType()const noexcept {
	return "Isso Exception";
}

int IssoException::GetLine() const noexcept {
	return line;
}

const std::string& IssoException::GetFile() const noexcept
{
	return file;
}

std::string IssoException::GetOriginString() const noexcept {
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
	<< "[Line] " << line;
	return oss.str();
}