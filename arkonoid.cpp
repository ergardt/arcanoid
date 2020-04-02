#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
using namespace sf;

class Ball
{
    public:
    sf::Sprite spriteBall;
    float x;
    float y;
    float vx;
    float vy;
    float dt = 0.1;
    Ball(sf::Sprite sBall, float tx, float ty, float tvx, float tvy)
    {
        spriteBall = sBall;
        x = tx;
        y = ty;
        vx = tvx;
        vy = tvy;
    }

};

class Platform
{
public:
    Sprite spritePlatform;

    void move()
    {
        if (Keyboard::isKeyPressed(Keyboard::Right))
             spritePlatform.move(10, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left))
            spritePlatform.move(-10, 0);
        
    }
};
            
int main()
{
    float dt = 0.1;
    int n = 0;
    int k = 0;
    int playButton = 0;
    int recButton = 0;
    int menuButton = 0;
    float vx=60;
    float vy=50;
    float x=300;
    float y=300;
    int deathMaxCount = 2;
    int deathCount = 0;
    int scoreCount = 0;
    bool gameover = false;
    srand(time(0));


    RenderWindow app(VideoMode(1000, 560), "_" );
    app.setFramerateLimit(60);


    Texture t1, t2, t3, t4, t5, t6, t7, t8,t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21;
    t1.loadFromFile("bl1.png");
    t2.loadFromFile("bl2.png");
    t3.loadFromFile("bl3.png");
    t4.loadFromFile("bl4.png");
    t5.loadFromFile("bl5.png");
    t6.loadFromFile("sky_blue.jpg");
    t9.loadFromFile("sky_black.jpg");
    t7.loadFromFile("ball.png");
    t8.loadFromFile("paddle.png");
    t10.loadFromFile("playc.png");
    t11.loadFromFile("arc.png");
    t12.loadFromFile("records.png");
    t13.loadFromFile("score.png");
    t14.loadFromFile("menu.png");
    t19.loadFromFile("recordsBig.png");
    t20.loadFromFile("playBig.png");
    t21.loadFromFile("menuBig.png");

    Sprite sBackground(t6), sBall(t7), sPaddle(t8), sMenu(t9), sPlay(t10), sArcanoid(t11), sRecords(t12),
    sScore(t13), sMenuBut(t14), sLevel1(t15), sLevel2(t16), sLevel3(t17), sContinue(t18),
    sRecordsBig(t19), sPlayBig(t20), sMenuBig(t21);
    sPaddle.setPosition(470 , 550);
    sPlay.setPosition(sf::Vector2f(430, 300));
    sArcanoid.setPosition(sf::Vector2f(200,60));
    sRecords.setPosition(sf::Vector2f(380, 400));
    sScore.setPosition(sf::Vector2f(150, 300));
    sMenuBut.setPosition(sf::Vector2f(60, 450));
    sLevel1.setPosition(sf::Vector2f(200, 400));
    sContinue.setPosition(sf::Vector2f(150, 480));
    sPlayBig.setPosition(sf::Vector2f(400, 285));
    sRecordsBig.setPosition(sf::Vector2f(330, 380));
    sMenuBig.setPosition(sf::Vector2f(30, 420));

    Sprite block[10000];

    sf::Texture blockTexture[5];
    blockTexture[0] = t1;
    blockTexture[1] = t5;
    blockTexture[2] = t6;
    blockTexture[3] = t7;
    blockTexture[4] = t8;

     for (int k = 0; k <= 4; k++)
     {
        for (int i = 0; i <= 19; i++)
        {
            for (int j = 2*k; j <= 2*k+1; j++)  
             {
                block[n].setTexture(blockTexture[k]);
                block[n].setPosition(i*50,j*24);
                n++;
             }
        }
    }          

    Ball Ball = Ball(sBall, 300, 300, 50, 60);
    Platform Platform;
   
    while (app.isOpen())
    {
       Event event;
       while (app.pollEvent(event))
       {
         if (event.type == Event::Closed)
             app.close();
       }
        sf::Font font;
        font.loadFromFile("Neons_demo.otf");
       /* std::ifstream g("tableRecords.txt");
        char s[1000];
        g.seekg(0, g.end);
        g.read(s, g.tellg());
        sf::Text recordsText(g.char(), font, 10);
        recordsText.setPosition(500, 50);
        recordsText.setFillColor(sf::Color(200, 0, 100));*/

         app.draw(sMenu);
         app.draw(sPlay);
         app.draw(sArcanoid);
         app.draw(sRecords);


         if (sf::IntRect(380, 400, 200, 100).contains(sf::Mouse::getPosition(app)))
        {

             app.draw(sMenu);
             app.draw(sPlay);
             app.draw(sArcanoid);
             app.draw(sRecordsBig);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                recButton += 1;
            }
            if  (not (sf::IntRect(380, 400, 200, 100).contains(sf::Mouse::getPosition(app))))
               {
                     sRecords.setPosition(sf::Vector2f(380, 400));
                     app.draw(sPlay);
                }
        }

            if (recButton > 0)
            {
                sRecords.setPosition(sf::Vector2f(30, 40));
                app.draw(sMenu);
                app.draw(sRecords);
                app.draw(sMenuBut);
               // app.draw(recordsText);

            }
            if  ((sf::IntRect(30, 450, 200, 100).contains(sf::Mouse::getPosition(app))) && (recButton > 0))
            {
                app.draw(sMenu);
                app.draw(sRecords);
                app.draw(sMenuBig);
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                {
                    menuButton += 2;
                }
            }

           if (menuButton > 0)
           {
             sRecords.setPosition(sf::Vector2f(380, 400));
             app.draw(sMenu);
             app.draw(sPlay);
             app.draw(sArcanoid);
             app.draw(sRecords);
             menuButton = 0;
             recButton = 0;
            }

         if  ((sf::IntRect(430, 300, 200, 80).contains(sf::Mouse::getPosition(app))) && (recButton == 0))

            {
                if (menuButton == 0)
                {
                app.draw(sMenu);
                app.draw(sPlayBig);
                app.draw(sArcanoid);
                app.draw(sRecords);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                         playButton += 1;
                    }
               if  (not (sf::IntRect(430, 300, 200, 80).contains(sf::Mouse::getPosition(app))))
               {

                     sPlay.setPosition(sf::Vector2f(430, 300));
                     app.draw(sPlay);
                }

                }
            }


            if (playButton > 0)
            {
               
               {
                x += vx*dt;
                y += vy*dt;
                for (int i = 0; i < n; i++)
                    if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
                         {
                            block[i].setPosition(-100,0);
                            scoreCount += int(1);
                            vx = -vx;
                            vy = -vy;
                         }



                if (x < 0 || x > 1000)
                    vx = -vx;
                if (y < 0)
                    vy = -vy;
            }

                if (y > 560)
                {
                    if (FloatRect(x + 3, y + 3, 6, 6).intersects(sPaddle.getGlobalBounds()))
                    {
                        vy = -vy;
                    }
                    else
                    {
                        //death
                        if ( deathCount < deathMaxCount )
                        {
                                deathCount++;
                                sPaddle.setPosition(470,550);
                                vx = 50;
                                vy = 60;
                                x = 300;
                                y = 300;
                        }
                        else
                        {
                            gameover = true;
                        }
                    }
                }

                if (!gameover) 
                {
                    Platform.move();
                    if ( FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds()))
                    vy = -vy;

                    sBall.setPosition(x,y);
                    app.clear();
                    app.draw(sBackground);
                    app.draw(sBall);
                    app.draw(sPaddle);
                    for (int i = 0; i < n; i++)
                        app.draw(block[i]);
                }
            }

            if (gameover)
            {
                app.clear();
                
                std::stringstream ss;
                ss << scoreCount;
                sf::Text scoreText (ss.str(), font, 150);
                scoreText.setFillColor(sf::Color(0, 183, 255));
                scoreText.setPosition(550,230);
                app.clear();
                app.draw(sMenu);
                app.draw(scoreText);
                app.draw(sScore);
                app.display();
                sf::sleep(sf::seconds(5));
                return 0;
            } 
            else 
            {
                app.display();
            }
        }
    delete [] block;
    return 0;
}

