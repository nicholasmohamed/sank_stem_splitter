#pragma once

#include <Python.h>
#include <py3c.h>  
#include <string>

std::string call_python_func(std::string module_name, std::string func_name, std::string filepath, int num_stems);

static void python_call_func_failure(PyObject* result);