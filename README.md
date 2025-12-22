# CS 210 Portfolio Project Reflection

## Summarize the project and what problem it was solving.
This project is an item-tracking program for the Corner Grocer. The store provides a text file containing a list of items purchased throughout the day, and the program analyzes that data to show how frequently each item appears. The program allows the user to view the frequency of a specific item, display all items with their purchase counts, and display a histogram representation of those counts. This helps the store make decisions about organizing inventory and improving the customer shopping experience.

## What did you do particularly well?
I did well designing the program so it cleanly separates responsibilities: reading and processing the input file, storing counts, and displaying results through a menu-driven interface. I also focused on producing clear output formatting for the user, including the histogram view. In addition, I used consistent naming and structured control flow so the program behavior is easy to follow.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
One improvement would be stronger input validation and error handling for both menu selections and item searches (for example, handling empty input, unexpected characters, or missing files more gracefully). Another improvement would be making item matching case-insensitive and trimming whitespace to prevent mismatches due to formatting. I could also improve efficiency by using `unordered_map` for faster lookups and adding functions to avoid repeated code. These changes would make the program more reliable, easier to use, and more resilient to real-world messy data.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging part was building the file-processing logic in a way that correctly counts items while also working smoothly with the menu options and output requirements. I overcame this by breaking the problem into smaller steps: reading each line, updating a count structure, then writing small test runs to confirm each output format. I relied on debugging (printing intermediate results), course resources, and C++ reference documentation. Moving forward, I’m adding resources like cppreference, IDE debugging tools, and structured test cases to my support network.

## What skills from this project will be particularly transferable to other projects or course work?
This project strengthened skills that carry directly into other software projects: file I/O, data processing, using collections/maps, writing modular functions, and building interactive menu-based programs. It also reinforced problem decomposition, debugging strategies, and writing code that matches specific requirements—skills that apply to both future coursework and professional development.

## How did you make this program maintainable, readable, and adaptable?
I kept the program maintainable by organizing code into functions with clear names and single responsibilities, and by using consistent formatting and comments where needed. The menu logic is centralized so updates to user options can be made in one place. The program is adaptable because the input data source can be changed easily (by swapping the file), and the counting/display logic can be extended without rewriting the entire structure.
