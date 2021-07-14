#pragma once
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
#include <vector>
#include <string>
#include "maze_cell.cpp"
#include "maze_wall.cpp"
#include "maze_algorithm.cpp"

struct Maze {
    //Constructors
    Maze(unsigned width, unsigned height, MazeAlgorithm* maze_algorithm);
    Maze(const Maze& other) = delete;
    Maze(Maze&& other) noexcept;
    
    //Destructor
    ~Maze();
    
    //Methods
    void reset();
    void reconstruct();
    void regenerate();
    void set_algorithm(MazeAlgorithm* maze_algorithm);
    std::string to_string() const; 

    //Operators
    Maze& operator=(const Maze& other) = delete;
    Maze& operator=(Maze&& other) noexcept;

private:
    MazeAlgorithm* maze_algorithm;
    std::vector<std::vector<MazeCell>> cells;
    std::vector<*MazeWall> walls;
    size_t width;
    size_t height;
};

//Constructor
Maze::Maze(size_t width, size_t height, MazeAlgorithm* maze_algorithm)
    : maze_algorithm{ maze_algorithm },
    cells{},
    walls{},
    width{ width },
    height{ height } {
    this->reconstruct();
    this->regenerate();
}

//Destructor
Maze::~Maze() {
    delete maze_algorithm;
    for (auto wall : walls) {
        delete wall;
    }
}

//Move Constructor
Maze::Maze(Maze&& other) noexcept
    : maze_algorithm{ std::move(other.maze_algorithm) },
    cells{ std::move(other.cells) }, 
    walls{ std::move(other.walls) },
    width{ std::move(other.width) },
    height{ std::move(other.height) } {}

//Move Assignment Operator
Maze& Maze::operator=(Maze&& other) noexcept {
    delete maze_algorithm;
    maze_algorithm{ std::move(other.maze_algorithm) };
    cells = std::move(other.cells);
    for (auto wall : walls) {
        delete wall;
    }
    walls{ std::move(other.walls) };
    width = other.width;
    height = other.height;
    other.width = 0;
    other.height = 0;
}

//Resets all walls in maze to active. Primarily used to reset a maze for regeneration.
void Maze::reset() {
    for (auto wall : walls) {
        wall.active = true
    }
}

//Reconstructs maze with the dimensions width and height. 
//Used to build a maze. No algorithm is applied on the Maze.
void Maze::reconstruct() {
    if (cells.capacity() != 0) { cells = std::vector<std::vector<MazeCell>>{}; }
    cells.reserve(width);
    for (size_t i = 0; i < width; i++) {
        cells.push_back(std::vector<MazeCell>{});
        cells[i].reserve(height);
        for (size_t j = 0; j < height; j++) {
            cells[i].push_back(MazeCell);
        }
    }

    //Build Walls
    for x in 0..width {
        for y in 0..height {
            let top_wall = Rc::new(RefCell::new(MazeWall::new(true)));
            let left_wall = Rc::new(RefCell::new(MazeWall::new(true)));

            //Set current cell's top and left walls
            self.cells[x][y].set_top_wall(Rc::clone(&top_wall));
            self.cells[x][y].set_left_wall(Rc::clone(&left_wall));

            //Set neighboring cell's bottom and right walls
            if x != 0 {
                self.cells[x - 1][y].set_right_wall(Rc::clone(&left_wall));
            }
            if y != 0 {
                self.cells[x][y - 1].set_bottom_wall(Rc::clone(&top_wall));
            }

            //Add wall to the Maze walls vector
            self.walls.push(Rc::clone(&top_wall));
            self.walls.push(Rc::clone(&left_wall));
        }
    }

    //Add walls to the bottom row and right column
    for column in self.cells.iter_mut() {
        let bottom_wall = Rc::new(RefCell::new(MazeWall::new(true)));
        column[height - 1].set_bottom_wall(Rc::clone(&bottom_wall));
        self.walls.push(Rc::clone(&bottom_wall));
    }

    for row in self.cells[width - 1].iter_mut() {
        let right_wall = Rc::new(RefCell::new(MazeWall::new(true)));
        row.set_right_wall(Rc::clone(&right_wall));
        self.walls.push(Rc::clone(&right_wall));
    }
}

void Maze::regenerate() {
    this->reset();
    this->maze_algorithm.generate(&mut self.cells, &mut self.walls);
}

void set_algorithm(MazeAlgorithm* new_algorithm) {
    this->maze_algorithm = new_algorithm;
}

//to_string()
std::string Maze::to_string() {
    //Exception case
    if self.cells.len() == 0 { return ""; }

    string maze_str = "";

    for (size_t y = 0; y < height; y++) {
        //Top Row
        for (size_t x = 0; x < width; x++) {
            maze_str += "██";

            if (cells[x][y].top_wall().active) { 
                maze_str += "██"; 
            }
            else { 
                maze_str += "  "; 
            }
        }

        //Rightest wall of top row
        maze_str += "██\n";
        
        //Middle Row
        for (size_t x = 0; x < width; x++) {
            if cells[x][y].left_wall().active { 
                maze_str += "██"; 
            }
            else { 
                maze_str += "  "; 
            }

            maze_str += "  ";
        }

        //Rightest wall of middle row
        if cells[width - 1][y].right_wall().active { 
           maze_str += "██\n"; 
        }
        else { 
            maze_str += "  \n"; 
        }
    }

    //Bottom Row
    for (size_t x = 0; x < width; x++) {
        maze_str += "██";

        if cells[x][height - 1].bottom_wall().active { 
            maze_str += "██"; 
        }
        else { 
            maze_str += "  "; 
        }
    }

    //Bottom right corner
    maze_str += "██\n";

    return maze_str;
} 
