# SANDISK JOURNEY 

6 month duration from Jan 2025 to Jun 2025,
Data Analyst Intern
Tech Stack: Python, Advanced Excel, Power BI, Tablue, SQL
Team : Global Operations, Supply Chain Management
My Manager: Mukundan Thangavelu
Team Members: Praneet Udyavar, Yuvraj, Ashwin Kaushik

I am a Business Analyst Intern who analyzes data, identifies trends, and helps improve business processes using tools like Excel, Power BI, SQL, and Python. I assist in reporting, dashboard creation, and automation, enabling data-driven decision-making for the organization.

Tools & Libraries:
Power BI: For interactive dashboards with DAX measures (e.g., tariff savings calculations).
Python: Pandas for data cleaning, PyInstaller for .exe automation, cx_Oracle for DB connectivity.
SQL/Oracle DB: Extracted transactional data (1M+ rows) with optimized queries.
Excel VBA: Legacy report generation before automation.

Python Library used: 
Pandas: Library for handling and analyzing structured data using DataFrames.
cx_Oracle: Connects Python to Oracle databases for SQL operations.
xlwings: Automates Excel from Python using COM interface.
openpyxl: Reads and writes Excel (.xlsx) files in Python.


## 1st Month - Jan 
### Knowledge Transfer (KT)

Supply Chain Planning & Database Management: My senior manager introduced me to supply chain planning and how product details are stored in databases like Oracle DB. I learned about manual data entry, different attributes, workflows, and how data flows across the system for efficient supply chain operations.

I work in Global Operations Department, it is responsible for Supply Chain Planning and some other stuffs. Supply Chain Planning consist of 4 major teams:
Silicon Planning
Product Planning
Capacity Planning
Asia Planning

It’s main objective is to ensure material supply and capacity availability to transform wafer supply into products into products to meet priorities like:
Meeting Demand Ontime.
Revenue & Profit.

-- 

Power BI & Data Modeling Courses: They provided me with free Power BI courses, where I learned about data modeling, optimization, and advanced concepts like STAR Schema & Snowflake Schema. These lessons helped me design efficient data structures, improve report performance, and create insightful dashboards.

Self-Learning in SQL, Excel & Python: My manager advised me to enhance SQL, MS Excel, and Python skills through YouTube tutorials, blogs, and ChatGPT. This approach helped me refine my problem-solving abilities, understand real-world use cases, and apply automation techniques to business analysis tasks.


## 2nd and 3rd Month - Feb and Mar
### Tariff Tracking Dashboard

The organization faced data fragmentation, with inventory spread across Excel, SAP, and Oracle in different formats. Teams spent hours on manual report consolidation every week, increasing the risk of tariff misclassification. Amid rising US-China tariffs (7.5% – 40%), there is no system to track overall tariff exposure, creating compliance risks.
Currently, there is no effective mechanism in place to identify leakages in the duty amount, making it difficult to track where unnecessary costs are being incurred. Additionally, there is a pressing need to flag specific products that are contributing to irrelevant or incorrect tariff charges, which are directly leading to significant financial losses


> Problem Statement: There is a report which we recieve every week, It includes details of all the products being imported in USA. Create a script which summarizes all the important details of the product which are imported in USA till now in a single excel file and generate a pivot table to analyze the data. 

> Unstructured data
Tariff exposure based on different category (Tech Used, Qaulity, Family, BU).

Understanding the Problem Statement: I first analyzed the weekly import report structure to understand the key attributes, format, and how the data is structured. Discussions with my manager helped clarify which product details were important for summarization and how the final report should look.

Choosing the Right Tools: Since the data was in Excel format, I used Python with xlwings to automate the processing and generate pivot tables. However, I later optimized the script by incorporating openpyxl to improve read/write efficiency.

Data Processing & Cleaning: The script extracted data from multiple reports, merged them into a single dataset, and cleaned inconsistencies. I used pandas for data filtering, removing duplicates, and structuring the data for better analysis.

Performance Optimization: Initially, reading and writing large Excel files was slow with xlwings. To overcome this, I integrated openpyxl, which significantly improved processing speed and efficiency without compromising functionality.

Generating a Pivot Table for Analysis: Using xlwings, I automatically created a pivot table in the final Excel report, summarizing import trends, product categories, and quantity details. This helped in better visualization and decision-making for stakeholders.

Making the Solution User-Friendly: To ensure non-technical users could easily use the solution, I compiled the script into a standalone .exe file using pyinstaller. This allowed anyone to run the automation without needing Python installed.

Presenting the Solution to My Manager: I demonstrated the script’s functionality to my manager, showcasing how it automates the entire process, improves speed, and generates actionable insights. I provided a comparison of manual vs. automated reporting efficiency to highlight its impact.

Preparing Documentation for Usability: I created a detailed documentation guide covering installation, usage instructions, troubleshooting tips, and future improvements. This ensured that the tool could be easily maintained and updated.

Successfully Delivering the Assignment: By combining automation, optimization, and user-friendly deployment, I was able to streamline the import data analysis process. This project not only reduced manual effort but also improved data accuracy and reporting speed, making it a valuable asset for the team 

---

> Problem Statement: Create a dashboard in Power BI which visualizes the trends of different properties of products such as Business Unit, Card Type, Product Category, Tariff Paid, Manufacturing Site, etc. Such that one can take necessary measures to improve profit & revenue based on visualization.

Creating Custom Measures & KPIs with DAX: I implemented DAX queries to create custom measures for important KPIs like total revenue, profit margin, and average tariff paid. This helped in deriving meaningful insights from the raw data.

Building Interactive Visualizations: I used Bar Charts, Pivot Tables, Matrix Visuals, and Pie Charts to represent different trends and comparisons. These visual elements provided clear insights into revenue impact, cost distribution, and product performance.

Enhancing UI & Design for Better User Experience: I focused on UI/UX design by selecting appropriate color combinations and arranging visuals for better readability. A clean layout with consistent color schemes and tooltips improved report usability.

Presenting & Deploying the Dashboard: After testing, I presented the dashboard to my manager, demonstrating how interactive filters and KPIs help in making data-driven decisions to improve revenue and profit. The final dashboard was published for seamless access.

> Overview

Objective: Monitor import duties across product categories (e.g., SSDs, USB drives, MicroSD), buildable sites, China/Non-China qualified. Track data based based on weeks and months.

Data Sources:
Weekly customs reports from US teams (SharePoint/OneDrive).
Oracle DB for dimension tables which is used to map item_id with its relevant informations.
Forecast report from Manufacturing Sites.

Key Features:
Dynamic KPIs (e.g., "Non-CN Qualified %" to identify China-alternative sourcing).
Trend analysis of tariff hikes (e.g., US-China trade war impacts).
Filter by COO (Country of Origin), Super Family, BU (Business Unit), etc.

> Automation

I developed a Python automation script to streamline tariff reporting by consolidating multiple weekly Excel files into structured outputs. The script leveraged libraries like openpyxl and xlwings to create and format pivot tables, providing auto-generated summaries such as total duty amount. To enable non-technical users to run the tool effortlessly, I converted the script into a standalone .exe file using PyInstaller.

Additionally, the script integrated cx_Oracle to connect with internal databases where needed, ensuring fast real-time data syncing. Importing data via Power BI took 30-50 minuntes. We used oracle instant client with python to fetch data from oracle db. This automation not only reduced manual effort but also improved reporting consistency and accessibility across cross-functional teams.

> Dashboard

To derive insights from complex tariff data, I developed a series of interactive visualizations using Power BI. One of the key visuals was KPI’S that highlighted important overall numbers, enabling teams to pinpoint the SKUs driving the majority of duties. This allowed procurement and supply chain stakeholders to focus their cost-reduction strategies effectively.

I also created time series graphs to monitor duty rate fluctuations between January and May 2025. These visuals revealed key patterns such as quarterly spikes and emerging trends, which were crucial for budgeting and forecasting. The graphs helped in identifying peak periods and planning ahead for cost-intensive months.

To enhance user experience, the dashboard included interactive filters for drill-down by business unit, product family, and country. This made the analysis more dynamic and customizable, empowering users from different regions or departments to explore relevant data slices without modifying the core dataset.

Additionally, I used DAX formulas to introduce calculated metrics that added strategic value. For example, the "Top 5 Super Families" measure identified product groups contributing to over 60% of total tariffs, aiding prioritization. Another metric, "Non-CN Qualified %", highlighted items not tied to Chinese sourcing, helping teams evaluate diversification opportunities and reduce tariff exposure.

> Optimization

Initially, Oracle database queries used for tariff reporting were highly inefficient, taking over 60 minutes to run. This delay hindered timely analysis and slowed down decision-making across teams.

To address this, I implemented a star schema by separating fact and dimension tables, which optimized query performance. I also introduced incremental refresh logic to update only new or changed records, significantly reducing processing overhead.

Using the cx_Oracle library, I improved data extraction speed through optimized connections and query handling. These enhancements led to an 80% reduction in load time, bringing refresh durations down to just 5 minutes.

> RESULT

The project delivered significant operational efficiencies, with a 75% reduction in manual report consolidation time—from 1-2 hours to just 10 minutes per week. This automation freed up time for higher-value activities like scenario planning.

On the financial front, the solution enabled $X M in potential cost avoidance by identifying and recommending the shift of 18% of China imports to Malaysia, based on comparative duty rates and capacity availability.

The resulting dashboard became very useful for the organization and was officially adopted by other business units also enhancing cross-functional visibility.

## 4, 5 and 6th Month - Apr, May, Jun
### Inventory Management

> Fragmented Data

Primary Goals:
Visibility: Centralize disjointed inventory and tariff data from multiple global sites.
Automation: Replace manual reporting with Python scripts and Power BI dashboards.
Cost Optimization: Identify savings opportunities in tariffs costs ($M+ impact) and inventory write-offs.

Key Metrics Tracked:
Monitoring Inventory aging (45/60/90+ days), Ring Numbers, Die Quantities, etc.
Nettable/Non-nettable stock potential.

---

Unlike conventional industries, semiconductors require precise tracking of wafers, dies, and finished goods across global supply chains, where materials often have limited shelf lives (e.g., 45-90 days) and unnoticed high demand item can lead to high financial losses.Excess inventory risks costly write-offs from expired stock, while shortages disrupt production of high-demand chips.Effective Inventory management requires real-time tracking demand-supply alignment, and predictive analytics to minimize waste while ensuring production continuity in this capital-intensive sector

    Inventory reporting faced several data challenges, including over naming conventions for different attributes, making data merging complex. Additionally, manual errors plagued the process. Some of the Contract Manufacturer (CM) reports had misplaced table due to copy-paste error.

    Another major hurdle was system fragmentation, Due to multiple Build Sites we have to collect data via different method and we get it in different formats. This lack of unstructured data made end-to-end visibility and real-time decision-making difficult.

    These issues had serious business impacts. For instance, undetected inventory aging over 90 days led to Million dollars in scrap losses at the CM sites past years. Moreover, X% of non-nettable inventory was actually reclaimable, but it remained stranded due to limited system visibility.

---

To manage high-volumeinventory dataused csv instead of excel file. I integrated multiple data sources including daily, weekly &  bi-weekly reports from CM to monitor feeds for FG/WIP, and historical yield data from Oracle DB in a snowflake Data Model to improve query speed.

The ETL pipeline was built using Python scripts and Power Query. I used openpyxl to clean inconsistent reports, cx_Oracle to extract 18-month aging trends, and M-code in Power Query to transform SAP data—calculating key fields like "Days Aging" for each component.

We categorized inventory into aging buckets: Green (0–45 days), Amber (46–60), Red (61–90), and Black (>90 days), with Black posing high scrap risk. Aging analysis also considered technology node such as BiCS3, BiCS4, BICS6, BICS8 which drives 58% of total demand.

Other attributes such as PB, Die quanties, Ring numbers, Tech Used also played a vital role to display trends based on each Fiscal Quarter and pinpoint which items are more important and which are causing disruption in the trends.

To support robust and scalable analytics, I implemented a snowflake schema with well-structured fact and dimension tables. Key fact tables included Fact_Inventory (daily inventory snapshots) and Fact_Yield (wafer-to-die conversions), while dimension tables like Dim_Product, Dim_Site, and Dim_Time enabled detailed slicing by node type, site type, and fiscal calendar.

This schema significantly improved performance—complex queries like "Aging by Site × Product" ran 30% faster, and the overall Power BI file size was reduced by 40% (from 1.2GB to 720MB), improving refresh times and user experience.

The Power BI dashboard was enhanced with advanced interactive features. Users could drill through from site-level views to individual wafer IDs, while conditional formatting flagged aging inventory (e.g., red highlights for items >60 days). What-If analysis tools allowed planners to simulate the cost impact of redistributing 50% of amber-zone stock.

Custom DAX formulas like Aging Risk Score dynamically categorized inventory risk levels as Low, Medium, High, or Critical, based on aging days. This intelligent layering of insights boosted adoption—85% of planners used the dashboard weekly, compared to only 35% adoption for the previous Excel-based reports.

---

**RESULT**

The inventory optimization initiative delivered hard savings by recovering M from through strategic reallocation. It also achieved a 12% reduction in scrap compared to previous quarter by better managing inventory.

Efficiency improved significantly, with increase in decision-making speed thanks to weekly instead of monthly updates on aging reports. Additionally, die utilization at the certain site saw a 28% boost, maximizing resource use and reducing waste.


# Summary

Switching from VBA to Python was transformational, with Pandas handling over 10+ million rows smoothly while Excel crashed. Implementing a Star and snowflake schema boosted query speed, showing the value of smart data modeling despite added complexity.

The project highlighted the need for real-time tracking of tariffs due to their fast impact on supply chains. It also showed that aging buckets must fit production cycles, like the crucial 45-day period for SSDs.

Personally, I improved leadership by guiding cross-functional meetings between US and Malaysia teams. The project boosted profits by optimizing inventory and cutting scrap, increasing revenue through better asset use and cost savings. It also reduced electronic waste, supporting sustainability and lowering environmental impact.

Automation cut manual reporting time by 75%, freeing teams for strategic work. This promoted Python automation, driving broader adoption for data-driven processes.

