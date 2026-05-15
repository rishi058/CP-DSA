
# Data Science Interview Questions and Answers

## Power BI and Tableau

### 1. What are the core components of Power BI?
* Power Query: For data transformation and cleaning
* Power Pivot: For data modeling and relationships
* Power View: For creating visualizations
* Power Map: For geographic visualization
* DAX: For creating calculations and data analysis
* Power BI Desktop: Main development tool
* Power BI Service: Cloud-based platform for sharing

### 2. Explain the difference between Power BI Desktop, Power BI Service, and Power BI Mobile
* Power BI Desktop: Windows application for creating reports and datasets
* Power BI Service: Cloud-based platform for sharing and viewing reports
* Power BI Mobile: App for viewing reports on mobile devices
* Desktop is for development, Service for distribution, Mobile for consumption

### 3. What are the different types of views in Power BI Desktop?
* Report View: Create visualizations and reports
* Data View: See raw data in table format
* Model View: Create relationships between tables
* Each view serves different purposes in report development
* Switch between views using navigation pane

### 4. Describe the connectivity modes in Power BI
* Import Mode: Data copied into Power BI
* DirectQuery: Real-time connection to source
* Live Connection: Connects to SSAS models
* Import is best for small datasets
* DirectQuery for large, real-time data
* Live Connection for existing enterprise models

### 5. What is the difference between a report and a dashboard in Power BI?
* Reports: Multiple pages of visualizations
* Dashboards: Single page of key metrics
* Reports are interactive and detailed
* Dashboards show high-level KPIs
* Reports are source, dashboards are summary
* Dashboards can combine multiple reports

### 6. How can you connect Power BI to external data sources?
* Databases: SQL Server, Oracle, MySQL
* Files: Excel, CSV, XML
* Cloud Services: SharePoint, Azure
* Web Services: Web APIs
* Use "Get Data" option in Power BI
* Choose connection type and provide credentials

### 7. Explain the role of DAX in Power BI
* DAX = Data Analysis Expressions
* Creates calculated columns and measures
* Performs complex calculations
* Similar to Excel formulas but more powerful
* Used for time intelligence calculations
* Essential for advanced analytics

### 8. What are the different types of Power BI visualizations?
* Basic: Bar, Line, Pie charts
* Tables: Matrix, Tables
* Maps: Basic maps, Filled maps
* Custom visuals from marketplace
* KPI cards and gauges
* Advanced: Waterfall, Funnel charts

### 9. How do you handle performance optimization in Power BI reports?
* Minimize data import size
* Use appropriate data types
* Avoid complex calculations
* Implement query folding
* Use bookmarks for navigation
* Optimize relationship cardinality

### 10. How to perform data transformation in Power BI using Power Query Editor?
* Remove unnecessary columns
* Change data types
* Merge/Append queries
* Filter rows
* Create custom columns
* Split/combine columns

## Advanced Excel

### 11. What are pivot tables and how do they differ from regular tables?
* Pivot tables summarize data dynamically
* Regular tables show raw data
* Pivot tables allow drag-drop analysis
* Can create calculations automatically
* Easy to group and filter data
* Change view without changing source

### 12. How to use advanced Excel formulas?
* VLOOKUP: Vertical search in tables
* HLOOKUP: Horizontal search
* INDEX-MATCH: More flexible than VLOOKUP
* VLOOKUP limitations: Left-to-right only
* INDEX-MATCH works both directions
* Used for data matching and lookup

### 13. How does conditional formatting work?
* Automatically formats cells based on rules
* Color scales for value ranges
* Icon sets for visual indicators
* Data bars for comparisons
* Custom rules possible
* Helps visualize data patterns

### 14. How to visualize data trends using Excel charts?
* Choose appropriate chart type
* Line charts for trends
* Bar charts for comparisons
* Pie charts for proportions
* Add trendlines
* Customize colors and labels

### 15. How to manage large datasets in Excel?
* Use filters to view specific data
* Apply sorting for organization
* Create named ranges
* Use PivotTables for analysis
* Implement VBA macros
* Use data validation rules

## Numpy and Pandas

### 16. How does Numpy improve performance in Python?
* Uses optimized C code
* Vectorized operations
* Contiguous memory storage
* Faster than Python lists
* Efficient array operations
* Better memory management

### 17. What is broadcasting in Numpy?
* Automatic array size matching
* Performs operations on different-sized arrays
* Eliminates explicit loops
* Makes code more efficient
* Follows specific rules
* Saves memory and time

### 18. How to perform basic operations using Numpy?
* np.sum() for summation
* np.mean() for average
* np.std() for standard deviation
* Axis parameter for dimension
* Supports array operations
* Fast computation on arrays

### 19. How to create and manipulate DataFrame in Pandas?
* pd.DataFrame() creates new frame
* Can use dict or array input
* Add/remove columns easily
* Sort and filter data
* Reset index when needed
* Apply functions to columns

### 20. Ways to handle missing data in Pandas DataFrame?
* dropna() removes missing values
* fillna() fills missing values
* interpolate() estimates values
* replace() substitutes values
* Check with isnull()
* Forward/backward fill

### 21. Difference between Series and DataFrame in Pandas?
* Series is 1-dimensional
* DataFrame is 2-dimensional
* Series like array with index
* DataFrame like table
* Series for single column
* DataFrame for multiple columns

### 22. How to merge, join, concatenate in Pandas?
* merge() combines on keys
* concat() stacks data
* join() uses index
* Different join types available
* Handle duplicate columns
* Check for data alignment

### 23. How to group and aggregate data in Pandas?
* groupby() creates groups
* agg() applies functions
* Common functions: sum, mean
* Multiple aggregations possible
* Reset index after grouping
* Create pivot tables

### 24. How to filter data in Pandas?
* Boolean indexing
* loc[] for labels
* iloc[] for positions
* Query() method
* Multiple conditions possible
* Filter by values or index

## Matplotlib and Visualization

### 25. How to create basic plots in Matplotlib?
* plt.plot() for line plots
* plt.scatter() for scatter plots
* plt.bar() for bar charts
* Define x and y data
* Set labels and title
* Customize appearance

### 26. How to customize plot appearance in Matplotlib?
* Use plt.xlabel() and ylabel()
* Set colors with 'color' parameter
* Add legends with plt.legend()
* Adjust figure size with plt.figure()
* Customize line styles
* Add grid with plt.grid()

### 27. Difference between Matplotlib and Seaborn?
* Matplotlib: Basic plotting library
* Seaborn: Built on Matplotlib
* Seaborn: Better default styles
* Seaborn: Statistical plots built-in
* Matplotlib: More control
* Seaborn: Less code needed

### 28. How to visualize correlation matrix?
* Use numpy.corrcoef()
* plt.imshow() for display
* Add colorbar for scale
* Use plt.matshow()
* Customize colors with cmap
* Add annotations with plt.text()

### 29. How to create heatmap in Seaborn?
* Use sns.heatmap()
* Set annot=True for values
* Choose colormap with cmap
* Add labels with xlabel/ylabel
* Customize color scale
* Add title with plt.title()

## Machine Learning with Scikit-learn

### 30. Main types of machine learning algorithms?
* Supervised: Classification, Regression
* Unsupervised: Clustering, Dimensionality Reduction
* Reinforcement Learning
* Examples: Decision Trees, SVM
* Neural Networks
* K-means Clustering

### 31. How to evaluate model using cross-validation?
* Use train_test_split()
* cross_val_score() for validation
* KFold for splitting
* Evaluate multiple metrics
* Get mean and std scores
* Avoid overfitting

### 32. How to handle class imbalance?
* Use oversampling (SMOTE)
* Undersampling majority class
* Adjust class weights
* Collect more data
* Use different metrics
* Ensemble methods

### 33. Difference between classification and regression?
* Classification: Predicts categories
* Regression: Predicts continuous values
* Classification: Discrete outputs
* Regression: Continuous outputs
* Classification: Accuracy metrics
* Regression: Error metrics

### 34. Explain bias-variance tradeoff?
* Bias: Model simplicity
* Variance: Model complexity
* High bias: Underfitting
* High variance: Overfitting
* Need balance between both
* Affects model generalization

### 35. How to tune hyperparameters?
* Use GridSearchCV
* RandomizedSearchCV for large spaces
* Cross-validation for validation
* Define parameter grid
* Score with metrics
* Choose best parameters

### 36. Common classification metrics?
* Accuracy: Overall correctness
* Precision: True positive ratio
* Recall: Sensitivity
* F1-Score: Harmonic mean
* ROC Curve: Performance curve
* Confusion Matrix: Error types

### 37. How to perform feature selection?
* SelectKBest for scoring
* RFE for recursive selection
* Use model coefficients
* Correlation analysis
* Feature importance
* Remove redundant features

### 38. What are decision trees?
* Tree-based prediction model
* Splits based on features
* Uses if-then rules
* Easy to interpret
* Can overfit easily
* Used in Random Forests

### 39. How to evaluate regression models?
* MSE: Mean Squared Error
* RMSE: Root Mean Squared Error
* MAE: Mean Absolute Error
* R-squared: Fit measure
* Cross-validation scores
* Residual plots

## Python Programming

### 40. Python lists, tuples, and sets differences?
* Lists: Mutable, ordered
* Tuples: Immutable, ordered
* Sets: Unique elements, unordered
* Lists: Square brackets
* Tuples: Parentheses
* Sets: Curly braces

### 41. Mutable vs immutable objects?
* Mutable: Can be changed
* Immutable: Cannot be changed
* Lists are mutable
* Strings are immutable
* Tuples are immutable
* Dictionaries are mutable

### 42. What is Python generator?
* Creates iterator function
* Uses yield keyword
* Memory efficient
* Generates values on-demand
* Can't access indexes
* One-time iteration

### 43. Handle missing data in Python?
* Check for None values
* Use numpy.isnan()
* Replace with mean/median
* Drop missing values
* Use default values
* Interpolate values

### 44. Purpose of lambda function?
* Anonymous function
* Single expression only
* Inline function definition
* Used with map/filter
* Short operations
* No formal def needed

### 45. How map() function works?
* Applies function to iterable
* Returns map object
* Can handle multiple iterables
* Memory efficient
* Similar to list comprehension
* Example: map(lambda x: x*2, list)

### 46. Using regex in Python?
* Import re module
* re.search() finds pattern
* re.match() from start
* re.findall() all occurrences
* Pattern matching
* Text manipulation

### 47. Deep vs shallow copy?
* Shallow: References same objects
* Deep: Creates new objects
* copy.copy() for shallow
* copy.deepcopy() for deep
* Nested objects differ
* Memory usage differs

### 48. Handle exceptions in Python?
* Use try-except blocks
* Catch specific exceptions
* Use finally clause
* Multiple except blocks
* Raise exceptions
* Handle errors gracefully

### 49. Purpose of *args and **kwargs?
* *args: Variable positional arguments
* **kwargs: Variable keyword arguments
* Flexible function parameters
* Used in function definitions
* Unpacking arguments
* Dynamic parameter handling

### 50. Difference between is and ==?
* is: Identity comparison
* ==: Value comparison
* is checks memory location
* == checks equality
* Use is for None
* == for value matching

## Jupyter Notebooks

### 51. Key features of Jupyter Notebooks?
* Interactive coding
* Mix code and text
* In-line visualization
* Markdown support
* Cell-based execution
* Easy sharing

### 52. Integrate Jupyter with libraries?
* Import libraries normally
* Use magic commands
* Display visualizations inline
* Interactive widgets
* Multiple kernel support
* Package management

### 53. Add Markdown and visualize output?
* Use markdown cells
* Support for LaTeX
* Display plots inline
* HTML rendering
* Interactive outputs
* Rich text formatting

### 54. Magic commands in Jupyter?
* %run: Run scripts
* %%time: Time execution
* %matplotlib inline: Plot display
* %who: List variables
* %%writefile: Save cells
* %load: Load external code

### 55. Share Jupyter notebooks?
* Export as various formats
* Use GitHub
* Share via nbviewer
* Convert to PDF
* Use Google Colab
* Email .ipynb files

## General Data Science and Concepts

### 56. Supervised vs unsupervised learning?
* Supervised: Labeled data
* Unsupervised: No labels
* Supervised: Known output
* Unsupervised: Find patterns
* Supervised: Prediction
* Unsupervised: Clustering

### 57. Overfitting and addressing it?
* Use cross-validation
* Increase training data
* Feature selection
* Regularization
* Reduce model complexity
* Early stopping

### 58. What is PCA?
* Dimensionality reduction
* Finds principal components
* Reduces features
* Preserves variance
* Handles collinearity
* Visualize high-dim data

### 59. Handle outliers in dataset?
* Identify with boxplots
* Use Z-score method
* IQR method
* Remove or cap outliers
* Investigate causes
* Transform data

### 60. Common preprocessing techniques?
* Scaling features
* Handling missing values
* Encoding categories
* Normalizing data
* Feature selection
* Dealing with outliers

### 61. Feature engineering impact?
* Creates new features
* Improves model performance
* Domain knowledge important
* Reduces dimensionality
* Captures relationships
* Enhances predictions