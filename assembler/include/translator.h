##ifndef TRANSLATOR_H_INCLUDED
    #define TRANSLATOR_H_INCLUDED value
    #include <vector>
    #include "structs.h"

    struct Translator
    {
        std::vector<Token_struct> token_data;

        Translator(std::vector<Token_struct> data);
    }

#endif