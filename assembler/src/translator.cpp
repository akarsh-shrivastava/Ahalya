#include <vector>
#include <string>
#include <iterator>
#include <stack>
#include <queue>
#include "translator.h"
#include "structs.h"

Translator::Translator(std::vector<Token_struct> data) : Analyzer()
{
    str2dec =   {
                    {"mov_m",  "1"},  {"mov_l",  "2"},

                    {"add_m",  "3"},  {"add_l",  "4"},
                    {"sub_m",  "5"},  {"sub_l",  "6"},
                    {"mul_m",  "7"},  {"mul_l",  "8"},
                    {"div_m",  "9"},  {"div_l", "10"},
                    {"mod_m", "11"},  {"mod_l", "12"},

                    {"and_m", "13"},  {"and_l", "14"},
                    {"or_m",  "15"},  {"or_l",  "16"},
                    {"not_m", "17"},
                    {"neg_m", "18"},
                    {"xor_m", "19"},  {"xor_l", "20"},
                    
                    {"cmp_m", "21"},  {"cmp_l", "22"},

                    {"jmp",   "23"},
                    {"def",   "24"},


                    {"less"  , "1"},
                    {"eq"    , "2"},
                    {"lesseq", "3"},
                    {"grt"   , "4"},
                    {"neq"   , "5"},
                    {"grteq" , "6"},
                    {"always", "7"}

                };
    token_data   = data;
    current_line = "";
    decimal_code = "";
    line_count   = 1;
    error_msg          = "";
}

void Translator::syntax_error(std::vector<Token_struct>::iterator itr, std::string err_msg)
{
    error_msg += "Error at line "+std::to_string(line_count)+": "+err_msg+"\n";
    while(itr->tok != "\n") itr++;
    line_count++;
}

void Translator::build_decimal_instr()
{
    std::string status;
    std::vector<Token_struct>::iterator itr;
    for (itr = token_data.begin(); itr != token_data.end(); itr++)
    {
        if (itr->tok == "\n")
        {
            line_count++;
        }
        if (itr->type == "instruction_1addr")
        {
            current_line += (str2dec[itr->tok+"_m"] + "\n");
            itr++;
            if(itr->type == "ds_addr_open")
            {
                itr++;
                if (itr->type == "constant")
                {
                    current_line += (itr->tok + "\n");
                    itr++;
                    if (itr->type == "ds_addr_close")
                    {
                        itr++;
                        if (itr->type == "delimitor")
                        {
                            current_line += "0\n";
                            decimal_code += current_line;
                            current_line.clear();
                            line_count++;
                        }
                        else
                        {
                            syntax_error(itr, "expected end of line");
                        }
                    }
                    else
                    {
                        syntax_error(itr, "address marker ([) not closed");
                    }
                }
                else
                {
                    syntax_error(itr, "not a valid address");
                }
            }
            else
            {
                syntax_error(itr, "expected an address");
            }
        }
        else if (itr->type == "instruction_2addr");
        else if (itr->type == "jump");
        else if (itr->type == "possible_identifier");
        else;
    }
}