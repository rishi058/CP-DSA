### Top Javascript Interview Questions


**1. What is JavaScript, and what is it used for?**
   - JavaScript is a versatile programming language used for creating dynamic content on web pages, such as animations, interactive forms, and web applications. 

   - It runs in the browser and on servers (Node.js), allowing for both client- and server-side scripting.

   - Known for its ability to make web pages interactive and responsive to user actions.

**2. Explain “var,” “let,” and “const” keywords in JavaScript.**
   - `var`: has function-level scope, can be redeclared and hoisted, which can lead to unexpected bugs.

   - `let`: block-scoped, meaning it only exists within the brackets it’s defined in; cannot be redeclared in the same scope.

   - `const`: also block-scoped, must be assigned a value at declaration and cannot be reassigned, ideal for constant values.

**3. What are data types in JavaScript?**
   - JavaScript has seven primitive types: `string`, `number`, `boolean`, `null`, `undefined`, `symbol`, and `bigint`.

   - There is also a non-primitive type, `object`, which includes arrays, functions, and other objects.

   - Primitive types are immutable, meaning their value cannot change, while objects are mutable and can hold complex data.

**4. What is the purpose of the “this” keyword?**
   - The `this` keyword represents the object that is currently calling a function, allowing for dynamic context within functions.
   
   - In a global context, `this` refers to the global object (like `window` in browsers).

   - In objects, `this` refers to the specific instance, which is useful in methods to access other properties and methods of the object.

**5. Explain closures and their use cases.**
   - A closure occurs when a function "remembers" its lexical scope, even if it’s executed outside that scope.

   - Useful for encapsulating data, creating private variables, and factory functions.

   - For example, closures are commonly used to keep state in asynchronous code, as the inner function can access the outer function's variables even after it has finished executing.

**6. How do arrow functions differ from regular functions?**
   - Arrow functions don’t create their own `this` context, inheriting `this` from the surrounding scope.

   - They are more concise, particularly for one-liners and callbacks.

   - However, they are unsuitable for methods within objects or as constructors because they don’t support `this` or `new`.

**7. What is the Document Object Model (DOM)?**
   - The DOM is an object-oriented structure representing the HTML of a webpage.
   - It enables JavaScript to interact with and manipulate HTML and CSS by accessing, adding, or modifying elements, attributes, and styles.

   - The DOM is hierarchical, with nodes representing each element, allowing scripts to access elements by navigating this structure.

**8. Describe event delegation and how it works.**
   - Event delegation is a technique to handle events more efficiently by attaching a single event listener to a parent element rather than multiple listeners on child elements.

   - When an event occurs, it bubbles up from the target element to the parent, allowing the parent to respond to events on its children.

   - It’s useful for managing dynamic elements, improving performance.

**9. How is “==” different from “===”?**
   - `==` is a loose equality operator that compares values after converting them to a common type (type coercion).

   - `===` is a strict equality operator that compares both value and type, without conversion.

   - Using `===` is generally safer and preferred to avoid unexpected behavior due to type coercion.

**10. What is the difference between “null” and “undefined”?**
   - `null` is an intentional absence of any value, meaning the developer has explicitly assigned "no value."

   - `undefined` means a variable has been declared but not assigned a value.

   - Both are falsy values but are used differently; `null` is more intentional, while `undefined` often indicates an uninitialized or missing value.

**11. Explain the concept of asynchronous programming in JavaScript.**
   - Asynchronous programming allows JavaScript to perform non-blocking tasks, such as fetching data from a server without halting other code execution.

   - It’s achieved using callbacks, promises, and async/await syntax, which lets JavaScript continue executing other code while waiting for long-running tasks to complete.

   - Useful for handling I/O operations like API calls and file reads.

**12. What is a promise, and how does it work?**
   - A promise is an object representing a future result of an asynchronous operation.

   - It can be in one of three states: `pending`, `fulfilled`, or `rejected`.

   - When fulfilled, it resolves with a result; when rejected, it provides an error.

   - Promises are used to handle asynchronous tasks in a cleaner, chainable way than traditional callbacks.

**13. How does async/await work?**
   - `async` and `await` allow for writing asynchronous code in a synchronous style.

   - Functions marked with `async` return a promise, while `await` pauses execution until the promise is resolved.

   - This syntax simplifies chaining of promises and makes code more readable, handling complex async flows in a clean, linear way.

**14. What are callback functions, and why are they used?**
   - A callback function is a function passed as an argument to another function, executed after the outer function completes.

   - They enable asynchronous behavior, allowing code to run after tasks like fetching data.

   - Commonly used in event handling and for functions that perform time-consuming tasks, like network requests.

**15. What is a higher-order function?**
   - A higher-order function takes one or more functions as arguments or returns a function as its result.

   - These are useful for functional programming and allow for operations like mapping, filtering, and composing functions.

   - Examples include `map`, `filter`, and `reduce`, which operate on arrays and other data structures.

**16. What are prototypes in JavaScript?**
   - Prototypes are JavaScript’s way of implementing inheritance.

   - Each object has a hidden property called `__proto__`, which points to the prototype of its constructor function.

   - Prototypes allow objects to inherit methods and properties from other objects, helping to reduce memory usage by sharing methods across instances.

**17. Explain prototypal inheritance.**
   - Prototypal inheritance allows an object to inherit properties and methods from another object.

   - Objects in JavaScript can directly link to other objects, forming a prototype chain.

   - This chain allows objects to access properties and methods from parent objects, promoting code reuse and reducing redundancy.

**18. What is a pure function?**
   - A pure function is a function that always produces the same output for the same input and has no side effects (it doesn’t alter any external state).

   - Pure functions make code more predictable and easier to debug.

   - They are fundamental to functional programming and are often preferred for their reliability and testability.

**19. What is hoisting in JavaScript?**
   - Hoisting is JavaScript’s behavior of moving variable and function declarations to the top of their scope.

   - Variables declared with `var` and function declarations are hoisted, allowing them to be referenced before their declaration.

   - However, `let` and `const` are hoisted differently, placing them in a "temporal dead zone" until initialization.

**20. How do you create and manipulate arrays?**
   - Arrays in JavaScript can be created using `[]` or `new Array()`.

   - Common methods for array manipulation include `push` (add), `pop` (remove last), `shift` (remove first), `unshift` (add at start), `map`, `filter`, and `reduce`.

   - These methods allow for efficient data storage and manipulation within lists.

**21. What are JavaScript modules?**
   - JavaScript modules allow code to be divided into separate files or blocks, each with its own scope.

   - Using `export` and `import` statements, modules let you reuse code across different files.

   - Modules are used to organize code, making it more maintainable, readable, and allowing for cleaner dependency management.

**22. Describe the event loop in JavaScript.**
   - The event loop manages asynchronous tasks in JavaScript, enabling non-blocking behavior.

   - It continuously checks the call stack for tasks and executes them, while queued asynchronous tasks (like timers or promises) are processed once the stack is clear.

   - This allows JavaScript to handle asynchronous operations efficiently without halting the main thread.

**23. How does JavaScript handle memory management?**
   - JavaScript uses automatic garbage collection, removing objects that are no longer referenced.

   - The memory management system tracks object references and frees memory when it detects no links to an object.

   - While automatic, developers can help optimize memory usage by avoiding unnecessary references and cleaning up listeners.

**24. What are JavaScript promises, and why are they used?**
   - A promise is an object representing a future outcome (resolved or rejected) of an asynchronous operation.

   - Promises are used to handle async code in a structured way, improving readability over traditional callbacks.

   - They allow chaining of async operations, error handling, and provide a standardized pattern for dealing with async tasks.

**25. Explain the concept of currying.**
   - Currying transforms a function with multiple arguments into a series of functions, each taking a single argument.

   - For example, `add(2,3)` becomes `add(2)(3)`.

   - Currying is useful in functional programming, allowing partial application of arguments, making functions more reusable and composable.

**26. What is a first-class function?**
   - In JavaScript, functions are first-class citizens, meaning they can be treated as values.

   - They can be stored in variables, passed as arguments, and returned from other functions.

   - This property enables powerful programming patterns, such as higher-order functions and functional programming.

**27. How does JavaScript handle exceptions?**
   - JavaScript uses `try`, `catch`, `finally`, and `throw` to handle exceptions.

   - `try` runs code that might throw an error; if an error occurs, `catch` handles it.

   - `finally` executes code regardless of error occurrence, often used for cleanup.

   - `throw` can be used to manually trigger an error for custom handling.

**28. What are factory functions?**
   - A factory function is a function that creates and returns an object without using `new`.

   - It’s an alternative to constructor functions and allows customization of each object instance.

   - Factory functions are flexible, as they don’t require classes and can easily create multiple similar objects.

**29. What is the difference between local storage and session storage?**
   - Both local storage and session storage store data in the browser as key-value pairs.

   - Local storage persists even after the browser is closed, while session storage is cleared once the session ends.

   - Local storage has a larger storage limit and is used for longer-term data, while session storage suits temporary data.

**30. Describe garbage collection in JavaScript.**
   - Garbage collection in JavaScript is an automatic process where the engine removes objects no longer referenced.

   - The main method is reference counting, which tracks how many references each object has.

   - When an object’s reference count drops to zero, memory is freed, allowing for efficient memory management.


**31. What is the spread operator, and how does it work?**
   - The spread operator (`...`) expands elements in an array or object.

   - It allows you to copy, merge, or add elements to arrays and objects.

   - Useful for tasks like combining arrays (`[...arr1, ...arr2]`) or cloning objects (`{...obj}`).

**32. How do destructuring assignments work in JavaScript?**
   - Destructuring allows you to extract values from arrays or properties from objects into distinct variables.

   - Arrays: `const [a, b] = [1, 2];` assigns `1` to `a` and `2` to `b`.

   - Objects: `const {name, age} = person;` assigns values from `person` to `name` and `age`.

**33. What are generator functions, and how do you use them?**
   - Generators are special functions using `function*` syntax that can pause and resume execution with `yield`.

   - They return an iterator object that can produce multiple values over time.
   
   - Useful for tasks like lazy evaluation or handling async code with iterative steps.

**34. Explain the purpose of the `Symbol` type in JavaScript.**
   - Symbols are unique, immutable primitive values used to create unique property keys.

   - Useful in situations where property names must be unique, such as defining custom object methods without name clashes.

   - Symbols help prevent accidental overwriting of properties.

**35. What is an Immediately Invoked Function Expression (IIFE)?**
   - An IIFE is a function that runs immediately after being defined, often in the form `(function() { ... })()`.

   - It creates a private scope, preventing variables within it from polluting the global scope.

   - Commonly used in modular code to control variable scope and prevent conflicts.

**36. How do you prevent a JavaScript object from being modified?**
   - Use `Object.freeze(obj)` to make an object immutable, preventing changes to properties or values.

   - `Object.seal(obj)` also restricts modifications but allows changes to existing properties.

   - Both methods are useful for ensuring data consistency and protecting object structures.

**37. What is event bubbling and capturing?**
   - Event capturing goes from the root to the target element, while bubbling goes from the target back up to the root.

   - Bubbling is the default; capturing can be enabled with the third argument in `addEventListener`.
   
   - Understanding both helps manage event flow and delegate events efficiently.

**38. How does JavaScript handle scoping?**
   - JavaScript has function scope and block scope (`let` and `const`).

   - `var` is function-scoped, meaning it’s visible within the function it’s declared in.

   - `let` and `const` are block-scoped, limited to the block in which they’re defined, providing better control over variable visibility.

**39. Explain the concept of a "promise chain."**
   - A promise chain is a series of `.then()` calls where each step depends on the previous one.

   - Useful for handling sequential asynchronous operations, improving readability by avoiding nested callbacks.

   - Errors in any step can be handled in a single `.catch()` at the end of the chain.

**40. What is a Map, and how does it differ from an object?**
   - A `Map` is a key-value pair collection where keys can be any data type.

   - Unlike objects, `Map` maintains insertion order and has methods like `get`, `set`, and `has`.

   - Ideal for when you need ordered keys or non-string keys in a collection.

**41. What is a Set, and when should it be used?**
   - A `Set` is a collection of unique values, meaning duplicates are automatically removed.

   - Useful for tasks where duplicate values aren’t allowed, such as storing unique items.

   - Supports operations like `add`, `delete`, and `has`, and can be converted to arrays if needed.

**42. What is JSON, and how is it used in JavaScript?**
   - JSON (JavaScript Object Notation) is a text format for representing structured data.

   - Often used to transfer data between a server and client.

   - JavaScript provides `JSON.stringify()` to convert objects to JSON and `JSON.parse()` to parse JSON into JavaScript objects.

**43. How do you convert a JavaScript object to a JSON string and back?**
   - To convert an object to JSON: `JSON.stringify(object);`

   - To parse JSON into an object: `JSON.parse(jsonString);`

   - These methods are commonly used for data exchange, especially with APIs.

**44. What are default parameters in functions?**
   - Default parameters allow functions to have default values if arguments aren’t provided.

   - For example, `function greet(name = "Guest")` assigns "Guest" if no name is passed.

   - Simplifies function logic by handling undefined arguments without conditional statements.

**45. Explain the difference between synchronous and asynchronous code.**
   - Synchronous code executes line by line, blocking further execution until the current task is complete.

   - Asynchronous code allows other tasks to run while waiting for long-running operations (like API calls).

   - JavaScript uses callbacks, promises, and async/await to handle asynchronous operations without blocking.

**46. What is the use of the `bind` method in JavaScript?**
   - `bind` creates a new function with a specified `this` value and preset arguments.

   - Useful for ensuring functions execute in a particular context, especially in event handlers and callbacks.

   - For example, `func.bind(obj)` binds `func` to `obj`’s context.

**47. What do the `call` and `apply` methods do?**
   - `call` invokes a function with a specified `this` and arguments passed individually.

   - `apply` is similar but takes arguments as an array.

   - Both are used to control the `this` value, often for reusing methods in different contexts.

**48. What is tail call optimization?**
   - Tail call optimization is a feature where recursive calls in the tail position (last action in a function) are optimized to avoid adding to the call stack.

   - Helps prevent stack overflow in recursive functions by reusing stack frames.

   - Available in strict mode, though not universally supported across environments.

**49. Explain the term “scope chain” in JavaScript.**
   - The scope chain is the series of nested scopes JavaScript follows to resolve variable references.

   - It begins with the current scope and moves outward until reaching the global scope.

   - Helps JavaScript determine variable visibility, linking inner and outer scope variables.

**50. What are ES6 classes, and how do they differ from constructor functions?**
   - ES6 classes are syntactic sugar for creating objects with a constructor-like syntax.

   - They simplify object-oriented programming with features like inheritance (`extends`) and a cleaner syntax.

   - Unlike constructor functions, classes must be instantiated with `new` and do not hoist.

**51. What is the purpose of the `super` keyword?**
   - `super` is used in ES6 classes to call parent class constructors and methods.

   - It allows a subclass to inherit and extend behavior from a parent class.

   - Essential for implementing inheritance in class-based object-oriented code.

**52. Explain the `Object.assign()` method.**
   - `Object.assign()` copies properties from one or more source objects to a target object.

   - Useful for cloning objects and merging multiple objects.

   - It performs a shallow copy, meaning it copies references to nested objects, not deep copies.

**53. How can you clone an object in JavaScript?**
   - For shallow cloning, use `Object.assign({}, obj)` or the spread operator `{...obj}`.

   - For deep cloning, `JSON.parse(JSON.stringify(obj))` works for simple data structures.

   - For complex objects, consider libraries like Lodash or structured cloning techniques.

**54. What is a WeakMap, and when should it be used?**
   - A `WeakMap` is a collection of key-value pairs where keys are objects and values can be any type.

   - Keys are weakly held, allowing garbage collection if there are no other references.

   - Useful for private data storage in objects, especially in memory-sensitive applications.

**55. What is a WeakSet, and how does it differ from a Set?**
   - `WeakSet` holds objects only, allowing garbage collection if there are no other references.

   - Unlike `Set`, it doesn’t store primitive values and cannot be iterated.

   - Best suited for cases where objects should be referenced without preventing garbage collection.

**56. Explain the difference between `.map()` and `.forEach()`.**
   - `.map()` creates a new array by applying a function to each element in the original array.

   - `.forEach()` executes a function on each array element but returns `undefined`.

   - Use `.map()` when transforming arrays and `.forEach()` for side effects like logging.

**57. What are tagged template literals?**
   - Tagged template literals allow custom processing of template literals.

   - A tag function receives template strings and values, manipulating them before output.

   - Useful for functions that need formatted output, such as templating engines or localization.

**58. How can you add and remove properties from an object?**
   - To add a property: `object.newProperty = value;` or `object["newProperty"] = value;`.

   - To delete a property: `delete object.propertyName;`.
   
   - Manipulating properties is useful for dynamic data and

 controlling object structure.

**59. What is debouncing, and how is it useful?**
   - Debouncing limits a function’s execution by setting a delay after its last invocation.

   - Commonly used to improve performance for tasks triggered frequently, like resizing or scrolling events.

   - Ensures that functions aren’t called excessively, reducing resource usage.

**60. What is throttling, and when should it be used?**
   - Throttling limits a function’s execution to once per specified time interval, regardless of how often it’s triggered.

   - Useful for optimizing tasks like scrolling or mouse movements by restricting execution frequency.
   
   - Helps in enhancing app responsiveness and preventing resource exhaustion.
