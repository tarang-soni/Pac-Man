#include "Animation.h"

Animation::Animation(sf::Sprite& target):target(target),playbackMode(PlayBackMode::NONE)
{
	progress = totalLength = 0.f;
}

Animation::~Animation()
{
}

void Animation::AddFrame(Frame&& frame)
{
	totalLength += frame.duration;
	frames.push_back(std::move(frame));
}

void Animation::Update(double elapsed)
{
	progress += elapsed;
	double p = progress;
	for (size_t i = 0; i < frames.size(); i++)
	{

		p -= frames[i].duration;

		if (playbackMode == PlayBackMode::LOOP && p > 0.0 && &(frames[i]) == &(frames.back())) {
			i = -1;    // start over from the beginning
			continue; // break off the loop and start where i is
		}
		if (p <= 0.0 || &(frames[i]) == &frames.back()) {
			target.setTextureRect(frames[i].rect);
			break;
		}

	}
}
