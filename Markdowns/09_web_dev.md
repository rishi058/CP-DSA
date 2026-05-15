### HTML & CSS

#### 1. **What is the purpose of the `DOCTYPE` declaration in HTML?**
   - `DOCTYPE` tells the browser which HTML version the document is using. In HTML5, `<!DOCTYPE html>` enables standards mode for consistent rendering across browsers.

#### 2. **Explain the difference between inline, inline-block, and block elements in CSS.**
   - **Inline** elements do not start on a new line and only take up necessary width (e.g., `<span>`). **Block** elements start on a new line and take full width (e.g., `<div>`). **Inline-block** elements don’t start on a new line but respect width and height settings.

#### 3. **What is CSS Flexbox, and when should you use it?**
   - CSS Flexbox is a layout model that allows responsive alignment and distribution of space among items. It is ideal for complex, one-dimensional layouts like navigation bars and card alignments.

#### 4. **Explain the CSS Grid layout and how it differs from Flexbox.**
   - CSS Grid is a two-dimensional layout model for arranging elements in rows and columns, making it ideal for complete web page layouts. Flexbox, on the other hand, is one-dimensional (row or column).

#### 5. **What is the purpose of media queries in CSS?**
   - Media queries enable responsive design by applying different CSS styles based on screen size, orientation, and other device characteristics.

#### 6. **How does z-index work in CSS?**
   - The `z-index` property controls the stack order of overlapping elements. Higher values appear on top. It only works on elements with a defined position (relative, absolute, or fixed).

#### 7. **What are CSS preprocessors, and why use them?**
   - CSS preprocessors like **Sass** and **LESS** add functionality like variables, nesting, and mixins to CSS, making it easier to write and manage styles, especially in large projects.

#### 8. **Explain the difference between responsive design and adaptive design.**
   - **Responsive design** uses flexible layouts to adjust to any screen size, while **adaptive design** uses static layouts tailored for specific screen sizes, requiring multiple layouts.

#### 9. **What are pseudo-classes in CSS? Give examples.**
   - Pseudo-classes define special states of elements, such as `:hover` for mouse hover, `:nth-child()` for specific child elements, and `:active` for clicked elements.

#### 10. **What is the CSS box model?**
   - The CSS box model includes content, padding, border, and margin around an element. It defines how an element's total width and height are calculated and displayed on the page.

---

### Node.js & Express

#### 11. **What is Node.js, and why is it popular for web development?**
   - Node.js is a JavaScript runtime built on Chrome's V8 engine that allows JavaScript to run server-side. It's popular for its non-blocking, event-driven architecture and high scalability for handling multiple connections.

#### 12. **Explain the role of Express.js in the MERN stack.**
   - Express.js is a web application framework for Node.js, providing tools and features for handling HTTP requests, defining routes, and managing middleware, making server-side development faster and more organized.

#### 13. **What is middleware in Express.js?**
   - Middleware functions in Express.js execute during request processing. They can modify requests/responses, end the request-response cycle, or pass control to the next middleware, enabling logging, authentication, error handling, etc.

#### 14. **Explain the event-driven architecture of Node.js.**
   - Node.js uses an event-driven architecture where an event loop listens for and processes events asynchronously, allowing non-blocking I/O operations and efficient handling of concurrent connections.

#### 15. **How do you handle errors in Express.js?**
   - Error handling in Express.js involves using error-handling middleware, which captures errors and manages responses to clients. The last middleware typically handles errors with four parameters: `err, req, res, next`.

#### 16. **What is the purpose of `package.json` in a Node.js project?**
   - `package.json` defines a Node.js project’s metadata, including dependencies, scripts, version, and project name. It enables dependency management and automates script execution.

#### 17. **Explain the role of `npm` in Node.js.**
   - **npm** (Node Package Manager) manages Node.js packages, allowing developers to install, update, and publish packages. It simplifies managing project dependencies and tools.

#### 18. **What is the difference between synchronous and asynchronous programming in Node.js?**
   - **Synchronous** operations block the execution until the task completes, while **asynchronous** operations allow other tasks to run simultaneously. Node.js relies on asynchronous programming for non-blocking, efficient server performance.

#### 19. **How does Node.js handle file system operations?**
   - Node.js handles file operations using the `fs` module, which provides synchronous and asynchronous methods for reading, writing, updating, and deleting files.

#### 20. **What is RESTful API, and how do you create one with Express.js?**
   - A RESTful API follows REST principles, exposing resources through standard HTTP methods. In Express.js, it’s created by defining routes with HTTP methods (GET, POST, PUT, DELETE) and corresponding controller functions.

---

### MongoDB

#### 21. **What is MongoDB, and why is it suited for web development?**
   - MongoDB is a NoSQL database storing data in JSON-like documents, allowing flexibility in schema design. It's suited for web development due to scalability, ease of use, and compatibility with JavaScript.

#### 22. **Explain the difference between SQL and NoSQL databases.**
   - **SQL databases** use structured tables and fixed schemas for data storage, while **NoSQL databases** like MongoDB store data in a flexible, unstructured format, often in key-value pairs, documents, or graphs.

#### 23. **What is a document in MongoDB?**
   - A document is a record in MongoDB, represented as a JSON-like object (BSON format). It contains fields and values, enabling flexible and schema-less data storage.

#### 24. **What are collections in MongoDB?**
   - A collection in MongoDB is a group of documents, similar to a table in relational databases. Collections store documents with related data, enabling easy data organization and retrieval.

#### 25. **How do you create a connection to MongoDB in a Node.js application?**
   - In a Node.js application, connect to MongoDB using the `mongoose` library or MongoDB's native driver. Define the database URL, then use `mongoose.connect()` or `MongoClient.connect()`.

#### 26. **What is Mongoose, and why is it used in MongoDB projects?**
   - Mongoose is an ODM (Object Data Modeling) library for MongoDB. It simplifies schema definition, data validation, and interactions with MongoDB, making data management easier in Node.js applications.

#### 27. **Explain indexing in MongoDB and why it is important.**
   - Indexing in MongoDB improves query performance by organizing fields for faster retrieval. Without indexes, MongoDB performs a full collection scan, which is slower for large datasets.

#### 28. **How does replication work in MongoDB?**
   - MongoDB replication uses replica sets to maintain multiple copies of data across servers. It enhances data availability, fault tolerance, and disaster recovery by automatically promoting backups as primary during failures.

#### 29. **What is sharding, and why is it used in MongoDB?**
   - Sharding is MongoDB's horizontal scaling method, distributing data across multiple servers. It ensures efficient data handling and query performance for large datasets by splitting data into shards.

#### 30. **How do you perform CRUD operations in MongoDB?**
   - CRUD operations in MongoDB use:
     - **Create**: `insertOne`, `insertMany`
     - **Read**: `find`, `findOne`
     - **Update**: `updateOne`, `updateMany`
     - **Delete**: `deleteOne`, `deleteMany`

---

### React

#### 31. **What is React, and why is it popular?**
   - React is a JavaScript library for building UI components. It’s popular for its virtual DOM, component-based architecture, and efficient rendering, allowing developers to build interactive user interfaces.

#### 32. **Explain the virtual DOM in React.**
   - The virtual DOM is a lightweight copy of the real DOM. React uses it to optimize rendering by comparing changes in components and updating only the affected parts of the real DOM.

#### 33. **What are components in React?**
   - Components are reusable UI elements in React. They are the building blocks of a React application, with each component encapsulating its structure, behavior, and styling.

#### 34. **Explain the difference between functional and class components in React.**
   - **Functional components** are simpler, stateless, and defined as JavaScript functions. **Class components** are stateful and use lifecycle methods. Functional components can use state and lifecycle via hooks.

#### 35. **What is JSX in React?**
   - JSX is a syntax extension for JavaScript, allowing developers to write HTML-like code within JavaScript. It simplifies React component rendering by making

 the code more readable.

#### 36. **What are React hooks, and why are they used?**
   - React hooks like `useState` and `useEffect` enable functional components to manage state and lifecycle events, reducing the need for class components and enhancing reusability.

#### 37. **What is the purpose of `useState` and `useEffect` hooks in React?**
   - `useState` manages component state, while `useEffect` handles side effects like data fetching or DOM manipulation after rendering. Together, they add state and lifecycle methods to functional components.

#### 38. **How does state management work in React?**
   - React’s state management uses `useState` for local component state. For global state, tools like **Redux** or **Context API** help manage shared state across components efficiently.

#### 39. **What is Redux, and how does it work with React?**
   - Redux is a state management library for predictable state management. It stores the application state in a single store and updates it through actions and reducers, ensuring predictable and manageable state changes.

#### 40. **Explain how React Router works.**
   - React Router is a library for client-side routing, enabling navigation within single-page applications (SPAs) without reloading the page. It manages URL-based rendering, linking components to different paths.
