#pragma once
#include <vector>
#include <memory>
#include "../Util/Coords.h"
#include "../Util/Size.h"
#include "../Algorithms/Generation/IMazeGenerator.h"
#include "../Algorithms/Pathfinding/IPathfinder.h"

enum class Cell {
	EMPTY,
	WALL
};

class IMazeObserver;

class Maze {
public:
	Maze(const Size& size);
	~Maze() = default;
public:
	void setCellAt(const Coords& position, const Cell& cell);
	Cell getCellAt(const Coords& position) const;

	void fill(const Cell& cell);

	Size getSize() const;

	bool isOutOfBounds(const Coords& position) const;

	void setGenerator(std::unique_ptr<IMazeGenerator> generator);
	void generate();

	void setPathStart(const Coords& position);
	void setPathDestination(const Coords& position);

	void setPathfinder(std::unique_ptr<IPathFinder> pathfinder);
	void findPath();

	void registerObserver(IMazeObserver* observer);
private:
	std::size_t getIndex(const Coords& position) const;
private:
	std::vector<Cell> m_cells;
	Size m_size;
	std::unique_ptr<IMazeGenerator> m_generator;
	Coords m_start, m_end;
	std::unique_ptr<IPathFinder> m_pathfinder;
	std::vector<IMazeObserver*> m_observers;
};