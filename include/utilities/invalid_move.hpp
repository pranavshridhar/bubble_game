#include <stdexcept>
#include <string>

class InvalidMoveException : public std::exception {
private:
    std::string message;

public:
    InvalidMoveException(int row, int col) {
        message = "Move at row " + std::to_string(row)
        + ", col " + std::to_string(col) + " is an illegal move.";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};
