#include "Snake.h"
#include <algorithm>

Snake::Snake(const int fieldRows, const int fieldCols, const Point &startPos)
    : _FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos), _snakeNodes({startPos}) {}

Snake::~Snake() {}


std::deque<Point> &Snake::getSnakeNodes() {
    return this->_snakeNodes;
}


StatusCode Snake::move(const Direction dir, const std::vector<Point> &obstacles, std::vector<Point> &powerUps) {
    switch (dir) { // Move the current position
        case Direction::UP: {
            --this->_currPos.row;
            break;
        }
        case Direction::DOWN: {
            ++this->_currPos.row;
            break;
        }
        case Direction::LEFT: {
            --this->_currPos.col;
            break;
        }
        case Direction::RIGHT: {
            ++this->_currPos.col;
            break;
        }
    }

    if (
        this->_currPos.col >= this->_FIELD_COLS || this->_currPos.row >= this->_FIELD_ROWS ||
        this->_currPos.col < 0 || this->_currPos.row < 0
    ) // Out of bounds
        return StatusCode::SNAKE_DEAD;

    for (const Point &obstacle: obstacles)
        if (obstacle.col == this->_currPos.col && obstacle.row == this->_currPos.row) // Hit an obstacle
            return StatusCode::SNAKE_DEAD;

    for (int i = 1; i < this->getSnakeNodes().size(); ++i) // Hit it's body part
        if (this->_currPos.col == this->getSnakeNodes().at(i).col && this->_currPos.row == this->getSnakeNodes().at(i).
            row)
            return StatusCode::SNAKE_DEAD;

    bool hasHitPowerUp = false;

    for (const Point &powerUp: powerUps) { // Search whether a Power up was hit
        if (powerUp.col == this->_currPos.col && powerUp.row == this->_currPos.row) {
            hasHitPowerUp = true;
            break;
        }
    }

    int newRow = this->_snakeNodes.begin()->row;
    int newColumn = this->_snakeNodes.begin()->col;

    switch (dir) { // Move the head
        case Direction::UP: {
            --this->_snakeNodes.begin()->row;
            break;
        }
        case Direction::DOWN: {
            ++this->_snakeNodes.begin()->row;
            break;
        }
        case Direction::LEFT: {
            --this->_snakeNodes.begin()->col;
            break;
        }
        case Direction::RIGHT: {
            ++this->_snakeNodes.begin()->col;
            break;
        }
    }

    for (auto iter = this->_snakeNodes.begin() + 1; iter != this->_snakeNodes.end(); ++iter) { // Move every body part (except the head) with the previous body part location
        const int bufferRow = iter->row;
        const int bufferColumn = iter->col;

        iter->row = newRow;
        iter->col = newColumn;

        newRow = bufferRow;
        newColumn = bufferColumn;
    }

    if (hasHitPowerUp) { // In case of a power up extend the snake at the end, remove the power up from the vector
        this->_snakeNodes.push_back(Point{newRow, newColumn});

        powerUps.erase(
            std::remove_if(powerUps.begin(), powerUps.end(), [&](Point point) {
                return
                        point.col == this->_currPos.col &&
                        point.row == this->_currPos.row;
            })
        );

        return StatusCode::SNAKE_GROWING;
    }

    return StatusCode::SNAKE_MOVING;
}
