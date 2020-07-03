#ifndef _HUD_
#define _HUD_

class Hud {
	private:
		int mapWidth, mapHeight;
	public:
		Hud(void);
		Hud(int width, int height);
		void render(void) const;
		int getMapWidth(void) const;
		int getMapHeight(void) const;

		friend class Game;
};

#endif
