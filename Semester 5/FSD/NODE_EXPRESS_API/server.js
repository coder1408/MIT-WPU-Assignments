import express from "express";
import usersRouter from "./users.js"; // Adjust the path based on your project structure

const app = express();
const PORT = process.env.PORT || 3000;

app.use(express.json()); // For parsing application/json

// Default route
app.get("/", (req, res) => {
  res.send("Welcome to the API! Use /users to access user data.");
});

// Users router
app.use("/users", usersRouter);

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});
