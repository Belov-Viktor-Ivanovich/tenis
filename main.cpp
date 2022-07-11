#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int WIDHT = 800;
int HEIGHT = 800;
float RADIUS = 20;
float x = WIDHT / 2 - RADIUS;
float y = HEIGHT / 2 - RADIUS;






int main()
{
	RenderWindow window(VideoMode(WIDHT, HEIGHT), "my windows");
	CircleShape shape(RADIUS);
    RectangleShape rectangle(Vector2f(120, 20));
    rectangle.setPosition(0, 780);
	window.setFramerateLimit(60);
	Image image,imageFon;
    imageFon.loadFromFile("C:\\Users\\Марина\\Documents\\Белов C++\\тренировка\\Прыгающий шарик\\Project1\\222.jpg");
	image.loadFromFile("C:\\Users\\Марина\\Documents\\Белов C++\\тренировка\\Прыгающий шарик\\Project1\\111.png.jpg");
	Texture texture,textureFon;
    textureFon.loadFromImage(imageFon);
	texture.loadFromImage(image);
    rectangle.setTexture(&texture);
	shape.setPosition(x, 0); 
	shape.setTexture(&texture);
    bool flag = true;
    bool flagP = true;
    bool flagL = false;
    bool flagR = false;
    float yM = 2;
    float xM = 0;
    int k = 0;
    int div = 0;    //1 left 2 right
    Sprite splite;
    splite.setTexture(textureFon);
    

	while (window.isOpen())
	{
        if (shape.getPosition().y > 800)
        {
            window.close();
        }
        k++;
        if(!flagP)shape.move(xM, yM);
        if (flagP) {
            shape.move(0, yM);
        }
        if (shape.getPosition().x >= rectangle.getPosition().x - 30 && shape.getPosition().x <= rectangle.getPosition().x + 110)
        {
            if (shape.getPosition().y <= 743 && shape.getPosition().y >= 737)
            {
                if (flagL)
                {
                    xM -= yM;
                    yM *= -1;
                }
                else if (flagR)
                {
                    xM += yM;
                    yM *= -1;
                }
                else yM *= -1;
                flagP = false;
                
            }

        }
        if (shape.getPosition().y <= 0)
        {
            yM *= -1;
        }
        else if (shape.getPosition().x <= 0)
        {
            xM *= -1;
        }
        else if (shape.getPosition().x >= 757)
        {
            xM *= -1;
        }
        
        if (k % 20 == 0)
        {
            flagR = false;
            flagL = false;
        }
        if (k > 100000)
        {
            k = 0;
            div = 0;
        }

		Event event;
		while (window.pollEvent(event))
		{
            k++;
            switch (event.type)
            {
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                {
                    cout << "Window was closed. Was pressed esc.";
                    window.close();
                }
                else if (event.key.code == Keyboard::Enter)
                {
                    flag = !flag;
                }
                else if (event.key.code == Keyboard::Right)
                {
                    if (rectangle.getPosition().x < 680)
                    rectangle.move(12, 0);
                    flagR = true;
                    div = 2;
                }
                else if (event.key.code == Keyboard::Left)
                {
                    if (rectangle.getPosition().x > 0)
                    rectangle.move(-12, 0);
                    flagL = true;
                    div = 1;
                }
                /*else if (event.key.code == Keyboard::Up)
                {
                    if (shape.getPosition().y > 0)
                        shape.move(0, -4);
                }
                else if (event.key.code == Keyboard::Down)
                {
                    if (shape.getPosition().y < 700)
                        shape.move(0, 4);
                }*/
                /*else if (event.key.code == Keyboard::Space)
                {
                    while (shape.getPosition().y>0)
                    {
                        shape.move(0, ~speed);
                        window.draw(splite);
                        window.draw(shape);
                        window.draw(rectangle);
                        window.display();
                    }
                    while (shape.getPosition().y < 700)
                    {
                        shape.move(0, speed);
                        window.draw(splite);
                        window.draw(shape);
                        window.draw(rectangle);
                        window.display();
                    }
                }*/
                else if(shape.getPosition().y > 700)window.close();
                break;
            }
            // "close requested" event: we close the window
            //событие «запрос на закрытие»: мы закрываем окно
            if (event.type == sf::Event::Closed)
                window.close();
		}
       // window.clear(Color::Green);  
        window.draw(splite);
        if (flag)window.draw(shape);
        window.draw(rectangle);
        window.display();
	}





    


}