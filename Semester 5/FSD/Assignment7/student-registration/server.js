const express = require("express");
const mongoose = require("mongoose");
const cors = require("cors");
const bodyParser = require("body-parser");

const app = express();
const port = 5000;

app.use(cors());
app.use(bodyParser.json());

// Connect to MongoDB
mongoose.connect("mongodb://localhost:27017/studentDB", {
  useNewUrlParser: true,
  useUnifiedTopology: true,
});

const studentSchema = new mongoose.Schema({
  firstName: String,
  lastName: String,
  rollNo: String,
  password: String,
  contactNumber: String,
});

const Student = mongoose.model("Student", studentSchema);

// Insert Student Record
app.post("/api/students", (req, res) => {
  const student = new Student(req.body);
  student
    .save()
    .then(() => res.status(200).json({ message: "Student added successfully" }))
    .catch((error) => res.status(400).json({ error }));
});

// Fetch All Students
app.get("/api/students", (req, res) => {
  Student.find()
    .then((students) => res.json(students))
    .catch((error) => res.status(400).json({ error }));
});

// Update Student Record
app.put("/api/students/:rollNo", (req, res) => {
  Student.findOneAndUpdate({ rollNo: req.params.rollNo }, req.body, {
    new: true,
  })
    .then((student) => res.json(student))
    .catch((error) => res.status(400).json({ error }));
});

// Delete Student Record
app.delete("/api/students/:rollNo", (req, res) => {
  Student.findOneAndDelete({ rollNo: req.params.rollNo })
    .then(() => res.json({ message: "Student deleted successfully" }))
    .catch((error) => res.status(400).json({ error }));
});

app.listen(port, () => console.log(`Server running on port ${port}`));
