#include "PythonInterface.h"

/* Execute stem_split_as_wav(wavepath, stems=5) in the Python interpreter
return result of the function must be Python strings */

using namespace std;

string call_python_func(string module_name, string func_name, string filepath, int num_stems)
{
    PyObject* args;
    PyObject* kwargs;
    PyObject* result = 0;
    string retval;

    PyObject *pName, *pModule, *pDict, *pFunc, *pValue;

    // Initialize the Python Interpreter
    Py_Initialize();

    // Build the name object
    pName = PyUnicode_FromString(module_name.c_str());

    // Load the module object
    pModule = PyImport_Import(pName);

    // pDict is a borrowed reference 
    pDict = PyModule_GetDict(pModule);

    // pFunc is also a borrowed reference 
    pFunc = PyDict_GetItemString(pDict, func_name.c_str());

    // Verify that func is a proper callable 
    if (!PyCallable_Check(pFunc))
    {
        fprintf(stderr, "stem_split_as_wav: expected a callable\n");
        python_call_func_failure(result);
    }

    // build values for calling arguments
    args = Py_BuildValue("(s*i)", filepath, num_stems);
    kwargs = NULL;

    // call the function with arguments
    result = PyObject_Call(pFunc, args, kwargs);
    Py_DECREF(args);
    Py_XDECREF(kwargs);

    // check for errors
    if (PyErr_Occurred())
    {
        PyErr_Print();
        python_call_func_failure(result);
    }

    // Verify the result is a string object  
    if (!PyStr_Check(result))
    {
        fprintf(stderr, "call_func: callable didn't return a float\n");
        python_call_func_failure(result);
    }

    // Convert the return value
    retval = PyStr_AsString(result);
    Py_DECREF(result);
    return retval;
}

void python_call_func_failure(PyObject* result) {
    Py_XDECREF(result);
    abort();
}