#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cctype>
#include <algorithm>

#include "structs.h"
#include "analyzer.h"

Analyzer::Analyzer ()
{

    delimitor = "\n";
    seperator = ",";
    colon     = ":";

    cs_addr_open   = "{";
    cs_addr_close  = "}";
    es_addr_open   = "(";
    es_addr_close  = ")";
    ds_addr_open   = "[";
    ds_addr_close  = "]";

    instructions_2addr  = {
                              "mov",
                              "add","sub","mul","div","mod",
                              "and","or","xor",
                              "cmp","def"
                          };

    instructions_1addr  = {
                              "not","neg"
                          };

    jump                = {
                              "jmp"
                          };

    jump_conditions     = {
                                "eq"  ,  "neq",
                               "grt"  ,  "grteq",
                              "less"  ,  "lesseq",
                              "always"
                          };

    segments      = {
                        ".code",".data"
                    };
}




void Analyzer::build_token_data(std::vector<std::string> tokens)
{
    std::vector<std::string>::iterator itr;
    Token_struct tok_data;

    for (itr=tokens.begin(); itr!=tokens.end(); itr++)
    {
        tok_data.tok = *itr;
        tok_data.type = get_type(itr);
    
        token_data.push_back(tok_data);
    }
}

bool Analyzer::is_string(std::string tok)
{
    if( *(tok.begin())=='"' && *(tok.end())=='"' )
        return true;

    return false;
}

bool Analyzer::is_const(std::string tok)
{
    for (std::string::iterator i=tok.begin(); i!=tok.end(); i++)
        if (!isdigit(*i))
            return false;

    return true;
}

bool Analyzer::is_possible_identifier(std::string tok)
{
    int i,len=tok.size();

    if( !(isalpha(tok[0]) || tok[0]=='_') )
        return false;

    for(i=1;i<len;i++)
    {
        if( !(isalpha(tok[0]) || tok[0]=='_' || isdigit(tok[0]) ) )
            return false;
    }

    return true;
}

std::string Analyzer::get_type(std::vector<std::string>::iterator itr)
{
    if ( (std::find(instructions_1addr.begin(), instructions_1addr.end(), *itr)) != instructions_1addr.end())
    {
        return "instruction_1addr";
    }

    else if ( (std::find(instructions_2addr.begin(), instructions_2addr.end(), *itr)) != instructions_2addr.end())
    {
        return "instruction_2addr";
    }

    else if ( (std::find(jump.begin(), jump.end(), *itr)) != jump.end())
    {
        return "jump";
    }

    else if ( (std::find(jump_conditions.begin(), jump_conditions.end(), *itr)) != jump_conditions.end())
    {
        return "jump_condition";
    }

    else if ((*itr) == ".code" || (*itr) == ".data" || (*itr) == ".extra")
    {
        return *itr;
    }

    else if ((*itr) == delimitor )
    {
        return "delimitor";
    }

    else if ((*itr) == seperator )
    {
        return "seperator";
    }

    else if ((*itr) == colon )
    {
        return "colon";
    }

    else if ((*itr) == cs_addr_open )
    {
        return "cs_addr_open";
    }

    else if ((*itr) == cs_addr_close )
    {
        return "cs_addr_close";
    }

    else if ((*itr) == es_addr_open )
    {
        return "es_addr_open";
    }

    else if ((*itr) == es_addr_close )
    {
        return "es_addr_close";
    }

    else if ((*itr) == ds_addr_open )
    {
        return "ds_addr_open";
    }

    else if ((*itr) == ds_addr_close )
    {
        return "ds_addr_close";
    }

    else if(is_possible_identifier(*itr))
    {
        return "possible_identifier";
    }

    else if(is_string(*itr))
    {
        return "string";
    }

    else if(is_const(*itr))
    {
        return "constant";
    }

    else
    {
        return "unknown token";
    }
}


void Analyzer::print_token_data()
{
    for (std::vector<Token_struct>::iterator i = token_data.begin(); i != token_data.end(); ++i)
    {
        (*i).print();
    }
}

std::vector<Token_struct> Analyzer::get_token_data()
{
    return token_data;
}
