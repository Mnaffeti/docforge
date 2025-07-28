# C++ Project Documentation Generator

A comprehensive Python tool that automatically analyzes C++ projects and generates professional documentation using Doxygen comments and Sphinx HTML output.

## 🚀 Features

- **Automatic Project Analysis**: Discovers all C++ source files, build configurations, and dependencies
- **Intelligent Code Parsing**: Identifies classes, functions, namespaces, enums, and structs
- **Doxygen Comment Generation**: Creates professional documentation comments with proper formatting
- **AI-Powered Comments**: Optional OpenAI integration for intelligent comment generation
- **Sphinx Documentation**: Generates complete HTML documentation with professional theming
- **Build System Integration**: Works with CMake, Make, and other build systems
- **Cross-References**: Automatic linking between related code elements
- **Professional Output**: Publication-ready documentation with examples and guides

## 📋 Requirements

### Python Dependencies
```bash
pip install -r requirements.txt
```

### External Tools
- **Doxygen**: For API documentation generation
  - Windows: Download from [doxygen.nl](https://www.doxygen.nl/)
  - Ubuntu/Debian: `sudo apt-get install doxygen`
  - macOS: `brew install doxygen`

### Optional Dependencies
- **OpenAI API Key**: For AI-powered comment generation
  - Set environment variable: `OPENAI_API_KEY=your_api_key_here`

## 🔧 Installation

1. Clone or download this repository
2. Install Python dependencies:
   ```bash
   pip install -r requirements.txt
   ```
3. Install Doxygen (see requirements above)
4. (Optional) Set up OpenAI API key for enhanced comment generation

## 💻 Usage

### Command Line Interface

#### Basic Usage
```bash
python cpp_doc_generator.py /path/to/cpp/project
```

#### With Custom Output Directory
```bash
python cpp_doc_generator.py /path/to/cpp/project -o /path/to/output
```

#### With OpenAI Integration
```bash
python cpp_doc_generator.py /path/to/cpp/project --openai --api-key YOUR_API_KEY
```

#### Verbose Output
```bash
python cpp_doc_generator.py /path/to/cpp/project -v
```

### Python API

```python
from cpp_doc_generator import CppDocumentationAgent

# Basic usage
agent = CppDocumentationAgent(
    project_path="/path/to/cpp/project",
    output_dir="./documentation"
)

# With OpenAI integration
agent = CppDocumentationAgent(
    project_path="/path/to/cpp/project",
    output_dir="./documentation",
    use_openai=True,
    api_key="your-openai-api-key"
)

# Generate documentation
agent.generate_documentation()
```

### Examples

Run the example script to see various usage scenarios:
```bash
python example_usage.py
```

## 📁 Output Structure

The tool generates a comprehensive documentation structure:

```
documentation/
├── docs/                           # Sphinx documentation
│   ├── conf.py                    # Sphinx configuration
│   ├── index.rst                  # Main documentation page
│   ├── Doxyfile                   # Doxygen configuration
│   ├── api/                       # API reference
│   │   ├── index.rst
│   │   ├── classes.rst
│   │   ├── functions.rst
│   │   └── namespaces.rst
│   ├── usage/                     # User guide
│   │   ├── index.rst
│   │   ├── installation.rst
│   │   ├── quickstart.rst
│   │   ├── examples.rst
│   │   └── troubleshooting.rst
│   └── developer/                 # Developer guide
│       ├── index.rst
│       ├── architecture.rst
│       ├── contributing.rst
│       └── building_docs.rst
├── original_sources/              # Backup of original files
├── build_docs.py                  # Documentation build script
└── PROJECT_DOCUMENTATION_REPORT.md
```

## 🔄 Documentation Build Process

After generation, build the final HTML documentation:

```bash
cd documentation
python build_docs.py
```

This will:
1. Run Doxygen to generate XML API documentation
2. Build Sphinx HTML documentation
3. Create a complete, navigable documentation website

## 📊 Generated Documentation Includes

### 1. **Doxygen Comments**
Professional inline documentation added to source files:

```cpp
/**
 * @brief Calculator class for basic arithmetic operations
 * 
 * Provides methods for performing addition, subtraction, multiplication,
 * and division operations with proper error handling and result tracking.
 * 
 * @since Version 1.0
 * 
 * @example
 * Calculator calc;
 * double result = calc.add(5.0, 3.0);
 */
class Calculator {
    /**
     * @brief Adds two numbers
     * 
     * @param a First operand
     * @param b Second operand
     * @return double Sum of a and b
     * @throws std::overflow_error If result exceeds maximum value
     */
    double add(double a, double b);
};
```

### 2. **API Reference**
Complete API documentation with:
- Class hierarchies and relationships
- Function signatures and parameters
- Return values and exceptions
- Cross-references between related elements
- Usage examples for each component

### 3. **User Guide**
Comprehensive user documentation:
- Installation instructions
- Quick start guide
- Detailed examples
- Configuration options
- Troubleshooting guide

### 4. **Developer Guide**
Technical documentation for contributors:
- Architecture overview
- Code organization
- Contributing guidelines
- Development setup instructions

## 🔍 Analysis Capabilities

The tool automatically detects and documents:

- **Classes and Structures**: Member functions, variables, inheritance
- **Functions**: Parameters, return types, exception handling
- **Namespaces**: Organization and scope
- **Enumerations**: Values and usage
- **Dependencies**: Include relationships and external libraries
- **Build Configuration**: CMake, Makefile analysis
- **Project Structure**: File organization and modules

## ⚙️ Configuration Options

### Doxygen Comment Generation

- **Template-based**: Uses intelligent templates (default)
- **AI-powered**: Uses OpenAI GPT models for natural language comments
- **Customizable**: Modify templates for project-specific conventions

### Sphinx Documentation

- **Theme**: Professional ReadTheDocs theme
- **Extensions**: MathJax, cross-references, code highlighting
- **Structure**: Modular organization with clear navigation
- **Customizable**: Easy to modify layout and styling

## 🧪 Testing

Test the tool with the included sample project:

```bash
python example_usage.py
# Select option 4: "Sample Project Demo"
```

This creates a sample C++ calculator project and generates documentation for it.

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Make your changes
4. Add tests for new functionality
5. Submit a pull request

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🔧 Troubleshooting

### Common Issues

#### "Doxygen not found"
- Install Doxygen and ensure it's in your PATH
- On Windows, add Doxygen installation directory to PATH

#### "OpenAI API Error"
- Verify your API key is correct
- Check your OpenAI account has sufficient credits
- Ensure you have access to the specified model (GPT-4/GPT-3.5)

#### "Sphinx build failed"
- Install all required Python packages: `pip install -r requirements.txt`
- Check that all .rst files are properly formatted
- Verify Doxygen XML output exists before running Sphinx

#### "No source files found"
- Verify the project path contains .cpp/.h files
- Check file permissions
- Ensure the project directory structure is accessible

### Getting Help

- Check the generated `PROJECT_DOCUMENTATION_REPORT.md` for analysis results
- Run with `-v` flag for verbose output
- Review the example usage scenarios in `example_usage.py`

## 📈 Example Projects

The tool works well with various C++ project types:

- **Libraries**: Static and dynamic libraries with complex APIs
- **Applications**: Command-line tools and GUI applications  
- **Game Engines**: Complex hierarchies and design patterns
- **Scientific Computing**: Mathematical libraries and algorithms
- **System Programming**: Low-level utilities and drivers

## 🎯 Future Enhancements

- Support for additional documentation formats (PDF, EPUB)
- Integration with continuous integration systems
- Template customization for different documentation styles
- Support for additional programming languages
- Advanced code analysis and metrics generation

---

## 📞 Support

For questions, issues, or contributions, please:
- Open an issue on the project repository
- Check the troubleshooting section above
- Review the example usage scenarios

**Happy Documenting! 📚**
