#pragma once

#include "Entity.hpp"

#include <map>
#include <memory>
#include <vector>

class Manager {
  public:
    void refresh();
    void clear();
    void update();
    void render(sf::RenderWindow& target);

    template<typename T, typename... TArgs>
    T& create(TArgs&&... args)
    {
        static_assert(std::is_base_of<Entity, T>::value, "`T` must be derived from `Entity`");

        auto uniquePtr(std::make_unique<T>(std::forward<TArgs>(args)...));
        auto rawPtr(uniquePtr.get());

        groupedEntities_[typeid(T).hash_code()].emplace_back(rawPtr);
        entities_.emplace_back(std::move(uniquePtr));

        return *rawPtr;
    }

    template<typename T>
    auto& getAll()
    {
        return groupedEntities_[typeid(T).hash_code()];
    }

    template<typename T, typename TFunc>
    void forEachEntity(const TFunc& func)
    {
        for (auto ptr : getAll<T>()) {
            func(*reinterpret_cast<T*>(ptr));
        }
    }

  private:
    std::vector<std::unique_ptr<Entity>> entities_;
    std::map<std::size_t, std::vector<Entity*>> groupedEntities_;
};
