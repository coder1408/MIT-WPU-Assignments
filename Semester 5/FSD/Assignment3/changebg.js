document.getElementById("colorButton").addEventListener("click", function () {
  // Array of colors
  const colors = [
    "#FF5733",
    "#33FF57",
    "#3357FF",
    "#F333FF",
    "#FF8C33",
    "#33FFF3",
  ];

  // Select a random color from the array
  const randomColor = colors[Math.floor(Math.random() * colors.length)];

  // Change the background color of the body
  document.body.style.backgroundColor = randomColor;
});
