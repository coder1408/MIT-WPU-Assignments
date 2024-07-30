function validateForm() {
  let isValid = true;

  // Clear previous error messages
  document.getElementById("usernameError").innerText = "";
  document.getElementById("emailError").innerText = "";
  document.getElementById("phoneError").innerText = "";
  document.getElementById("passwordError").innerText = "";
  document.getElementById("confirmPasswordError").innerText = "";

  // Get form values
  const username = document.getElementById("username").value.trim();
  const email = document.getElementById("email").value.trim();
  const phone = document.getElementById("phone").value.trim();
  const password = document.getElementById("password").value.trim();
  const confirmPassword = document
    .getElementById("confirmPassword")
    .value.trim();

  // Validate username
  if (username === "") {
    document.getElementById("usernameError").innerText = "Username is required";
    isValid = false;
  }

  // Validate email
  const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]{2,3}$/;
  if (email === "" || !emailRegex.test(email)) {
    document.getElementById("emailError").innerText =
      "Enter a valid email address";
    isValid = false;
  }

  // Validate phone
  const phoneRegex = /^\d{10}$/;
  if (phone === "" || !phoneRegex.test(phone)) {
    document.getElementById("phoneError").innerText =
      "Enter a valid 10-digit phone number";
    isValid = false;
  }

  // Validate password
  const passwordRegex = /^(?=.*[A-Z])(?=.*\d)(?=.*[&$#@]).{7,}$/;
  if (password === "" || !passwordRegex.test(password)) {
    document.getElementById("passwordError").innerText =
      "Password must be at least 7 characters long and contain at least one capital letter, one digit, and one special character (&, $, #, @)";
    isValid = false;
  }

  // Validate confirm password
  if (confirmPassword === "" || confirmPassword !== password) {
    document.getElementById("confirmPasswordError").innerText =
      "Passwords do not match";
    isValid = false;
  }

  return isValid;
}

// Change image source
function changeImage() {
  const image = document.getElementById("myImage");
  image.src = image.src.includes("image1.jpeg") ? "image2.jpeg" : "image1.jpeg";
}

// Add a text node to a parent node
function addTextNode() {
  const parentNode = document.getElementById("parentNode");
  const newText = document.createTextNode("This is a new text node.");
  parentNode.appendChild(newText);
}

// Delete a node
function deleteNode() {
  const nodeToDelete = document.getElementById("nodeToDelete");
  if (nodeToDelete) {
    nodeToDelete.remove();
  }
}
