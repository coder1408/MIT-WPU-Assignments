import React, { useState, useEffect } from "react";
import axios from "axios";
import "./App.css";

const App = () => {
  const [students, setStudents] = useState([]);
  const [student, setStudent] = useState({
    firstName: "",
    lastName: "",
    rollNo: "",
    password: "",
    contactNumber: "",
  });
  const [isEdit, setIsEdit] = useState(false);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState("");

  useEffect(() => {
    fetchStudents();
  }, []);

  const fetchStudents = async () => {
    setLoading(true);
    try {
      const response = await axios.get("http://localhost:5000/api/students");
      setStudents(response.data);
    } catch (err) {
      setError("Error fetching students");
    } finally {
      setLoading(false);
    }
  };

  const handleChange = (e) => {
    setStudent({ ...student, [e.target.name]: e.target.value });
  };

  const handleSubmit = async () => {
    setLoading(true);
    setError("");
    try {
      if (isEdit) {
        await axios.put(
          `http://localhost:5000/api/students/${student.rollNo}`,
          student
        );
      } else {
        await axios.post("http://localhost:5000/api/students", student);
      }
      fetchStudents();
      resetForm();
    } catch (err) {
      setError("Error saving student data");
    } finally {
      setLoading(false);
    }
  };

  const editStudent = (stud) => {
    setStudent(stud);
    setIsEdit(true);
  };

  const deleteStudent = async (rollNo) => {
    setLoading(true);
    try {
      await axios.delete(`http://localhost:5000/api/students/${rollNo}`);
      fetchStudents();
    } catch (err) {
      setError("Error deleting student");
    } finally {
      setLoading(false);
    }
  };

  const resetForm = () => {
    setStudent({
      firstName: "",
      lastName: "",
      rollNo: "",
      password: "",
      contactNumber: "",
    });
    setIsEdit(false);
  };

  return (
    <div style={styles.container}>
      <h2 style={styles.header}>Student Registration System</h2>
      {error && <p style={styles.error}>{error}</p>}
      <form style={styles.form}>
        <input
          type="text"
          name="firstName"
          placeholder="First Name"
          value={student.firstName}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="lastName"
          placeholder="Last Name"
          value={student.lastName}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="rollNo"
          placeholder="Roll No"
          value={student.rollNo}
          onChange={handleChange}
          required
          disabled={isEdit}
        />
        <input
          type="password"
          name="password"
          placeholder="Password"
          value={student.password}
          onChange={handleChange}
          required
        />
        <input
          type="text"
          name="contactNumber"
          placeholder="Contact Number"
          value={student.contactNumber}
          onChange={handleChange}
          required
        />
        <button type="button" onClick={handleSubmit} style={styles.button}>
          {isEdit ? "Update Student" : "Add Student"}
        </button>
        {isEdit && (
          <button type="button" onClick={resetForm} style={styles.button}>
            Cancel
          </button>
        )}
      </form>

      {loading ? (
        <p>Loading...</p>
      ) : (
        <>
          <h3 style={styles.header}>Student List</h3>
          <table border="1" style={styles.table}>
            <thead>
              <tr>
                <th>First Name</th>
                <th>Last Name</th>
                <th>Roll No</th>
                <th>Contact Number</th>
                <th>Actions</th>
              </tr>
            </thead>
            <tbody>
              {students.map((stud) => (
                <tr key={stud.rollNo}>
                  <td>{stud.firstName}</td>
                  <td>{stud.lastName}</td>
                  <td>{stud.rollNo}</td>
                  <td>{stud.contactNumber}</td>
                  <td>
                    <button
                      onClick={() => deleteStudent(stud.rollNo)}
                      style={styles.button}
                    >
                      Delete
                    </button>
                    <button
                      onClick={() => editStudent(stud)}
                      style={styles.button}
                    >
                      Edit
                    </button>
                  </td>
                </tr>
              ))}
            </tbody>
          </table>
        </>
      )}
    </div>
  );
};

// Basic CSS Styles
const styles = {
  container: {
    maxWidth: "800px",
    margin: "0 auto",
    padding: "20px",
  },
  header: {
    textAlign: "center",
    marginBottom: "20px",
  },
  form: {
    display: "flex",
    flexDirection: "column",
    gap: "10px",
    marginBottom: "20px",
  },
  button: {
    padding: "10px",
    marginTop: "10px",
    cursor: "pointer",
    backgroundColor: "#007BFF",
    color: "white",
    border: "none",
    borderRadius: "5px",
  },
  table: {
    width: "100%",
    textAlign: "left",
  },
  error: {
    color: "red",
  },
};

export default App;
