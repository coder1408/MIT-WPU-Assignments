function submitForm() {
    // Get values from the form
    const patientName = document.getElementById('patientName').value;
    const contactNo = document.getElementById('contactNo').value;
    const age = document.getElementById('age').value;
    const gender = document.getElementById('gender').value;
    const bloodGroup = document.getElementById('bloodGroup').value;
    const address = document.getElementById('address').value;
    const remarks = document.getElementById('remarks').value;

    // Create a new patient record object
    const newPatient = {
        name: patientName,
        contactNumber: contactNo,
        age: age,
        gender: gender,
        bloodGroup: bloodGroup,
        address: address,
        remarks: remarks
    };

    // Add the new patient to the table on the current page
    appendPatientToTable(newPatient);

    // Add the new patient to the table on the home page
    appendPatientToHomePageTable(newPatient);

    // You can redirect the user or perform other actions after saving the record

    // Optionally, reset the form
    document.getElementById('addPatientForm').reset();
}


function getCurrentDate() {
    const today = new Date();
    const year = today.getFullYear();
    const month = String(today.getMonth() + 1).padStart(2, '0');
    const day = String(today.getDate()).padStart(2, '0');
    return `${year}-${month}-${day}`;
}

function appendPatientToHomePageTable(patient) {
    // Get the parent window
    const parentWindow = window.opener;

    // Check if the parent window is available and the function exists
    if (parentWindow && parentWindow.appendPatientToTable) {
        // Call the function in the parent window to add the new patient
        parentWindow.appendPatientToTable(patient);
    }
}
