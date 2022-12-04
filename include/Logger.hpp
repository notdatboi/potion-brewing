#pragma once
#include <memory>
#include <mutex>
#include <fstream>
#include <cstring_view.hpp>

namespace common
{

class Logger
{
	static std::mutex m_instanceMutex;
	static std::unique_ptr<Logger> m_instance;
	static const compat::cstring_view m_logFileName;

	std::mutex m_streamMutex;
	std::fstream m_logFile;

	Logger();

public:
	~Logger();

	static Logger& getInstance();

	class Appender
	{
		Logger& m_logger;

	public:
		template<class T>
		Appender& operator<<(const T& val)
		{
			m_logger << val;
			return *this;
		}

		Appender(Logger& logger); // appends line ending symbol
		~Appender();
	};

	template<class T>
	Logger& operator<<(const T& val)
	{
		{
			std::lock_guard<std::mutex> lock(m_instanceMutex);
			m_logFile << val;
		}
		return *this;
	}

	void flush();
};

}
