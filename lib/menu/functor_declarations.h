#pragma once

typedef int (*GETINT)();
typedef void (*SETINT)(int);

typedef float (*GETFLOAT)();
typedef void (*SETFLOAT)(float);

typedef const char* (*GETSTR)();

typedef bool (*GETCOMPASSDATA)(float*, float*);