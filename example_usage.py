#!/usr/bin/env python3
"""
Example usage script for the C++ Documentation Generator

This script demonstrates how to use the documentation generator
with different configurations and options.
"""

import os
import sys
from pathlib import Path

# Add the current directory to Python path so we can import our module
sys.path.insert(0, str(Path(__file__).parent))

from cpp_doc_generator import CppDocumentationAgent, CppProjectAnalyzer

def example_basic_usage():
    """Example: Basic documentation generation without Gemini"""
    print("=== Basic Usage Example ===")
    
    # Example project path (replace with actual project path)
    project_path = r"C:\path\to\your\cpp\project"
    
    # Check if the project path exists (for demo purposes)
    if not Path(project_path).exists():
        print(f"Note: Project path '{project_path}' does not exist.")
        print("Replace with an actual C++ project path to test.")
        return
    
    # Create documentation agent
    agent = CppDocumentationAgent(
        project_path=project_path,
        output_dir="./generated_docs",
        use_gemini=False  # Use template-based comment generation
    )
    
    # Generate documentation
    try:
        agent.generate_documentation()
        print("Documentation generated successfully!")
    except Exception as e:
        print(f"Error: {e}")

def example_with_gemini():
    """Example: Documentation generation with Gemini integration"""
    print("=== Gemini Integration Example ===")
    
    # Example project path
    project_path = r"C:\path\to\your\cpp\project"
    
    # Gemini API key (get from environment variable for security)
    api_key = os.getenv('GEMINI_API_KEY')
    
    if not api_key:
        print("Gemini API key not found in environment variable 'GEMINI_API_KEY'")
        print("Set it with: set GEMINI_API_KEY=your_api_key_here")
        return
    
    if not Path(project_path).exists():
        print(f"Note: Project path '{project_path}' does not exist.")
        print("Replace with an actual C++ project path to test.")
        return
    
    # Create documentation agent with Gemini
    agent = CppDocumentationAgent(
        project_path=project_path,
        output_dir="./ai_generated_docs",
        use_gemini=True,
        api_key=api_key
    )
    
    print("Note: Using Gemini free tier model (gemini-1.5-flash-8b)")
    print("Free tier has daily quotas. If exceeded, will fall back to templates.")
    
    # Generate documentation
    try:
        agent.generate_documentation()
        print("AI-enhanced documentation generated successfully!")
    except Exception as e:
        print(f"Error: {e}")

def example_project_analysis_only():
    """Example: Only analyze project structure without generating docs"""
    print("=== Project Analysis Only Example ===")
    
    project_path = r"C:\path\to\your\cpp\project"
    
    if not Path(project_path).exists():
        print(f"Note: Project path '{project_path}' does not exist.")
        print("Replace with an actual C++ project path to test.")
        return
    
    # Create analyzer
    analyzer = CppProjectAnalyzer(project_path)
    
    # Analyze project
    try:
        project_structure = analyzer.analyze_project()
        
        # Print analysis results
        print(f"Project Name: {project_structure.project_name}")
        print(f"Header Files: {len(project_structure.header_files)}")
        print(f"Source Files: {len(project_structure.source_files)}")
        print(f"Classes Found: {len([e for e in project_structure.code_elements if e.type == 'class'])}")
        print(f"Functions Found: {len([e for e in project_structure.code_elements if e.type == 'function'])}")
        print(f"Namespaces: {', '.join(project_structure.namespaces) if project_structure.namespaces else 'None'}")
        print(f"Dependencies: {', '.join(project_structure.dependencies) if project_structure.dependencies else 'None'}")
        
    except Exception as e:
        print(f"Error during analysis: {e}")

def example_sample_project():
    """Example: Create and document a sample C++ project"""
    print("=== Sample Project Example ===")
    
    # Create a sample C++ project for demonstration
    sample_dir = Path("./sample_cpp_project")
    sample_dir.mkdir(exist_ok=True)
    
    # Create sample header file
    header_content = '''#ifndef CALCULATOR_H
#define CALCULATOR_H

namespace math {
    
    class Calculator {
    public:
        Calculator();
        ~Calculator();
        
        double add(double a, double b);
        double subtract(double a, double b);
        double multiply(double a, double b);
        double divide(double a, double b);
        
        void reset();
        double getLastResult() const;
        
    private:
        double lastResult;
        bool isInitialized;
    };
    
    enum OperationType {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE
    };
    
    struct CalculationResult {
        double value;
        bool isValid;
        OperationType operation;
    };
}

#endif // CALCULATOR_H
'''
    
    with open(sample_dir / "calculator.h", 'w') as f:
        f.write(header_content)
    
    # Create sample source file
    source_content = '''#include "calculator.h"
#include <stdexcept>

namespace math {
    
    Calculator::Calculator() : lastResult(0.0), isInitialized(true) {
    }
    
    Calculator::~Calculator() {
    }
    
    double Calculator::add(double a, double b) {
        lastResult = a + b;
        return lastResult;
    }
    
    double Calculator::subtract(double a, double b) {
        lastResult = a - b;
        return lastResult;
    }
    
    double Calculator::multiply(double a, double b) {
        lastResult = a * b;
        return lastResult;
    }
    
    double Calculator::divide(double a, double b) {
        if (b == 0.0) {
            throw std::runtime_error("Division by zero");
        }
        lastResult = a / b;
        return lastResult;
    }
    
    void Calculator::reset() {
        lastResult = 0.0;
    }
    
    double Calculator::getLastResult() const {
        return lastResult;
    }
}
'''
    
    with open(sample_dir / "calculator.cpp", 'w') as f:
        f.write(source_content)
    
    # Create sample CMakeLists.txt
    cmake_content = '''cmake_minimum_required(VERSION 3.10)
project(CalculatorDemo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(calculator calculator.cpp calculator.h)

# Example executable
add_executable(demo main.cpp)
target_link_libraries(demo calculator)

# Install targets
install(TARGETS calculator DESTINATION lib)
install(FILES calculator.h DESTINATION include)
'''
    
    with open(sample_dir / "CMakeLists.txt", 'w') as f:
        f.write(cmake_content)
    
    # Create sample main.cpp
    main_content = '''#include "calculator.h"
#include <iostream>

int main() {
    math::Calculator calc;
    
    std::cout << "Calculator Demo" << std::endl;
    std::cout << "5 + 3 = " << calc.add(5.0, 3.0) << std::endl;
    std::cout << "10 - 4 = " << calc.subtract(10.0, 4.0) << std::endl;
    std::cout << "6 * 7 = " << calc.multiply(6.0, 7.0) << std::endl;
    std::cout << "20 / 4 = " << calc.divide(20.0, 4.0) << std::endl;
    
    return 0;
}
'''
    
    with open(sample_dir / "main.cpp", 'w') as f:
        f.write(main_content)
    
    print(f"Sample C++ project created in: {sample_dir}")
    print("Now generating documentation for the sample project...")
    
    # Generate documentation for the sample project
    agent = CppDocumentationAgent(
        project_path=str(sample_dir),
        output_dir="./sample_documentation",
        use_gemini=False
    )
    
    try:
        agent.generate_documentation()
        print("Sample project documentation generated successfully!")
        print("Check the './sample_documentation' folder for results.")
    except Exception as e:
        print(f"Error generating documentation: {e}")

def print_usage_instructions():
    """Print detailed usage instructions"""
    print("""
C++ Documentation Generator - Usage Instructions
===============================================

This tool analyzes C++ projects and generates comprehensive documentation
including Doxygen comments and Sphinx HTML documentation.

Command Line Usage:
------------------

Basic usage (template-based comments):
    python cpp_doc_generator.py /path/to/cpp/project

With custom output directory:
    python cpp_doc_generator.py /path/to/cpp/project -o /path/to/output

With Gemini integration (requires API key):
    python cpp_doc_generator.py /path/to/cpp/project --gemini --api-key YOUR_API_KEY

Verbose output:
    python cpp_doc_generator.py /path/to/cpp/project -v

Python API Usage:
----------------

    from cpp_doc_generator import CppDocumentationAgent
    
    agent = CppDocumentationAgent(
        project_path="/path/to/cpp/project",
        output_dir="./docs",
        use_gemini=True,
        api_key="your-gemini-api-key"
    )
    
    agent.generate_documentation()

Features:
---------

1. **Project Structure Analysis**
   - Automatically discovers all .h/.hpp/.cpp files
   - Analyzes CMakeLists.txt or Makefiles
   - Maps include dependencies
   - Identifies namespaces and classes

2. **Doxygen Comment Generation**
   - Template-based comments (default)
   - AI-powered comments (with Gemini API)
   - Professional formatting
   - Parameter and return value documentation

3. **Sphinx Documentation**
   - Complete HTML documentation
   - API reference with cross-links
   - User guide and examples
   - Developer documentation
   - Professional theme

4. **Build Integration**
   - Generates Doxyfile configuration
   - Creates build scripts
   - Integrates with existing build systems

Output Structure:
----------------

    documentation/
    ├── docs/                    # Sphinx documentation
    │   ├── conf.py             # Sphinx configuration
    │   ├── index.rst           # Main documentation page
    │   ├── api/                # API reference
    │   ├── usage/              # User guide
    │   └── developer/          # Developer guide
    ├── original_sources/        # Backup of original files
    ├── build_docs.py           # Documentation build script
    └── PROJECT_DOCUMENTATION_REPORT.md

Requirements:
------------

Python packages (install with: pip install -r requirements.txt):
- sphinx
- sphinx-rtd-theme  
- breathe
- google-generativeai (optional, for AI comments)

External tools:
- Doxygen (for API documentation)

""")

def main():
    """Main function with example selection"""
    print("C++ Documentation Generator - Examples")
    print("=" * 50)
    
    examples = {
        '1': ('Basic Usage (Template Comments)', example_basic_usage),
        '2': ('Gemini Integration', example_with_gemini),
        '3': ('Project Analysis Only', example_project_analysis_only),
        '4': ('Sample Project Demo', example_sample_project),
        '5': ('Usage Instructions', print_usage_instructions),
    }
    
    print("\nAvailable examples:")
    for key, (description, _) in examples.items():
        print(f"  {key}. {description}")
    
    print(f"  q. Quit")
    
    while True:
        choice = input("\nSelect an example (1-5, q to quit): ").strip().lower()
        
        if choice == 'q':
            print("Goodbye!")
            break
        
        if choice in examples:
            print()
            _, example_func = examples[choice]
            example_func()
            print("\n" + "=" * 50)
        else:
            print("Invalid choice. Please select 1-5 or q to quit.")

if __name__ == "__main__":
    main()
