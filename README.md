# Computación Paralela

> Coursework in C++ exploring how memory access patterns and the CPU cache hierarchy affect performance in numerical kernels.

## Description

This repository contains exercises from a **Parallel Computing** university course.
The current programs focus on the foundations of high-performance computing: how the
**cache hierarchy** and **data locality** impact the runtime of classic numerical
kernels such as matrix–vector and matrix–matrix multiplication.

Each exercise measures and compares the execution time of two mathematically
equivalent implementations that differ only in the order in which memory is
traversed, demonstrating the practical cost of cache misses.

> **Note:** These exercises are currently **sequential** (single-threaded). They use
> only the C++ standard library and `std::chrono` / `clock()` for timing. No parallel
> runtime (OpenMP, MPI, pthreads or CUDA) is used yet in the code present in this
> repository.

## Exercises

### `bucles-cache.cpp` — Loop ordering in matrix–vector multiplication

Computes `y = A · x` for a `20000 × 20000` matrix using `std::vector` and times two
different loop nestings:

| Loop order   | Access pattern                                            |
| ------------ | --------------------------------------------------------- |
| `i`, `j`     | Row-major traversal of `A` — cache-friendly               |
| `j`, `i`     | Column-major traversal of `A` — poor spatial locality     |

The program prints the elapsed time (in nanoseconds) for each version, illustrating
how **loop interchange** and row-major storage affect cache behavior.

```
PRIMER BUCLE: <time>
SEGUNDO BUCLE: <time>
```

### `tarea-2` — Cache blocking (tiling) in matrix multiplication

A C++ source file (no extension) that multiplies two random `800 × 800` integer
matrices and compares two strategies:

- **`matrixProduct`** — the classic triple-nested `i, j, k` multiplication.
- **`matrixBlockProduct`** — a **blocked / tiled** multiplication that partitions the
  matrices into `MAX / 4` sub-blocks to improve temporal and spatial locality.

Helper functions `fillMatrix` (random fill with `rand() % 10`) and `printMatrix` are
also included. Timing is done with `clock()` and reported in seconds.

```
Normal Matrix Product: <time>
Matrix Product by Block: <time>
```

> In the current `main`, the call to the non-blocked `matrixProduct` is commented out,
> so only the blocked version is timed by default. Uncomment the call in `main` to
> compare both.

## Tech Stack

- **Language:** C++ (uses `std::vector`, `std::chrono`, and C-style arrays)
- **Standard:** C++11 or later (required by `<chrono>`)
- **Compiler:** any modern C++ compiler such as `g++` or `clang++`
- **Timing:** `std::chrono::high_resolution_clock` (`bucles-cache.cpp`) and
  `clock()` from `<ctime>` (`tarea-2`)

## Build & Run

There is no build system in the repository; compile each file directly.

### `bucles-cache.cpp`

```bash
g++ -O2 -std=c++11 bucles-cache.cpp -o bucles-cache
./bucles-cache
```

### `tarea-2`

Because `tarea-2` has no `.cpp` extension, tell the compiler it is C++ source with
`-x c++`:

```bash
g++ -O2 -std=c++11 -x c++ tarea-2 -o tarea-2-bin
./tarea-2-bin
```

> **Tip:** `bucles-cache.cpp` allocates a `20000 × 20000` matrix of `double`
> (~3.2 GB). Reduce the `MAX` macro if your machine has limited RAM. Enabling
> optimizations (`-O2`) makes the cache effects clearer and the runs faster.

## Project Structure

```
computacion-paralela/
├── bucles-cache.cpp   # Loop-ordering effect in matrix–vector product (y = A·x)
└── tarea-2            # Cache blocking / tiling in matrix–matrix product (C++ source)
```

## License

No license file is currently provided with this repository.
