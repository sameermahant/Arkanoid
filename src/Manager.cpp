#include "Manager.hpp"

void Manager::refresh()
{
    for (auto& pair : groupedEntities_) {
        auto& entitiesVector(pair.second);

        entitiesVector.erase(std::remove_if(std::begin(entitiesVector), std::end(entitiesVector),
                                            [](auto rawPtr) { return rawPtr->isMarkedToDestroy(); }),
                             std::end(entitiesVector));

        entities_.erase(std::remove_if(std::begin(entities_), std::end(entities_),
                                       [](const auto& uniquePtr) { return uniquePtr->isMarkedToDestroy(); }),
                        std::end(entities_));
    }
}

void Manager::clear()
{
    groupedEntities_.clear();
    entities_.clear();
}

void Manager::update()
{
    for (auto& entity : entities_) {
        entity->update();
    }
}

void Manager::render(sf::RenderWindow& target)
{
    for (auto& entity : entities_) {
        entity->render(target);
    }
}
