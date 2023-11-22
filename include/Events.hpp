#pragma once
#include <functional>
#include <map>
#include <vector>
#include <memory>
#include <Utils.hpp>
#include <SDL3/SDL.h>

namespace ui
{

class EventListener
{
public:
	EventListener(Uint32 eventType, std::function<void(const SDL_Event&)> handler) : m_eventType(eventType), m_handler(std::move(handler)) {}
	size_t getEventType() const { return static_cast<size_t>(m_eventType); }
	void notify(const SDL_Event& eventData)
    {
        if (eventData.type == m_eventType)
            m_handler(eventData);
    }

private:
	Uint32 m_eventType;
	std::function<void(const SDL_Event&)> m_handler;
};

class EventHandler
{
public:
	void notify(const SDL_Event& eventData)
	{
		for (const auto& listener : m_listeners[eventData.type])
		{
            listener->notify(eventData);
		}
		for (auto handlerIt = m_childHandlers.begin(); handlerIt != m_childHandlers.end();)
		{
			auto handler = handlerIt->lock();
			if (handler)
			{
				handler->notify(eventData);
				++handlerIt;
			}
			else
				handlerIt = m_childHandlers.erase(handlerIt);
		}
	}

	void subscribe(std::shared_ptr<EventListener> listener) { m_listeners[listener->getEventType()].emplace_back(std::move(listener)); }
	void subscribe(Uint32 eventType, std::function<void(const SDL_Event&)> handler) { m_listeners[eventType].emplace_back(std::make_shared<EventListener>(eventType, handler)); }

    void addChildHandler(std::weak_ptr<EventHandler> handler) { m_childHandlers.push_back(std::move(handler)); }

protected:
	using EventListenerContainer = std::map<Uint32, std::vector<std::shared_ptr<EventListener>>>;
	using EventHandlerList = std::vector<std::weak_ptr<EventHandler>>;

	EventListenerContainer m_listeners;
	EventHandlerList m_childHandlers;
};

}