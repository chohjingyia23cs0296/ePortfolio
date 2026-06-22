## ☁️ Tutorial 1: Microsoft Azure - End-to-End Data Engineering Pipeline

### 📌 Project Overview

The core objective of this project is to address a critical business need: analyzing customer demographics, specifically gender distribution, to understand how it influences product purchases. To achieve this, a comprehensive end-to-end data pipeline was built on Microsoft Azure to extract customer and sales data from an on-premises SQL database, transform it in the cloud, and generate actionable insights.

### 🛠️ Description of the Solution

To process the data efficiently and maintain a clean organizational structure, the solution implements a **Medallion Architecture** integrated with Azure Data Lake Storage Gen2.

* **Bronze Layer (Raw):** Azure Data Factory (ADF) extracts the data directly from the on-premises SQL database and loads it into the Bronze container in raw Parquet format.

* **Silver Layer (Cleansed):** Azure Databricks performs minor data cleansing, such as parsing messy timestamp formats and standardizing them into a clean `yyyy-MM-dd` date format, saving the results as highly optimized Delta files.

* **Gold Layer (Analytics-Ready):** Final structural transformations are applied in Databricks (e.g., converting PascalCase column names to snake_case for query-friendliness). Azure Synapse Analytics then creates logical SQL views over these refined Delta tables to serve the data seamlessly to Power BI.


### 💻 Technology Stack

* **Microsoft SQL server:** The source system was Microsoft SQL server to simulate an on-premise operational database. It hosted AdventureWorksLT2025 database comprising customer, product, and sales related tables. 

* **Azure Data Factory (ADF):** The main orchestration and ingestion service, utilizing a Self-Hosted Integration Runtime (SHIR) to enable safe communication between the on-premises SQL Server and the cloud.


* **Azure Data Lake Storage Gen2:** Provides the stratified storage foundation for the Bronze, Silver, and Gold layers.


* **Azure Databricks:** Used for executing PySpark notebooks to clean, standardize, and transform the data.


* **Azure Synapse Analytics:** Provides the structured analytics layer using serverless SQL pools to create queryable views.


* **Azure Key Vault:** Ensures secure governance by storing sensitive credentials, such as the SQL Server password, preventing hardcoded authentication in the pipeline logic.


* **Microsoft Power BI:** Used for the final visualization layer.


### 🏗️ Data Pipeline Architecture
![Azure Pipeline Architecture](https://raw.githubusercontent.com/chohjingyia23cs0296/SPECIAL-TOPIC-IN-DATA-ENGINEERING/main/Tutorial%201%20-%20MICROSOFT%20AZURE/images/azure_data_pipeline.png)

The architecture follows a standard ETL workflow. Data is ingested dynamically using a `ForEach` activity in ADF, stored as raw Parquet files, transformed via Databricks notebooks triggered by ADF, and finally imported into Power BI via Synapse Serverless endpoints.

### 📊 MS Power BI Dashboard
![Power BI Dashboard](https://raw.githubusercontent.com/chohjingyia23cs0296/SPECIAL-TOPIC-IN-DATA-ENGINEERING/main/Tutorial%201%20-%20MICROSOFT%20AZURE/images/Power%20BI%20Dashboard.png)

The interactive dashboard highlights key business indicators, tracking 296 products and over 7.08M in total sales.

* **Demographic Insights:** Reveals that male customers dominate the demographic base at 58.56%.


* **Geographical Analysis:** Utilizes bubble charts to map total sales distribution across North America and Europe.


* **Interactivity:** Includes a dynamic order date filter allowing stakeholders to isolate performance metrics for specific time ranges.



### 💡 Reflection

* **What I Gained:** I learned how to build an end to end pipeline on Microsoft Azure. I followed the youtube tutorial to extract the raw data from the on premise database to clean and finally create a visual 
dashboard with power BI.I understand the Medallion Architecture which transforms step-by-step from Bronze (raw) to Silver (clean) to Gold (business-ready). I also learn practical skills in Azure Data Factory (ADF), PySpark in Databricks, and Azure Synapse Analytics. 

* **Suggested Improvements & Problem-Solving:** During configuration, I struggled with a "Login failed" error when attempting to connect to the Azure SQL Database. Through troubleshooting, I realized that the university WiFi often uses shifting IP addresses. To resolve this and ensure smoother pipeline execution in the future, I learned the importance of properly configuring server-level firewall rules and allowing Azure services to bypass gateway restrictions. Future iterations of this pipeline could benefit from automating these firewall rule updates for dynamic IP environments.
