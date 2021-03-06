/*===================================================================================================
  File:                    platform.h
  Author:                  Jonathan Livingstone
  Email:                   seagull127@ymail.com
  Licence:                 Public Domain
                           No Warranty is offered or implied about the reliability,
                           suitability, or usability
                           The use of this code is at your own risk
                           Anyone can use this code, modify it, sell it to terrorists, etc.
  ===================================================================================================*/

#if !defined(_PLATFORM_H)

#include "shared.h"

// Memory.
Void *system_malloc(PtrSize size, PtrSize cnt = 1);
Bool system_free(Void *ptr);
Void *system_realloc(Void *ptr, PtrSize size);
#if defined(system_alloc)
    #undef system_alloc
#endif
#define system_alloc(Type, ...) (Type *)system_malloc(sizeof(Type), ##__VA_ARGS__)

// File IO.
struct File;
File system_read_entire_file_and_null_terminate(Char const *fname, Void *memory);
Bool system_write_to_file(Char const *fname, Char const *data, PtrSize data_size);
PtrSize system_get_file_size(Char const *fname);

Bool system_create_folder(Char const *name);

// Utility stuff.
Bool system_check_for_debugger(void);
Void system_write_to_console(Char const *str, ...);
Void system_write_to_stderr(Char const *str);

Char const *system_get_file_extension(Char const *fname);

Void system_set_current_folder(Char const *folder_name);

#define _PLATFORM_H
#endif