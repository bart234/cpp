#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

//function prototype
bool czy_zderzenie(sf::Sprite &spr_ball, sf::Sprite &spr_pad);
char zderzenie_x_czy_y(sf::Sprite &spr_ball, sf::Sprite &spr_pad);
void pod_moves_x_y(sf::Sprite *spr_pod,float pod_move_speed,sf::RenderWindow *oknoAplikacji);
float zmiana_wsp_odbicia_zaleznie_od_miejsca(sf::Sprite &spr_ball, sf::Sprite &spr_pad,char kierunek_zderzenia,float kierunek_ball_x,float kierunek_ball_y);
//--------------------------------------------------------------------------------------


//functions--------------------------------------------------------------
float zmiana_wsp_odbicia_zaleznie_od_miejsca(sf::Sprite &spr_ball, sf::Sprite &spr_element,char kierunek_zderzenia,float kierunek_ball_x,float kierunek_ball_y)
    {/*
    sf::Vector2f aktualna_pozycja_pod = spr_element->getPosition();
    sf::Vector2f aktualna_pozycja_ball = spr_ball->getPosition();
    sf::Vector2f srodek_ball = spr_ball->getOrigin();
    sf::Vector2f srodek_element = spr_element->getOrigin();

    float ball_2r_lenght {spr_ball->getTexture()->getSize().x * spr_ball->getScale().x};

    float pod_x_lenght {spr_element->getTexture()->getSize().x * spr_element->getScale().x};
    float pod_y_lenght {spr_element->getTexture()->getSize().y * spr_element->getScale().y};

    float x_ball_left{aktualna_pozycja_ball.x};
    float x_ball_right{aktualna_pozycja_ball.x + ball_2r_lenght};
    float y_ball_top{aktualna_pozycja_ball.y};
    float y_ball_bot{aktualna_pozycja_ball.y + ball_2r_lenght};


    float x_pad_left{aktualna_pozycja_pod.x};float x_pad_right{aktualna_pozycja_pod.x + pod_x_lenght};
    float y_pad_top{aktualna_pozycja_pod.y}; float y_pad_bot{aktualna_pozycja_pod.y+pod_y_lenght};

        if(kierunek_zderzenia =='x'){
            //wez srodek pilki oraz srodek elementu
            //male elementy - wsp kierunku zalezny od odleglosci od srodka ale odwrotny od aktualnego ruchu
            //duze elementy (sciany) - wsp kierunku taki jak porzednio ale w druga strone
            //w jakiej odleglosi od srodka uderzyl srodek pilki
            if (srodek_ball.y >srodek_element.y){
                //pilka pozyej osi x - odbicie dalej do gory

            }else{
                //pilka ponizej polowy obiektu -osi x wiec trzeba by odbibic troche w dol - tutaj wyliczyc
            }

        }else{

        }*/
    }

char zderzenie_x_czy_y(sf::Sprite *spr_ball, sf::Sprite *spr_pad)
    {
    sf::Vector2f aktualna_pozycja_pod = spr_pad->getPosition();
    sf::Vector2f aktualna_pozycja_ball = spr_ball->getPosition();
    sf::Vector2f srodek_ball = spr_ball->getOrigin();

    float ball_2r_lenght {spr_ball->getTexture()->getSize().x * spr_ball->getScale().x};

    float pod_x_lenght {spr_pad->getTexture()->getSize().x * spr_pad->getScale().x};
    float pod_y_lenght {spr_pad->getTexture()->getSize().y * spr_pad->getScale().y};

    float x_ball_left{aktualna_pozycja_ball.x};
    float x_ball_right{aktualna_pozycja_ball.x + ball_2r_lenght};
    float y_ball_top{aktualna_pozycja_ball.y};
    float y_ball_bot{aktualna_pozycja_ball.y + ball_2r_lenght};
    float x_ball_srodek{x_ball_left +ball_2r_lenght/2};
    float y_ball_srodek{y_ball_top +ball_2r_lenght/2};


    float x_pad_left{aktualna_pozycja_pod.x};float x_pad_right{aktualna_pozycja_pod.x + pod_x_lenght};
    float y_pad_top{aktualna_pozycja_pod.y}; float y_pad_bot{aktualna_pozycja_pod.y+pod_y_lenght};

    //x
    if (abs(x_ball_right) >= abs(x_pad_left)  &&  ((y_ball_srodek>=y_pad_top)&&(y_ball_srodek<=y_pad_bot)))
    {
        std::cout<<"zderzenie x z prawej"<<std::endl;
        return 'x';
    }

    //x
    if (abs(x_ball_left) <=abs(x_pad_right)  &&  ((y_ball_srodek>=y_pad_top)&&(y_ball_srodek<=y_pad_bot)))
    {
        std::cout<<"zderzenie x z lewej"<<std::endl;
        return 'x';
    }

    //printf("y_ball_top: %f | y_pad_bot: %f | x_ball_srodek: %f | x_pad_left: %f | x_ball_srodek: %f | x_pad_right: %f | ",y_ball_top,y_pad_bot,x_ball_srodek,x_pad_left,x_ball_srodek,x_pad_right);

    if (abs(y_ball_top - y_pad_bot)<1  &&  ((x_ball_srodek>=x_pad_left)&&(x_ball_srodek<=x_pad_right)))
    {
        //std::cout<<"sufit test "<<std::endl;
        return 'y';
    }

}

bool czy_zderzenie(sf::Sprite *spr_ball, sf::Sprite *spr_pad)
    {
    sf::Vector2f aktualna_pozycja_pod = spr_pad->getPosition();
    sf::Vector2f aktualna_pozycja_ball = spr_ball->getPosition();

    float ball_2r_lenght {spr_ball->getTexture()->getSize().x * spr_ball->getScale().x};

    float pod_x_lenght {spr_pad->getTexture()->getSize().x * spr_pad->getScale().x};
    float pod_y_lenght {spr_pad->getTexture()->getSize().y * spr_pad->getScale().y};

    float x_ball_left{aktualna_pozycja_ball.x};
    float x_ball_right{aktualna_pozycja_ball.x + ball_2r_lenght};
    float y_ball_top{aktualna_pozycja_ball.y};
    float y_ball_bot{aktualna_pozycja_ball.y + ball_2r_lenght};


    float x_pad_left{aktualna_pozycja_pod.x};float x_pad_right{aktualna_pozycja_pod.x + pod_x_lenght};
    float y_pad_top{aktualna_pozycja_pod.y}; float y_pad_bot{aktualna_pozycja_pod.y+pod_y_lenght};

    //printf("ball_right: %f , pad_left: %f , ball_left: %f , pad_right: %f \n",x_ball_right,x_pad_left,x_ball_left,x_pad_right);
    if(
       ((x_ball_right >= x_pad_left && x_ball_right <= x_pad_right) ||(x_ball_left < x_pad_right && x_ball_left >= x_pad_left))
         &&
       ((y_ball_top <= y_pad_bot && y_ball_top >= y_pad_top) || (y_ball_bot>=y_pad_top && y_ball_bot <= y_pad_bot))
       )
    {
        return true;
    }else
    {
        return false;
    }
}

void pod_moves_x_y(sf::Sprite *spr_pad,float pod_move_speed,sf::RenderWindow *oknoAplikacji)
{
    float szerokosc_pada = spr_pad->getTexture()->getSize().x * spr_pad->getScale().x;

    sf::Vector2u wymiary_okna = oknoAplikacji->getSize();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        if((spr_pad->getPosition().x - (pod_move_speed))< 0)
            {
            }
        else
            {
            spr_pad->move( -pod_move_speed, 0 );
            }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        if ((spr_pad->getPosition().x+ (szerokosc_pada) + pod_move_speed)> wymiary_okna.x)
            {
            }
        else
            {
            spr_pad->move(+pod_move_speed,0);
            }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        spr_pad->move( 0, +pod_move_speed );
    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        spr_pad->move(0,-pod_move_speed);
    }


}

//--------------------------------------------------------------------------------------


int main()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 850, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );

           //sf::Texture
    sf::Texture mojaTextura;
    mojaTextura.loadFromFile("obrazek.bmp"); // true gdy wczytalo, false jak blad
    sf::Sprite sprajt ;
    sprajt.setTexture(mojaTextura);
    sf::Vector2u wymiary_okna = oknoAplikacji.getSize();

    sf::Texture text_ball;
    text_ball.loadFromFile("ball.bmp");
    sf::Sprite spr_ball;
    spr_ball.setTexture(text_ball);
    float ball_2r_lenght {spr_ball.getTexture()->getSize().x * spr_ball.getScale().x};

    sf::Texture text_pad;
    text_pad.loadFromFile("kreska.bmp");
    sf::Sprite spr_pad;
    spr_pad.setTexture(text_pad);
    float pod_x_lenght {spr_pad.getTexture()->getSize().x * spr_pad.getScale().x};
    float pod_y_lenght {spr_pad.getTexture()->getSize().y * spr_pad.getScale().y};

    sf::Texture text_sciana_right;
    text_sciana_right.loadFromFile("sciana.bmp");
    sf::Sprite spr_sciana_right;
    spr_sciana_right.setTexture(text_sciana_right);

    sf::Texture text_sciana_left;
    text_sciana_left.loadFromFile("sciana.bmp");
    sf::Sprite spr_sciana_left;
    spr_sciana_left.setTexture(text_sciana_left);

    sf::Texture text_sciana_top;
    text_sciana_top.loadFromFile("sciana_top.bmp");
    sf::Sprite spr_sciana_top;
    spr_sciana_top.setTexture(text_sciana_top);

    sf::Texture text_sciana_bot;
    text_sciana_bot.loadFromFile("sciana_top.bmp");
    sf::Sprite spr_sciana_bot;
    spr_sciana_bot.setTexture(text_sciana_bot);

    //float sciana_grubosc {spr_sciana_left->getTexture()->getSize().x * spr_sciana_left->getScale().x}; //5
    //float sciana_dlugosc {spr_sciana_left->getTexture()->getSize().y * spr_sciana_left->getScale().y};  //800 ?

    //parametry gry
    float cienkosc_sciany{5};
    float pod_move_speed {15.0};
    float pod_grubosc {20.0};
    float odl_od_ramki_dolnej{10};
    int temp_x{0};

    float move_on_y{0.03};
    float *move_y {&move_on_y};

    float move_on_x{0.0};
    float *move_x{&move_on_x};

    float kierunek{0.1};
    float *param_kierunku{&kierunek};

    //pozycje podczas startu gry
    spr_sciana_right.setPosition(wymiary_okna.x-5,0);
    spr_sciana_left.setPosition(0+5,0);
    spr_sciana_top.setPosition(20,0+5);
    spr_sciana_bot.setPosition(0,wymiary_okna.y-5);
    spr_ball.setPosition(wymiary_okna.x/2,wymiary_okna.y/2);
    spr_pad.setPosition(wymiary_okna.x/2 - pod_x_lenght/2,400);
    //spr_pad.setPosition(wymiary_okna.x/2 - pod_x_lenght/2,wymiary_okna.y-pod_y_lenght - odl_od_ramki_dolnej);





    while( oknoAplikacji.isOpen() ) // petla glowna
    {
        sf::Event zdarzenie;

        //event loop
        while(oknoAplikacji.pollEvent(zdarzenie))
        {

            //exit
            if(zdarzenie.type == sf::Event::Closed)
                {oknoAplikacji.close();}
            if(zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape)
                {oknoAplikacji.close();}
            //pad moves
            pod_moves_x_y(&spr_pad,pod_move_speed, &oknoAplikacji);
        }
        // event loop  end

//ruch pod katem

{
    if (temp_x==10){
            if(abs(*move_y)>abs(*move_x))
                {
                spr_ball.move(*move_x+*param_kierunku,*move_y);
                temp_x = 0;
            }else{
                spr_ball.move(*move_x,*move_y+*param_kierunku);
                temp_x = 0;
            }
    }else{
        spr_ball.move(*move_x,*move_y);
    }
    ++temp_x;
}

   //czy zderzenie
{
    if(czy_zderzenie(&spr_ball, &spr_pad)==true)
    {
        if (zderzenie_x_czy_y(&spr_ball, &spr_pad)== 'x'){
            //pad nie ma uderzen bokiem ale dodamy
            //prawa strona (odbicie jak sciana lewa bo na zewnatrz)
            if ((spr_ball.getPosition().x)<(spr_sciana_left.getPosition().x+cienkosc_sciany )) {
                spr_ball.move( 1,0);
            }

            //lewa strona (odbicie jak sciana prawa bo na zewnatrz)
            if ((spr_ball.getPosition().x +ball_2r_lenght)>spr_sciana_right.getPosition().x ){
                spr_ball.move( -1,0);
            }

            if(abs(*move_y)>abs(*move_x)){
                *param_kierunku *= -1;
            }else{
                *move_x*=-1;
            }
         }else{
             //dotyczy scian poziomych
             //jesli pilka wpadla odrobine w teksture , wyjmujemy zaleznie czy  wpadla z dolu czy z gory
            if((spr_ball.getPosition().y+ball_2r_lenght)>spr_pad.getPosition().y){
                //od gory
                spr_ball.move(0,-1);
            }
               //od dolu
            if ((spr_ball.getPosition().y)<(spr_pad.getPosition().y+pod_grubosc)){
                    spr_ball.move( 0,+1);
            }

            if(abs(*move_y)>abs(*move_x)){
                *move_y *=-1;
            }else{

                std::cout<<"pad 04 przy y < x"<<std::endl;
                //*param_kierunku *= -1;
            }
         }

            float pozycja_srodka_pilki {spr_ball.getPosition().x + (ball_2r_lenght/2)};
            float pozycja_srodka_pad {spr_pad.getPosition().x + (pod_x_lenght/2)};
            float pozycja_pilki_od_srodka_pada {abs (pozycja_srodka_pad-pozycja_srodka_pilki)};
            std::cout<<"pozycja pilki na padzie: "<<pozycja_pilki_od_srodka_pada<<std::endl;

            if (pozycja_srodka_pilki > pozycja_srodka_pad){
                //z prawej
                //*param_kierunku = *param_kierunku + (pozycja_pilki_od_srodka_pada*2)/100;
                *param_kierunku = (pozycja_pilki_od_srodka_pada*2)/100;
                /*if (*param_kierunku > 0){
                        //0.1 - 1

                    *param_kierunku += 1;
                }else{
                    *param_kierunku -= 0.8
;
                }*/


            }else{
                //z lewej
                *param_kierunku = -(*param_kierunku + (pozycja_pilki_od_srodka_pada*2)/100);
        //printf("zderzenie: param kierunku po: %f \n",*param_kierunku);
            }






    }
}

    if(czy_zderzenie(&spr_ball, &spr_sciana_right)==true)
    {
         if (zderzenie_x_czy_y(&spr_ball, &spr_sciana_right)== 'x'){
            if ((spr_ball.getPosition().x +ball_2r_lenght)>spr_sciana_right.getPosition().x ){
                std::cout<<"weszla w sciane prawa na:"<<(spr_ball.getPosition().x +ball_2r_lenght)-spr_sciana_right.getPosition().x<<std::endl;
                spr_ball.move( -1,0);
                }

                if(abs(*move_y)>abs(*move_x)){
                    std::cout<<"Pt1"<<std::endl;
                    *param_kierunku *= -1;
                }else{
                    std::cout<<"Pt2"<<std::endl;
                    *move_x*=-1;
                }
         }else{
             //dotyczy scian poziomych
             std::cout<<"blad: dot sciana right - weszlo w sciany poziome"<<std::endl;
             std::cout<<zderzenie_x_czy_y(&spr_ball, &spr_sciana_right)<<std::endl;
         }
    }

    if(czy_zderzenie(&spr_ball, &spr_sciana_left)==true)
    {
         if (zderzenie_x_czy_y(&spr_ball, &spr_sciana_left)== 'x'){
            if ((spr_ball.getPosition().x)<(spr_sciana_left.getPosition().x+cienkosc_sciany )) {
                spr_ball.move( 1,0);
                std::cout<<"weszla w sciane lewa na:"<<((spr_ball.getPosition().x)-(spr_sciana_left.getPosition().x+cienkosc_sciany ))<<std::endl;
            }
            if(abs(*move_y)>abs(*move_x)){
                *param_kierunku *= -1;
                std::cout<<"test1"<<std::endl;
             }else{
                std::cout<<"test2"<<std::endl;
                //*param_kierunku *=-1; //bez zmian
                *move_x *=-1;
            }

         }else{
             std::cout<<"blad: dot sciana left - weszlo w sciany poziome"<<std::endl;
             //dotyczy scian poziomych
         }
    }

    if(czy_zderzenie(&spr_ball, &spr_sciana_top)==true)
    {
        if (zderzenie_x_czy_y(&spr_ball, &spr_sciana_top)== 'x'){
            std::cout<<"to x przy  scianie poziomej wiec blad"<<std::endl;
        }else{
           //jesli pilka wpadla odrobine w teksture , wyjmujemy
            if ((spr_ball.getPosition().y)<(spr_sciana_top.getPosition().y+cienkosc_sciany)){
                    spr_ball.move( 0,+1);
            }

            if(abs(*move_y)>abs(*move_x)){
                std::cout<<"sufit przy y > x"<<std::endl;
                *move_y*=-1;
            }else{
                *param_kierunku *= -1;
            }
        }
    }

    if(czy_zderzenie(&spr_ball, &spr_sciana_bot)==true)
    {
        if (zderzenie_x_czy_y(&spr_ball, &spr_sciana_bot)== 'x'){
            std::cout<<"to x przy  scianie poziomej wiec blad"<<std::endl;
        }else{
            //jesli pilka wpadla odrobine w teksture , wyjmujemy
            if ((spr_ball.getPosition().y+ball_2r_lenght)>(spr_sciana_bot.getPosition().y)){
                std::cout<<"weszla w podloge na (bot):"<<(spr_ball.getPosition().y+ball_2r_lenght)-(spr_sciana_bot.getPosition().y)<<std::endl;
                spr_ball.move( 0,-1);
            }

            if(abs(*move_y)>abs(*move_x)){
                std::cout<<"podloda przy y > x"<<std::endl;
                *move_y *=-1;
            }else{
                *param_kierunku *= -1;
            }
        }
    }

    // ball outside frame

        if(((spr_ball.getPosition().y + ball_2r_lenght) >= wymiary_okna.y)||(spr_ball.getPosition().y<=0)){
        *move_y = 0;
        std::cout<<"przegrales"<<std::endl;
        break;
    }

 //std::cout<<"ball x:"<<spr_ball.getPosition().x<<" y: " <<spr_ball.getPosition().y <<"sciana x:"<<spr_sciana_right.getPosition().x<<" y: " <<spr_sciana_right.getPosition().y <<std::endl;

//---------------------------
    oknoAplikacji.clear();
    oknoAplikacji.draw(spr_sciana_left);
    oknoAplikacji.draw(spr_sciana_right);
    oknoAplikacji.draw(spr_sciana_top);
    oknoAplikacji.draw(spr_sciana_bot);
    oknoAplikacji.draw(spr_ball);
    oknoAplikacji.draw(spr_pad);
    oknoAplikacji.display();
    }


    return 0;
}

