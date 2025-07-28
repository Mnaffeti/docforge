#include "calculator.h"
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>

namespace math {

    // BasicCalculator Implementation
    BasicCalculator::BasicCalculator() 
        : lastResult(0.0), isInitialized(true), currentMode(CalculatorMode::BASIC) {
        calculationHistory.reserve(MAX_HISTORY_SIZE);
    }

    BasicCalculator::BasicCalculator(CalculatorMode mode) 
        : lastResult(0.0), isInitialized(true), currentMode(mode) {
        calculationHistory.reserve(MAX_HISTORY_SIZE);
    }

    BasicCalculator::~BasicCalculator() = default;

    double BasicCalculator::add(double a, double b) {
        validateInput(a);
        validateInput(b);
        
        lastResult = a + b;
        addToHistory(lastResult);
        return lastResult;
    }

    double BasicCalculator::subtract(double a, double b) {
        validateInput(a);
        validateInput(b);
        
        lastResult = a - b;
        addToHistory(lastResult);
        return lastResult;
    }

    double BasicCalculator::multiply(double a, double b) {
        validateInput(a);
        validateInput(b);
        
        lastResult = a * b;
        addToHistory(lastResult);
        return lastResult;
    }

    double BasicCalculator::divide(double a, double b) {
        validateInput(a);
        validateInput(b);
        
        if (std::abs(b) < constants::EPSILON) {
            throw DivisionByZeroException("Cannot divide by zero");
        }
        
        lastResult = a / b;
        addToHistory(lastResult);
        return lastResult;
    }

    void BasicCalculator::reset() {
        lastResult = 0.0;
        clearHistory();
    }

    double BasicCalculator::getLastResult() const {
        return lastResult;
    }

    std::vector<double> BasicCalculator::getHistory() const {
        return calculationHistory;
    }

    void BasicCalculator::clearHistory() {
        calculationHistory.clear();
    }

    void BasicCalculator::setMode(CalculatorMode mode) {
        currentMode = mode;
    }

    CalculatorMode BasicCalculator::getMode() const {
        return currentMode;
    }

    bool BasicCalculator::isValidNumber(double value) const {
        return !utils::isNaN(value) && !utils::isInfinite(value);
    }

    void BasicCalculator::validateInput(double value) {
        if (!isValidNumber(value)) {
            throw InvalidInputException("Invalid number provided", value);
        }
    }

    void BasicCalculator::addToHistory(double result) {
        if (calculationHistory.size() >= MAX_HISTORY_SIZE) {
            calculationHistory.erase(calculationHistory.begin());
        }
        calculationHistory.push_back(result);
    }

    // ScientificCalculator Implementation
    ScientificCalculator::ScientificCalculator() : BasicCalculator(CalculatorMode::SCIENTIFIC), useRadians(true) {
    }

    ScientificCalculator::~ScientificCalculator() = default;

    double ScientificCalculator::power(double base, double exponent) {
        validateInput(base);
        validateInput(exponent);
        
        lastResult = std::pow(base, exponent);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::sqrt(double value) {
        validatePositive(value);
        
        lastResult = std::sqrt(value);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::sin(double angle) {
        validateInput(angle);
        
        double radians = useRadians ? angle : convertToRadians(angle);
        lastResult = std::sin(radians);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::cos(double angle) {
        validateInput(angle);
        
        double radians = useRadians ? angle : convertToRadians(angle);
        lastResult = std::cos(radians);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::tan(double angle) {
        validateInput(angle);
        
        double radians = useRadians ? angle : convertToRadians(angle);
        lastResult = std::tan(radians);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::log(double value) {
        validatePositive(value);
        
        lastResult = std::log10(value);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::ln(double value) {
        validatePositive(value);
        
        lastResult = std::log(value);
        addToHistory(lastResult);
        return lastResult;
    }

    double ScientificCalculator::convertToRadians(double degrees) {
        return degrees * constants::PI / 180.0;
    }

    double ScientificCalculator::convertToDegrees(double radians) {
        return radians * 180.0 / constants::PI;
    }

    void ScientificCalculator::setAngleMode(bool useRadians) {
        this->useRadians = useRadians;
    }

    bool ScientificCalculator::isRadianMode() const {
        return useRadians;
    }

    void ScientificCalculator::validatePositive(double value) {
        validateInput(value);
        if (value < 0) {
            throw InvalidInputException("Value must be positive", value);
        }
    }

    // CalculatorFactory Implementation
    std::unique_ptr<BasicCalculator> CalculatorFactory::createCalculator(CalculatorMode mode) {
        switch (mode) {
            case CalculatorMode::BASIC:
                return std::make_unique<BasicCalculator>(mode);
            case CalculatorMode::SCIENTIFIC:
                return std::make_unique<ScientificCalculator>();
            case CalculatorMode::PROGRAMMER:
                // For this example, we'll return a basic calculator
                return std::make_unique<BasicCalculator>(mode);
            default:
                throw std::invalid_argument("Unknown calculator mode");
        }
    }

    std::unique_ptr<ICalculatorEngine> CalculatorFactory::createEngine(CalculatorMode mode) {
        // Implementation would create specific engine types
        return nullptr; // Placeholder
    }

    bool CalculatorFactory::isValidMode(CalculatorMode mode) {
        return mode == CalculatorMode::BASIC || 
               mode == CalculatorMode::SCIENTIFIC || 
               mode == CalculatorMode::PROGRAMMER;
    }

    // Exception implementations
    CalculatorException::CalculatorException(const std::string& message) 
        : std::runtime_error(message), failedOperation(OperationType::ADD) {
    }

    CalculatorException::CalculatorException(const std::string& message, OperationType operation) 
        : std::runtime_error(message), failedOperation(operation) {
    }

    OperationType CalculatorException::getOperation() const {
        return failedOperation;
    }

    DivisionByZeroException::DivisionByZeroException(const std::string& message) 
        : CalculatorException(message, OperationType::DIVIDE) {
    }

    InvalidInputException::InvalidInputException(const std::string& message, double invalidValue) 
        : CalculatorException(message), value(invalidValue) {
    }

    double InvalidInputException::getInvalidValue() const {
        return value;
    }

    // Utility functions
    namespace utils {
        bool isInfinite(double value) {
            return std::isinf(value);
        }

        bool isNaN(double value) {
            return std::isnan(value);
        }

        double roundToPrecision(double value, int precision) {
            double factor = std::pow(10.0, precision);
            return std::round(value * factor) / factor;
        }

        std::string formatNumber(double value, int precision) {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(precision) << value;
            return oss.str();
        }
    }
}
