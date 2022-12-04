#pragma once
#include <map>
#include <memory>
#include <cassert>
#include <list>
#include <CommonEvents.hpp>

namespace ui
{

class EventHandler
{
public:
	template<class T>
	void notify(typename T::Event event, const T& eventData)
	{
		for (const auto& listener : m_listeners[static_cast<size_t>(event)])
		{
			auto* downcastedListener = dynamic_cast<EventListener<T>*>(listener.get()); // todo: dynamic_cast in debug, reinterpret in release
			if (downcastedListener)
				downcastedListener->notify(eventData);
			else
				assert(false && "Incorrect event listener type");
		}
		for (auto handlerIt = m_childHandlers.begin(); handlerIt != m_childHandlers.end();)
		{
			auto handler = handlerIt->lock();
			if (handler)
			{
				handler->notify(event, eventData);
				++handlerIt;
			}
			else
				handlerIt = m_childHandlers.erase(handlerIt);
		}
	}

	void subscribe(std::shared_ptr<BasicEventListener> listener) { m_listeners[listener->getEventId()].push_back(std::move(listener)); }

protected:
	using EventListenerList = std::vector<std::shared_ptr<BasicEventListener>>;
	using EventHandlerList = std::list<std::weak_ptr<EventHandler>>;

	std::map<size_t, EventListenerList> m_listeners;
	EventHandlerList m_childHandlers;
};

}
