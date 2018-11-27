#ifndef ANALYZER_H_INCLUDED
    #define ANALYZER_H_INCLUDED
    #include <vector>
    #include <string>
    #include <iterator>

    #include "structs.h"

    struct Analyzer
    {
        std::vector<std::string> instructions;
        std::vector<std::string> segments;

        std::string cs_addr_open ;
        std::string cs_addr_close;
        std::string es_addr_open ;
        std::string es_addr_close;
        std::string ds_addr_open ;
        std::string ds_addr_close;

        std::string delimitor = "\n";
        std::string seperator = ",";
        
        std::vector<Token_struct> token_data;

        Analyzer();
        void build_token_data(std::vector<std::string> tokens);
        bool is_possible_identifier(std::string tok);
        bool is_string(std::string tok);
        bool is_const(std::string tok);
        std::string get_type(std::vector<std::string>::iterator itr);
        std::vector<Token_struct> Analyzer::get_token_data()

        void print_token_data();
    };
#endif
