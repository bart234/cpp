#include "cls_Tests.h"

int main()
{
    //tests::test_1_split_by_delimiter();
    //tests::test_3_file_man();
    //tests::test_4_find_n_element_in_string_between_delimiter();
    //tests::test_5_fm_GetRowByElementFromNcolumn();
    //tests::test_6_fm_GetVectorWithWholeColumnFromFile();
    //tests::test_7_input_validation();
    //tests::test_8_test_find_map();
    //tests::test_a9_check_alidateInputOnlyLetterAndSpaces();
    //tests::test_a10_check_cleanStringFromAllOtherSigns();
    //tests::test_a11_check_returnDuplicatedValueAndPositionWhereItis();
    //tests::test_a11_function_test_returnDuplicatedValueAndPositionWhereItis();
    //tests::test_a12_check_returnDuplicatedValueAndPositionWhereItisInVector();
    //return 0;

    //TODO:
    //std::pair<int,std::string> Playlist_I::CreateNewPlaylist(std::string path_to_pls_list_file) add --> std::cout<<"To cancel it type: cancel"<<std::endl;
    //test: MP_playlist_i.h -> CreateNewPlaylist (this->Load_pls_with_track_to_pick_for_everyone();)  -> excavate kind of error from deeper funcion    
    //TODO: simplify mp_user_base and mp_user_main - check what for is user base
    //DONE: there is a error at user/user1 - fix that - there was no folder for new user
    //TODO: make files check and error handler if there is no files for user 
    //TODO: during creating new user - create user folder with filees
    //TODO: move class Option_MainMenu_Template into another file , rename it
    //TODO: check if after login, at 1th menu I will make logout - will i still be loged in, or no
    //TODO: more space in make playlist, wyszczegolnic checki i psrawdzic czy wogole dzialaja

    //user: Bob 
    //pwd: user1
    App my_app{};
    my_app.app_run();      

}

