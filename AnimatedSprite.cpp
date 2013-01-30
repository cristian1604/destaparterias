#include "AnimatedSprite.h"
AnimatedSprite::AnimatedSprite(const std::string &filename, unsigned nCols, unsigned nRows):TiledSprite(filename, nCols, nRows){
	frameTime = 0;
	currentFrameElapsed = 0;
	isPlaying = false;
}

void AnimatedSprite::SetAnimation(const vector<unsigned> &frames, float animTime, bool loop, unsigned startFrame, bool resetFrameTime){
	this->frames = frames;
	frameTime = animTime / frames.size();
	this->loop = loop;
	currentFrame = startFrame;
	if (resetFrameTime) currentFrameElapsed = 0;
	isPlaying = true;
}


void AnimatedSprite::Animate(const float &dt){
	if (!isPlaying) return;
	currentFrameElapsed+=dt;
	if (currentFrameElapsed>=frameTime){
		currentFrameElapsed-=frameTime;
		++currentFrame;
		if (currentFrameElapsed >= frames.size()){
			if (loop){
				currentFrame = 0;
				SetTileIndex(currentFrame);
			}else{
				isPlaying = false;
			}
		}else{
			SetTileIndex(currentFrame);
		}
	}
}


void AnimatedSprite::Stop(unsigned tileIndex){
	isPlaying = false;
	SetTileIndex(tileIndex);
}


bool AnimatedSprite::IsAnimating() const{
	return isPlaying;
}


