#include "fx/PlaybackCategory.h"

AUD_NAMESPACE_BEGIN
PlaybackCategory::PlaybackCategory() :
	m_volumeStorage(std::make_shared<VolumeStorage>(1.0f))
{
}

void PlaybackCategory::addHandle(std::shared_ptr<IHandle> handle)
{
	switch (m_status) 
	{
	case STATUS_STOPPED:
		handle->stop();
		break;
	case STATUS_PAUSED:
		handle->pause();
		break;
	};
	m_handles.push_back(handle);
}

void PlaybackCategory::resume()
{
	for each (auto han in m_handles)
		han->resume();
	m_status = STATUS_PLAYING;
}

void PlaybackCategory::pause()
{
	for each (auto han in m_handles)
		han->pause();
	m_status = STATUS_PAUSED;
}

float PlaybackCategory::getVolume()
{
	return m_volumeStorage->getVolume();
}

void PlaybackCategory::setVolume(float volume)
{
	m_volumeStorage->setVolume(volume);
}

void PlaybackCategory::stop() 
{
	for each (auto han in m_handles)
		han->stop();
	m_status = STATUS_STOPPED;
}
AUD_NAMESPACE_END