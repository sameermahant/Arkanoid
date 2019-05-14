#include "Manager.hpp"

// This function will do the job of cleaning the entities which are marked to destroy
void Manager::refresh()
{
    for (auto& [entity_type, vector_entity_ptrs] : groupedEntities_) {

        vector_entity_ptrs.erase(std::remove_if(std::begin(vector_entity_ptrs), std::end(vector_entity_ptrs),
                                                [](auto rawPtr) { return rawPtr->isMarkedToDestroy(); }),
                                 std::end(vector_entity_ptrs));

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
