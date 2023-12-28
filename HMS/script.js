const usernameInput = document.getElementById('username');
const passwordInput = document.getElementById('password');
const loginButton = document.querySelector('button');

loginButton.addEventListener('click', (event) => {
  event.preventDefault(); // Prevent the default form submission behavior

  const username = usernameInput.value.trim();
  const password = passwordInput.value.trim();

  if (username === 'mith' && password === 'mith123') {
    window.location.href = 'HomePage.html'; // Redirect to home page
  } else {
    alert('Invalid username or password!');
  }
}, { once: true });


