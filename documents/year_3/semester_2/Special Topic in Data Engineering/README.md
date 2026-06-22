# 🚀 Special Topic in Data Engineering (SECP3843)

**Author:** Choh Jing Yi (Matric No. A23CS0296)  
**Course:** Special Topic in Data Engineering 

## 📌 Repository Overview

This repository contains a comprehensive collection of data engineering pipelines, deep learning implementations, and technical research conducted throughout the course. The projects showcase hands-on experience in building scalable Extract, Transform, Load (ETL) systems, designing cloud-native data architectures, and implementing artificial intelligence algorithms.

---

## 📂 Projects & Coursework

### 1. Azure End-to-End Data Pipeline (Tutorial 1)
- **Overview:** An automated, cloud-native data pipeline built using the Medallion Architecture (Bronze, Silver, Gold layers) to ensure data quality and traceability.
- **Tech Stack:** Azure Data Factory, Azure Databricks (PySpark), Azure Synapse Analytics, Power BI.
- **Highlights:** Successfully orchestrated on-premises SQL data ingestion, resolved complex Azure firewall/connectivity issues, and served refined data through an interactive Power BI dashboard.

### 2. Apache Spark ETL Pipeline (Tutorial 2)
- **Overview:** A professional-grade local ETL pipeline designed to process over 2.2 GB of raw Brazilian School Census (Censo Escolar) microdata.
- **Tech Stack:** Apache Spark (PySpark), PostgreSQL, Python 3.11, Jupyter Notebook.
- **Highlights:** Leveraged distributed processing to overcome Pandas' memory limitations. Converted raw CSVs into highly compressed Parquet format (reducing data footprint from ~2.46 GB to ~322 MB) and structured the output into a query-optimized Star Schema before loading into PostgreSQL via JDBC.

### 3. Image Classification with CNNs (Tutorial 3)
- **Overview:** A deep learning project evaluating computer vision models using the CIFAR-10 dataset.
- **Tech Stack:** TensorFlow, Keras, Python.
- **Highlights:** Transitioned from a baseline Artificial Neural Network (ANN) to a robust Convolutional Neural Network (CNN). Implemented advanced techniques like Data Augmentation, Dropout, and Batch Normalization to eliminate overfitting and significantly boost classification accuracy and mathematical confidence.

### 4. AI-Assisted ETL Pipeline (Tutorial 4)
- **Overview:** An exploration of AI agents acting as "construction assistants" to automate data engineering workflows.
- **Tech Stack:** Express.dev (Nexla), WeatherAPI, Snowflake, Firebase Firestore.
- **Highlights:** Demonstrated how natural language prompting can accelerate pipeline construction, automate API data extraction, and flatten nested JSON data. Highlighted the critical shift of the data engineer's role toward becoming a "system architect" overseeing AI-generated processes.

### 5. Technical Report: Data Engineering Ecosystem
- **Overview:** An academic analysis of the evolving Data Engineering Ecosystem and the Modern Data Stack (MDS).
- **Key Themes:** The paradigm shift from ETL to ELT, the rise of Data Lakehouses (decoupling compute from storage), and the adoption of decentralized ownership models like Data Mesh.
- **Highlights:** Provided strategic recommendations for enterprises to build resilient architectures using cloud scalability, unified metadata management, and AI-driven pipeline monitoring.

---

## 💡 Key Learnings & Reflection

Building this repository provided me with practical, hands-on experience in constructing scalable, end-to-end data pipelines from scratch. 

A significant portion of my growth came from meticulous problem-solving and troubleshooting environment-specific challenges. I successfully resolved Python worker crashes in PySpark by aligning environment variables, corrected complex JDBC driver pathing issues, and navigated cloud security rules in Azure. These projects have given me a deep understanding of big data frameworks, relational data modeling, and the critical role of infrastructure and security in modern data engineering.
