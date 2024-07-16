#pragma once

#include <spdlog/spdlog.h>

namespace Sigma
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger> GetCoreLogger() { return sCoreLogger; }
		static std::shared_ptr<spdlog::logger> GetClientLogger() { return sClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
		
	};
}