#include <iostream>
#include <string_view>
#include "html_parser.h"
#include <stack>


HTMLParser::HTMLParser(std::string_view htmlContent) : content(htmlContent) {}

HTMLElement HTMLParser::parse() {
    size_t pos = 0; 
    std::stack<HTMLElement*> elements; 
    HTMLElement root(""); 
    elements.push(&root); 
    
    while (pos < content.size()) {
        if (std::isspace(content[pos])) {
            // CASE 1: spaces
            pos++; 
        } else if (content[pos] == '<' && content[pos+1] != '/') {
            // CASE 2: opening tag
            pos++; // <
            size_t start = pos; 
            while (content[pos] != '>') { 
                pos++; 
            }
            std::string_view name = content.substr(start, pos - start); // get tag name
            pos++; // > 
            HTMLElement element(name); 
            elements.top()->addChild(element); // parent is element from top of stack
            HTMLElement* newChild = const_cast<HTMLElement*>(&elements.top()->getChildren().back()); // get pointer to child
            elements.push(newChild); 

        } else if (content[pos] == '<' && content[pos+1] == '/') {
            // CASE 3: closing tag
            pos += 2; // </
            while (content[pos] != '>') {
                pos++;
            } 
            pos++; // > 
            elements.pop();  
        } else {
            // CASE 4: closing tag
            // text: set text for element at stack.top()   
            size_t start = pos; // first char of tag
            while (content[pos] != '<') { 
                pos++; 
            }

            // set text for an element
            std::string text = content.substr(start, pos - start); 
            if (!text.empty() && !elements.empty()) {
                elements.top()->setTextContent(text); 
            }
        }
    }
    return root.getChildren().front(); // return the root of tree (all children added)
}
