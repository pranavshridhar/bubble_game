#include <stdexcept>
#include <string>

class OutOfBoundsException : public std::exception {
private:
    std::string message;

public:
    OutOfBoundsException(int row, int col) {
        message = "Move at row " + std::to_string(row) 
        + ", col " + std::to_string(col) + " is out of bounds.";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};
