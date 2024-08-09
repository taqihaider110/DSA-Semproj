# LUDO Board Game Project

## Project Overview

This project implements the classic LUDO board game, showcasing the use of various data structures and algorithms to facilitate game functionality and mechanics. The implementation emphasizes practical application of data structures and algorithms (DSAA) concepts, particularly singly circular linked lists, to create an engaging and functional board game experience.

## Key Concepts from DSAA

- **Singly Circular Linked Lists:** Used to simulate the LUDO board, with modifications to accommodate the forks in the road near “home” lines.
- **Traversals:** Employed for piece movements across the board.
- **Optimized Algorithms:** Utilized to track pieces, manage capture states, and handle collisions between pieces.

## Goals

- **Functional Gameplay:** Create a playable version of LUDO.
- **Data Structures:** Implement features using appropriate data structures tailored to specific game requirements.
- **User Interaction:** Develop a user-friendly program that is easy to understand and interact with.
- **Modularity:** Use object-oriented programming (OOP) principles and data structures to build a modular system with reusable components.

## Specifications

- **Modular Approach:** 
  - Developed multiple libraries for specific functionalities, promoting code reuse and separation of concerns.
- **Data Structures:**
  - Custom linked lists and structures simulate the LUDO board and manage game logic.
- **Algorithmic Approach:**
  - Implemented optimized algorithms to handle game scenarios, minimizing unnecessary calculations.

## Pros

- **Colored Board:** Visual representation of the board with colors showing each move.
- **Accurate Tracking:** Real-time updates of piece locations as they move.
- **Capture Logic:** Proper handling of piece captures and relocations to a jail.
- **Move Validation:** Prevention of standstills and infinite loops with invalid move logic.
- **Validation Checks:** Handles invalid selections and other game validations.

## Cons

- **Piece Movement Visibility:** Movement of pieces is not shown by color on the board.
- **Tracking Positions:** Requires tracking of pieces based on relative positions from their starting points.
- **Position Clarity:** Piece positions are unclear until it’s the player’s turn due to lack of color indicators.

## Milestones

1. **Game Logic:** 
   - Implemented game initialization, piece movement logic, win conditions, and basic move checks using random number generation.
2. **Board Display (Basic):** 
   - Created a basic board display to visualize layout and structure.
3. **Capture Logic:** 
   - Added logic for piece interaction, capture moves, and relocation to jail.
4. **Piece Independence:** 
   - Allowed players to choose which piece to move independently.
5. **Colored Board:** 
   - Used the `Windows.h` library to add color to the console for a more engaging visual experience.
6. **Computer-Controlled Player:** 
   - Integrated computer-controlled players using random number generation for automatic gameplay.
7. **Final Completion:** 
   - Integrated all modules into a fully functional and playable game.

Main Menu:
![Main Menu](https://github.com/user-attachments/assets/325540f9-d69b-4f53-8330-c6f87f1aaa64)

Example Turn:
![Example Turn](https://github.com/user-attachments/assets/b0be9d40-86ef-496f-863d-6e85d2c42e68)

After Turn:
 ![After Turn](https://github.com/user-attachments/assets/1a81a6db-0a61-4fbf-a711-e44964a76495)

Winner Screen:
  ![Winner Screen](https://github.com/user-attachments/assets/cf7d06df-71d1-41f2-a7d4-86c64e0f6cd2)

