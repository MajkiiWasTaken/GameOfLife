# Game of Life

![Platform](https://img.shields.io/badge/platform-Windows-blue)
![Language](https://img.shields.io/badge/language-C-00599C)
![Type](https://img.shields.io/badge/type-Cellular%20Automaton-orange)
![Status](https://img.shields.io/badge/status-Completed-brightgreen)

### Overview

**Game of Life** is a console-based implementation of **Conway's Game of Life** written in **C** for Windows.

The simulation demonstrates how a set of simple rules can generate surprisingly complex and emergent behavior. Each execution starts with a randomly generated population of cells, creating a unique simulation every time.

---

### Simulation Preview

The application renders the simulation directly in the Windows console.

Features include:

* Randomized initial generation
* Real-time simulation updates
* Generation counter
* Alive cell statistics
* Framed simulation area

---

### Features

#### Cellular Simulation

* Random generation of the initial population
* Automatic evolution of generations
* Neighbor counting based on the eight surrounding cells
* Simultaneous updates using a secondary grid

#### Statistics

* Current generation display
* Total number of alive cells
* Continuously updated simulation information

#### Console Interface

* Clear bordered playfield
* Lightweight text-based rendering
* Automatic screen refresh every 200 milliseconds

---

### How It Works

The simulation follows Conway's original rules.

#### Core Workflow

1. Generate a random starting population.
2. Display the current state of the grid.
3. Count the living neighbors of each cell.
4. Compute the next generation.
5. Replace the old generation with the new one.
6. Update statistics and repeat.

---

### Rules of the Game

#### Alive Cell

* Survives with **2 or 3 living neighbors**
* Dies from **underpopulation** if it has fewer than 2 neighbors
* Dies from **overpopulation** if it has more than 3 neighbors

#### Dead Cell

* Becomes alive if it has **exactly 3 living neighbors**

All cells are updated simultaneously between generations.

---

### Data Flow

1. Application starts.
2. The grid is populated randomly.
3. The current generation is rendered.
4. Neighbor counts are calculated.
5. A new generation is produced.
6. Statistics are updated.
7. The simulation continues indefinitely.

---

### Requirements

* Windows
* Visual Studio 2022 or newer
* MSVC compiler

---

### Getting Started

1. Clone the repository.
2. Open the project in Visual Studio.
3. Build the solution.
4. Run the executable.
5. Observe how complex behavior emerges from simple rules.

---

### Technologies Used

* **C**
* **Windows Console API**
* `stdio.h`
* `stdlib.h`
* `time.h`
* `windows.h`

---

### Notes

The simulation uses a secondary grid to calculate future generations, ensuring that all cells are updated simultaneously without affecting neighbor calculations.

Since the initial population is generated randomly, every execution produces a different outcome.

---

### Author

**MajkiiWasTaken**
