#if !defined(BREAKOUT_GENERATED_H)
#define BREAKOUT_GENERATED_H

// Forward declared structs (these must be declared outside the namespace...)
struct V2;
struct Transform;
struct Ball;
struct Paddle;
struct GameState;

#define _std std // TODO(Jonny): This is really stupid...

// Enum with field for every type detected.
namespace pp { enum MetaType {
    MetaType_char,
    MetaType_short,
    MetaType_int,
    MetaType_long,
    MetaType_float,
    MetaType_double,
    MetaType_bool,
    MetaType_V2,
    MetaType_Transform,
    MetaType_Ball,
    MetaType_Paddle,
    MetaType_GameState,
}; }

#include "static_generated.h"
namespace pp { // PreProcessor

//
// Meta type specialization
//

// char
template<> struct Type<char> {
    using type = char;
    using weak_type = char;

    char const * name = "char";
    char const * weak_name = "char";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<char> operator=(Type<char> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<char *> {
    using type = char *;
    using weak_type = char;

    char const * name = "char *";
    char const * weak_name = "char";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<char *> operator=(Type<char *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<char **> {
    using type = char **;
    using weak_type = char;

    char const * name = "char **";
    char const * weak_name = "char";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<char **> operator=(Type<char **> a) = delete; // To avoid warning 4512 in MSVC.
};

// short
template<> struct Type<short> {
    using type = short;
    using weak_type = short;

    char const * name = "short";
    char const * weak_name = "short";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<short> operator=(Type<short> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<short *> {
    using type = short *;
    using weak_type = short;

    char const * name = "short *";
    char const * weak_name = "short";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<short *> operator=(Type<short *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<short **> {
    using type = short **;
    using weak_type = short;

    char const * name = "short **";
    char const * weak_name = "short";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<short **> operator=(Type<short **> a) = delete; // To avoid warning 4512 in MSVC.
};

// int
template<> struct Type<int> {
    using type = int;
    using weak_type = int;

    char const * name = "int";
    char const * weak_name = "int";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<int> operator=(Type<int> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<int *> {
    using type = int *;
    using weak_type = int;

    char const * name = "int *";
    char const * weak_name = "int";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<int *> operator=(Type<int *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<int **> {
    using type = int **;
    using weak_type = int;

    char const * name = "int **";
    char const * weak_name = "int";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<int **> operator=(Type<int **> a) = delete; // To avoid warning 4512 in MSVC.
};

// long
template<> struct Type<long> {
    using type = long;
    using weak_type = long;

    char const * name = "long";
    char const * weak_name = "long";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<long> operator=(Type<long> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<long *> {
    using type = long *;
    using weak_type = long;

    char const * name = "long *";
    char const * weak_name = "long";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<long *> operator=(Type<long *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<long **> {
    using type = long **;
    using weak_type = long;

    char const * name = "long **";
    char const * weak_name = "long";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<long **> operator=(Type<long **> a) = delete; // To avoid warning 4512 in MSVC.
};

// float
template<> struct Type<float> {
    using type = float;
    using weak_type = float;

    char const * name = "float";
    char const * weak_name = "float";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<float> operator=(Type<float> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<float *> {
    using type = float *;
    using weak_type = float;

    char const * name = "float *";
    char const * weak_name = "float";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<float *> operator=(Type<float *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<float **> {
    using type = float **;
    using weak_type = float;

    char const * name = "float **";
    char const * weak_name = "float";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<float **> operator=(Type<float **> a) = delete; // To avoid warning 4512 in MSVC.
};

// double
template<> struct Type<double> {
    using type = double;
    using weak_type = double;

    char const * name = "double";
    char const * weak_name = "double";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<double> operator=(Type<double> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<double *> {
    using type = double *;
    using weak_type = double;

    char const * name = "double *";
    char const * weak_name = "double";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<double *> operator=(Type<double *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<double **> {
    using type = double **;
    using weak_type = double;

    char const * name = "double **";
    char const * weak_name = "double";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<double **> operator=(Type<double **> a) = delete; // To avoid warning 4512 in MSVC.
};

// bool
template<> struct Type<bool> {
    using type = bool;
    using weak_type = bool;

    char const * name = "bool";
    char const * weak_name = "bool";

    size_t const member_count = 0;

    bool const is_ptr = false;

    Type<bool> operator=(Type<bool> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<bool *> {
    using type = bool *;
    using weak_type = bool;

    char const * name = "bool *";
    char const * weak_name = "bool";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<bool *> operator=(Type<bool *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<bool **> {
    using type = bool **;
    using weak_type = bool;

    char const * name = "bool **";
    char const * weak_name = "bool";

    size_t const member_count = 0;

    bool const is_ptr = true;

    Type<bool **> operator=(Type<bool **> a) = delete; // To avoid warning 4512 in MSVC.
};

// V2
template<> struct Type<V2> {
    using type = V2;
    using weak_type = V2;

    char const * name = "V2";
    char const * weak_name = "V2";

    size_t const member_count = 2;

    bool const is_ptr = false;

    Type<V2> operator=(Type<V2> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<V2 *> {
    using type = V2 *;
    using weak_type = V2;

    char const * name = "V2 *";
    char const * weak_name = "V2";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<V2 *> operator=(Type<V2 *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<V2 **> {
    using type = V2 **;
    using weak_type = V2;

    char const * name = "V2 **";
    char const * weak_name = "V2";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<V2 **> operator=(Type<V2 **> a) = delete; // To avoid warning 4512 in MSVC.
};

// Transform
template<> struct Type<Transform> {
    using type = Transform;
    using weak_type = Transform;

    char const * name = "Transform";
    char const * weak_name = "Transform";

    size_t const member_count = 2;

    bool const is_ptr = false;

    Type<Transform> operator=(Type<Transform> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Transform *> {
    using type = Transform *;
    using weak_type = Transform;

    char const * name = "Transform *";
    char const * weak_name = "Transform";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<Transform *> operator=(Type<Transform *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Transform **> {
    using type = Transform **;
    using weak_type = Transform;

    char const * name = "Transform **";
    char const * weak_name = "Transform";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<Transform **> operator=(Type<Transform **> a) = delete; // To avoid warning 4512 in MSVC.
};

// Ball
template<> struct Type<Ball> {
    using type = Ball;
    using weak_type = Ball;

    char const * name = "Ball";
    char const * weak_name = "Ball";

    size_t const member_count = 2;

    bool const is_ptr = false;

    Type<Ball> operator=(Type<Ball> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Ball *> {
    using type = Ball *;
    using weak_type = Ball;

    char const * name = "Ball *";
    char const * weak_name = "Ball";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<Ball *> operator=(Type<Ball *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Ball **> {
    using type = Ball **;
    using weak_type = Ball;

    char const * name = "Ball **";
    char const * weak_name = "Ball";

    size_t const member_count = 2;

    bool const is_ptr = true;

    Type<Ball **> operator=(Type<Ball **> a) = delete; // To avoid warning 4512 in MSVC.
};

// Paddle
template<> struct Type<Paddle> {
    using type = Paddle;
    using weak_type = Paddle;

    char const * name = "Paddle";
    char const * weak_name = "Paddle";

    size_t const member_count = 1;

    bool const is_ptr = false;

    Type<Paddle> operator=(Type<Paddle> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Paddle *> {
    using type = Paddle *;
    using weak_type = Paddle;

    char const * name = "Paddle *";
    char const * weak_name = "Paddle";

    size_t const member_count = 1;

    bool const is_ptr = true;

    Type<Paddle *> operator=(Type<Paddle *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<Paddle **> {
    using type = Paddle **;
    using weak_type = Paddle;

    char const * name = "Paddle **";
    char const * weak_name = "Paddle";

    size_t const member_count = 1;

    bool const is_ptr = true;

    Type<Paddle **> operator=(Type<Paddle **> a) = delete; // To avoid warning 4512 in MSVC.
};

// GameState
template<> struct Type<GameState> {
    using type = GameState;
    using weak_type = GameState;

    char const * name = "GameState";
    char const * weak_name = "GameState";

    size_t const member_count = 3;

    bool const is_ptr = false;

    Type<GameState> operator=(Type<GameState> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<GameState *> {
    using type = GameState *;
    using weak_type = GameState;

    char const * name = "GameState *";
    char const * weak_name = "GameState";

    size_t const member_count = 3;

    bool const is_ptr = true;

    Type<GameState *> operator=(Type<GameState *> a) = delete; // To avoid warning 4512 in MSVC.
};
template<> struct Type<GameState **> {
    using type = GameState **;
    using weak_type = GameState;

    char const * name = "GameState **";
    char const * weak_name = "GameState";

    size_t const member_count = 3;

    bool const is_ptr = true;

    Type<GameState **> operator=(Type<GameState **> a) = delete; // To avoid warning 4512 in MSVC.
};
static bool is_meta_type_container(int type) {
    if(type == MetaType_char) {return(false);} // false
    else if(type == MetaType_short) {return(false);} // false
    else if(type == MetaType_int) {return(false);} // false
    else if(type == MetaType_long) {return(false);} // false
    else if(type == MetaType_float) {return(false);} // false
    else if(type == MetaType_double) {return(false);} // false
    else if(type == MetaType_bool) {return(false);} // false
    else if(type == MetaType_V2) {return(false);} // false
    else if(type == MetaType_Transform) {return(false);} // false
    else if(type == MetaType_Ball) {return(false);} // false
    else if(type == MetaType_Paddle) {return(false);} // false
    else if(type == MetaType_GameState) {return(false);} // false

    // Should not be reached.
    assert(0);
    return(0);
}
static char const * meta_type_to_name(MetaType mt, bool is_ptr) {
    if(mt == MetaType_V2) {
        if(is_ptr) {return("V2 *");}
        else       {return("V2");  }
    } else if(mt == MetaType_Transform) {
        if(is_ptr) {return("Transform *");}
        else       {return("Transform");  }
    } else if(mt == MetaType_Ball) {
        if(is_ptr) {return("Ball *");}
        else       {return("Ball");  }
    } else if(mt == MetaType_Paddle) {
        if(is_ptr) {return("Paddle *");}
        else       {return("Paddle");  }
    } else if(mt == MetaType_GameState) {
        if(is_ptr) {return("GameState *");}
        else       {return("GameState");  }
    }

    assert(0); 
    return(0); // Not found
}
// Function to serialize a struct to a char array buffer.
static size_t
serialize_struct_(void *var, char const *name, char const *type_as_str, int indent, char *buffer, size_t buf_size, size_t bytes_written) {
    assert((buffer) && (buf_size > 0)); // Check params.

    if(!bytes_written) {memset(buffer, 0, buf_size);} // If this is the first time through, zero the buffer.

    MemberDefinition *members_of_Something = get_members_of_str(type_as_str); assert(members_of_Something); // Get the members_of pointer. 
    if(members_of_Something) {
        // Setup the indent buffer.
        char indent_buf[256] = {};
        for(int i = 0; (i < indent); ++i) {indent_buf[i] = ' ';}

        // Write the name and the type.
        if((name) && (strlen(name) > 0)) {
            bytes_written += pp_sprintf((char *)buffer + bytes_written, buf_size - bytes_written, "\n%s%s %s", indent_buf, type_as_str, name);
        }
        indent += 4;

        // Add 4 to the indent.
        for(int i = 0; (i < indent); ++i) {indent_buf[i] = ' ';}

        int num_members = get_number_of_members_str(type_as_str); assert(num_members != -1); // Get the number of members for the for loop.
        for(int i = 0; (i < num_members); ++i) {
            MemberDefinition *member = members_of_Something + i; // Get the member pointer with meta data.
            size_t *member_ptr = (size_t *)((char *)var + member->offset); // Get the actual pointer to the memory address.
            switch(member->type) {
                // This is a little verbose so I can get the right template overload for serialize_primitive. I should just
                // make it a macro though.
                case MetaType_double: { // double.
                    bytes_written = serialize_primitive_((double *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                case MetaType_float: { // float.
                    bytes_written = serialize_primitive_((float *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                case MetaType_int: { // int.
                    bytes_written = serialize_primitive_((int *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                case MetaType_long: { // long.
                    bytes_written = serialize_primitive_((long *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                case MetaType_short: { // short.
                    bytes_written = serialize_primitive_((short *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                case MetaType_bool: { // bool.
                    bytes_written = serialize_primitive_((bool *)member_ptr, (member->is_ptr != 0), member->arr_size, member->name, indent, buffer, buf_size, bytes_written);
                } break;

                // char (special case).
                case MetaType_char: {
                    if(member_ptr) {
                        if(member->is_ptr) {
                            bytes_written += pp_sprintf(buffer + bytes_written, buf_size - bytes_written, "\n%schar *%s = \"%s\"", indent_buf, member->name, (char *)(*(size_t *)member_ptr));
                        } else {
                            bytes_written += pp_sprintf(buffer + bytes_written, buf_size - bytes_written, "\n%schar %s = %c", indent_buf, member->name, *(char *)((size_t *)member_ptr));
                        }
                    } else {
                        bytes_written += pp_sprintf((char *)buffer + bytes_written, buf_size - bytes_written, "\n%schar *%s = (null)", indent_buf, member->name);
                    }
                } break; // case MetaType_char

                default: {
                    if(is_meta_type_container(member->type)) {

                    } else {
                        char const *struct_name = meta_type_to_name(member->type, member->is_ptr != 0);
                        bytes_written = serialize_struct_(member_ptr, member->name, struct_name, indent, buffer, buf_size - bytes_written, bytes_written);
                    }
                } break; // default 
            }
        }
    }

    return(bytes_written);
}

// Convert a type into a members of pointer.
template<typename T> static MemberDefinition *get_members_of_(void) {
    // Recreated structs.
    struct _V2 {  _float x;  _float y;  };
    struct _Transform {  _V2 pos;  _V2 size;  };
    struct _Ball {  _Transform trans;  _V2 speed;  };
    struct _Paddle {  _Transform trans;  };
    struct _GameState {  _Paddle paddle;  _Ball ball;  _int score;  };
    // V2
    if(type_compare(T, V2)) {
        static MemberDefinition members_of_V2[] = {
            {MetaType_float, "x", offset_of(&_V2::x), false, 1},
            {MetaType_float, "y", offset_of(&_V2::y), false, 1},
        };
        return(members_of_V2);

    // Transform
    } else if(type_compare(T, Transform)) {
        static MemberDefinition members_of_Transform[] = {
            {MetaType_V2, "pos", offset_of(&_Transform::pos), false, 1},
            {MetaType_V2, "size", offset_of(&_Transform::size), false, 1},
        };
        return(members_of_Transform);

    // Ball
    } else if(type_compare(T, Ball)) {
        static MemberDefinition members_of_Ball[] = {
            {MetaType_Transform, "trans", offset_of(&_Ball::trans), false, 1},
            {MetaType_V2, "speed", offset_of(&_Ball::speed), false, 1},
        };
        return(members_of_Ball);

    // Paddle
    } else if(type_compare(T, Paddle)) {
        static MemberDefinition members_of_Paddle[] = {
            {MetaType_Transform, "trans", offset_of(&_Paddle::trans), false, 1},
        };
        return(members_of_Paddle);

    // GameState
    } else if(type_compare(T, GameState)) {
        static MemberDefinition members_of_GameState[] = {
            {MetaType_Paddle, "paddle", offset_of(&_GameState::paddle), false, 1},
            {MetaType_Ball, "ball", offset_of(&_GameState::ball), false, 1},
            {MetaType_int, "score", offset_of(&_GameState::score), false, 1},
        };
        return(members_of_GameState);
    }

    return(0); // Error.
}

// Convert a type into a members of pointer.
static MemberDefinition *get_members_of_str(char const *str) {
    // Recreated structs.
    struct _V2 {  _float x;  _float y;  };
    struct _Transform {  _V2 pos;  _V2 size;  };
    struct _Ball {  _Transform trans;  _V2 speed;  };
    struct _Paddle {  _Transform trans;  };
    struct _GameState {  _Paddle paddle;  _Ball ball;  _int score;  };
    // char
    if((strcmp(str, "char") == 0) || (strcmp(str, "char *") == 0) || (strcmp(str, "char **") == 0)) {
        static MemberDefinition members_of_char[] = {
            {MetaType_char, "", 0, false, 1}
        };
        return(members_of_char);

    // short
    } else if((strcmp(str, "short") == 0) || (strcmp(str, "short *") == 0) || (strcmp(str, "short **") == 0)) {
        static MemberDefinition members_of_short[] = {
            {MetaType_short, "", 0, false, 1}
        };
        return(members_of_short);

    // int
    } else if((strcmp(str, "int") == 0) || (strcmp(str, "int *") == 0) || (strcmp(str, "int **") == 0)) {
        static MemberDefinition members_of_int[] = {
            {MetaType_int, "", 0, false, 1}
        };
        return(members_of_int);

    // long
    } else if((strcmp(str, "long") == 0) || (strcmp(str, "long *") == 0) || (strcmp(str, "long **") == 0)) {
        static MemberDefinition members_of_long[] = {
            {MetaType_long, "", 0, false, 1}
        };
        return(members_of_long);

    // float
    } else if((strcmp(str, "float") == 0) || (strcmp(str, "float *") == 0) || (strcmp(str, "float **") == 0)) {
        static MemberDefinition members_of_float[] = {
            {MetaType_float, "", 0, false, 1}
        };
        return(members_of_float);

    // double
    } else if((strcmp(str, "double") == 0) || (strcmp(str, "double *") == 0) || (strcmp(str, "double **") == 0)) {
        static MemberDefinition members_of_double[] = {
            {MetaType_double, "", 0, false, 1}
        };
        return(members_of_double);

    // bool
    } else if((strcmp(str, "bool") == 0) || (strcmp(str, "bool *") == 0) || (strcmp(str, "bool **") == 0)) {
        static MemberDefinition members_of_bool[] = {
            {MetaType_bool, "", 0, false, 1}
        };
        return(members_of_bool);


    // V2
    } else if((strcmp(str, "V2") == 0) || (strcmp(str, "V2 *") == 0) || (strcmp(str, "V2 **") == 0)) {
        static MemberDefinition members_of_V2[] = {
            {MetaType_float, "x", offset_of(&_V2::x), false, 1},
            {MetaType_float, "y", offset_of(&_V2::y), false, 1},
        };
        return(members_of_V2);

    // Transform
    } else if((strcmp(str, "Transform") == 0) || (strcmp(str, "Transform *") == 0) || (strcmp(str, "Transform **") == 0)) {
        static MemberDefinition members_of_Transform[] = {
            {MetaType_V2, "pos", offset_of(&_Transform::pos), false, 1},
            {MetaType_V2, "size", offset_of(&_Transform::size), false, 1},
        };
        return(members_of_Transform);

    // Ball
    } else if((strcmp(str, "Ball") == 0) || (strcmp(str, "Ball *") == 0) || (strcmp(str, "Ball **") == 0)) {
        static MemberDefinition members_of_Ball[] = {
            {MetaType_Transform, "trans", offset_of(&_Ball::trans), false, 1},
            {MetaType_V2, "speed", offset_of(&_Ball::speed), false, 1},
        };
        return(members_of_Ball);

    // Paddle
    } else if((strcmp(str, "Paddle") == 0) || (strcmp(str, "Paddle *") == 0) || (strcmp(str, "Paddle **") == 0)) {
        static MemberDefinition members_of_Paddle[] = {
            {MetaType_Transform, "trans", offset_of(&_Paddle::trans), false, 1},
        };
        return(members_of_Paddle);

    // GameState
    } else if((strcmp(str, "GameState") == 0) || (strcmp(str, "GameState *") == 0) || (strcmp(str, "GameState **") == 0)) {
        static MemberDefinition members_of_GameState[] = {
            {MetaType_Paddle, "paddle", offset_of(&_GameState::paddle), false, 1},
            {MetaType_Ball, "ball", offset_of(&_GameState::ball), false, 1},
            {MetaType_int, "score", offset_of(&_GameState::score), false, 1},
        };
        return(members_of_GameState);
    }

    return(0); // Error.
}

// Get the number of members for a type.
static int get_number_of_members_str(char const *str) {
    if(strcmp(str, "char") == 0) {return(1);}
    else if(strcmp(str, "short") == 0) {return(1);}
    else if(strcmp(str, "int") == 0) {return(1);}
    else if(strcmp(str, "long") == 0) {return(1);}
    else if(strcmp(str, "float") == 0) {return(1);}
    else if(strcmp(str, "double") == 0) {return(1);}
    else if(strcmp(str, "bool") == 0) {return(1);}
    else if(strcmp(str, "V2") == 0) {return(2);} // V2
    else if(strcmp(str, "Transform") == 0) {return(2);} // Transform
    else if(strcmp(str, "Ball") == 0) {return(2);} // Ball
    else if(strcmp(str, "Paddle") == 0) {return(1);} // Paddle
    else if(strcmp(str, "GameState") == 0) {return(3);} // GameState

    return(-1); // Error.
}

// Get the number of base types.
template<typename T> static int get_base_type_count_(void) {

    return(0); // Not found.
}

// Get the base type.
template<typename T> static char const *get_base_type_as_string_(int index/*= 0*/) {

    return(0); // Not found.
}

#define weak_type_compare(A, B) TypeCompare_<pp::Type<A>::weak_type, pp::Type<B>::weak_type>::e;
#undef _std // :(
} // namespace pp

#endif // Header guard.

