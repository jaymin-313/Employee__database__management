
#ifndef log_flag
#define log_flag

#include<iostream>
#include<fstream>
#include <vector>
#include <iostream>
#include<string>
#include<chrono>
#include <ctime>
#include "myexception.h"
namespace logs {

	class Log
	{

	public:
		enum class Level {
			LevelError = 0, LevelWarning, LevelInfo
		};

		static Log& getInstance() {
			static Log logDB;
			return logDB;
		}

		void SetLogLevel(Level) noexcept;

		std::string getDateTime() noexcept;

		void enableFileLog() noexcept;
		void disableFileLog() noexcept;
		void writeBuffer_File();

		std::string stringify(int value) const noexcept;
		std::string stringify(double value) const noexcept;
		std::string stringify(const std::string& value) const noexcept;
		std::string stringify(const char& value) const noexcept;

		void print_args() noexcept {

			if (writeToFile) {
				log = log + std::string("\n");
				bufferedLogs.emplace_back(log);
				++bufferedLogCount;
				if (bufferedLogCount == 5) {
					writeBuffer_File();
				}
			}

			/*std::cout << "\n";*/

		}

		template <typename t1, typename... args>
		void print_args(t1 first, args... rest) noexcept
		{
			if (writeToFile) {
				log = log + (stringify(first)) + std::string(" ");
			}
			//std::cout << first << " ";
			Log::print_args(rest...);
		}

		template <typename... parameters>
		void generalLogger(parameters... Args) noexcept;

		template < typename... parameters>
		void Warn(parameters &&... Args) noexcept;

		template < typename... parameters>
		void Error(parameters &&... Args) noexcept;

		template < typename... parameters>
		void Info(parameters &&... Args) noexcept;


	private:
		Level m_LogLevel;
		std::ofstream writeLog;
		std::string fileName;
		bool writeToFile = true;
		std::string log;
		std::vector<std::string> bufferedLogs;
		int bufferedLogCount{ 0 };

		explicit Log()
			:m_LogLevel{ Level::LevelInfo }, fileName{ "databaseLog.txt" } {}

		explicit Log(Level l1, std::string filePara = { "databaseLog.txt" })
			: m_LogLevel{ l1 }, fileName{ filePara }
		{
		}

		Log(const Log&) = delete;
		Log& operator=(const Log&) = delete;

		~Log() { writeBuffer_File(); }

	};

	template < typename... parameters>
	void Log::Info(parameters &&... Args) noexcept
	{
		if (m_LogLevel >= Level::LevelInfo) {

			log = std::string{ "[ " } + std::string(getDateTime()) + std::string{ " ]" } + std::string{ "[Info ]: " };

			generalLogger(Args...);
		}
	}

	template < typename... parameters>
	void Log::Warn(parameters &&... Args) noexcept
	{
		if (m_LogLevel >= Level::LevelWarning) {

			log = std::string{ "[ " } + std::string(getDateTime()) + std::string{ " ]" } + std::string{ "[Warn ]: " };

			generalLogger(Args...);
		}
	}

	template < typename... parameters>
	void Log::Error(parameters &&... Args) noexcept
	{
		if (m_LogLevel >= Level::LevelError) {

			log = std::string{ "[ " } + std::string(getDateTime()) + std::string{ " ]" } + std::string{ "[Error]: " };

			generalLogger(Args...);
		}
	}

	template<typename ...parameters>
	void Log::generalLogger(parameters ...Args) noexcept
	{

		//std::cout << log;
		Log::print_args(Args...);

	}

}

#endif