function validateForm() {
  let isValid = true;

  // Clear previous error messages
  $("#usernameError").text("");
  $("#emailError").text("");
  $("#phoneError").text("");
  $("#passwordError").text("");
  $("#confirmPasswordError").text("");

  // Get form values
  const username = $("#username").val().trim();
  const email = $("#email").val().trim();
  const phone = $("#phone").val().trim();
  const password = $("#password").val().trim();
  const confirmPassword = $("#confirmPassword").val().trim();

  // Validate username
  if (username === "") {
    $("#usernameError").text("Username is required");
    isValid = false;
  }

  // Validate email
  const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]{2,3}$/;
  if (email === "" || !emailRegex.test(email)) {
    $("#emailError").text("Enter a valid email address");
    isValid = false;
  }

  // Validate phone
  const phoneRegex = /^\d{10}$/;
  if (phone === "" || !phoneRegex.test(phone)) {
    $("#phoneError").text("Enter a valid 10-digit phone number");
    isValid = false;
  }

  // Validate password
  const passwordRegex = /^(?=.*[A-Z])(?=.*\d)(?=.*[&$#@]).{7,}$/;
  if (password === "" || !passwordRegex.test(password)) {
    $("#passwordError").text(
      "Password must be at least 7 characters long and contain at least one capital letter, one digit, and one special character (&, $, #, @)"
    );
    isValid = false;
  }

  // Validate confirm password
  if (confirmPassword === "" || confirmPassword !== password) {
    $("#confirmPasswordError").text("Passwords do not match");
    isValid = false;
  }

  return isValid;
}

// Change image source
function changeImage() {
  const image = $("#myImage");
  image.attr(
    "src",
    image.attr("src").includes("image1.jpeg") ? "image2.jpeg" : "image1.jpeg"
  );
}

// Add a text node to a parent node
function addTextNode() {
  const newText = document.createTextNode("This is a new text node.");
  $("#parentNode").append(newText);
}

// Delete a node
function deleteNode() {
  $("#nodeToDelete").remove();
}

// jQuery operations
$(document).ready(function () {
  // Change button text
  $("#changeTextButton").click(function () {
    $(this).text("Button Text Changed");
  });

  // Set background image using jQuery CSS property
  $("#setBackgroundButton").click(function () {
    $("body").css("background-image", "url('background.jpg')");
  });

  // Access HTML form data using jQuery
  $("#accessFormDataButton").click(function () {
    const formData = {
      username: $("#username").val(),
      email: $("#email").val(),
      phone: $("#phone").val(),
      password: $("#password").val(),
      confirmPassword: $("#confirmPassword").val(),
    };
    console.log(formData);
    alert(JSON.stringify(formData));
  });

  // Add attribute using jQuery
  $("#addAttributeButton").click(function () {
    $("input").attr("placeholder", "Enter value");
  });
});
