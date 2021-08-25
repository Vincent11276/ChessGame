/*
MIT License

Copyright (c) 2021 Vincent

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <filesystem>

#define MAX_TILE_COUNT 32


class TileMap : public sf::Drawable, public sf::Transformable
{
private:
    std::vector<std::vector<int>> mapdata;

    sf::Vector2f cellSize;

public: 
    /**
     * @brief Construct a new Tile Map object
     * 
     */
    TileMap();

    /**
     * @brief Construct a new Tile Map object
     * 
     * @param p_mapSize Size of the tile map
     * 
     * @param p_cellSize Size of the cell
     */
    TileMap(sf::Vector2i p_mapSize, sf::Vector2f p_cellSize);
    
    /**
     * @brief Loads tile from sf::Texture
     * 
     * @param p_tileSet Tile set texture source
     * 
     * @param append Resets the current tileset before loading if set to false
     */
    void loadFromTexture(sf::Texture &p_tileSet, bool p_append=true);

    /**
     * @brief Loads all images and extract it to tiles within the sepecified directory
     * 
     * @param path Target directory
     * 
     * @param append Resets the current tileset before loading if set to false
     */
    void loadFromDirectory(const std::string &p_path, bool p_append=true);

    /**
     * @brief Maps cell by cell from the source data, error free on any sizes
     * 
     * @param data Source tiledata
     */
    void mapCellsFrom(std::vector<std::vector<int>> &p_tiledata);

    /**
     * @brief Empties all cell, does not reset size
     * 
     */
    void clear();

    /**
     * @brief Empties cell specified by coordinates
     * 
     * @param p_coords Coordinates of the cell
     */
    void remove(sf::Vector2i p_coords);
    
    /**
     * @brief Sets a cell specified by coordinates, does nothing if out-of-index
     * 
     * @param id ID of the tile 
     * 
     * @param p_coords coordinate of the cell to be removed
     */
    void setCell(int id, sf::Vector2i p_coords);
    
    /**
     * @brief Gets cell ID specified by coordinates, does nothing if out-of-index
     * 
     * @param p_coords 
     * 
     * @return int 
     */
    int getCell(sf::Vector2i p_coords);

    // [TO-DO]
    // void resizeMap(sf::Vector2i p_size);

    /**
     * @brief Returns the size of tile map
     * 
     * @return sf::Vector2i 
     */

    void setCells(std::vector<std::vector<int>> &p_cells);

    std::vector<std::vector<int>> &getCells();

    sf::Vector2i getMapSize();

    /**
     * @brief Returns a list of cell coordinates that is equal to the ID specified
     * 
     * @param id ID of the tile
     * 
     * @return std::vector<sf::Vector2i> 
     */
    std::vector<sf::Vector2i> getUsedCells(int id);

    /**
     * @brief Returns a list of cell coordinates that is occupied
     * 
     * @return std::vector<sf::Vector2i> 
     */
    std::vector<sf::Vector2i> getUsedCells();

    /**
     * @brief Returns the rect of the occupied cells
     * 
     * @return sf::Vector2i 
     */
    sf::Vector2i getUsedRect();

    /**
     * @brief returns coordinates equivalent to tile map
     * 
     * @param p_coords coordinates of the world
     * 
     * @return sf::Vector2f 
     */
    sf::Vector2i worldToMap(sf::Vector2i p_coords);

    /**
     * @brief returns coordinates equivalent to the world
     * 
     * @param p_coords coordinates of the tile map
     * 
     * @return sf::Vector2i 
     */
    sf::Vector2i mapToWorld(sf::Vector2i p_coords);

    /**
     * @brief Checks if coordinates specified are in-bounds with the tile data size for further indexing error free
     * 
     * @param p_coords 
     * @return true if in-bounds
     * @return false if out-of-bounds
     */
    bool isInBounds(sf::Vector2i p_coords);

public:
    sf::VertexArray     tileVertices;
    sf::RenderTexture   tileSet;
    int32_t             tileCount = 0;

    void setTileVertices(int id, sf::Vector2i p_coords);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
