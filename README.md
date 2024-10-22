## Purpose
The purpose of the repository is a proof of concept on the use of static variables when importing library. It is related to the import of the Baresip library and multiple calls.
It is a series of examples to get a new namespace and load different shared objects in order not to overwrite possible static variables.

## Examples
- core: Short dynamic library in which we access a static variable
- header: Example using the dynamic library
- runtime_qt: Example making use of the runtime library and from QLibrary (https://doc.qt.io/qt-6/qlibrary.html)
- runtime_native: Example loading the library at runtime and from posix calls (```dlopen```)
- runtime_native_indeoendent: Example loading the library at runtime in a new namespace and from posix calls (```dlmopen```)
```
LM_ID_NEWLM
              Create a new namespace and load the shared object in that
              namespace.  The object must have been correctly linked to
              reference all of the other shared objects that it
              requires, since the new namespace is initially empty.
```

## Compile
Open the examples with Qt Creator or desired, compile core and make symbolic link to the binaries examples folder. 
