#include <vector>
#include <string>
#include <iterator>
#include "translator.h"
#include "structs.h"

Translator::Translator(std::vector<Token_struct> data)
{
	token_data = data;
}

void Translator::build_decimal_instr()
{
	std::vector<Token_struct>::iterator itr;
	for (itr = token_data.begin(); itr != token_data.end(); ++itr)
	{
		
	}
}