#pragma once

class Fruit{
    private:
        int x;
        int y;
    public:
        Fruit(int width, int height);
        
        int getX();
        int getY();

        void spawn(int width, int height);
};