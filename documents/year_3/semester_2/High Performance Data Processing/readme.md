# High Performance Data Processing

## Overview
This folder contains coursework and project deliverables for the High Performance Data Processing module (Year 3, Semester 2). The work focuses on designing, implementing and evaluating high-performance data-extraction pipelines and large-scale data processing. The primary project is a web crawler that extracts property listings from Mudah.my, collects and cleans a large dataset, and compares baseline and optimized crawling approaches.

## Objectives
- Implement a reliable web crawler to extract property listings at scale.
- Collect and store a large, structured dataset (target: ≥ 100,000 structured records).
- Clean and preprocess the raw dataset for analysis (deduplication, normalization).
- Apply performance optimizations (asynchronous IO, concurrency control, batch writes).
- Measure and compare baseline vs optimized crawler performance (time, throughput, memory).
- Produce reproducible analysis and documentation (notebooks, reports, charts).

## Folder Contents / Evidence
- Assignment 1/
  - HPDP__Choh_Jing_Yi.pdf — assignment report (individual).
- Assignment 2: Mastering Big Data Handling/
  - big_data (1).ipynb — Jupyter notebook with code and analysis.
  - big_data.md — exported analysis and explanations.
- EXERCISE4/
  - WEEK 4 - EXERCISE.pdf — exercise worksheet/solutions.
- web_crawler_project/
  - readme.md — detailed project README (implementation, dataset description, tools).
  - requirements.txt — Python dependencies.
  - scripts/ — crawler and utility scripts (baseline and optimized crawlers, cleaning, chart generation).
  - data/ — raw and cleaned CSV datasets (baseline/optimized outputs and final cleaned dataset).
  - images/ — generated charts and visualizations (performance comparisons, dataset analysis).

## What I Did
- Implemented a baseline sequential crawler to extract listing pages and save raw CSV results.
- Built an optimized asynchronous crawler using aiohttp + asyncio with concurrency control and batch writes to increase throughput and reduce IO bottlenecks.
- Implemented partitioning and batching strategies to scale collection and reduce memory pressure.
- Cleaned the raw dataset: deduplication, normalization of prices and sizes, removal of invalid or incomplete records.
- Profiled and compared performance (execution time, throughput, memory usage) between baseline and optimized approaches and generated comparative charts.
- Compiled findings into a Jupyter notebook, markdown write-up and a PDF report.

## Key Learning Outcomes
- Practical application of asynchronous programming (aiohttp, asyncio) to improve web-scraping throughput.
- Experience with concurrency limits, polite crawling (rate-limiting, retries), and batching strategies to balance speed and resource usage.
- Methods for profiling and measuring performance (time, memory, CPU) and interpreting results to guide optimizations.
- Large-scale data cleaning techniques to transform messy real-world scraped data into a reliable dataset for analysis.
- Reproducible research practices: documenting dependencies, scripts, and steps to reproduce results.

## Reflection
The optimized asynchronous crawler significantly improved throughput compared to the baseline sequential approach, validating the benefit of async IO for large-scale scraping. Major challenges included handling inconsistent HTML structures across listings, transient network errors, duplicate records, and balancing politeness with performance. Data cleaning was essential to produce accurate analytic results; many insights depended on careful normalization and validation of fields such as price and size.

## Possible Improvements
- Respectfulness & compliance: add robust robots.txt parsing and adaptive politeness strategies (dynamic delays, adaptive backoff).
- Distributed crawling: scale across multiple machines or workers (e.g., queue-based workers, Celery, Kafka) to collect larger datasets reliably.
- Persistent scalable storage: use a database or object store (PostgreSQL, MongoDB, or cloud storage) to improve reliability and support resumable crawls.
- Enhanced robustness: add circuit-breakers, more sophisticated retry/backoff strategies, and structured logging/monitoring (metrics, alerts).
- Testing & CI: add unit and integration tests for parsing logic and CI jobs to run small validation crawls.
- Containerization and reproducibility: provide Dockerfile and deployment instructions for consistent environments.
- Expanded analysis: add geospatial visualizations, time-series trends and automated dashboards for dataset monitoring.

````
