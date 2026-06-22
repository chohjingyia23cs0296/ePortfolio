# Programming Techniques II

## Overview
This folder contains coursework and project artifacts for Programming Techniques II (Year 1, Semester 2). The work focuses on intermediate programming skills in C++: problem decomposition, implementation of algorithms and data structures, debugging, building console applications and producing executable deliverables for lab exercises and projects.

## Objectives
- Consolidate procedural and object-oriented programming skills in C++.
- Implement, test and debug algorithmic solutions for weekly programming problems and lab exercises.
- Build complete projects that read/write files, use modular design, and produce executable programs.
- Demonstrate ability to organise code, produce working binaries and document project deliverables.

## Folder Contents / Evidence
- paiprogrammig/  
  - Multiple assignment/source files and compiled executables (e.g., PP2_Q1_...cpp, PP3_Q1_...exe, PP4_Q1_...cpp/.exe, E2_...exe, E4_...exe, question1.exe, question2.exe, q33.exe, usequestion3.exe).  
  - Subfolders (PP1, PP2, PP3, PP4) for per-period problems and supporting files.
- y1s2/  
  - Chapter folders (chapter1..chapter9), exercises and labs (labexecercise, labexcercise2, labexcercise4).  
  - Project source and binaries: project1v2.cpp, project1v2.exe, projectv3.cpp, projectv3.exe.  
  - Test folders (test1, test2) and a final/ directory for final deliverables.
- (This readme.md) — overview and guidance for the folder contents.

Note: the repository contains both .cpp source files and compiled Windows executables (.exe) for demonstration/running results.

## What I Did
- Completed weekly programming problems and lab exercises, implementing solutions in C++ and producing working binaries to demonstrate program behaviour.
- Built and iterated on semester projects (project1v2, projectv3) that combine multiple features: file I/O, data parsing, modular functions/classes, and user interaction.
- Performed testing and debugging cycles: ran test inputs, fixed logic errors, and improved program robustness (input validation, boundary checks).
- Packaged some deliverables as executables to simplify demonstration and marking.

## Key Learning Outcomes
- Stronger proficiency in C++ syntax and idioms (functions, classes, STL usage where applicable).
- Practical experience with program structure: splitting code across files, using headers, and building projects.
- File I/O and data handling: reading/writing text files, parsing input and persisting results.
- Debugging and testing workflow: using test cases, iterating on fixes and validating edge cases.
- Basic build and release practice: creating runnable binaries for demonstration and assessment.

## Reflection
Programming Techniques II helped transition from simple scripts to larger, modular programs. Producing executable deliverables highlighted the importance of:
- Maintaining clear source code alongside compiled binaries so results can be reproduced and reviewed.
- Writing small, testable components before integrating them into a larger project.
- Documenting usage for deliverables (how to run the executables, what inputs they expect).

## Possible Improvements
- Include build instructions and toolchain notes (compiler, flags, OS) and add Makefiles or a simple build script so others can rebuild the executables from source.
- Prefer storing source-first and avoid committing large binaries (.exe). Provide a release or a separate dist/ folder for optional binaries.
- Add short README files inside key subfolders (paiprogrammig/, y1s2/, project folders) describing purpose and how to run each program.
- Add sample input files and expected output for automated or manual testing.
- Consider adding unit tests or simple test harnesses to make regression testing easier.
- Add comments and docstrings in source files to explain algorithms and non-obvious implementation details.

