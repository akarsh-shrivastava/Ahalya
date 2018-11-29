#include <vector>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include "translator.h"
#include "structs.h"

Translator::Translator(std::vector<Token_struct> data) : Analyzer()
{
    token_data   = data;
    decimal_code = "";
}

void Translator::build_decimal_instr()
{
    std::stack<std::string> status;
    std::vector<Token_struct>::iterator itr;
    for (itr = token_data.begin(); itr != token_data.end(); ++itr)
    {
        if (status.empty())
        {
            if (itr->type == "instruction_1addr");
            else if (itr->type == "instruction_2addr");
            else if (itr->type == "jump");
            else if (itr->type == "possible_identifier");
            else;
            
        }
    }
}