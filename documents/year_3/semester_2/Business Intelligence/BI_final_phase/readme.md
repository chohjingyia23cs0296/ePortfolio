# Business Intelligence Analytics for U.S. E-Commerce Performance Optimization (2019–2025)

## Overview
This project applies Business Intelligence (BI) techniques to analyze a synthetic dataset of 1 million U.S. e‑commerce orders from 2019 to 2025. Using Alteryx Designer for data preparation and Power BI for visualization, the project transforms raw transactional data into actionable insights to help businesses understand revenue drivers, delivery bottlenecks, and customer payment behaviors.

## Objectives
- Optimize logistics operations by identifying root causes and geographic locations of delivery delays.  
- Improve profitability by evaluating total revenue across product categories and identifying key contributors and risks.  
- Understand customer behavior by analyzing payment method preferences and correlations with satisfaction.  
- Enable data-driven decisions by developing interactive storyboards and dashboards for executive stakeholders to monitor KPIs.

## Folder Contents / Evidence
- `dataset/` — Raw CSV files (Orders, Customers, Products, Payments, Sellers, Reviews, Delivery).  
- `alteryx_workflows/` — Alteryx workflow files (.yxmd) used for data integration, cleaning, and transformation.  
- `dashboards/` — Power BI files (.pbix) and exported PDF reports.  
- `images/` — Screenshots of workflows and dashboards used in this README.  
- `BI_Project_Final_Report.pdf` — Comprehensive final report with methodology, insights, and recommendations.

## What I Did

### Project structure and collaboration
- Worked as part of a group; the analytical workload was divided into three main modules. I focused on data integration, cleaning, and visualization while contributing to final synthesis and interpretation.

### Data Integration & Cleaning (Alteryx)
- Imported multiple structured CSV files and performed data cleansing:
  - Removed duplicates and handled null / malformed values.
  - Standardized text formats and converted raw text fields to appropriate DateTime and numeric types.
- Resolved one-to-many relationships (e.g., split payments) by grouping and aggregating via `order_id` before joining, preventing duplication of revenue figures.
- Built a repeatable ETL workflow to produce a single, analysis-ready dataset.

_(Replace with your Alteryx workflow screenshot)_

![Alteryx workflow screenshot](images/alteryx_workflow.png)

### Data Modeling & Visualization (Power BI)
- Built interactive dashboards with KPIs such as:
  - Total Revenue
  - Total Orders
  - Average Review Score
  - Delivery Delay Rate
  - Payment Method Distribution
- Designed the storyboard "The E‑Commerce Customer Journey" to guide stakeholders through:
  - Revenue trends over time
  - Payment distributions and customer behavior
  - Regional logistics delays and hotspots
- Applied visualization best practices (e.g., donut charts for payment distribution, bar charts for category revenue, matrix tables for dense geographic data).

_(Replace with your main Power BI dashboard/storyboard screenshot)_

![Power BI dashboard screenshot](images/powerbi_dashboard.png)

## Key Learning Outcomes
- **ETL proficiency:** Hands-on experience using Alteryx Designer to clean, transform, and join messy, relational datasets into an analysis-ready source of truth.  
- **Data visualization best practices:** Learned to choose appropriate charts and layouts to present insights clearly and avoid misleading or cluttered visuals.  
- **Business acumen:** Improved ability to translate metrics into recommendations (e.g., suggesting warehouse capacity changes based on regional delay patterns).  
- **Interactive storytelling:** Gained experience building Power BI storyboards and slicers to allow stakeholders to explore data dynamically.

## Reflection
This project bridged technical data processing and strategic business insight. A major challenge was handling one-to-many relationships (such as split payments) that can cause duplication when joining tables; aggregating these prior to joins was a crucial step. The final dashboard successfully told a coherent story: Electronics were the primary revenue drivers, credit cards dominated payment methods, and high-volume states like California and New York experienced the most logistical strain. The work demonstrated how reproducible ETL and clear visual storytelling can turn large transactional datasets into actionable decisions.

## Possible Improvements
- Predictive analytics: Integrate machine learning (e.g., Python or Alteryx predictive tools) to forecast revenue and anticipate delivery bottlenecks, especially for holiday seasons.  
- Deeper geographic drilling: Add interactive maps in Power BI to analyze delays at city or ZIP-code level rather than state-level only.  
- Cost analysis: Incorporate shipping costs and marketing spend to calculate ROI and Customer Acquisition Cost (CAC).  
- ETL validation: Implement automated schema and data-quality checks in the workflow to detect unexpected changes or null spikes earlier.  
- Dashboard interactivity: Add drill-throughs, tooltips with summary metrics, and advanced filtering to enable deeper ad-hoc exploration by stakeholders.

---

If you'd like, I can add the actual screenshots to `images/` and insert them into this README, or save this content directly to the repository (this will overwrite the current README in the folder). Tell me which you'd prefer.