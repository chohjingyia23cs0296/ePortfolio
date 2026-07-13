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

### 6. Individual Project: Scalable Traffic Safety Analytics using Apache Spark
- **Overview:** An end-to-end data engineering project that develops a scalable traffic accident analytics platform using Apache Spark and the Medallion Data Lakehouse Architecture. The project integrates multiple heterogeneous data sources, including the US Accidents dataset, the Nager.Date Public Holiday API, and U.S. Census population data, to support predictive analytics and interactive business intelligence.
- **Tech Stack:** Apache Spark (PySpark), Delta Lake, Spark MLlib, Power BI, Python.
- **Highlights:**
  - Designed and implemented a complete Medallion Architecture consisting of Bronze, Silver, and Gold layers.
  - Integrated CSV and JSON data sources into a unified analytical framework using PySpark.
  - Performed large-scale data cleaning, transformation, feature engineering, and dimensional modelling.
  - Developed a Star Schema with one fact table and two dimension tables to support efficient analytical queries.
  - Integrated a Random Forest Classifier using Spark MLlib to predict traffic accident severity.
  - Built an interactive Power BI dashboard for accident trend analysis, severity prediction, holiday impact analysis, and population-normalized traffic statistics.

---

## 💡 Key Learnings & Reflection

This course shows my learning journey from theory to practice in data engineering. Through the technical report, I learned core concepts like ELT, Lakehouse, cloud architecture, and why modern data systems need scalability and good governance. Through the tutorials, I gained hands-on skills in Azure, Apache Spark, ETL design, CNN models, and AI-assisted pipeline development. I also learned to solve real technical issues, not just follow steps. Through the individual project, I learned to build a full end-to-end solution: data integration, Medallion architecture, feature engineering, machine learning, and dashboard reporting. This experience helped me think more like a complete data engineer.


