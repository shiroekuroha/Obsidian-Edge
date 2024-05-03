#ifndef OE_CORE_H
#define OE_CORE_H

#ifdef _WIN32 || _WIN64
	#ifdef LIB_EXPORT
		#define OE_API __declspec(dllexport)
	#else
		#define OE_API __declspec(dllimport)
	#endif
#elif unix
	#if __linux__
		#ifdef LIB_EXPORT
			#define OE_API __attribute__((visibility("default")))
		#else
			#define OE_API
		#endif
	#elif __APPLE__
		#error ERROR: APPLE PLATFORM NOT SUPPORTED
	#else
		#error ERROR: UNKNOWN UNIX PLATFORM NOT SUPPORTED
	#endif
#else
	#error ERROR: UNKNOW PLATFORM NOT SUPPORTED
#endif

#endif