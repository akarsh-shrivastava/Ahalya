#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>

#include "preprocessor.h"
#include "tokenizer.h"
#include "analyzer.h"
#include "translator.h"

int main(int n,char** args)
{
    std::ifstream f(args[1]);
    std::string code="";
    char ch;
    if(!f)
        std::cout<<"No such file\n";
    else
    {
        while(f.get(ch))
            code.push_back(ch);
        f.close();
        /*std::cout<<code;*/
    }

    if(code.length()>0)
    {
        Preprocessor p(code);
        p.preprocess();
        code.clear();
        code=p.get_preprocessed_code();

        Tokenizer t;
        std::vector<std::string> tokens=t.tokenize(code);

        Analyzer a;
        a.build_token_data(tokens);
        a.print_token_data();

        Translator tr(a.token_data);
        tr.build_decimal_instr();
        std::cout<<tr.error_msg<<"\n\n";
        std::cout<<tr.decimal_code;

    }
}
