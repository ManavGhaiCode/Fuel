#ifndef _FUEL_CONFIG_H_
#define _FUEL_CONFIG_H_

typedef unsigned long u64;
typedef long i64;
typedef double f64;

typedef unsigned int u32;
typedef int i32;
typedef float f32;

typedef unsigned short u16;
typedef short i16;

typedef unsigned char u8;
typedef char i8;

#ifdef __linux__
    #ifdef __x86_64
        #define FUEL_PLATFORM_LINUX
    #else
        #error "64-bit Distro Snapshot Required!"
    #endif
#elif defined(_WIN32) || defined (__WIN32) || defined (__WIN32__)
    #ifdef _WIN64
        #define FUEL_PLATFORM_WINDOWS
    #else
        #error "64-bit Windows Required!"
    #endif
#else
    #error "Unsupported Platform!"
#endif

#endif // _FUEL_CONFIG_H_