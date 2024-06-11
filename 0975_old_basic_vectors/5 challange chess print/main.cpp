#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/*
TODO:
prepare chess game schemat without implementation 
divide it on classes  and on subsytems*/

class Board
{
    private:
        int default_board_size = 8;
        int in_board_size;
        std::vector<std::vector<std::unique_ptr<Field>>>  board;
    public:
        Board(int board_size):in_board_size{board_size=default_board_size}{}
        ~Board(){};
        void prepare_board()
        {            
            std::vector<std::vector<std::unique_ptr<Field>>> board;
            for(int y =1; y<= in_board_size;++y)
            {   
                std::vector<std::unique_ptr<Field>> one_row;
                for(int x =1; x<= in_board_size;++x)
                {  
                    std::unique_ptr<Field>f1{new Field{x,y}};
                    one_row.push_back(std::move(f1)); 
                }
                board.push_back(std::move(one_row));  
            }
        }
        std::vector<std::vector<std::unique_ptr<Field>>> & get_board()
        {return board;}
};

/*base for diffrent chess pices*/
/**/
class ChessPiece
{
    std::string& name;
    void draw();
    virtual bool check_availible_moves(std::vector<std::vector<std::unique_ptr<Field>>>)=0;
};

class Queen: public ChessPiece
{   

};

class Pawn: public ChessPiece
{

};


class Field
{
    public:
    bool is_empty{true};
    int x;
    int y;
    ChessPiece & figure_at;
    Field(int in_x,int in_y):x{in_x},y{in_y}{}
    //ChessPiece & figure_at;
};

class GamePlay
{
    public:
        void print_board(Board &board)
        {
            
            for(int y =0; y<= board.get_board().size()-1;++y)
            {
                for(int x =0; x<= board.get_board().at(y).size()-1;++x)
                {
                    std::cout<<"x: " <<board.get_board().at(y).at(x)->x<<" y: " <<board.get_board().at(y).at(x)->y<<std::endl;
                }
            }
        }

};


int main()
{


    

    
/*
    for(int y =1; y<= 8;++y)
    {   
        
            std::unique_ptr<Field>f1{new Field{0,y}};
            b1.push_back(std::move(f1)); 
        
        //b1.push_back(one_row);  
    }*/


/*
    std::unique_ptr<Field>f1{new Field{0,0}};
    b1.push_back(std::move(f1));
        std::unique_ptr<Field>f2{new Field{1,0}};
    b1.push_back(std::move(f2));
        std::unique_ptr<Field>f3{new Field{1,0}};
    b1.push_back(std::move(f3));*/

    




/*
    std::vector<std::vector<std::unique_ptr<Field>>>  board{};

    for(int x =1;x<=8;++x)
    {
        for(int y =1;y<=8;++y)
        {
            std::unique_ptr<Field> f= std::make_unique<Field>();
            board[x][y].push_back(std::move(f));
        }
    }
*/

    return 0;
}