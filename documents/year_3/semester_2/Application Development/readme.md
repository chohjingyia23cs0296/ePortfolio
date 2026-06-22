# Application Development

## Overview

This folder contains evidence and documentation for my Application Development work in Year 3 — Semester 2. It brings together lab work and a larger project where I designed, implemented, and tested cross-platform mobile applications using Flutter, with Firebase as the backend. The primary project in this folder is "eHadir" — an attendance system — and the lab work includes a Flutter starter project and related assignment materials.

## Objectives

- Understand practical application development workflows for mobile and web.
- Design and implement app features using Flutter and Firebase.
- Apply state management patterns and integrate backend services.
- Practice testing, debugging, and deployment preparation for cross-platform apps.
- Document development process and collect evidence of learning and progress.

## Folder Contents / Evidence

- lab 1/
  - Lab Assignment 1 WEB DEVELOPMENT (PDF) — lab brief and instructions.
  - assignment1/ — Flutter starter project:
    - README.md (project overview & getting started)
    - pubspec.yaml / pubspec.lock
    - platform folders (android, ios, web, macos, windows, linux)
    - test/ (placeholder for unit/widget tests)
- project/
  - Lab2_Proposal_Section01_DevSync.pdf — project proposal section.
- This top-level readme.md (this file) — summary, reflections and suggestions for improvement.

## What I Did

- Lab work:
  - Completed Lab Assignment 1 materials and set up a Flutter starter project (assignment1).
  - Configured project dependencies in pubspec.yaml and generated lock file.
  - Created a project skeleton with platform folders and initial README.

- Project — eHadir (Attendance System):
  - Designed app features and UI flows for scheduling, attendance taking, and discipline reports.
  - Implemented core functionality using Flutter:
    - Schedule booking with conflict prevention.
    - My Schedule view with direct actions for taking attendance.
    - Attendance tracker for lecturers to log presence.
    - Discipline reporting workflow routed to Program and Department Heads.
    - Role-based profile screens (student, lecturer, program head).
  - Integrated Firebase services:
    - Firebase Authentication for secure sign-in.
    - Cloud Firestore for real-time storage of users, schedules, attendance and reports.
  - Applied Riverpod for state management and FL Chart for analytics visualization.
  - Documented project structure and tech stack in the project README.
  - Prepared project proposal and planning documentation (Lab2_Proposal PDF).

## Key Learning Outcomes

- Gained hands-on experience with Flutter app architecture and cross-platform development.
- Learned how to integrate Firebase Authentication and Cloud Firestore with a mobile app.
- Practiced state management using Riverpod and how it simplifies data flows and testing.
- Understood scheduling logic and strategies for preventing booking conflicts.
- Built UI screens for multiple user roles and learned to manage role-based views.
- Improved debugging and testing skills on multiple platforms (mobile and web).
- Practiced documenting project decisions, structure, and development evidence.

## Reflection

Working on both lab assignments and the eHadir project helped me move from simple examples to a real, feature-driven application. I learned the importance of planning (designing data models and user flows) before implementing features, and how state management patterns (like Riverpod) make complex UIs more maintainable.

Challenges I encountered included handling concurrent schedule updates, designing secure and efficient Firestore rules, and balancing feature scope with available time. Iterative testing on different platforms revealed platform-specific UI and permissions quirks that improved my cross-platform development awareness.

## Possible Improvements

- Expand automated tests:
  - Add unit tests for business logic (scheduling conflict logic).
  - Add widget and integration tests for key flows (login, book schedule, take attendance).
- UI/UX polish:
  - Improve visual design, accessibility (contrast, labels, screen reader support), and responsive layouts.
- Offline support & sync:
  - Add local caching and offline-first sync for unreliable networks.
- Performance & cost optimizations:
  - Optimize Firestore read/write patterns to reduce costs and latency.
- Security:
  - Harden Firebase security rules and validate inputs client- and server-side.
- CI/CD:
  - Set up continuous integration to run tests and code analysis on push/PR, and automations for building release artifacts.
- Feature expansion:
  - Reporting dashboards for administrators, exportable attendance reports, notifications for schedule changes.

---

If you’d like, I can commit this README.md into the repository at documents/year_3/semester_2/Application Development/readme.md. Would you like me to update the file in the repo now?
