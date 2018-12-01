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
    line_count   = 0;
    msg          = "";
}

void Translator::syntax_error(std::vector<Token_struct>::iterator itr)
{
    while(*itr != "\n") itr++;
    line_count++;
}

void Translator::build_decimal_instr()
{
    std::stack<std::string> status;
    std::vector<Token_struct>::iterator itr;
    for (itr = token_data.begin(); itr != token_data.end(); ++itr)
    {
        if (status.empty())
        {
            if (itr->type == "instruction_1addr")
            {
                status.push("instruction_1addr");
            }
            else if (itr->type == "instruction_2addr")
            {
                status.push("instruction_2addr");
            }
            else if (itr->type == "jump")
            {
                status.push("jump");
            }
            else if (itr->type == "possible_identifier")
            {
                status.push("possible_identifier");
            }
            else
            {
                syntax_error(itr);
                char buff[100];
                sprintf(buff, "Error at line %d. Expected instruction or label.\n",line_count);
                msg += std::string (buff);
            }
        }

        else if (status.top)
    }
}