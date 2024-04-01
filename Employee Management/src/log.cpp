#include "../include/log.h"

using logs::Log;

void Log::SetLogLevel(Level level) noexcept
{
	m_LogLevel = level;
}

[[nodiscard]] std::string logs::Log::getDateTime() noexcept
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

[[nodiscard]] std::string Log::stringify(int value) const noexcept {
	return std::to_string(value);
}

[[nodiscard]] std::string Log::stringify(double value) const noexcept {
	return std::to_string(value);
}

[[nodiscard]] std::string Log::stringify(const std::string& value) const noexcept {
	return value;
}

[[nodiscard]] std::string Log::stringify(const char& value) const noexcept {
	return std::to_string(value);
}


