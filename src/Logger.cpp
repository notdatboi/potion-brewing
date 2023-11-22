#include <Logger.hpp>

namespace common
{

std::mutex Logger::m_instanceMutex;
std::unique_ptr<Logger> Logger::m_instance;
const std::string Logger::m_logFileName = "log.txt";

Logger::Appender::Appender(Logger& logger)
	: m_logger(logger)
{
}

Logger::Appender::~Appender()
{
	try
	{
		m_logger << '\n';
	}
	catch (...) {}
}

Logger::Logger()
	: m_logFile(m_logFileName.c_str(), std::ios_base::app | std::ios_base::out)
{
}

Logger::~Logger()
{
	try
	{
		flush();
	} catch (...) {}
}

Logger& Logger::getInstance()
{
	if (!m_instance)
	{
		std::lock_guard<std::mutex> lock(m_instanceMutex);
		if (!m_instance)
			m_instance = std::unique_ptr<Logger>(new Logger());
	}
	return *m_instance;
}

void Logger::flush()
{
	std::lock_guard<std::mutex> lock(m_instanceMutex);
	m_logFile.flush();
}

}
