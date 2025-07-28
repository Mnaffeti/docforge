#include "calculator.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <limits>

/**
 * @brief TestRunner class
 * 
 * Detailed description of the TestRunner class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * TestRunner obj;
 * // Usage example
 */
/**
 * @brief TestRunner class
 * 
 * Detailed description of the TestRunner class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * TestRunner obj;
 * // Usage example
 */
class TestRunner {
public:
/**
 * @brief runAllTests function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for runAllTests
 */
/**
 * @brief runAllTests function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for runAllTests
 */
    static void runAllTests() {
        std::cout << "Running Calculator Tests...\n";
        std::cout << "=============================\n\n";
        
        testBasicOperations();
        testScientificOperations();
        testErrorHandling();
        testUtilities();
        testConstants();
        testFactoryMethods();
        
        std::cout << "\n=============================\n";
        std::cout << "All tests passed successfully!\n";
    }

private:
/**
 * @brief testBasicOperations function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testBasicOperations
 */
/**
 * @brief testBasicOperations function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testBasicOperations
 */
    static void testBasicOperations() {
        std::cout << "Testing basic operations...\n";
        
        math::BasicCalculator calc;
        
        // Test addition
        double result = calc.add(5.0, 3.0);
        assert(std::abs(result - 8.0) < math::constants::EPSILON);
        assert(std::abs(calc.getLastResult() - 8.0) < math::constants::EPSILON);
        
        // Test subtraction
        result = calc.subtract(10.0, 4.0);
        assert(std::abs(result - 6.0) < math::constants::EPSILON);
        
        // Test multiplication
        result = calc.multiply(6.0, 7.0);
        assert(std::abs(result - 42.0) < math::constants::EPSILON);
        
        // Test division
        result = calc.divide(20.0, 4.0);
        assert(std::abs(result - 5.0) < math::constants::EPSILON);
        
        // Test history
        auto history = calc.getHistory();
        assert(history.size() == 4);
        assert(std::abs(history[0] - 8.0) < math::constants::EPSILON);
        assert(std::abs(history[3] - 5.0) < math::constants::EPSILON);
        
        // Test reset
        calc.reset();
        assert(std::abs(calc.getLastResult()) < math::constants::EPSILON);
        assert(calc.getHistory().empty());
        
        // Test mode
        calc.setMode(math::CalculatorMode::SCIENTIFIC);
        assert(calc.getMode() == math::CalculatorMode::SCIENTIFIC);
        
        std::cout << "  ✓ Basic operations tests passed\n";
    }
    
/**
 * @brief testScientificOperations function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testScientificOperations
 */
/**
 * @brief testScientificOperations function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testScientificOperations
 */
    static void testScientificOperations() {
        std::cout << "Testing scientific operations...\n";
        
        math::ScientificCalculator sciCalc;
        
        // Test power
        double result = sciCalc.power(2.0, 3.0);
        assert(std::abs(result - 8.0) < math::constants::EPSILON);
        
        // Test square root
        result = sciCalc.sqrt(16.0);
        assert(std::abs(result - 4.0) < math::constants::EPSILON);
        
        // Test trigonometric functions
        result = sciCalc.sin(math::constants::PI / 2.0);
        assert(std::abs(result - 1.0) < 1e-10);
        
        result = sciCalc.cos(0.0);
        assert(std::abs(result - 1.0) < math::constants::EPSILON);
        
        result = sciCalc.tan(math::constants::PI / 4.0);
        assert(std::abs(result - 1.0) < 1e-10);
        
        // Test logarithmic functions
        result = sciCalc.log(100.0);
        assert(std::abs(result - 2.0) < math::constants::EPSILON);
        
        result = sciCalc.ln(math::constants::E);
        assert(std::abs(result - 1.0) < math::constants::EPSILON);
        
        // Test angle conversion
        result = sciCalc.convertToRadians(180.0);
        assert(std::abs(result - math::constants::PI) < math::constants::EPSILON);
        
        result = sciCalc.convertToDegrees(math::constants::PI);
        assert(std::abs(result - 180.0) < math::constants::EPSILON);
        
        // Test angle mode
        sciCalc.setAngleMode(false);  // Use degrees
        assert(!sciCalc.isRadianMode());
        
        result = sciCalc.sin(90.0);  // 90 degrees = π/2 radians
        assert(std::abs(result - 1.0) < 1e-10);
        
        std::cout << "  ✓ Scientific operations tests passed\n";
    }
    
/**
 * @brief testErrorHandling function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testErrorHandling
 */
/**
 * @brief testErrorHandling function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testErrorHandling
 */
    static void testErrorHandling() {
        std::cout << "Testing error handling...\n";
        
        math::BasicCalculator calc;
        
        // Test division by zero
        bool exceptionCaught = false;
        try {
            calc.divide(10.0, 0.0);
        } catch (const math::DivisionByZeroException& e) {
            exceptionCaught = true;
            assert(e.getOperation() == math::OperationType::DIVIDE);
        }
        assert(exceptionCaught);
        
        // Test invalid input (NaN)
        exceptionCaught = false;
        try {
            double nan = std::numeric_limits<double>::quiet_NaN();
            calc.add(5.0, nan);
        } catch (const math::InvalidInputException& e) {
            exceptionCaught = true;
            assert(std::isnan(e.getInvalidValue()));
        }
        assert(exceptionCaught);
        
        // Test scientific calculator negative square root
        math::ScientificCalculator sciCalc;
        exceptionCaught = false;
        try {
            sciCalc.sqrt(-1.0);
        } catch (const math::InvalidInputException& e) {
            exceptionCaught = true;
            assert(e.getInvalidValue() == -1.0);
        }
        assert(exceptionCaught);
        
        // Test negative logarithm
        exceptionCaught = false;
        try {
            sciCalc.log(-1.0);
        } catch (const math::InvalidInputException& e) {
            exceptionCaught = true;
        }
        assert(exceptionCaught);
        
        std::cout << "  ✓ Error handling tests passed\n";
    }
    
/**
 * @brief testUtilities function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testUtilities
 */
/**
 * @brief testUtilities function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testUtilities
 */
    static void testUtilities() {
        std::cout << "Testing utility functions...\n";
        
        // Test number validation
        assert(!math::utils::isNaN(5.0));
        assert(math::utils::isNaN(std::numeric_limits<double>::quiet_NaN()));
        
        assert(!math::utils::isInfinite(5.0));
        assert(math::utils::isInfinite(std::numeric_limits<double>::infinity()));
        
        // Test rounding
        double result = math::utils::roundToPrecision(3.14159, 2);
        assert(std::abs(result - 3.14) < math::constants::EPSILON);
        
        // Test formatting
        std::string formatted = math::utils::formatNumber(3.14159, 3);
        assert(formatted == "3.142");
        
        std::cout << "  ✓ Utility function tests passed\n";
    }
    
/**
 * @brief testConstants function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testConstants
 */
/**
 * @brief testConstants function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testConstants
 */
    static void testConstants() {
        std::cout << "Testing mathematical constants...\n";
        
/**
 * @brief assert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return constants Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for assert
 */
/**
 * @brief assert function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return constants Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for assert
 */
        // Basic sanity checks for constants
        assert(math::constants::PI > 3.14 && math::constants::PI < 3.15);
        assert(math::constants::E > 2.71 && math::constants::E < 2.72);
        assert(math::constants::GOLDEN_RATIO > 1.61 && math::constants::GOLDEN_RATIO < 1.62);
        assert(math::constants::EPSILON > 0 && math::constants::EPSILON < 1e-9);
        
        std::cout << "  ✓ Constants tests passed\n";
    }
    
/**
 * @brief testFactoryMethods function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testFactoryMethods
 */
/**
 * @brief testFactoryMethods function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for testFactoryMethods
 */
    static void testFactoryMethods() {
        std::cout << "Testing factory methods...\n";
        
        // Test basic calculator creation
        auto basicCalc = math::CalculatorFactory::createCalculator(math::CalculatorMode::BASIC);
        assert(basicCalc != nullptr);
        assert(basicCalc->getMode() == math::CalculatorMode::BASIC);
        
        // Test scientific calculator creation
        auto sciCalc = math::CalculatorFactory::createCalculator(math::CalculatorMode::SCIENTIFIC);
        assert(sciCalc != nullptr);
        assert(sciCalc->getMode() == math::CalculatorMode::SCIENTIFIC);
        
        // Verify it's actually a scientific calculator
        auto* scientificCalc = dynamic_cast<math::ScientificCalculator*>(sciCalc.get());
        assert(scientificCalc != nullptr);
        
        // Test mode validation
        assert(math::CalculatorFactory::isValidMode(math::CalculatorMode::BASIC));
        assert(math::CalculatorFactory::isValidMode(math::CalculatorMode::SCIENTIFIC));
        assert(math::CalculatorFactory::isValidMode(math::CalculatorMode::PROGRAMMER));
        
        std::cout << "  ✓ Factory method tests passed\n";
    }
};

/**
 * @brief main function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for main
 */
/**
 * @brief main function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return int Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for main
 */
int main() {
    try {
        TestRunner::runAllTests();
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Test failed with unknown exception" << std::endl;
        return 1;
    }
}
