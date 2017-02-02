/*===================================================================================================
  File:                    lexer.h
  Author:                  Jonathan Livingstone
  Email:                   seagull127@ymail.com
  Licence:                 Public Domain
                           No Warranty is offered or implied about the reliability,
                           suitability, or usability
                           The use of this code is at your own risk
                           Anyone can use this code, modify it, sell it to terrorists, etc.
  ===================================================================================================*/

#if !defined(_UTILS_H)

#include <stdint.h>
#include <stdarg.h>
#include <string.h>

#include "stb_sprintf.h"

typedef uint64_t Uint64;
typedef uint32_t Uint32;
typedef uint16_t Uint16;
typedef uint8_t Uint8;

typedef int64_t Int64;
typedef int32_t Int32;
typedef int16_t Int16;
typedef int8_t Int8;

typedef bool Bool;
typedef void Void;
typedef char Char;

typedef Int32 Int; // Int guaranteed to be 4 bytes.

typedef Uint8 Byte;
typedef intptr_t PtrSize;

typedef float Float;
typedef double Float64;

#define cast(type) (type)
#define array_count(arr) (sizeof(arr) / (sizeof(*(arr))))
#define preprocessor_concat(a, b) a##b

#define internal static

//
// Detect compiler/platform.
//
#define COMPILER_WIN32 0
#define COMPILER_CLANG 0
#define COMPILER_GCC 0

#define ENVIRONMENT64 0
#define ENVIRONMENT32 0

#define OS_WIN32 0
#define OS_LINUX 0

#if defined(__clang__)
    #undef COMPILER_CLANG
    #define COMPILER_CLANG 1
#elif defined(_MSC_VER)
    #undef COMPILER_WIN32
    #define COMPILER_WIN32 1
#elif (defined(__GNUC__) || defined(__GNUG__)) // This has to be after __clang__, because Clang also defines this.
    #undef COMPILER_GCC
    #define COMPILER_GCC 1
#else
    #error "Could not detect compiler."
#endif

#if defined(__linux__)
    #undef OS_LINUX
    #define OS_LINUX 1
#elif defined(_WIN32)
    #undef OS_WIN32
    #define OS_WIN32 1
#else
    #error "Could not detect OS"
#endif

#if OS_LINUX
    #if (__x86_64__ || __ppc64__)
        #undef ENVIRONMENT64
        #define ENVIRONMENT64 1
    #else
        #undef ENVIRONMENT32
        #define ENVIRONMENT32 1
    #endif
#elif OS_WIN32
    #if defined(_WIN64)
        #undef ENVIRONMENT64
        #define ENVIRONMENT64 1
    #else
        #undef ENVIRONMENT32
        #define ENVIRONMENT32 1
    #endif
#endif

#if defined(_MSC_VER)
    #define my_sprintf(buf, size, format, ...) sprintf_s(buf, size, format, ##__VA_ARGS__)
#else
    #define my_sprintf(buf, size, format, ...) sprintf(buf, format, ##__VA_ARGS__)
#endif

// TODO(Jonny): This should probably be a flag, rather than compiled into the preprocessor.
#if COMPILER_MSVC
    #define GUID__(file, seperator, line) file seperator line ")"
    #define GUID_(file, line) GUID__(file, "(", #line)
    #define GUID(file, line) GUID_(file, line)
    #define MAKE_GUID GUID(__FILE__, __LINE__)
#else
    #define GUID__(file, seperator, line) file seperator line ":1: error:"
    #define GUID_(file, line) GUID__(file, ":", #line)
    #define GUID(file, line) GUID_(file, line)
    #define MAKE_GUID GUID(__FILE__, __LINE__)
#endif

//
// Error stuff.
//
enum ErrorType {
    ErrorType_ran_out_of_memory,
    ErrorType_assert_failed,
    ErrorType_no_parameters,
    ErrorType_cannot_find_file,
    ErrorType_could_not_write_to_disk,
    ErrorType_could_not_load_file,
    ErrorType_no_files_pass_in,
    ErrorType_could_not_find_mallocd_ptr,
    ErrorType_memory_not_freed,
    ErrorType_could_not_detect_struct_name,
    ErrorType_could_not_find_struct,
    ErrorType_unknown_token_found,
    ErrorType_failed_to_parse_enum,
    ErrorType_failed_parsing_variable,
    ErrorType_failed_to_find_size_of_array,
    ErrorType_did_not_write_entire_file,
    ErrorType_did_not_read_entire_file,

    ErrorType_count,
};

struct Error {
    ErrorType type;
    Char *guid;
};


#if ERROR_LOGGING
    #define push_error(type) push_error_(type, MAKE_GUID)
#else
    #define push_error(type) {}
#endif

Void push_error_(ErrorType type, Char *guid);
Char *ErrorTypeToString(ErrorType e);
Bool print_errors(void);

#if defined(assert)
    #undef assert
#endif
#if INTERNAL
    #define assert(Expression) do { static Bool Ignore = false; if(!Ignore) { if(!(Expression)) { push_error(ErrorType_assert_failed); *cast(int volatile *)0 = 0; } } } while(0)
#else
    #define assert(Expression) {}
#endif

struct File {
    Char *data;
    PtrSize size;
};

//
// Memory stuff.
//

// These are implemented in Platform code... but defined here.
Void *system_malloc(PtrSize size, PtrSize cnt = 1);
Bool system_free(Void *ptr);
Void *system_realloc(Void *ptr, PtrSize size);

#if defined(malloc)
    #undef malloc
#endif
#define malloc system_malloc

#if defined(calloc)
    #undef calloc
#endif
#define calloc system_malloc

#if defined(realloc)
    #undef realloc
#endif
#define realloc system_realloc

#if defined(free)
    #undef free
#endif
#define free system_free

#if defined(alloc)
    #undef alloc
#endif
#define alloc(Type, ...) (Type *)system_malloc(sizeof(Type), ##__VA_ARGS__)

#if MEM_CHECK
struct MemList {
    Void *ptr;
    MemList *next;
    Char *guid;
    Bool freed;
};
#if defined(MEM_ROOT_FILE)
    MemList *mem_list_root = 0;
#else
    extern MemList *mem_list_root;
#endif

// malloc.
static Void *malloc_(PtrSize size, Char *guid, PtrSize cnt = 1) {
    Void *res = system_malloc(size * cnt);

    if(res) {
        MemList *cur = cast(MemList *)system_malloc(sizeof(MemList));
        if(!cur) {
            push_error_(ErrorType_ran_out_of_memory, guid);
        } else {
            cur->ptr = res;
            cur->guid = guid;

            if(!mem_list_root) {
                mem_list_root = cur;
            } else {
                MemList *next = mem_list_root;
                while(next->next) {
                    next = next->next;
                }

                next->next = cur;
            }
        }
    }

    return(res);
}

// free
static Void free_(Void *ptr) {
    system_free(ptr);
    if(ptr) {
        Bool found = false;
        MemList *next = mem_list_root;
        while(next) {
            if(next->ptr == ptr) {
                found = true;
                next->freed = true;
            }

            next = next->next;
        }

        assert(found);
    }
}

// realloc
static Void *realloc_(Void *ptr, PtrSize size, Char *guid) {
    Void *res = system_realloc(ptr, size);
    if(ptr) {
        MemList *next = mem_list_root;
        while(next) {
            if(next->ptr == ptr) {
                break;    // while
            }
            next = next->next;
        }

        if(!next) {
            push_error_(ErrorType_could_not_find_mallocd_ptr, guid);
        } else      {
            next->ptr = res;
        }
    }
    return(res);
}

// malloc
#if defined(malloc)
    #undef malloc
#endif
#define malloc(size) malloc_(size, MAKE_GUID)

// calloc
#if defined(calloc)
    #undef calloc
#endif
#define calloc(size, cnt) malloc_(size, MAKE_GUID, cnt)

// realloc
#if defined(realloc)
    #undef realloc
#endif
#define realloc(ptr, size) realloc_(ptr, size, MAKE_GUID)

// free
#if defined(free)
    #undef free
#endif
#define free(ptr) free_(ptr)

// alloc
#if defined(alloc)
    #undef alloc
#endif
#define alloc(Type, ...) (Type *)malloc_(sizeof(Type), MAKE_GUID, ##__VA_ARGS__)

#endif // MEM_CHECK

//
// Scratch memory
//
// A quick-to-access temp region of memory. Should be frequently cleared.
static Int scratch_memory_size = 256 * 256;
Void *push_scratch_memory(Int size = scratch_memory_size);
Void clear_scratch_memory(void);
Void free_scratch_memory();

//
// String
//
struct String {
    Char *e;
    Int len;
};

String create_string(Char *str, Int len = 0);
Int string_length(Char *str);
Bool string_concat(Char *dest, Int len, Char *a, Int a_len, Char *b, Int b_len);
Bool string_compare(Char *a, Char *b, Int len);
Bool string_compare(Char *a, Char *b);
Void string_copy(Char *dest, Char *src);
Bool string_compare(String a, String b);
Bool string_compare_array(String *a, String *b, Int cnt);
Bool string_contains(String str, Char *target);

//
// Maths.
//
struct ResultInt {
    Int e;
    Bool success;
};

ResultInt char_to_int(Char c);
ResultInt string_to_int(String str);
ResultInt string_to_int(Char *str);
ResultInt calculator_string_to_int(Char *str);

Uint32 safe_truncate_size_64(Uint64 v);

//
// Variable.
//
struct Variable {
    String type;
    String name;
    Bool is_ptr;
    Int array_count; // This is 1 if it's not an array. TODO(Jonny): Is this true anymore?
    Bool is_inside_anonymous_struct;
};

Variable create_variable(Char *type, Char *name, Bool is_ptr = false, Int array_count = 1);
Bool compare_variable(Variable a, Variable b);
Bool compare_variable_array(Variable *a, Variable *b, Int count);

//
// Utils.
//
Char to_caps(Char c);


//
// memset and memcpy
//
#if 0
    #if !RUN_TESTS
        #if OS_WIN32
            extern "C" void   *__cdecl memcpy(_Out_writes_bytes_all_(_Size) void *_Dst, _In_reads_bytes_(_Size) const void *_Src, _In_ size_t _Size);
            extern "C" void   *__cdecl memset(_Out_writes_bytes_all_(_Size) void *_Dst, _In_ int _Val, _In_ size_t _Size);
        #else
            extern "C" void *memcpy(void *Dest, void const *Source, PtrSize Size);
            extern "C" void *memset(void *Dest, int Value, PtrSize NumBytesToSet);
        #endif

    #endif
#endif

#define _UTILS_H
#endif
