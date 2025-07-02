# Assignment deliverables

## Approach
My initial approach to this problem was to use recursion, since building a tree-like structure by adding children to each element naturally lends itself to a recursive solution. However, I quickly pivoted to using a stack after realizing how well it fits the problem of detecting and handling closing tags. The stack allows me to efficiently keep track of the current element context, making it straightforward to maintain correct parent-child relationships as the HTML is parsed.

## Design choices
I chose to use a stack to track the most recent parent element while parsing the HTML. When the parser encounters an opening tag, it creates a new element and pushes it onto the stack. When a closing tag is found, it pops the corresponding element off the stack. This approach ensures that the stack always holds the current path of nested elements, making it efficient to attach children to their appropriate parents. The parsing logic is handled by identifying four main cases: opening tags, closing tags, text content, and whitespace. By leveraging the stack to maintain pointers to elements in the tree, adding children becomes straightforward and time efficient, since both push and pop operations are done in constant time. 

## Limitations
However, a limitation to this design is the assumption that every opening tag has a corresponding closing tag. Void elements such as ```<img>``` or ```<input>``` and self closing tags like ```<br/>``` do not follow the standard open-close pair. Since the stack relies on explicit closing tags to maintain proper nesting, handling these cases would require additional logic to avoid misinterpreting the HTML structure or leaving elements incorrectly on the stack.
