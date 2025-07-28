#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <vector>
#include <memory>

namespace math {

    enum class OperationType {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        POWER,
        SQRT
    };

    enum class CalculatorMode {
        BASIC,
        SCIENTIFIC,
        PROGRAMMER
    };

    struct CalculationResult {
        double value;
        bool isValid;
        OperationType operation;
        std::string errorMessage;
    };

    class ICalculatorEngine {
    public:
        virtual ~ICalculatorEngine() = default;
        virtual double calculate(double a, double b, OperationType op) = 0;
        virtual bool supportsOperation(OperationType op) const = 0;
    };

    class BasicCalculator {
    public:
        BasicCalculator();
        explicit BasicCalculator(CalculatorMode mode);
        virtual ~BasicCalculator();

        double add(double a, double b);
        double subtract(double a, double b);
        double multiply(double a, double b);
        double divide(double a, double b);

        void reset();
        double getLastResult() const;
        std::vector<double> getHistory() const;
        void clearHistory();

        void setMode(CalculatorMode mode);
        CalculatorMode getMode() const;

        bool isValidNumber(double value) const;

    protected:
        virtual void validateInput(double value);
        void addToHistory(double result);

    private:
        double lastResult;
        bool isInitialized;
        CalculatorMode currentMode;
        std::vector<double> calculationHistory;
        static const int MAX_HISTORY_SIZE = 100;
    };

    class ScientificCalculator : public BasicCalculator {
    public:
        ScientificCalculator();
        ~ScientificCalculator() override;

        double power(double base, double exponent);
        double sqrt(double value);
        double sin(double angle);
        double cos(double angle);
        double tan(double angle);
        double log(double value);
        double ln(double value);

        double convertToRadians(double degrees);
        double convertToDegrees(double radians);

        void setAngleMode(bool useRadians);
        bool isRadianMode() const;

    private:
        bool useRadians;
        void validatePositive(double value);
    };

    class CalculatorFactory {
    public:
        static std::unique_ptr<BasicCalculator> createCalculator(CalculatorMode mode);
        static std::unique_ptr<ICalculatorEngine> createEngine(CalculatorMode mode);
        static bool isValidMode(CalculatorMode mode);

    private:
        CalculatorFactory() = default;
    };

    class CalculatorException : public std::runtime_error {
    public:
        explicit CalculatorException(const std::string& message);
        explicit CalculatorException(const std::string& message, OperationType operation);

        OperationType getOperation() const;

    private:
        OperationType failedOperation;
    };

    class DivisionByZeroException : public CalculatorException {
    public:
        explicit DivisionByZeroException(const std::string& message = "Division by zero");
    };

    class InvalidInputException : public CalculatorException {
    public:
        explicit InvalidInputException(const std::string& message, double invalidValue);
        double getInvalidValue() const;

    private:
        double value;
    };

    namespace constants {
        constexpr double PI = 3.14159265358979323846;
        constexpr double E = 2.71828182845904523536;
        constexpr double GOLDEN_RATIO = 1.61803398874989484820;
        constexpr double EPSILON = 1e-10;
    }

    namespace utils {
        bool isInfinite(double value);
        bool isNaN(double value);
        double roundToPrecision(double value, int precision);
        std::string formatNumber(double value, int precision = 6);
    }
}

#endif // CALCULATOR_H
