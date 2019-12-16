#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <iostream>
#include <list>
using namespace sf;

int main()
{



    
    srand(time(0));

    RenderWindow app(VideoMode(1000, 560), "_" );
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7, t8,t9, t10, t11, t12, t13, t14, t15, t16, t17, t18, t19, t20, t21;
    t1.loadFromFile("bl1.png");
    t2.loadFromFile("sky_blue.jpg");
    t3.loadFromFile("ball.png");
    t4.loadFromFile("paddle.png");
    t5.loadFromFile("bl2.png");
    t6.loadFromFile("bl3.png");
    t7.loadFromFile("bl4.png");
    t8.loadFromFile("bl5.png");
    t9.loadFromFile("sky_black.jpg");
    t10.loadFromFile("playc.png");
    t11.loadFromFile("arc.png");
    t12.loadFromFile("records.png");
    t13.loadFromFile("score.png");
    t14.loadFromFile("menu.png");
    t15.loadFromFile("level1.png");
    t16.loadFromFile("level2.png");
    t17.loadFromFile("level3.png");
    t18.loadFromFile("continue.png");
    t19.loadFromFile("recordsBig.png");
    t20.loadFromFile("playBig.png");
    t21.loadFromFile("menuBig.png");



   


    Sprite sBackground(t2), sBall(t3), sPaddle(t4), sMenu(t9), sPlay(t10), sArcanoid(t11), sRecords(t12), 
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
    //list <string> records;
    int deathMaxCount = 2;
    int deathCount = 0;
    int scoreCount = 0;
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 1; j++)
          {  
             
             block[n].setTexture(t1);
             block[n].setPosition(i*50,j*24);
             n++;
          }
     
        for (int j = 2; j <= 3; j++)
          {
           
             block[n].setTexture(t5);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 4; j <= 5; j++)
          {
            
             block[n].setTexture(t6);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 6; j <= 7; j++)
          {
           
             block[n].setTexture(t7);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 8; j <= 9; j++)
          {
           
             block[n].setTexture(t8);
             block[n].setPosition(i*50,j*24);
             n++;
          }
    }
    


              


    while (app.isOpen())
    {
       Event event;
       while (app.pollEvent(event))
       {
         if (event.type == Event::Closed)
             app.close();
       }
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


                x += vx*dt;
                for (int i = 0; i < n; i++)
                    if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
                         {  
                            block[i].setPosition(-100,0);
                            scoreCount += int(1);
                            vx = -vx;
                         }

                y += vy*dt;
                for (int i = 0; i < n; i++)
                    if ( FloatRect( x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
                        {
                            block[i].setPosition(-100,0);
                            scoreCount += int(1);
                            vy = -vy;
                        }

                if (x < 0 || x > 1000)  
                    vx = -vx;
                if (y < 0) 
                    vy = -vy;

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
                           
                          //  std::cout << scoreCount << std::endl;
                            return 0;
                            
                        }
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Right)) 
                    sPaddle.move(6, 0);
                if (Keyboard::isKeyPressed(Keyboard::Left)) 
                    sPaddle.move(-6, 0);

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
           

            app.display();
            }
            

delete [] block;
return 0;
}
  
