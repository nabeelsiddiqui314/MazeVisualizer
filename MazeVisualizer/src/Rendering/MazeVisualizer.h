#pragma once
#include "../Maze/IMazeObserver.h"
#include "Grid.h"

class Maze;

class MazeVisualizer : public IMazeObserver {
public:
	MazeVisualizer(Maze* maze, int cellWidth, int spacing);
	~MazeVisualizer() = default;
public:
	void onCellChange(const Coords& position) override;
	void render(sf::RenderTarget& target);
private:
	Maze* m_maze;
	Grid m_grid;
};