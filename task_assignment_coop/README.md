# Take-Home Assignment: Mini Webpage Renderer

## Overview

The goal of this task is to evaluate your proficiency in C++, particularly your ability to write clean, modular, and maintainable code. This assignment involves creating a simplified web page renderer that parses and "renders" a basic HTML-like structure. We understand that your time is valuable; this task is designed to be completed in about 2 hours.

## Task

Your task is to build a minimal webpage renderer that can parse a simple HTML-like input and outputs a text-based "rendered" version of the document structure.

### Input

The program accepts a file of HTML-like content, which includes basic elements like <html>, <head>,
<title>, <body>, <h1>, and <p>. It does not need to handle attributes or edge cases. The input will be well-formed and valid, with proper nesting of tags.

Here's an example of such input:

```html
<html>
  <head>
    <title>Test Page</title>
  </head>
  <body>
    <h1>Hello, World!</h1>
    <p>This is a test paragraph.</p>
  </body>
</html>
```

### Parsing

The program should parse the input into a structure that represents the hierarchy of the HTML-like document. You can think of it as building a simple DOM (Document Object Model), where each tag corresponds to an element in the hierarchy.

### Output

The program should produce a text-based rendering of the HTML structure. For example, given the input above, the output could look like this:

```plaintext
html
  head
    title: Test Page
  body
    h1: Hello, World!
    p: This is a test paragraph.
```

You are free to define your own output format, but the important part is to show the hierarchy of elements and their contents.

## Requirements

- The program must be written in C++.
- The code should demonstrate good object-oriented design. You are encouraged to use classes to represent HTML elements and their relationships.
- The program must manage memory appropriately. You can use smart pointers, RAII principles, or manual memory management as long as it's correctly handled.
- The program must free all memory it allocated during execution.

## Deliverables

1. Please provide the source code as a zip file or link to a public repository (eg. on GitHub).
2. Include a brief explanation of your approach, design choices, and/or any limitations of your solution.

Good luck, and we look forward to reviewing your submission!

## Development

A projet scaffold has been provided to help you get started. You task is to implement the `HTMLParser::parse` and `HTMLElement::render` functions in `mini-renderer`. You are free to modify the existing code or add new classes as needed.

### Prerequisites

Make sure you have the following installed on your system:

- A C++ compiler (eg. g++, clang)
- CMake (minimum version 3.10)

### Build

To compile the project, you can use the provided CMakeLists file.

```bash
cd mini-renderer
mkdir build
cd build
cmake ..
make
```

### Run

To run the program, execute the program binary:

```bash
./mini-renderer ../example.html
```

To run the tests, execute the compiled test binary:

```bash
./test
```
