#pragma once

#ifdef SLATE_PLATFORM_WINDOWS
#pragma warning(disable : 4251)
#ifdef SLATE_DYNAMIC
#ifdef SLATE_ENGINE
#define SLATE_EXPORT __declspec(dllexport)
#else
#define SLATE_EXPORT __declspec(dllimport)
#endif
#else
#define SLATE_EXPORT
#endif
#define SLATE_HIDDEN
#else
#define SlATE_EXPORT __attribute__((visibility("default")))
#define SLATE_HIDDEN __attribute__((visibility("hidden")))
#endif

