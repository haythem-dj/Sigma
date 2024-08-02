#pragma once

#ifdef _WIN32
	#ifdef _WIN64
		#define SG_PLATFORM_WINDOWS
		#ifdef DLL_BUILD
			#define SIGMA_API __declspec(dllexport)
		#else
			#define SIGMA_API __declspec(dllimport)
		#endif
	#else
		#error "Sigma only supports 64 bits systems."
	#endif
#else
	#error "Sigma supports only windows."
#endif

#ifndef GLM_ENABLE_EXPERIMENTAL
	#define GLM_ENABLE_EXPERIMENTAL
#endif

#ifndef STB_IMAGE_IMPLEMENTATION
	#define STB_IMAGE_IMPLEMENTATION
#endif

#ifdef DEBUG
	#define SG_ENABLE_LOG 1
	#define SG_ENABLE_ASSERT 1
#endif

#ifdef RELEASE
	#define SG_ENABLE_LOG 0
	#define SG_ENABLE_ASSERT 0
#endif

#ifdef SG_ENABLE_LOG
	#define SG_CORE_TRACE(...)      ::Sigma::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define SG_CORE_INFO(...)       ::Sigma::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define SG_CORE_WARN(...)       ::Sigma::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define SG_CORE_ERROR(...)      ::Sigma::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define SG_CORE_CRITICAL(...)   ::Sigma::Log::GetCoreLogger()->critical(__VA_ARGS__)

	#define SG_TRACE(...)    ::Sigma::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define SG_INFO(...)     ::Sigma::Log::GetClientLogger()->info(__VA_ARGS__)
	#define SG_WARN(...)     ::Sigma::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define SG_ERROR(...)    ::Sigma::Log::GetClientLogger()->error(__VA_ARGS__)
	#define SG_CRITICAL(...) ::Sigma::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
	#define SG_CORE_TRACE(...)
	#define SG_CORE_INFO(...)
	#define SG_CORE_WARN(...)
	#define SG_CORE_ERROR(...)
	#define SG_CORE_CRITICAL(...)

	#define SG_TRACE(...)
	#define SG_INFO(...)
	#define SG_WARN(...)
	#define SG_ERROR(...)
	#define SG_CRITICAL(...)
#endif

#ifdef SG_ENABLE_ASSERT
	#define SG_CORE_ASSERT(x, msg) if(!(x)) SG_CORE_ERROR("Assertiond failed: {0}", msg);
	#define SG_ASSERT(x, msg) if(!(x)) SG_ERROR("Assertiond failed: {0}", msg);
#else
	#define SG_CORE_ASSERT(x, msg)
	#define SG_ASSERT(x, msg)
#endif