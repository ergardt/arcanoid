#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <iostream>
using namespace sf;

int main()
{
    float dx=6; 
    float dy=5;
    float x=300;
    float y=300;
    int deathMaxCount = 3;
    int deathCount = 0;
    srand(time(0));

    RenderWindow app(VideoMode(1000, 560), "_" );
    app.setFramerateLimit(60);

    Texture t1, t2, t3, t4, t5, t6, t7, t8,t9, t10, t11, t12;
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


   


    Sprite sBackground(t2), sBall(t3), sPaddle(t4), sMenu(t9), sPlay(t10), sArcanoid(t11), sRecords(t12);
    sPaddle.setPosition(470 , 550);
    sPlay.setPosition(sf::Vector2f(430, 300)); 
    sArcanoid.setPosition(sf::Vector2f(200,60));
    sRecords.setPosition(sf::Vector2f(380, 400));


    Sprite block[10000];
    int collisions[1000];


    int n = 0;
    int k = 0;
    int a = 0;
    int counter = 0;
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 1; j++)
          {  
             collisions[n] = int(5);
             block[n].setTexture(t1);
             block[n].setPosition(i*50,j*24);
             n++;
          }
     
        for (int j = 2; j <= 3; j++)
          {
             collisions[n] = int(4);
             block[n].setTexture(t5);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 4; j <= 5; j++)
          {
            collisions[n] = int(3);
             block[n].setTexture(t6);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 6; j <= 7; j++)
          {
            collisions[n] = int(2);
             block[n].setTexture(t7);
             block[n].setPosition(i*50,j*24);
             n++;
          }
        for (int j = 8; j<=9; j++)
          {
            collisions[n] = int(1);
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



         if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (sf::IntRect(430, 300, 200, 80).contains(sf::Mouse::getPosition(app))))
            {
            a = a + 1;
            }

            if (a > 0)
            {
                x += dx;
                for (int i = 0; i < n; i++)
                    if (FloatRect(x+3, y+3, 6, 6).intersects(block[i].getGlobalBounds()))
                         {  
                            block[i].setPosition(-100,0);
                            counter += 1;
                            dx = -dx;
                         }

                y += dy;
                for (int i = 0; i < n; i++)
                    if ( FloatRect( x+3, y+3, 6, 6).intersects(block[i].getGlobalBounds()))
                        {
                            block[i].setPosition(-100,0);
                            dy = -dy;
                        }

                if (x < 0 || x > 1000)  dx = -dx;
                if (y < 0) dy = -dy;

                if (y > 560)
                {
                    if (FloatRect(x+3, y+3, 6, 6).intersects(sPaddle.getGlobalBounds()))
                    {
                        dy = -dy;
                    }
                    else
                    {
                        //death
                        if ( deathCount < deathMaxCount )
                        {
                                
                                deathCount++;
                                sPaddle.setPosition(470,550);
                                dx = 0;
                                dy = 8;
                                x = 550;
                                y = 400;
                        }

                    
                        else
                        {
                            return 0;
                        }
                    }
                }

                if (Keyboard::isKeyPressed(Keyboard::Right)) sPaddle.move(6,0);
                if (Keyboard::isKeyPressed(Keyboard::Left)) sPaddle.move(-6,0);

                if ( FloatRect(x,y,12,12).intersects(sPaddle.getGlobalBounds()) ) dy=-(rand()%5+2);

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
            
  return 0;
}
