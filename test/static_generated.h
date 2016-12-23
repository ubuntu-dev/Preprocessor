// Preprocessor API.
//
// Reference.
//
// Structs
//     - Print a struct to the console.
//     bool pp::print(TYPE var, char *buffer = 0, size_t buf_size = 0);
//
//     - Serialize a struct for output.
//     size_t pp::serialize(TYPE var, char *buffer, size_t buf_size);
//
//     - Get the number of members of a struct/class.
//     int pp::get_num_of_members(TYPE type);
//
//     - Turn type t into a string literal.
//     char const * pp::type_to_string(TYPE t);
//
//     - Turn type t into a string literal. Ignores pointer status.
//     char const * pp::weak_type_to_string(TYPE t);
//
//     - Get the number of objects this struct inherits from
//     int pp::get_base_type_count(TYPE t);
//
//     - Get the class t inherits from, as a string.
//     char const * pp::get_base_type_as_string(TYPE t, int index = 0);
//
// Enums
//     - Convert an enum index to a string.
//     char const * pp::enum_to_string(EnumType, EnumType value);
//
//     - Convert a string to an enum index.
//     int pp::string_to_enum(EnumType, char const *str);
//
//     - Get the total number of elements for an enum.
//     size_t pp::get_number_of_enum_elements(EnumType);
//
// Misc.
//     - Tests whether two types are the same.
//     bool pp::type_compare(TYPE a, TYPE b);
//
//     - Tests whether two types are the same, or if one is a base class of another.
//     bool pp::fuzzy_type_compare(TYPE a, TYPE b);
//
//     - Tests whether two types are the same, ignoring pointer status.
//     bool pp::weak_type_compare(TYPE a, TYPE b);

//
// Code shared between generated files.
#if !defined(STATIC_GENERATED_H)

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stddef.h>

namespace pp { // PreProcessor

typedef char _char;
typedef short _short;
typedef int _int;
typedef long _long;
typedef float _float;
typedef double _double;
typedef bool _bool;

struct MemberDefinition {
    int/*MetaType*/ type;
    char const *name;
    size_t offset;
    int is_ptr;
    int arr_size;
};

struct Variable {
    char const *ret_type;
    char const *name;
};

#define get_num_of_members(type) get_number_of_members_<type>()

#define serialize(var, buf, size) serialize_struct_<decltype(var)>(var, #var, 0, buf, size, 0)

#define print(var, ...) print_<decltype(var)>(var, #var, ##__VA_ARGS__)
template<typename T>static bool print_(T var, char const *name, char *buf = 0, size_t size = 0) {
    bool res = false, custom_buf = false;

    if(!buf) {
        size = 256 * 256;
        buf = (char *)malloc(size);
        custom_buf = true;
    }

    if(buf) {
        memset(buf, 0, size);
        size_t bytes_written = serialize_struct_<T>(var, name, 0, buf, size, 0);
        if(bytes_written < size) {
            printf("%s", buf);
            res = true;
        }

        if(custom_buf) { free(buf); }
    }

    return(res);
}

#define enum_to_string(Type, v) enum_to_string_##Type(v)

#define string_to_enum(Type, str) string_to_enum_##Type(str)

#define get_number_of_enum_elements(Type) number_of_elements_in_enum_##Type

template<class T, class U>struct TypeCompare_{ enum {e = 0}; };
template<class T>struct TypeCompare_<T, T>{ enum {e = 1}; };
#define type_compare(a, b) TypeCompare_<a, b>::e

#define type_to_string(Type) type_to_string_<Type>()
#define weak_type_to_string(Type) weak_type_to_string_<Type>()

#define get_base_type_count(Type) get_base_type_count_<Type>()
#define get_base_type_as_string(Type, ...) get_base_type_as_string_<Type>(##__VA_ARGS__)

#define fuzzy_type_compare(A, B) fuzzy_type_compare_<A, B>()
template<typename T, typename U> bool fuzzy_type_compare_(void) {
    char const *a_str = type_to_string(T);
    char const *b_str = type_to_string(U);
    if((a_str) && (b_str)) {
        if(strcmp(a_str, b_str) == 0) {
            return(true);
        } else {
            int base_count = get_base_type_count(T);
            for(int i = 0; (i < base_count); ++i) {
                char const *str = get_base_type_as_string(T);
                if(strcmp(b_str, str)) { return(true); }
            }
            
            for(int i = 0; (i < base_count); ++i) {
                char const *str = get_base_type_as_string(U);
                if(strcmp(a_str, str)) { return(true); }
            }
        }
    }

    return(false);
}

#define weak_type_compare(A, B) weak_type_compare_<A, B>()
template<typename T, typename U> bool weak_type_compare_(void) {
    char const *a_str = weak_type_to_string(T);
    char const *b_str = weak_type_to_string(U);
    if((a_str) && (b_str)) {
        if(strcmp(a_str, b_str) == 0) { return(true); }
    }

    return(false);
}

#if defined(_MSC_VER)
    #define pp_sprintf(buf, size, format, ...) sprintf_s(buf, size, format, ##__VA_ARGS__)
#else
    #define pp_sprintf(buf, size, format, ...) sprintf(buf, format, ##__VA_ARGS__)
#endif

} // namespace pp

#define STATIC_GENERATED
#endif // !defined(STATIC_GENERATED_H)
