#ifndef PROGRAM_H
#define PROGRAM_H

#include <cmath>
#include "raylib.h"

class Program
{
    public:
        Program();
        void loop();
        void close();
    private:
        bool running;
        Camera2D camera;
};

#endif