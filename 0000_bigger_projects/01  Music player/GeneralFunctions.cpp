#include "GeneralFunctions.h"

using namespace GeneralFuncitons;

bool is_number(const std::string &rawElement);
int validateIsInputOnlyLetterAndSpaces(std::string inputFromConsole,std::string accptable_chars_in_str = "");
int rawInputHandler(std::string inputFromConsole);
std::string FindNElementFromSeparatedByDelimString(std::string &string_to_search,char delimiter, size_t column_num_to_return);
std::vector<std::string>* SplitStringByDelimiter(std::string string_to_split, char delmiter);
std::string cleanStringFromAllOtherSigns(std::string string_to_clean, std::string accptable_chars_in_str);
std::map<int,std::vector<int>> returnDuplicatedValueAndPositionWhereItis(std::vector<int> vector_to_analize);
std::vector<std::pair<int,int>> returnVectorWithDuplicatedValuesAndItPosition(std::vector<int> vector_to_analize);