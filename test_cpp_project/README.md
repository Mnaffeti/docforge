# Math Library - Test C++ Project

This is a comprehensive C++ mathematics library designed to demonstrate various programming concepts and serve as a test case for documentation generation tools.

## Project Overview

The Math Library provides:
- Basic arithmetic operations (addition, subtraction, multiplication, division)
- Scientific calculator functionality (trigonometric functions, logarithms, power operations)
- Advanced memory management utilities
- Generic data structures (linked lists, binary search trees, hash tables)
- Comprehensive error handling with custom exceptions
- Factory pattern implementation for object creation

## Project Structure

```
test_cpp_project/
├── include/                    # Header files
│   ├── calculator.h           # Calculator classes and interfaces
│   ├── memory_manager.h       # Memory management utilities
│   └── data_structures.h      # Generic data structures
├── src/                       # Source files
│   ├── calculator.cpp         # Calculator implementation
│   └── main.cpp              # Demo application
├── tests/                     # Test files
│   └── test_calculator.cpp    # Unit tests
├── CMakeLists.txt             # Build configuration
└── README.md                  # This file
```

## Features

### Calculator Module
- **BasicCalculator**: Fundamental arithmetic operations with history tracking
- **ScientificCalculator**: Advanced mathematical functions including trigonometry and logarithms
- **CalculatorFactory**: Factory pattern for creating calculator instances
- **Custom Exceptions**: Specialized error handling for mathematical operations

### Memory Management Module
- **Pool**: Template-based memory pool for efficient allocation
- **MemoryTracker**: Singleton for tracking memory usage and detecting leaks
- **SmartArray**: RAII-compliant dynamic array implementation
- **Aligned Memory**: Utilities for aligned memory allocation

### Data Structures Module
- **LinkedList**: Doubly-linked list with iterator support
- **BinarySearchTree**: Self-balancing binary search tree
- **HashTable**: Hash table with linear probing
- **Algorithms**: Generic sorting and searching algorithms

## Building the Project

### Prerequisites
- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.12 or higher
- (Optional) Doxygen for documentation generation

### Build Instructions

```bash
# Create build directory
mkdir build
cd build

# Configure project
cmake ..

# Build the project
cmake --build .

# Run the demo
./calculator_demo

# Run tests
./run_tests
```

### Build Targets

- `mathlib`: Static library
- `mathlib_shared`: Shared/dynamic library
- `calculator_demo`: Demonstration application
- `run_tests`: Unit test executable
- `docs`: Generate Doxygen documentation (if Doxygen is available)
- `cppcheck`: Run static analysis (if cppcheck is available)

## Usage Examples

### Basic Calculator Usage

```cpp
#include "calculator.h"

math::BasicCalculator calc;
double result = calc.add(5.0, 3.0);  // Returns 8.0
calc.subtract(10.0, 4.0);            // Returns 6.0
auto history = calc.getHistory();    // Get calculation history
```

### Scientific Calculator Usage

```cpp
#include "calculator.h"

math::ScientificCalculator sciCalc;
double power = sciCalc.power(2.0, 3.0);           // Returns 8.0
double sqrt_val = sciCalc.sqrt(16.0);             // Returns 4.0
double sin_val = sciCalc.sin(math::constants::PI / 2.0);  // Returns 1.0
```

### Factory Pattern Usage

```cpp
#include "calculator.h"

auto calc = math::CalculatorFactory::createCalculator(math::CalculatorMode::SCIENTIFIC);
auto result = calc->add(5.0, 3.0);
```

### Error Handling

```cpp
#include "calculator.h"

try {
    math::BasicCalculator calc;
    calc.divide(10.0, 0.0);  // Throws DivisionByZeroException
} catch (const math::DivisionByZeroException& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

## Design Patterns Demonstrated

1. **Factory Pattern**: `CalculatorFactory` for creating calculator instances
2. **Template Pattern**: Generic data structures and memory management
3. **RAII**: Automatic resource management in `SmartArray` and memory pools
4. **Singleton Pattern**: `MemoryTracker` for global memory monitoring
5. **Iterator Pattern**: Custom iterators for data structures
6. **Exception Hierarchy**: Specialized exception classes for different error types

## Mathematical Constants

The library provides commonly used mathematical constants:

```cpp
math::constants::PI           // π (pi)
math::constants::E            // e (Euler's number)
math::constants::GOLDEN_RATIO // φ (golden ratio)
math::constants::EPSILON     // Small value for floating-point comparisons
```

## Utility Functions

```cpp
math::utils::isInfinite(value)              // Check if value is infinite
math::utils::isNaN(value)                   // Check if value is NaN
math::utils::roundToPrecision(value, prec)  // Round to specified precision
math::utils::formatNumber(value, prec)      // Format number as string
```

## Testing

The project includes comprehensive unit tests covering:
- Basic arithmetic operations
- Scientific calculator functions
- Error handling and exception safety
- Utility functions
- Mathematical constants
- Factory method functionality

Run tests with:
```bash
./run_tests
```

## Documentation

This project is designed to work with documentation generation tools. The code includes:
- Comprehensive class and function declarations
- Complex inheritance hierarchies
- Template classes and functions
- Namespace organization
- Custom exception classes
- Factory patterns
- Mathematical algorithms

## Contributing

This is a test project for documentation generation tools. When adding new features:

1. Follow the existing code structure and naming conventions
2. Add appropriate header documentation
3. Include unit tests for new functionality
4. Update this README if adding new modules

## License

This test project is provided for educational and demonstration purposes.

## Technical Details

- **Language**: C++17
- **Build System**: CMake
- **Threading**: Thread-safe memory management utilities
- **Exception Safety**: Strong exception safety guarantees
- **Memory Management**: RAII principles throughout
- **Performance**: Optimized algorithms and data structures

This project serves as an excellent test case for C++ documentation generation tools due to its comprehensive use of modern C++ features and design patterns.
