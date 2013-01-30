#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "TiledSprite.h"
#include <vector>
using namespace std;

class AnimatedSprite : public TiledSprite {	
	public:
	AnimatedSprite(const std::string &filename, unsigned nCols, unsigned nRows=1);
	void SetAnimation(const vector<unsigned> &frames, float animTime, bool loop = true, unsigned startFrame = 0, bool resetFrameTime = true);
	void Stop(unsigned tileIndex);
	bool IsAnimating() const;
	
	private:
	float frameTime, currentFrameElapsed;
	unsigned currentFrame;
	bool isPlaying;
	bool loop;
	vector<unsigned> frames;
	void Animate(const float &dt);
};

#endif

