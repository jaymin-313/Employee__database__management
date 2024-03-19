#include <iostream>
#include<string>
#include<chrono>
#include <ctime>
#include "../include/log.h";
#include "../include/myexception.h";

using logs::Log;

// Log Class implementation of all function definations
void Log::SetLogLevel(Level level) noexcept
{
	m_LogLevel = level;
}

std::string logs::Log::getDateTime() noexcept
{
	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);

	std::tm tmLocal;
	localtime_s(&tmLocal, &time);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", &tmLocal);

	/*std::string dateTime = std::to_string(tmLocal.tm_mday).append("-").append(std::to_string(tmLocal.tm_mon+1)).append("-").append(std::to_string(tmLocal.tm_year)).append(" ");
	dateTime = dateTime.append(std::to_string(tmLocal.tm_hour)).append(":").append(std::to_string(tmLocal.tm_min)).append(":").append(std::to_string(tmLocal.tm_sec));
	std::cout << dateTime;*/
	return std::string(buffer);
}

void Log::enableFileLog() noexcept {
	writeToFile = true;
}
void Log::disableFileLog() noexcept {
	writeToFile = false;
}

void Log::writeBuffer_File() {

	writeLog.open(fileName, std::ios::app);
	try {
		if (!writeLog.is_open()) {
			writeToFile = false;
			throw FileException("Error: Failed to open file for writing\n");
		}
	}
	catch (FileException e) {
		e.what();
	}

	for (auto data : bufferedLogs) {
		writeLog << data;
	}

	bufferedLogs.clear();

	writeLog.close();
}

std::string Log::stringify(int value) noexcept {
	return std::to_string(value);
}

std::string Log::stringify(double value) noexcept {
	return std::to_string(value);
}

std::string Log::stringify(const std::string& value) noexcept {
	return value;
}

std::string Log::stringify(const char& value) noexcept {
	return std::to_string(value);
}


//void Log::Warn(const utility::String& message)
//{
//	logDate.refdate(); 
//	if (m_LogLevel >= Level::LevelWarning) {
//		std::cout << "[ " << logDate.getStringrep() <<" ]" << "[Warn]: " << message << "\n";
//	}
//}
//
//void Log::Error(const utility::String& message)
//{
//	logDate.refdate();
//	if (m_LogLevel >= Level::LevelError) {
//		std::cout << "[ " << logDate.getStringrep() << " ]" << "[Error]: " << message << "\n";
//	}
//}
//
//void Log::Info(const utility::String& message)
//{
//	logDate.refdate();
//	if (m_LogLevel >= Level::LevelInfo) {
//		std::cout << "[ " << logDate.getStringrep() << " ]" << "[Info]: " << message << "\n";
//	}
//}