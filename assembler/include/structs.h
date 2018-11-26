#ifndef STRUCTS_H_INCLUDED
    #define STRUCTS_H_INCLUDED
    #include <string>

    struct Flag_struct
    {
        unsigned char str_open : 1;
        unsigned char char_open : 1;

        Flag_struct();
    };

    struct Token_struct
    {
        std::string tok;
        std::string type;

        void print();
    };
#endif