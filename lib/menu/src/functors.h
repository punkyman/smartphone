#pragma once

typedef uint8_t     (*GETU8)();
typedef int32_t     (*GETINT)();
typedef void        (*SETINT)(int32_t);
typedef float       (*GETFLOAT)();
typedef const char* (*GETSTR)();
typedef bool        (*CALLNUMBER)(const char*);
typedef bool        (*GETCOMPASSDATA)(float*, float*);
