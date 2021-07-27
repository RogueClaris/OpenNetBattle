#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <unordered_map>
#include <memory>

#include "bnOverworldObjectType.h"
#include "bnOverworldSprite.h"
#include "bnOverworldCustomProperties.h"
#include "bnOverworldShapes.h"
#include "bnOverworldTile.h"
#include "bnOverworldMap.h"
#include "../bnSpriteProxyNode.h"
#include "bnXML.h"

namespace Overworld {
  struct Tile;
  class Map;

  class MapObject {
  public:
    unsigned int id;
    std::string name;
    std::string typeString;
    ObjectType::ObjectType type;
    bool visible{ true };
    bool solid{};
    sf::Vector2f position;
    sf::Vector2f size;
    float rotation;
    CustomProperties customProperties;

    virtual bool Intersects(Map& map, float x, float y) const { return false; }
    std::shared_ptr<WorldSprite> GetWorldSprite() { return worldSprite; }

    virtual ~MapObject() = default;

  protected:
    std::shared_ptr<WorldSprite> worldSprite;

    MapObject() = default;

    friend Map;
  };

  class ShapeObject : public MapObject {
  public:
    std::unique_ptr<Overworld::Shape> shape;

    ShapeObject(unsigned int id, std::unique_ptr<Overworld::Shape> shape);

    static std::optional<ShapeObject> From(const XMLElement& element);

    bool Intersects(Map& map, float x, float y) const override;
  };

  class TileObject : public MapObject {
  public:
    Overworld::Tile tile;

    TileObject(unsigned int id, Overworld::Tile tile);
    TileObject(unsigned int id, unsigned int gid);

    static TileObject From(const XMLElement& element);

    bool Intersects(Map& map, float x, float y) const override;
    void Update(Map& map);
  };
}
