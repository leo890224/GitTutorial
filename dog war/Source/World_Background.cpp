#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "World_Background.h"

namespace game_framework
{
	World_Background::World_Background()
	{
		sx = 0;
		sy = 0;
	}
	void World_Background::LoadBitmap()
	{
		map.LoadBitmap(world_map);
	}

	int World_Background::ScreenX(int x)
	{
		return x - sx + 320;
	}

	int World_Background::ScreenY(int y)
	{
		return y - sy + 240;
	}

	void World_Background::OnMove(int nx, int ny)
	{
		if (sx < nx) sx += 10;
		if (sx > nx) sx -= 10;
		if (sy < ny) sy += 2;
		if (sy > ny) sy -= 2;
		if (sx < 320) sx = 320;
		if (sx > 2159) sx = 2159;
		if (sy < 240) sy = 240;
		if (sy > 720) sy = 720;
	}

	void World_Background::OnShow()
	{
		map.SetTopLeft(-sx + 320, -sy + 240);
		map.ShowBitmap();
	}
}