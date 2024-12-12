#### => RECURSION VISUALISER

This tool allows us to generate recursion tree for any custom made C++ recursion function.
It helps programmers to understand Recursion in a better way & increase their problems solving skill. Generally Recursion & DP based problems.

It is made using NextJS framework & TypeScript programming language.
I've used TailWind CSS for effecient & responsive UI, Axios for API fetching & HTTP Handling, CodeMirror-plugin for Integrated IDE, JUDGE CE API for compiling the code and REACT-FLOW library for tree-visualisation.

NOW LET ME TELL YOU HOW THIS TOOL WORKS :-

1. When one has completed writing the C++ recursion function. They have to modify it a little by passing one extra integer variable in that recursion function.And follow the instructions given to construct nodes of recursion tree using Tree Visualiser class. The informations about the recursion tree will now be stored in a Adjacency List when recursion function will execute.

2. Reingold-Tilford Tree Drawing Algorithm is used to assign coordinates to each node of the tree, so the nodes deosn't overlap.
This is the most complicated part of the project from my view. As it took me hours of research & implementations to finally 
complete this part.

3. This tree data will look like JSON object which is passed react-flow library as a parameter to plot the recursion tree.

---

#### => RADIO PLAYER APP

1. This radio app made with flutter features an open source Radio Api enabling it to provide upto 45000+ radio channels across worldwide. This app is currently published it on playstore.

2. Inside this app, one can get top-voted radio channels & top countries based on radio channels on their homepage. Here, I've also implemented search of radio channels based on tags like [channel_names, countries, genre & language]. One can also add radio-channels to thier fav-list, This fav-list data is stored in cloud storage known as Firestore database. 

3. While building it, I focused on creating a smooth and intuitive UI by integrating Hero Animations for transitions and a Carousel Slider for easy horizontal navigation.

4. I've also used Pagination to improve performance & allowing users to browse channels seamlessly.

5. I've used Firebase for managing secure Google sign-ins.

6. It focuses on modular directory structure which ensures scalability.

7. This app’s responsive design adapts seamlessly across multiple devices.

8. Using OOP and dependency injection, I've created an optimized, maintainable codebase prepared for future updates.

---

#### => DISCUSSIFY CHAT APPLICATION 

1. This is a real-time web based chat-appication. One of my FULL-STACK-WEB-DEVELOPMENT-PROJECT.

2. It's frontend is made using Vite, React, TypeScript, TailWind CSS & Daisy UI. I've used Axios for API Handling on the frontend side.

3. It's backend is made using NodeJS, ExpressJS, MongoDB & WebSocket. It feature JWT Authentication.

//-----------------------

1. I have also implemented a logger in the backend. Which Logs all api-calls along with is details like STATUS_CODE | TYPE OF API CALL | END_POINT | RESPONSE_TIME 
| RES_BODY | REQ_BODY.

2. This feature is comes in handy while developing the application as it's helps to make debugging process more effecient. 

3. I've implemented 2 major features using web-sockets.
a. SHOW ONLINE STATUS of each user who are currently active on the appication.
B. Realtime automatic message update. Where user will not have to refresh the page to view new messages.

//-----------------------

1. This projects focuses on modular directory structure which ensures scalability and maintainable codebase prepared for future updates.

2. The user-interface of this web-site offers DARK and LIGHT MODE with a beautiful animated theme switching.

3. It has a responsive UI which helps to adapts seamlessly across multiple devices.

---

#### => NOTES APP 

1. One of my initial Project, when i was on my learning curve & exploring diffrent tech-stacks.

2. It's features CRUD functionality.

3. It's backend & frontend both are written in Dart programming language.

4. This project uses Firestore database which is based on NoSQL.

5. It has Google-O-Auth implemented for login purposes.

6. All the notes are stored in the firestore database so that you can access it from any android phone using your login credentials.