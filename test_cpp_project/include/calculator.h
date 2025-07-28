#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>
#include <vector>
#include <memory>

/**
 * @brief math namespace
 * 
 * Contains classes and functions related to math functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
/**
 * @brief math namespace
 * 
 * Contains classes and functions related to math functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
namespace math {

/**
 * @brief OperationType enum
 * 
 * Detailed description of the OperationType enum.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief OperationType class
 * 
 * Detailed description of the OperationType class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * OperationType obj;
 * // Usage example
 */
/**
 * @brief OperationType enum
 * 
 * Detailed description of the OperationType enum.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief OperationType class
 * 
 * Detailed description of the OperationType class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * OperationType obj;
 * // Usage example
 */
    enum class OperationType {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        POWER,
        SQRT
    };

/**
 * @brief CalculatorMode enum
 * 
 * Detailed description of the CalculatorMode enum.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief CalculatorMode class
 * 
 * Detailed description of the CalculatorMode class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorMode obj;
 * // Usage example
 */
/**
 * @brief CalculatorMode enum
 * 
 * Detailed description of the CalculatorMode enum.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief CalculatorMode class
 * 
 * Detailed description of the CalculatorMode class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorMode obj;
 * // Usage example
 */
    enum class CalculatorMode {
        BASIC,
        SCIENTIFIC,
        PROGRAMMER
    };

/**
 * @brief CalculationResult struct
 * 
 * Detailed description of the CalculationResult struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
/**
 * @brief CalculationResult struct
 * 
 * Detailed description of the CalculationResult struct.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */
    struct CalculationResult {
        double value;
        bool isValid;
        OperationType operation;
        std::string errorMessage;
    };

/**
 * @brief ICalculatorEngine class
 * 
 * Detailed description of the ICalculatorEngine class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * ICalculatorEngine obj;
 * // Usage example
 */
/**
 * @brief ICalculatorEngine class
 * 
 * Detailed description of the ICalculatorEngine class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * ICalculatorEngine obj;
 * // Usage example
 */
    class ICalculatorEngine {
    public:
        virtual ~ICalculatorEngine() = default;
        virtual double calculate(double a, double b, OperationType op) = 0;
        virtual bool supportsOperation(OperationType op) const = 0;
    };

/**
 * @brief BasicCalculator class
 * 
 * Detailed description of the BasicCalculator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * BasicCalculator obj;
 * // Usage example
 */
/**
 * @brief BasicCalculator class
 * 
 * Detailed description of the BasicCalculator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * BasicCalculator obj;
 * // Usage example
 */
    class BasicCalculator {
    public:
        BasicCalculator();
/**
 * @brief BasicCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for BasicCalculator
 */
/**
 * @brief BasicCalculator function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for BasicCalculator
 */
        explicit BasicCalculator(CalculatorMode mode);
        virtual ~BasicCalculator();

/**
 * @brief add function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for add
 */
/**
 * @brief add function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for add
 */
        double add(double a, double b);
/**
 * @brief subtract function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for subtract
 */
/**
 * @brief subtract function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for subtract
 */
        double subtract(double a, double b);
/**
 * @brief multiply function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for multiply
 */
/**
 * @brief multiply function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for multiply
 */
        double multiply(double a, double b);
/**
 * @brief divide function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for divide
 */
/**
 * @brief divide function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for divide
 */
        double divide(double a, double b);

/**
 * @brief reset function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for reset
 */
/**
 * @brief reset function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for reset
 */
        void reset();
/**
 * @brief getLastResult function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getLastResult
 */
/**
 * @brief getLastResult function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getLastResult
 */
        double getLastResult() const;
        std::vector<double> getHistory() const;
/**
 * @brief clearHistory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clearHistory
 */
/**
 * @brief clearHistory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for clearHistory
 */
        void clearHistory();

/**
 * @brief setMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for setMode
 */
/**
 * @brief setMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for setMode
 */
        void setMode(CalculatorMode mode);
/**
 * @brief getMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return CalculatorMode Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getMode
 */
/**
 * @brief getMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return CalculatorMode Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getMode
 */
        CalculatorMode getMode() const;

/**
 * @brief isValidNumber function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isValidNumber
 */
/**
 * @brief isValidNumber function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isValidNumber
 */
        bool isValidNumber(double value) const;

    protected:
/**
 * @brief validateInput function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for validateInput
 */
/**
 * @brief validateInput function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for validateInput
 */
        virtual void validateInput(double value);
/**
 * @brief addToHistory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for addToHistory
 */
/**
 * @brief addToHistory function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for addToHistory
 */
        void addToHistory(double result);

    private:
        double lastResult;
        bool isInitialized;
        CalculatorMode currentMode;
        std::vector<double> calculationHistory;
        static const int MAX_HISTORY_SIZE = 100;
    };

/**
 * @brief ScientificCalculator class
 * 
 * Detailed description of the ScientificCalculator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * ScientificCalculator obj;
 * // Usage example
 */
/**
 * @brief ScientificCalculator class
 * 
 * Detailed description of the ScientificCalculator class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * ScientificCalculator obj;
 * // Usage example
 */
    class ScientificCalculator : public BasicCalculator {
    public:
        ScientificCalculator();
        ~ScientificCalculator() override;

/**
 * @brief power function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for power
 */
/**
 * @brief power function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for power
 */
        double power(double base, double exponent);
/**
 * @brief sqrt function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for sqrt
 */
/**
 * @brief sqrt function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for sqrt
 */
        double sqrt(double value);
/**
 * @brief sin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for sin
 */
/**
 * @brief sin function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for sin
 */
        double sin(double angle);
/**
 * @brief cos function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for cos
 */
/**
 * @brief cos function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for cos
 */
        double cos(double angle);
/**
 * @brief tan function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for tan
 */
/**
 * @brief tan function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for tan
 */
        double tan(double angle);
/**
 * @brief log function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for log
 */
/**
 * @brief log function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for log
 */
        double log(double value);
/**
 * @brief ln function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for ln
 */
/**
 * @brief ln function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for ln
 */
        double ln(double value);

/**
 * @brief convertToRadians function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for convertToRadians
 */
/**
 * @brief convertToRadians function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for convertToRadians
 */
        double convertToRadians(double degrees);
/**
 * @brief convertToDegrees function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for convertToDegrees
 */
/**
 * @brief convertToDegrees function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for convertToDegrees
 */
        double convertToDegrees(double radians);

/**
 * @brief setAngleMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for setAngleMode
 */
/**
 * @brief setAngleMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for setAngleMode
 */
        void setAngleMode(bool useRadians);
/**
 * @brief isRadianMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isRadianMode
 */
/**
 * @brief isRadianMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isRadianMode
 */
        bool isRadianMode() const;

    private:
        bool useRadians;
/**
 * @brief validatePositive function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for validatePositive
 */
/**
 * @brief validatePositive function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for validatePositive
 */
        void validatePositive(double value);
    };

/**
 * @brief CalculatorFactory class
 * 
 * Detailed description of the CalculatorFactory class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorFactory obj;
 * // Usage example
 */
/**
 * @brief CalculatorFactory class
 * 
 * Detailed description of the CalculatorFactory class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorFactory obj;
 * // Usage example
 */
    class CalculatorFactory {
    public:
        static std::unique_ptr<BasicCalculator> createCalculator(CalculatorMode mode);
        static std::unique_ptr<ICalculatorEngine> createEngine(CalculatorMode mode);
/**
 * @brief isValidMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isValidMode
 */
/**
 * @brief isValidMode function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isValidMode
 */
        static bool isValidMode(CalculatorMode mode);

    private:
        CalculatorFactory() = default;
    };

/**
 * @brief CalculatorException class
 * 
 * Detailed description of the CalculatorException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorException obj;
 * // Usage example
 */
/**
 * @brief CalculatorException class
 * 
 * Detailed description of the CalculatorException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * CalculatorException obj;
 * // Usage example
 */
    class CalculatorException : public std::runtime_error {
    public:
/**
 * @brief CalculatorException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for CalculatorException
 */
/**
 * @brief CalculatorException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for CalculatorException
 */
        explicit CalculatorException(const std::string& message);
/**
 * @brief CalculatorException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for CalculatorException
 */
/**
 * @brief CalculatorException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for CalculatorException
 */
        explicit CalculatorException(const std::string& message, OperationType operation);

/**
 * @brief getOperation function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return OperationType Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getOperation
 */
/**
 * @brief getOperation function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return OperationType Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getOperation
 */
        OperationType getOperation() const;

    private:
        OperationType failedOperation;
    };

/**
 * @brief DivisionByZeroException class
 * 
 * Detailed description of the DivisionByZeroException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * DivisionByZeroException obj;
 * // Usage example
 */
/**
 * @brief DivisionByZeroException class
 * 
 * Detailed description of the DivisionByZeroException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * DivisionByZeroException obj;
 * // Usage example
 */
    class DivisionByZeroException : public CalculatorException {
    public:
/**
 * @brief DivisionByZeroException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for DivisionByZeroException
 */
/**
 * @brief DivisionByZeroException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for DivisionByZeroException
 */
        explicit DivisionByZeroException(const std::string& message = "Division by zero");
    };

/**
 * @brief InvalidInputException class
 * 
 * Detailed description of the InvalidInputException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * InvalidInputException obj;
 * // Usage example
 */
/**
 * @brief InvalidInputException class
 * 
 * Detailed description of the InvalidInputException class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * InvalidInputException obj;
 * // Usage example
 */
    class InvalidInputException : public CalculatorException {
    public:
/**
 * @brief InvalidInputException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for InvalidInputException
 */
/**
 * @brief InvalidInputException function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return explicit Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for InvalidInputException
 */
        explicit InvalidInputException(const std::string& message, double invalidValue);
/**
 * @brief getInvalidValue function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getInvalidValue
 */
/**
 * @brief getInvalidValue function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for getInvalidValue
 */
        double getInvalidValue() const;

    private:
        double value;
    };

/**
 * @brief constants namespace
 * 
 * Contains classes and functions related to constants functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
/**
 * @brief constants namespace
 * 
 * Contains classes and functions related to constants functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
    namespace constants {
        constexpr double PI = 3.14159265358979323846;
        constexpr double E = 2.71828182845904523536;
        constexpr double GOLDEN_RATIO = 1.61803398874989484820;
        constexpr double EPSILON = 1e-10;
    }

/**
 * @brief utils namespace
 * 
 * Contains classes and functions related to utils functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
/**
 * @brief utils namespace
 * 
 * Contains classes and functions related to utils functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */
    namespace utils {
/**
 * @brief isInfinite function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isInfinite
 */
/**
 * @brief isInfinite function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isInfinite
 */
        bool isInfinite(double value);
/**
 * @brief isNaN function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isNaN
 */
/**
 * @brief isNaN function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return bool Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for isNaN
 */
        bool isNaN(double value);
/**
 * @brief roundToPrecision function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for roundToPrecision
 */
/**
 * @brief roundToPrecision function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return double Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for roundToPrecision
 */
        double roundToPrecision(double value, int precision);
/**
 * @brief formatNumber function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return string Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for formatNumber
 */
/**
 * @brief formatNumber function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * 
 * @param param_name Description of parameter
 * 
 * @return string Description of return value
 * 
 * @throws std::exception Description of when exceptions are thrown
 * 
 * @example
 * // Usage example for formatNumber
 */
        std::string formatNumber(double value, int precision = 6);
    }
}

#endif // CALCULATOR_H
