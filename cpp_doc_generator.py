#!/usr/bin/env python3
"""
C++ Project Documentation Generation Agent

This module provides comprehensive documentation generation for C++ projects,
including Doxygen comment generation and Sphinx HTML documentation.
"""

import os
import re
import json
import shutil
import subprocess
import sys
from pathlib import Path
from typing import Dict, List, Tuple, Optional, Set
from dataclasses import dataclass, field
import argparse
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

@dataclass
class CodeElement:
    """Represents a C++ code element (function, class, etc.)"""
    name: str
    type: str  # 'function', 'class', 'struct', 'enum', 'namespace'
    signature: str
    file_path: str
    line_number: int
    documentation: str = ""
    parameters: List[str] = field(default_factory=list)
    return_type: str = ""
    namespace: str = ""
    access_level: str = "public"  # public, private, protected
    
@dataclass
class ProjectStructure:
    """Represents the overall project structure"""
    project_name: str
    project_path: Path
    header_files: List[Path] = field(default_factory=list)
    source_files: List[Path] = field(default_factory=list)
    build_files: List[Path] = field(default_factory=list)
    readme_files: List[Path] = field(default_factory=list)
    config_files: List[Path] = field(default_factory=list)
    code_elements: List[CodeElement] = field(default_factory=list)
    dependencies: Set[str] = field(default_factory=set)
    namespaces: Set[str] = field(default_factory=set)

class CppProjectAnalyzer:
    """Analyzes C++ project structure and code elements"""
    
    def __init__(self, project_path: str):
        self.project_path = Path(project_path)
        self.project_structure = ProjectStructure(
            project_name=self.project_path.name,
            project_path=self.project_path
        )
        
    def analyze_project(self) -> ProjectStructure:
        """Perform complete project analysis"""
        logger.info(f"Starting analysis of project: {self.project_path}")
        
        self._scan_project_files()
        self._analyze_build_system()
        self._parse_source_files()
        self._extract_dependencies()
        
        logger.info(f"Analysis complete. Found {len(self.project_structure.code_elements)} code elements")
        return self.project_structure
    
    def _scan_project_files(self):
        """Scan project directory for relevant files"""
        logger.info("Scanning project files...")
        
        for root, dirs, files in os.walk(self.project_path):
            root_path = Path(root)
            
            for file in files:
                file_path = root_path / file
                file_ext = file_path.suffix.lower()
                
                if file_ext in ['.h', '.hpp', '.hxx']:
                    self.project_structure.header_files.append(file_path)
                elif file_ext in ['.cpp', '.cxx', '.cc', '.c']:
                    self.project_structure.source_files.append(file_path)
                elif file.lower() in ['cmakelists.txt', 'makefile', 'makefile.am']:
                    self.project_structure.build_files.append(file_path)
                elif file.lower().startswith('readme'):
                    self.project_structure.readme_files.append(file_path)
                elif file_ext in ['.json', '.xml', '.ini', '.cfg', '.config']:
                    self.project_structure.config_files.append(file_path)
        
        logger.info(f"Found {len(self.project_structure.header_files)} header files")
        logger.info(f"Found {len(self.project_structure.source_files)} source files")
    
    def _analyze_build_system(self):
        """Analyze build system configuration"""
        for build_file in self.project_structure.build_files:
            if build_file.name.lower() == 'cmakelists.txt':
                self._parse_cmake_file(build_file)
            elif 'makefile' in build_file.name.lower():
                self._parse_makefile(build_file)
    
    def _parse_cmake_file(self, cmake_file: Path):
        """Parse CMakeLists.txt for project information"""
        try:
            with open(cmake_file, 'r', encoding='utf-8') as f:
                content = f.read()
                
            # Extract project name
            project_match = re.search(r'project\s*\(\s*(\w+)', content, re.IGNORECASE)
            if project_match:
                self.project_structure.project_name = project_match.group(1)
                
            # Extract dependencies
            find_package_matches = re.findall(r'find_package\s*\(\s*(\w+)', content, re.IGNORECASE)
            self.project_structure.dependencies.update(find_package_matches)
            
        except Exception as e:
            logger.warning(f"Error parsing CMakeLists.txt: {e}")
    
    def _parse_makefile(self, makefile: Path):
        """Parse Makefile for project information"""
        try:
            with open(makefile, 'r', encoding='utf-8') as f:
                content = f.read()
                
            # Extract library dependencies
            lib_matches = re.findall(r'-l(\w+)', content)
            self.project_structure.dependencies.update(lib_matches)
            
        except Exception as e:
            logger.warning(f"Error parsing Makefile: {e}")
    
    def _parse_source_files(self):
        """Parse all source and header files for code elements"""
        all_files = self.project_structure.header_files + self.project_structure.source_files
        
        for file_path in all_files:
            try:
                self._parse_cpp_file(file_path)
            except Exception as e:
                logger.warning(f"Error parsing {file_path}: {e}")
    
    def _parse_cpp_file(self, file_path: Path):
        """Parse a single C++ file for code elements"""
        with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
        
        lines = content.split('\n')
        
        # Parse classes
        self._extract_classes(content, file_path, lines)
        
        # Parse functions
        self._extract_functions(content, file_path, lines)
        
        # Parse namespaces
        self._extract_namespaces(content, file_path, lines)
        
        # Parse enums and structs
        self._extract_enums_structs(content, file_path, lines)
    
    def _extract_classes(self, content: str, file_path: Path, lines: List[str]):
        """Extract class definitions"""
        class_pattern = r'class\s+(\w+)(?:\s*:\s*(?:public|private|protected)\s+[\w:,\s]+)?\s*\{'
        
        for match in re.finditer(class_pattern, content):
            class_name = match.group(1)
            line_num = content[:match.start()].count('\n') + 1
            
            # Get full class signature
            start_pos = match.start()
            brace_count = 0
            end_pos = start_pos
            
            for i, char in enumerate(content[start_pos:], start_pos):
                if char == '{':
                    brace_count += 1
                elif char == '}':
                    brace_count -= 1
                    if brace_count == 0:
                        end_pos = i + 1
                        break
            
            signature = content[start_pos:end_pos]
            
            element = CodeElement(
                name=class_name,
                type='class',
                signature=signature,
                file_path=str(file_path),
                line_number=line_num
            )
            
            self.project_structure.code_elements.append(element)
    
    def _extract_functions(self, content: str, file_path: Path, lines: List[str]):
        """Extract function definitions"""
        # More precise function pattern that matches actual C++ function definitions
        # This pattern looks for proper function signatures with return types
        func_pattern = r'^(?:\s*)(?:(?:inline|static|virtual|explicit|constexpr|extern)\s+)*(?:(?:const|unsigned|signed|long|short)\s+)*([a-zA-Z_][a-zA-Z0-9_]*(?:\s*[*&]*\s*)*)\s+(?:([a-zA-Z_][a-zA-Z0-9_]*::)*)?([a-zA-Z_][a-zA-Z0-9_]*)\s*\([^)]*\)\s*(?:const)?\s*(?:override)?\s*(?:noexcept)?\s*[{;]'
        
        for match in re.finditer(func_pattern, content, re.MULTILINE):
            return_type = match.group(1).strip()
            class_scope = match.group(2) if match.group(2) else ""
            func_name = match.group(3)
            line_num = content[:match.start()].count('\n') + 1
            
            # Skip keywords that are not valid return types
            if return_type.lower() in ['class', 'struct', 'enum', 'namespace', 'if', 'else', 'while', 'for', 'switch', 'do', 'try', 'catch']:
                continue
                
            # Skip C++ keywords and control structures
            if func_name.lower() in ['if', 'else', 'while', 'for', 'switch', 'do', 'try', 'catch', 'return', 'break', 'continue']:
                continue
                
            # Get the actual line content for additional validation
            line_start = content.rfind('\n', 0, match.start()) + 1
            line_end = content.find('\n', match.end())
            if line_end == -1:
                line_end = len(content)
            full_line = content[line_start:line_end].strip()
            
            # Skip if it's clearly not a function (assignment, control structures, etc.)
            if any(keyword in full_line.lower() for keyword in ['else if', 'if (', 'while (', 'for (', 'switch (']):
                continue
                
            # Skip variable declarations (has assignment operators)
            if ('=' in full_line and '{' not in full_line):
                continue
            
            # Check if this appears to be inside a function body (brace counting)
            preceding_context = content[max(0, match.start() - 2000):match.start()]
            
            # Count braces in preceding context
            brace_level = 0
            in_function = False
            
            # Simple state tracking for function vs class context
            lines_before = preceding_context.split('\n')
            for line in lines_before:
                line = line.strip()
                if not line or line.startswith('//') or line.startswith('/*'):
                    continue
                    
                # Check for function-like patterns in preceding lines
                if re.search(r'\w+\s*\([^)]*\)\s*\{', line):
                    in_function = True
                    
                brace_level += line.count('{') - line.count('}')
            
            # If we're inside braces (likely function body), skip this match
            if brace_level > 0 and in_function:
                continue
                
            # Additional validation: ensure this looks like a real function signature
            signature = match.group(0).strip()
            
            # Must have parentheses and valid C++ identifier patterns
            if not re.search(r'[a-zA-Z_][a-zA-Z0-9_]*\s*\([^)]*\)', signature):
                continue
            
            element = CodeElement(
                name=func_name,
                type='function',
                signature=signature,
                file_path=str(file_path),
                line_number=line_num,
                return_type=return_type,
                namespace=class_scope.rstrip('::') if class_scope else ""
            )
            
            self.project_structure.code_elements.append(element)
    
    def _extract_namespaces(self, content: str, file_path: Path, lines: List[str]):
        """Extract namespace definitions"""
        namespace_pattern = r'namespace\s+(\w+)\s*\{'
        
        for match in re.finditer(namespace_pattern, content):
            namespace_name = match.group(1)
            self.project_structure.namespaces.add(namespace_name)
            
            line_num = content[:match.start()].count('\n') + 1
            
            element = CodeElement(
                name=namespace_name,
                type='namespace',
                signature=match.group(0),
                file_path=str(file_path),
                line_number=line_num
            )
            
            self.project_structure.code_elements.append(element)
    
    def _extract_enums_structs(self, content: str, file_path: Path, lines: List[str]):
        """Extract enum and struct definitions"""
        enum_pattern = r'enum\s+(?:class\s+)?(\w+)\s*(?::\s*\w+)?\s*\{'
        struct_pattern = r'struct\s+(\w+)\s*(?::\s*(?:public|private|protected)\s+[\w:,\s]+)?\s*\{'
        
        for pattern, element_type in [(enum_pattern, 'enum'), (struct_pattern, 'struct')]:
            for match in re.finditer(pattern, content):
                name = match.group(1)
                line_num = content[:match.start()].count('\n') + 1
                
                element = CodeElement(
                    name=name,
                    type=element_type,
                    signature=match.group(0),
                    file_path=str(file_path),
                    line_number=line_num
                )
                
                self.project_structure.code_elements.append(element)
    
    def _extract_dependencies(self):
        """Extract include dependencies from source files"""
        include_pattern = r'#include\s*[<"]([^>"]+)[>"]'
        
        all_files = self.project_structure.header_files + self.project_structure.source_files
        
        for file_path in all_files:
            try:
                with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                    content = f.read()
                
                includes = re.findall(include_pattern, content)
                for include in includes:
                    # Filter out system includes vs project includes
                    if not include.startswith('/') and '.' in include:
                        self.project_structure.dependencies.add(include)
                        
            except Exception as e:
                logger.warning(f"Error extracting dependencies from {file_path}: {e}")

class DoxygenCommentGenerator:
    """Generates Doxygen comments for C++ code elements"""
    
    def __init__(self, use_gemini: bool = False, api_key: str = None, model_name: str = "gemini-1.5-flash-8b"):
        self.use_gemini = use_gemini
        self.api_key = api_key
        self.model_name = model_name
        
        if use_gemini and api_key:
            try:
                import google.generativeai as genai
                genai.configure(api_key=api_key)
                self.genai = genai
                self.model = genai.GenerativeModel(model_name)
                logger.info(f"Initialized Gemini model: {model_name}")
            except ImportError:
                logger.warning("Google Generative AI package not available. Using template-based generation.")
                self.use_gemini = False
    
    def generate_comment(self, element: CodeElement, context: str = "") -> str:
        """Generate Doxygen comment for a code element"""
        if self.use_gemini:
            return self._generate_ai_comment(element, context)
        else:
            return self._generate_template_comment(element)
    
    def _generate_ai_comment(self, element: CodeElement, context: str) -> str:
        """Generate comment using Gemini API"""
        try:
            prompt = f"""
Generate professional Doxygen comments for this C++ {element.type}:

{element.signature}

Context: {context}
File: {element.file_path}

You are an expert in documenting C++ code and Doxygen best practicesInclude appropriate @brief, @param, @return, @throws tags 
Make the documentation clear, concise, and professional.
Return only the Doxygen comment block starting with /** and ending with */.
"""
            
            # Add a small delay to be respectful of API rate limits
            import time
            time.sleep(0.5)
            
            response = self.model.generate_content(prompt)
            return response.text.strip()
            
        except Exception as e:
            error_msg = str(e)
            if "429" in error_msg or "quota" in error_msg.lower():
                logger.warning(f"Gemini API quota exceeded. Daily limit reached. Falling back to template generation.")
            elif "404" in error_msg:
                logger.warning(f"Gemini model '{self.model_name}' not found. Try 'gemini-1.5-flash-8b' for free tier. Falling back to template.")
            else:
                logger.warning(f"Gemini API error: {e}. Falling back to template.")
            return self._generate_template_comment(element)
    
    def _generate_template_comment(self, element: CodeElement) -> str:
        """Generate comment using templates"""
        if element.type == 'class':
            return self._generate_class_comment(element)
        elif element.type == 'function':
            return self._generate_function_comment(element)
        elif element.type == 'namespace':
            return self._generate_namespace_comment(element)
        elif element.type in ['enum', 'struct']:
            return self._generate_enum_struct_comment(element)
        else:
            return self._generate_generic_comment(element)
    
    def _generate_class_comment(self, element: CodeElement) -> str:
        """Generate class documentation template"""
        return f"""/**
 * @brief {element.name} class
 * 
 * Detailed description of the {element.name} class.
 * TODO: Add specific functionality description
 * 
 * @since Version 1.0
 * 
 * @example
 * {element.name} obj;
 * // Usage example
 */"""
    
    def _generate_function_comment(self, element: CodeElement) -> str:
        """Generate function documentation template"""
        comment = f"""/**
 * @brief {element.name} function
 * 
 * Detailed description of what this function does.
 * TODO: Add specific functionality description
 * """
        
        # Add parameter documentation if we can detect parameters
        if '(' in element.signature and ')' in element.signature:
            param_section = element.signature[element.signature.find('('):element.signature.find(')')+1]
            if param_section != '()':
                comment += "\n * @param param_name Description of parameter\n * "
        
        if element.return_type and element.return_type.lower() != 'void':
            comment += f"\n * @return {element.return_type} Description of return value\n * "
        
        comment += "\n * @throws std::exception Description of when exceptions are thrown\n * "
        comment += f"\n * @example\n * // Usage example for {element.name}\n */"
        
        return comment
    
    def _generate_namespace_comment(self, element: CodeElement) -> str:
        """Generate namespace documentation template"""
        return f"""/**
 * @brief {element.name} namespace
 * 
 * Contains classes and functions related to {element.name} functionality.
 * TODO: Add specific namespace purpose description
 * 
 * @since Version 1.0
 */"""
    
    def _generate_enum_struct_comment(self, element: CodeElement) -> str:
        """Generate enum/struct documentation template"""
        return f"""/**
 * @brief {element.name} {element.type}
 * 
 * Detailed description of the {element.name} {element.type}.
 * TODO: Add specific purpose and usage description
 * 
 * @since Version 1.0
 */"""
    
    def _generate_generic_comment(self, element: CodeElement) -> str:
        """Generate generic documentation template"""
        return f"""/**
 * @brief {element.name}
 * 
 * TODO: Add description for {element.type} {element.name}
 */"""

class SphinxDocumentationGenerator:
    """Generates Sphinx documentation structure and content"""
    
    def __init__(self, project_structure: ProjectStructure, output_dir: str):
        self.project_structure = project_structure
        self.output_dir = Path(output_dir)
        self.docs_dir = self.output_dir / "docs"
    
    def generate_documentation(self):
        """Generate complete Sphinx documentation"""
        logger.info("Generating Sphinx documentation...")
        
        self._create_directory_structure()
        self._generate_conf_py()
        self._generate_index_rst()
        self._generate_api_documentation()
        self._generate_usage_documentation()
        self._generate_developer_documentation()
        self._generate_doxyfile()
        
        logger.info(f"Sphinx documentation generated in {self.docs_dir}")
    
    def _create_directory_structure(self):
        """Create Sphinx directory structure"""
        directories = [
            self.docs_dir,
            self.docs_dir / "api",
            self.docs_dir / "usage",
            self.docs_dir / "developer",
            self.docs_dir / "_static",
            self.docs_dir / "_templates",
            self.docs_dir / "_build"
        ]
        
        for directory in directories:
            directory.mkdir(parents=True, exist_ok=True)
    
    def _generate_conf_py(self):
        """Generate Sphinx configuration file"""
        conf_content = f'''# Configuration file for the Sphinx documentation builder.

import os
import sys
sys.path.insert(0, os.path.abspath('.'))

# -- Project information -----------------------------------------------------
project = '{self.project_structure.project_name}'
copyright = '2025, {self.project_structure.project_name} Team'
author = '{self.project_structure.project_name} Team'
release = '1.0.0'

# -- General configuration ---------------------------------------------------
extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.viewcode',
    'sphinx.ext.napoleon',
    'sphinx.ext.todo',
    'sphinx.ext.mathjax',
    'sphinx.ext.intersphinx',
    'breathe',  # For Doxygen integration
]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

# -- Options for HTML output -------------------------------------------------
html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
html_theme_options = {{
    'navigation_depth': 4,
    'collapse_navigation': False,
    'sticky_navigation': True,
    'includehidden': True,
    'titles_only': False
}}

# -- Breathe configuration ---------------------------------------------------
breathe_projects = {{"{self.project_structure.project_name}": "_build/doxygen/xml/"}}
breathe_default_project = "{self.project_structure.project_name}"
breathe_default_members = ('members', 'undoc-members')

# -- Todo extension configuration --------------------------------------------
todo_include_todos = True

# -- Intersphinx configuration -----------------------------------------------
intersphinx_mapping = {{
    'python': ('https://docs.python.org/3/', None),
    'cpp': ('https://en.cppreference.com/', None),
}}
'''
        
        with open(self.docs_dir / "conf.py", 'w', encoding='utf-8') as f:
            f.write(conf_content)
    
    def _generate_index_rst(self):
        """Generate main index.rst file"""
        index_content = f'''{self.project_structure.project_name} Documentation
{'=' * (len(self.project_structure.project_name) + 14)}

Welcome to the {self.project_structure.project_name} documentation!

{self.project_structure.project_name} is a C++ project that provides...
TODO: Add project description based on analysis

Features
--------

* Feature 1: TODO - Add key features based on code analysis
* Feature 2: TODO - Add more features
* Feature 3: TODO - Add more features

Quick Start
-----------

.. code-block:: cpp

   #include "{self.project_structure.project_name}.h"
   
   int main() {{
       // TODO: Add quick start example
       return 0;
   }}

Project Statistics
------------------

* **Header Files**: {len(self.project_structure.header_files)}
* **Source Files**: {len(self.project_structure.source_files)}
* **Classes**: {len([e for e in self.project_structure.code_elements if e.type == 'class'])}
* **Functions**: {len([e for e in self.project_structure.code_elements if e.type == 'function'])}
* **Namespaces**: {len(self.project_structure.namespaces)}

.. toctree::
   :maxdepth: 2
   :caption: Contents:

   usage/index
   api/index
   developer/index

Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
'''
        
        with open(self.docs_dir / "index.rst", 'w', encoding='utf-8') as f:
            f.write(index_content)
    
    def _generate_api_documentation(self):
        """Generate API documentation files"""
        # API index
        api_index_content = '''API Reference
=============

This section contains the complete API reference for all classes, functions, and other code elements.

.. toctree::
   :maxdepth: 2

   classes
   functions
   namespaces
'''
        
        with open(self.docs_dir / "api" / "index.rst", 'w', encoding='utf-8') as f:
            f.write(api_index_content)
        
        # Classes documentation
        self._generate_classes_rst()
        
        # Functions documentation
        self._generate_functions_rst()
        
        # Namespaces documentation
        self._generate_namespaces_rst()
    
    def _generate_classes_rst(self):
        """Generate classes documentation"""
        classes = [e for e in self.project_structure.code_elements if e.type == 'class']
        
        content = '''Classes
=======

This section documents all classes in the project.

'''
        
        for cls in classes:
            content += f'''
{cls.name}
{'-' * len(cls.name)}

.. doxygenclass:: {cls.name}
   :members:
   :undoc-members:

**File:** ``{os.path.basename(cls.file_path)}`` (Line {cls.line_number})

'''
        
        with open(self.docs_dir / "api" / "classes.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_functions_rst(self):
        """Generate functions documentation"""
        functions = [e for e in self.project_structure.code_elements if e.type == 'function']
        
        content = '''Functions
=========

This section documents all functions in the project.

'''
        
        for func in functions:
            content += f'''
{func.name}
{'-' * len(func.name)}

.. doxygenfunction:: {func.name}

**File:** ``{os.path.basename(func.file_path)}`` (Line {func.line_number})

**Return Type:** ``{func.return_type}``

'''
        
        with open(self.docs_dir / "api" / "functions.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_namespaces_rst(self):
        """Generate namespaces documentation"""
        content = '''Namespaces
==========

This section documents all namespaces in the project.

'''
        
        for namespace in self.project_structure.namespaces:
            content += f'''
{namespace}
{'-' * len(namespace)}

.. doxygennamespace:: {namespace}
   :members:

'''
        
        with open(self.docs_dir / "api" / "namespaces.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_usage_documentation(self):
        """Generate usage documentation files"""
        # Usage index
        usage_index_content = '''User Guide
==========

This section provides comprehensive usage instructions and examples.

.. toctree::
   :maxdepth: 2

   installation
   quickstart
   examples
   troubleshooting
'''
        
        with open(self.docs_dir / "usage" / "index.rst", 'w', encoding='utf-8') as f:
            f.write(usage_index_content)
        
        self._generate_installation_rst()
        self._generate_quickstart_rst()
        self._generate_examples_rst()
        self._generate_troubleshooting_rst()
    
    def _generate_installation_rst(self):
        """Generate installation guide"""
        build_system = "CMake" if any("cmake" in str(f).lower() for f in self.project_structure.build_files) else "Make"
        
        content = f'''Installation
============

System Requirements
-------------------

* C++11 or higher
* {build_system}
* Git (for cloning the repository)

Dependencies
------------

The following libraries are required:

'''
        
        for dep in sorted(self.project_structure.dependencies):
            content += f"* {dep}\n"
        
        if build_system == "CMake":
            content += '''

Building with CMake
-------------------

.. code-block:: bash

   # Clone the repository
   git clone <repository-url>
   cd ''' + self.project_structure.project_name + '''
   
   # Create build directory
   mkdir build
   cd build
   
   # Configure and build
   cmake ..
   make
   
   # Install (optional)
   sudo make install

'''
        else:
            content += '''

Building with Make
------------------

.. code-block:: bash

   # Clone the repository
   git clone <repository-url>
   cd ''' + self.project_structure.project_name + '''
   
   # Build
   make
   
   # Install (optional)
   sudo make install

'''
        
        content += '''
Verification
------------

To verify the installation, run:

.. code-block:: bash

   # TODO: Add verification steps based on the project

'''
        
        with open(self.docs_dir / "usage" / "installation.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_quickstart_rst(self):
        """Generate quickstart guide"""
        content = f'''Quick Start Guide
=================

This guide will help you get up and running with {self.project_structure.project_name} quickly.

Basic Usage
-----------

Here's a simple example to get you started:

.. code-block:: cpp

   #include "{self.project_structure.project_name}.h"
   
   int main() {{
       // TODO: Add basic usage example
       return 0;
   }}

Next Steps
----------

* Read the :doc:`examples` section for more detailed examples
* Check the :doc:`../api/index` for complete API reference
* See :doc:`troubleshooting` if you encounter issues

'''
        
        with open(self.docs_dir / "usage" / "quickstart.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_examples_rst(self):
        """Generate examples documentation"""
        content = '''Examples
========

This section provides practical examples of using the library.

Basic Examples
--------------

Example 1: Basic Usage
~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

   // TODO: Add basic example

Advanced Examples
-----------------

Example 2: Advanced Usage
~~~~~~~~~~~~~~~~~~~~~~~~~

.. code-block:: cpp

   // TODO: Add advanced example

'''
        
        with open(self.docs_dir / "usage" / "examples.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_troubleshooting_rst(self):
        """Generate troubleshooting guide"""
        content = '''Troubleshooting
===============

Common Issues
-------------

Compilation Errors
~~~~~~~~~~~~~~~~~~

If you encounter compilation errors:

1. Ensure all dependencies are installed
2. Check that you're using a compatible C++ compiler
3. Verify the build system requirements

Runtime Issues
~~~~~~~~~~~~~~

If you encounter runtime issues:

1. Check that all required libraries are linked
2. Verify input parameters
3. Enable debug mode for more detailed error messages

Getting Help
------------

If you're still having issues:

* Check the project's issue tracker on GitHub
* Review the API documentation
* Contact the development team

'''
        
        with open(self.docs_dir / "usage" / "troubleshooting.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_developer_documentation(self):
        """Generate developer documentation files"""
        # Developer index
        dev_index_content = '''Developer Guide
===============

This section provides information for developers who want to contribute to the project.

.. toctree::
   :maxdepth: 2

   architecture
   contributing
   building_docs
'''
        
        with open(self.docs_dir / "developer" / "index.rst", 'w', encoding='utf-8') as f:
            f.write(dev_index_content)
        
        self._generate_architecture_rst()
        self._generate_contributing_rst()
        self._generate_building_docs_rst()
    
    def _generate_architecture_rst(self):
        """Generate architecture documentation"""
        content = f'''Architecture Overview
====================

This document describes the overall architecture of {self.project_structure.project_name}.

Project Structure
-----------------

The project is organized as follows:

'''
        
        # Add file structure based on analysis
        header_count = len(self.project_structure.header_files)
        source_count = len(self.project_structure.source_files)
        
        content += f'''
* **Header Files** ({header_count} files): Interface definitions
* **Source Files** ({source_count} files): Implementation code
'''
        
        if self.project_structure.namespaces:
            content += f'''
Namespaces
----------

The project uses the following namespaces:

'''
            for ns in sorted(self.project_structure.namespaces):
                content += f"* ``{ns}``\n"
        
        content += '''

Core Components
---------------

TODO: Add detailed component descriptions based on code analysis

Design Patterns
---------------

TODO: Document design patterns used in the codebase

'''
        
        with open(self.docs_dir / "developer" / "architecture.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_contributing_rst(self):
        """Generate contributing guide"""
        content = '''Contributing
============

We welcome contributions to the project! This guide will help you get started.

Getting Started
---------------

1. Fork the repository
2. Clone your fork locally
3. Create a new branch for your feature
4. Make your changes
5. Test your changes
6. Submit a pull request

Code Style
----------

Please follow these coding conventions:

* Use consistent indentation (4 spaces)
* Follow C++ naming conventions
* Add Doxygen comments for all public APIs
* Include unit tests for new functionality

Testing
-------

Before submitting changes:

1. Run all existing tests
2. Add tests for new functionality
3. Ensure code coverage remains high

Documentation
-------------

When adding new features:

1. Update API documentation with Doxygen comments
2. Add examples to the user guide
3. Update the changelog

'''
        
        with open(self.docs_dir / "developer" / "contributing.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_building_docs_rst(self):
        """Generate documentation building guide"""
        content = '''Building Documentation
=====================

This guide explains how to build the project documentation locally.

Prerequisites
-------------

To build the documentation, you need:

* Python 3.6+
* Sphinx
* Doxygen
* Breathe (Sphinx extension)

Installation
------------

Install the required Python packages:

.. code-block:: bash

   pip install sphinx sphinx-rtd-theme breathe

Install Doxygen:

* **Ubuntu/Debian**: ``sudo apt-get install doxygen``
* **macOS**: ``brew install doxygen``
* **Windows**: Download from https://www.doxygen.nl/

Building the Documentation
--------------------------

1. Generate Doxygen XML:

.. code-block:: bash

   cd docs
   doxygen Doxyfile

2. Build Sphinx HTML:

.. code-block:: bash

   sphinx-build -b html . _build/html

3. Open the documentation:

.. code-block:: bash

   # Linux/macOS
   open _build/html/index.html
   
   # Windows
   start _build/html/index.html

Automatic Building
------------------

You can also use the provided script to build everything:

.. code-block:: bash

   python build_docs.py

'''
        
        with open(self.docs_dir / "developer" / "building_docs.rst", 'w', encoding='utf-8') as f:
            f.write(content)
    
    def _generate_doxyfile(self):
        """Generate Doxygen configuration file"""
        doxyfile_content = f'''# Doxyfile for {self.project_structure.project_name}

# Project information
PROJECT_NAME           = "{self.project_structure.project_name}"
PROJECT_NUMBER         = "1.0.0"
PROJECT_BRIEF          = "C++ project documentation"

# Input configuration
INPUT                  = ../
FILE_PATTERNS          = *.h *.hpp *.hxx *.cpp *.cxx *.cc
RECURSIVE              = YES
EXCLUDE_PATTERNS       = */build/* */_build/* */.*

# Output configuration
OUTPUT_DIRECTORY       = _build/doxygen
GENERATE_HTML          = NO
GENERATE_XML           = YES
XML_OUTPUT             = xml

# Documentation extraction
EXTRACT_ALL            = YES
EXTRACT_PRIVATE        = NO
EXTRACT_STATIC         = YES
EXTRACT_LOCAL_CLASSES  = YES

# Source code configuration
SOURCE_BROWSER         = YES
INLINE_SOURCES         = NO
VERBATIM_HEADERS       = YES

# Class diagrams
HAVE_DOT               = YES
CLASS_DIAGRAMS         = YES
COLLABORATION_GRAPH    = YES
GROUP_GRAPHS           = YES
UML_LOOK               = YES
TEMPLATE_RELATIONS     = YES
INCLUDE_GRAPH          = YES
INCLUDED_BY_GRAPH      = YES
CALL_GRAPH             = YES
CALLER_GRAPH           = YES

# Preprocessing
ENABLE_PREPROCESSING   = YES
MACRO_EXPANSION        = YES
EXPAND_ONLY_PREDEF     = NO
SEARCH_INCLUDES        = YES

# Other options
QUIET                  = NO
WARNINGS               = YES
WARN_IF_UNDOCUMENTED   = YES
WARN_IF_DOC_ERROR      = YES
'''
        
        with open(self.docs_dir / "Doxyfile", 'w', encoding='utf-8') as f:
            f.write(doxyfile_content)

class CppDocumentationAgent:
    """Main documentation generation agent"""
    
    def __init__(self, project_path: str, output_dir: str = None, use_gemini: bool = False, api_key: str = None):
        self.project_path = Path(project_path)
        self.output_dir = Path(output_dir) if output_dir else self.project_path / "documentation"
        self.use_gemini = use_gemini
        self.api_key = api_key
        
        # Initialize components
        self.analyzer = CppProjectAnalyzer(str(self.project_path))
        self.comment_generator = DoxygenCommentGenerator(use_gemini, api_key)
        
    def generate_documentation(self):
        """Generate complete project documentation"""
        logger.info("Starting C++ project documentation generation...")
        
        # Phase 1: Analyze project structure
        project_structure = self.analyzer.analyze_project()
        
        # Phase 2: Generate Doxygen comments
        self._add_doxygen_comments(project_structure)
        
        # Phase 3: Generate Sphinx documentation
        sphinx_generator = SphinxDocumentationGenerator(project_structure, str(self.output_dir))
        sphinx_generator.generate_documentation()
        
        # Phase 4: Generate build scripts
        self._generate_build_scripts()
        
        # Phase 5: Generate project report
        self._generate_project_report(project_structure)
        
        logger.info(f"Documentation generation complete! Output in: {self.output_dir}")
    
    def _add_doxygen_comments(self, project_structure: ProjectStructure):
        """Add Doxygen comments to source files"""
        logger.info("Generating Doxygen comments...")
        
        # Create backup directory
        backup_dir = self.output_dir / "original_sources"
        backup_dir.mkdir(parents=True, exist_ok=True)
        
        # Group elements by file
        files_to_modify = {}
        for element in project_structure.code_elements:
            file_path = Path(element.file_path)
            if file_path not in files_to_modify:
                files_to_modify[file_path] = []
            files_to_modify[file_path].append(element)
        
        # Process each file
        for file_path, elements in files_to_modify.items():
            self._add_comments_to_file(file_path, elements, backup_dir)
    
    def _add_comments_to_file(self, file_path: Path, elements: List[CodeElement], backup_dir: Path):
        """Add Doxygen comments to a single file"""
        try:
            # Create backup
            backup_path = backup_dir / file_path.name
            shutil.copy2(file_path, backup_path)
            
            # Read file content
            with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
                lines = f.readlines()
            
            # Sort elements by line number (reverse order to maintain line numbers)
            elements.sort(key=lambda x: x.line_number, reverse=True)
            
            # Add comments
            for element in elements:
                comment = self.comment_generator.generate_comment(element)
                comment_lines = [line + '\n' for line in comment.split('\n')]
                
                # Insert comment before the element (line numbers are 1-based)
                insert_line = element.line_number - 1
                if insert_line >= 0:
                    lines[insert_line:insert_line] = comment_lines
            
            # Write modified content
            with open(file_path, 'w', encoding='utf-8') as f:
                f.writelines(lines)
                
            logger.info(f"Added Doxygen comments to {file_path}")
            
        except Exception as e:
            logger.error(f"Error adding comments to {file_path}: {e}")
    
    def _generate_build_scripts(self):
        """Generate build scripts for documentation"""
        # Create build documentation script
        build_script_content = '''#!/usr/bin/env python3
"""
Documentation build script for ''' + self.analyzer.project_structure.project_name + '''
"""

import os
import subprocess
import sys
from pathlib import Path

def run_command(cmd, cwd=None):
    """Run a command and return success status"""
    print(f"Running: {cmd}")
    try:
        result = subprocess.run(cmd, shell=True, cwd=cwd, check=True, 
                              capture_output=True, text=True)
        print(result.stdout)
        return True
    except subprocess.CalledProcessError as e:
        print(f"Error: {e}")
        print(f"Output: {e.stdout}")
        print(f"Error: {e.stderr}")
        return False

def build_documentation():
    """Build complete documentation"""
    docs_dir = Path(__file__).parent / "docs"
    
    print("Building Doxygen documentation...")
    if not run_command("doxygen Doxyfile", cwd=docs_dir):
        print("Failed to build Doxygen documentation")
        return False
    
    print("Building Sphinx documentation...")
    if not run_command("sphinx-build -b html . _build/html", cwd=docs_dir):
        print("Failed to build Sphinx documentation")
        return False
    
    print("Documentation built successfully!")
    print(f"Open: {docs_dir / '_build' / 'html' / 'index.html'}")
    return True

if __name__ == "__main__":
    build_documentation()
'''
        
        script_path = self.output_dir / "build_docs.py"
        with open(script_path, 'w', encoding='utf-8') as f:
            f.write(build_script_content)
        
        # Make script executable on Unix-like systems
        try:
            import stat
            script_path.chmod(script_path.stat().st_mode | stat.S_IEXEC)
        except:
            pass  # Windows doesn't need this
    
    def _generate_project_report(self, project_structure: ProjectStructure):
        """Generate comprehensive project analysis report"""
        report_content = f'''# Project Documentation Report

## Project Analysis Summary

**Project Name:** {project_structure.project_name}
**Analysis Date:** {logger.handlers[0].formatter.formatTime if logger.handlers else "N/A"}

## Project Statistics

- **Header Files:** {len(project_structure.header_files)}
- **Source Files:** {len(project_structure.source_files)}
- **Total Code Elements:** {len(project_structure.code_elements)}
- **Classes:** {len([e for e in project_structure.code_elements if e.type == 'class'])}
- **Functions:** {len([e for e in project_structure.code_elements if e.type == 'function'])}
- **Namespaces:** {len(project_structure.namespaces)}
- **Dependencies:** {len(project_structure.dependencies)}

## File Structure

### Header Files
'''
        
        for header in project_structure.header_files:
            report_content += f"- `{header.relative_to(project_structure.project_path)}`\n"
        
        report_content += "\n### Source Files\n"
        for source in project_structure.source_files:
            report_content += f"- `{source.relative_to(project_structure.project_path)}`\n"
        
        if project_structure.namespaces:
            report_content += "\n## Namespaces\n"
            for ns in sorted(project_structure.namespaces):
                report_content += f"- `{ns}`\n"
        
        if project_structure.dependencies:
            report_content += "\n## Dependencies\n"
            for dep in sorted(project_structure.dependencies):
                report_content += f"- `{dep}`\n"
        
        report_content += f'''

## Documentation Generated

The following documentation has been generated:

1. **Doxygen Comments**: Added to all source files
2. **Sphinx Documentation**: Complete HTML documentation structure
3. **API Reference**: Automated API documentation
4. **User Guide**: Installation, usage, and examples
5. **Developer Guide**: Architecture and contributing information

## Build Instructions

To build the documentation:

```bash
cd {self.output_dir.relative_to(Path.cwd()) if self.output_dir.is_relative_to(Path.cwd()) else self.output_dir}
python build_docs.py
```

## Documentation Structure

```
docs/
â”œâ”€â”€ conf.py                 # Sphinx configuration
â”œâ”€â”€ index.rst              # Main documentation index
â”œâ”€â”€ Doxyfile               # Doxygen configuration
â”œâ”€â”€ api/                   # API reference
â”‚   â”œâ”€â”€ index.rst
â”‚   â”œâ”€â”€ classes.rst
â”‚   â”œâ”€â”€ functions.rst
â”‚   â””â”€â”€ namespaces.rst
â”œâ”€â”€ usage/                 # User guide
â”‚   â”œâ”€â”€ index.rst
â”‚   â”œâ”€â”€ installation.rst
â”‚   â”œâ”€â”€ quickstart.rst
â”‚   â”œâ”€â”€ examples.rst
â”‚   â””â”€â”€ troubleshooting.rst
â””â”€â”€ developer/             # Developer guide
    â”œâ”€â”€ index.rst
    â”œâ”€â”€ architecture.rst
    â”œâ”€â”€ contributing.rst
    â””â”€â”€ building_docs.rst
```

## Next Steps

1. Review generated Doxygen comments and customize as needed
2. Add project-specific examples and usage instructions
3. Customize the Sphinx theme and styling
4. Set up automated documentation builds
5. Deploy documentation to a web server or documentation hosting service

## Notes

- Original source files have been backed up in `original_sources/`
- TODO comments have been added where manual input is needed
- Documentation can be regenerated at any time using the build script
'''
        
        report_path = self.output_dir / "PROJECT_DOCUMENTATION_REPORT.md"
        with open(report_path, 'w', encoding='utf-8') as f:
            f.write(report_content)
        
        logger.info(f"Project report generated: {report_path}")

def main():
    """Main entry point for the documentation generator"""
    parser = argparse.ArgumentParser(
        description='Generate comprehensive documentation for C++ projects'
    )
    parser.add_argument('project_path', help='Path to the C++ project directory')
    parser.add_argument('-o', '--output', help='Output directory for documentation')
    parser.add_argument('--gemini', action='store_true', 
                       help='Use Gemini API for generating comments')
    parser.add_argument('--api-key', help='Gemini API key')
    parser.add_argument('-v', '--verbose', action='store_true', 
                       help='Enable verbose logging')
    
    args = parser.parse_args()
    
    if args.verbose:
        logging.getLogger().setLevel(logging.DEBUG)
    
    # Validate project path
    project_path = Path(args.project_path)
    if not project_path.exists():
        logger.error(f"Project path does not exist: {project_path}")
        sys.exit(1)
    
    if not project_path.is_dir():
        logger.error(f"Project path is not a directory: {project_path}")
        sys.exit(1)
    
    # Initialize documentation agent
    agent = CppDocumentationAgent(
        project_path=str(project_path),
        output_dir=args.output,
        use_gemini=args.gemini,
        api_key=args.api_key
    )
    
    try:
        # Generate documentation
        agent.generate_documentation()
        print(f"\\nDocumentation generation completed successfully!")
        print(f"Output directory: {agent.output_dir}")
        print(f"To build HTML documentation, run: python {agent.output_dir}/build_docs.py")
        
    except Exception as e:
        logger.error(f"Documentation generation failed: {e}")
        if args.verbose:
            import traceback
            traceback.print_exc()
        sys.exit(1)

if __name__ == "__main__":
    main()

