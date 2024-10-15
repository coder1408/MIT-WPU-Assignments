import express from "express";
const router = express.Router();
const users = [
  {
    firstName: "Tom",
    lastName: "Gray",
    age: 23,
  },
  {
    firstName: "Jill",
    lastName: "Kemp",
    age: 25,
  },
];
router.get("/", (req, res) => {
  console.log(users);
  res.send(users);
});
router.post("/", (req, res) => {
  const user = req.body;
  users.push(user);
  res.send(`User with the name ${user.firstName} added to the database`);
});
export default router;
