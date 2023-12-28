document.addEventListener('DOMContentLoaded', function () {
  const patientForm = document.querySelector('.patient-form');

  patientForm.addEventListener('submit', function (event) {
      event.preventDefault(); // Prevents the default form submission behavior

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

      // Perform any further actions like sending the data to the server

      // For now, you can log the new patient object to the console
      console.log('New Patient Record:', newPatient);

      // You can redirect the user or perform other actions after saving the record

      // Optionally, reset the form
      patientForm.reset();
  });
});
