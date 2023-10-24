#pragma once

#include <Python.h>
#include <py3c.h>  
#include <string>

std::string call_python_func(PyObject* func, std::string filepath, int num_stems);

static void python_call_func_failure(PyObject* result, PyGILState_STATE state);