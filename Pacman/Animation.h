#pragma once
#include <SFML/Graphics.hpp>
struct Frame {
	sf::IntRect rect;
	double duration;
};
enum PlayBackMode {
	NONE,
	LOOP
};
class Animation
{
	std::vector<Frame> frames;
	double totalLength;
	double progress;
	sf::Sprite& target;
	PlayBackMode playbackMode;
public:
	Animation(sf::Sprite& target);
	virtual ~Animation();
	void AddFrame(Frame&& frame);
	void Update(double elapsed);
	const double GetLength() const { return totalLength; }
	void SetPlaybackMode(PlayBackMode mode) { playbackMode = mode; }
};

