#ifndef _MAP_
#define _MAP_

class Map {
    private:
        char** map;
        int width, height;
    public:
        Map(int width, int height);
        void render(int xStart, int yStart) const;
    
    friend class Game;
};

#endif