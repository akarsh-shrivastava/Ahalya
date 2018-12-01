#ifndef TRANSLATOR_H_INCLUDED
    #define TRANSLATOR_H_INCLUDED
    #include <vector>
    #include "analyzer.h"
    #include "structs.h"

    struct Translator: public Analyzer
    {
        std::vector<Token_struct> token_data;
        std::string decimal_code;
        int line_count;
        std::string msg;

        Translator(std::vector<Token_struct> data);
        void build_decimal_instr();
        void syntax_error(std::vector<Token_struct>::iterator itr);

    }

#endif