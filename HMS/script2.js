const logOutButton = document.querySelector('.logout');

logOutButton.addEventListener('click', () => {
    alert('You have been logged out!');
    window.location.href = 'HMS.html';
});

const addPatientButton = document.querySelector('.left-panel li:nth-child(1) a');

addPatientButton.addEventListener('click', () => {
    window.location.href = 'APR.html';
});
