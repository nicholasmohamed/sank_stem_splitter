#include "PythonInterface.h"

/* Execute stem_split_as_wav(wavepath, stems=5) in the Python interpreter
return result of the function must be Python strings */

using namespace std;

string call_python_func(PyObject* func, string filepath, int num_stems)
{
    PyObject* args;
    PyObject* kwargs;
    PyObject* result = 0;
    string retval;

    // Make sure we own the GIL 
    PyGILState_STATE state = PyGILState_Ensure();


    // Verify that func is a proper callable 
    if (!PyCallable_Check(func))
    {
        fprintf(stderr, "stem_split_as_wav: expected a callable\n");
        python_call_func_failure(result, state);
    }

    // build values for calling arguments
    args = Py_BuildValue("(s*i)", filepath, num_stems);
    kwargs = NULL;

    // call the function with arguments
    result = PyObject_Call(func, args, kwargs);
    Py_DECREF(args);
    Py_XDECREF(kwargs);

    // check for errors
    if (PyErr_Occurred())
    {
        PyErr_Print();
        python_call_func_failure(result, state);
    }

    // Verify the result is a string object  
    if (!PyStr_Check(result))
    {
        fprintf(stderr, "call_func: callable didn't return a float\n");
        python_call_func_failure(result, state);
    }

    // Convert the return value
    retval = PyStr_AsString(result);
    Py_DECREF(result);

    // Step 7 
    PyGILState_Release(state);
    return retval;
}

void python_call_func_failure(PyObject* result, PyGILState_STATE state) {
    Py_XDECREF(result);
    PyGILState_Release(state);
    abort();
}