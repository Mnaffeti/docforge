#include "calculator.h"
#include <iostream>
#include <iomanip>
#include <vector>

/**
 * @brief printBanner function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for printBanner
 */
/**
 * @brief printBanner function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for printBanner
 */
void printBanner() {
    std::cout << "====================================\n";
    std::cout << "    Math Library Demo Program      \n";
    std::cout << "====================================\n\n";
}

/**
 * @brief demonstrateBasicCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateBasicCalculator
 */
/**
 * @brief demonstrateBasicCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateBasicCalculator
 */
void demonstrateBasicCalculator() {
    std::cout << "=== Basic Calculator Demo ===\n";
    
    math::BasicCalculator calc;
    
    try {
        std::cout << "5.0 + 3.0 = " << calc.add(5.0, 3.0) << std::endl;
        std::cout << "10.0 - 4.0 = " << calc.subtract(10.0, 4.0) << std::endl;
        std::cout << "6.0 * 7.0 = " << calc.multiply(6.0, 7.0) << std::endl;
        std::cout << "20.0 / 4.0 = " << calc.divide(20.0, 4.0) << std::endl;
        
        std::cout << "\nLast result: " << calc.getLastResult() << std::endl;
        
        auto history = calc.getHistory();
        std::cout << "Calculation history (" << history.size() << " items):\n";
        for (size_t i = 0; i < history.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << std::fixed << std::setprecision(2) 
                      << history[i] << std::endl;
        }
        
    } catch (const math::CalculatorException& e) {
        std::cerr << "Calculator error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

/**
 * @brief demonstrateScientificCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateScientificCalculator
 */
/**
 * @brief demonstrateScientificCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateScientificCalculator
 */
void demonstrateScientificCalculator() {
    std::cout << "=== Scientific Calculator Demo ===\n";
    
    math::ScientificCalculator sciCalc;
    
    try {
        std::cout << std::fixed << std::setprecision(6);
        
        std::cout << "2^3 = " << sciCalc.power(2.0, 3.0) << std::endl;
        std::cout << "sqrt(16) = " << sciCalc.sqrt(16.0) << std::endl;
        
        // Trigonometric functions (in radians)
        std::cout << "sin(π/2) = " << sciCalc.sin(math::constants::PI / 2.0) << std::endl;
        std::cout << "cos(0) = " << sciCalc.cos(0.0) << std::endl;
        std::cout << "tan(π/4) = " << sciCalc.tan(math::constants::PI / 4.0) << std::endl;
        
        // Logarithmic functions
        std::cout << "log10(100) = " << sciCalc.log(100.0) << std::endl;
        std::cout << "ln(e) = " << sciCalc.ln(math::constants::E) << std::endl;
        
        // Angle conversion
        std::cout << "90 degrees = " << sciCalc.convertToRadians(90.0) << " radians" << std::endl;
        std::cout << "π radians = " << sciCalc.convertToDegrees(math::constants::PI) << " degrees" << std::endl;
        
    } catch (const math::CalculatorException& e) {
        std::cerr << "Scientific calculator error: " << e.what() << std::endl;
    }
    
    std::cout << std::endl;
}

/**
 * @brief demonstrateConstants function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateConstants
 */
/**
 * @brief demonstrateConstants function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateConstants
 */
void demonstrateConstants() {
    std::cout << "=== Mathematical Constants ===\n";
    
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "π (PI) = " << math::constants::PI << std::endl;
    std::cout << "e (Euler's number) = " << math::constants::E << std::endl;
    std::cout << "φ (Golden ratio) = " << math::constants::GOLDEN_RATIO << std::endl;
    std::cout << "ε (Epsilon) = " << math::constants::EPSILON << std::endl;
    
    std::cout << std::endl;
}

/**
 * @brief demonstrateUtilities function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateUtilities
 */
/**
 * @brief demonstrateUtilities function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateUtilities
 */
void demonstrateUtilities() {
    std::cout << "=== Utility Functions Demo ===\n";
    
    double testValue = 123.456789;
    
    std::cout << "Original value: " << testValue << std::endl;
    std::cout << "Rounded to 2 decimals: " << math::utils::roundToPrecision(testValue, 2) << std::endl;
    std::cout << "Formatted (4 decimals): " << math::utils::formatNumber(testValue, 4) << std::endl;
    
    // Test special values
    double inf = std::numeric_limits<double>::infinity();
    double nan = std::numeric_limits<double>::quiet_NaN();
    
    std::cout << "Is infinity infinite? " << (math::utils::isInfinite(inf) ? "Yes" : "No") << std::endl;
    std::cout << "Is NaN a number? " << (math::utils::isNaN(nan) ? "No" : "Yes") << std::endl;
    
    std::cout << std::endl;
}

/**
 * @brief demonstrateErrorHandling function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateErrorHandling
 */
/**
 * @brief demonstrateErrorHandling function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateErrorHandling
 */
void demonstrateErrorHandling() {
    std::cout << "=== Error Handling Demo ===\n";
    
    math::BasicCalculator calc;
    
    // Division by zero
    try {
        std::cout << "Attempting division by zero...\n";
        calc.divide(10.0, 0.0);
    } catch (const math::DivisionByZeroException& e) {
        std::cout << "Caught DivisionByZeroException: " << e.what() << std::endl;
    }
    
    // Invalid input
    try {
        std::cout << "Attempting calculation with NaN...\n";
        double nan = std::numeric_limits<double>::quiet_NaN();
        calc.add(5.0, nan);
    } catch (const math::InvalidInputException& e) {
        std::cout << "Caught InvalidInputException: " << e.what() << std::endl;
        std::cout << "Invalid value was: " << e.getInvalidValue() << std::endl;
    }
    
    std::cout << std::endl;
}

/**
 * @brief demonstrateFactory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateFactory
 */
/**
 * @brief demonstrateFactory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for demonstrateFactory
 */
void demonstrateFactory() {
    std::cout << "=== Factory Pattern Demo ===\n";
    
    // Create different calculator types using factory
    auto basicCalc = math::CalculatorFactory::createCalculator(math::CalculatorMode::BASIC);
    auto sciCalc = math::CalculatorFactory::createCalculator(math::CalculatorMode::SCIENTIFIC);
    
    std::cout << "Basic calculator result: " << basicCalc->add(5.0, 3.0) << std::endl;
    
    // Dynamic cast to access scientific functions
    auto* scientificCalc = dynamic_cast<math::ScientificCalculator*>(sciCalc.get());
    if (scientificCalc) {
        std::cout << "Scientific calculator power result: " << scientificCalc->power(2.0, 3.0) << std::endl;
    }
    
    // Test mode validation
    std::cout << "Is BASIC mode valid? " << 
        (math::CalculatorFactory::isValidMode(math::CalculatorMode::BASIC) ? "Yes" : "No") << std::endl;
    
    std::cout << std::endl;
}

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
    printBanner();
    
    try {
        demonstrateBasicCalculator();
        demonstrateScientificCalculator();
        demonstrateConstants();
        demonstrateUtilities();
        demonstrateErrorHandling();
        demonstrateFactory();
        
        std::cout << "=== Demo completed successfully! ===\n";
        
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
