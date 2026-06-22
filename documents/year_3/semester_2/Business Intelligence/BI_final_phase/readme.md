# Business Intelligence Analytics for U.S. E-Commerce Performance Optimization (2019-2025)

## Overview
This project applies Business Intelligence (BI) techniques to analyze a massive dataset containing 1 million U.S. e-commerce orders spanning from 2019 to 2025. As online marketplaces continue to expand, organizations must efficiently manage complex backend operations involving heavy transactional volumes, fluid product inventories, and intricate logistics networks. Without an automated BI solution, processing this sea of raw data to uncover the root causes of delivery delays, track revenue contributors, or evaluate customer patterns becomes nearly impossible.

By utilizing **Alteryx Designer** for robust Extract, Transform, Load (ETL) pipeline development and **Microsoft Power BI** for deep data modeling and interactive visualization, this project successfully transforms raw e-commerce data streams into structured, actionable business insights.

---

## Objectives
* **Identify Operational Bottlenecks:** Pinpoint the root causes and regional distribution of systemic shipping delays across the fulfillment network.
* **Optimize Category Profitability:** Evaluate revenue distribution across product sectors to safeguard top revenue streams and mitigate category concentration risk.
* **Decode Customer Payment & Satisfaction Trends:** Analyze consumer payment methods and determine how checkout choices affect transaction volumes and overall satisfaction scores.
* **Deliver Executive-Ready Visualizations:** Build an interactive data storyboard ("The E-Commerce Customer Journey") to support high-level, data-driven strategic planning.

---

## Folder Contents / Evidence
* `dataset/` - Contains the primary structured CSV source tables (Orders, Products, Customers, Payments, Sellers, Delivery, and Reviews).
* `alteryx_workflows/` - Houses the data preparation files (`.yxmd`) mapping the custom analytical data pipelines.
* `dashboards/` - Houses the interactive Power BI workbook file (`.pbix`).
* `documents/` - Contains the formal compiled documentation, phase notes, and project report.
* `images/` - Stores the workflow architecture and dashboard interface screenshots embedded below.

---

## What I Did

Operating as a collaborative three-person BI team, we modularized our engineering workflow into distinct analytical sectors to handle data cleanup and modeling parallelly:

### 1. Sales and Product Analytics (Muhammad Syahmi Faris)
* Sequentially integrated the `orders.csv`, `customers.csv`, `order_items.csv`, and `products.csv` files using strict relational table joins.
* Created calculated fields via the Formula tool to derive vital operational financial metrics, including *Profit Margin (%)*, *Discount Rate (%)*, and extracted *Order Year*.
* Aggregated overall sales performance metrics utilizing summary tools grouped cleanly by state, calendar year, and category name.

#### Sales Analytics Workflow Architecture:
![Sales and Product Analytics Workflow](images/sales_product_analytics.png)

### 2. Logistics and Delivery Analytics (Afif Shaqir Irfan)
* Cleaned and structuralized `orders.csv`, `sellers.csv`, and `order_items.csv` tables, applying aggressive filtering tools to purge missing records or corrupted timestamps.
* Engineered custom time-delta equations tracking *Days of Delay*—measuring the exact variance between the actual delivery date and the baseline estimated delivery date.
* Flagged shipping delays uniformly using Boolean indicators to accurately compile regional delay rates by individual merchant location and fulfillment state.

#### Logistics Analytics Workflow Architecture:
![Logistics and Delivery Analytics Workflow](images/logistics_delivery_analytics.png)

### 3. Customer and Payment Analytics (Choh Jing Yi)
* Resolved database grain mismatches caused by complex one-to-many relationships within split payment records.
* Prevented transaction row duplication by pre-aggregating individual transaction lines by `order_id` within Alteryx prior to merging downstream customer table rows.
* Consolidated final data models detailing total financial revenue streams and true average review score metrics mapped across individual payment channels.

#### Customer & Payment Analytics Workflow Architecture:
![Customer and Payment Analytics Workflow](images/customer_payment_analytics.png)

### 4. Interactive Dashboard & Narrative Compilation (Joint Effort)
* Connected the cleaned Alteryx outputs to Power BI to design **"The E-Commerce Customer Journey"** interactive dashboard ecosystem.
* Embedded multi-layered data slicers (Year, State, and Payment Type Filters) to empower business executives to dynamically slice and drill into the underlying transactional layers.

#### Compiled Executive Storyboard Interface:
![E-Commerce Customer Journey Dashboard](images/ecommerce_customer_journey_dashboard.png)

---

## Key Learning Outcomes
* **Advanced Data Pipeline Engineering:** Mastered data blending inside Alteryx, gaining experience resolving real-world database anomalies, structural column mismatches, and data duplication threats.
* **Defensive Visual Modeling & Best Practices:** Acquired design frameworks within Power BI, discovering how to avoid cluttered visualization charts and focus on scannability via high-level KPI cards and horizontal metric hierarchies.
* **Transforming Data into Actionable Strategy:** Developed corporate analytical skills to bridge the gap between technical metrics (like delivery delay timestamps) and high-impact corporate solutions (such as suggesting carrier contract overhauls).
* **Structured Collaborative Governance:** Learned to partition large-scale analytical tasks cleanly into specific, independent domain modules that seamlessly combine into a cohesive single source of truth.

---

## Reflection
This project offered a profound perspective on how uncleaned, multi-source raw enterprise data can be systematically tamed to drive core organizational decisions. One of our most rewarding breakthroughs occurred while configuring the customer payment pipeline. Initially, customers split single invoices across multiple funding options (vouchers combined with credit cards), which resulted in significant row inflation and skewed financial metrics when joined blindly. Figuring out how to build pre-aggregation blocks in Alteryx before compiling table joins was an invaluable lesson in data architecture integrity. 

Unveiling the final interactive storyboard highlighted the clear narrative hidden within the numbers: the company's dependency on Electronics for revenue (~732.78M), the dominance of credit card transactions (47.48%), and the reality that logistical strains are not isolated state problems, but systemic network challenges averaging a 9.83% delay rate nationwide.

---

## Possible Improvements
* **Integration of Machine Learning Forecasters:** Introduce predictive modeling components (such as ARIMA or Random Forest models inside Alteryx) to map seasonal demand peaks and proactively anticipate logistics bottle-necks before holiday delivery seasons.
* **Granular Spatial Mapping:** Scale geographic data tracking down from high-level state boundaries to exact regional postal zip codes using Power BI's interactive shape maps for precise delivery hub optimization.
* **Marketing & Unit Economics Expansion:** Merge customer acquisition costs (CAC) and localized marketing expenditures to analyze the true localized lifetime value (LTV) of each active consumer demographic.
