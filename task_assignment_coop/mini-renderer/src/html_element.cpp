#include <iostream>
#include <string>
#include <string_view>
#include "html_element.h"

void HTMLElement::addChild(const HTMLElement& element) {
    children.push_back(element);
}

void HTMLElement::render() const {
    // TODO: Add implementation
    //std::cout << "Render not yet implemented." << std::endl;
    size_t currentIndent = 0; 
    indentModel(currentIndent); 
}
void HTMLElement::indentModel(int indent) const {

    for (int i = 0; i < indent; i++) { // indents for the level
        std::cout << "  "; 
    }

    std::cout << name; 
    if (!textContent.empty()) {
        std::cout << ": " << textContent; // add text content
    }

    std::cout << std::endl;

    for (auto& child: children) {
        child.indentModel(indent + 1);   // recursively indent all children
    }

}

