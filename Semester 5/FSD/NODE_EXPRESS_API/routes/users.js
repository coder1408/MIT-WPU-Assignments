import express from 'express';
import {v4 as uuidv4} from 'uuid';

const router = express.Router();

let users = [
    {
        firstName: "John",
        lastName: "Doe",
        age: 25
    },
    {
        firstName: "Jane",
        lastName: "Doe",
        age: 24
    }
];
router.get('/',(req,res)=>{
    console.log(users);
    res.send(users);
});
router.post('/',(req,res)=>{
    const user = req.body;
    const userId = uuidv4();
    const userWithId ={...user,id:userId};
    users.push(userWithId);
    res.send(`User with the name ${user.firstName} added to the database `);

});
router.get('/:id',(req,res)=>{
   const{id}=req.params;
   const foundUser = users.find((user)=>user.id==id)
   res.send(foundUser);
});
router.delete('/:id',(req,res)=>{
    const { id } = req.params;
    users = users.filter((user)=> user.id != id);
    res.send(`User with the id ${id} deleted from the database`);
});
router.patch('/:id', (req, res) => {
    const { id } = req.params;
    const { firstName, lastName, age } = req.body;

    // Find the user by ID
    const user = users.find((user) => user.id == id);

    // Check if the user exists
    if (!user) {
        return res.status(404).send(`User with the id ${id} not found`);
    }

    // Update user details if provided
    if (firstName) {
        user.firstName = firstName;
    }
    if (lastName) {
        user.lastName = lastName;
    }
    if (age) {
        user.age = age;
    }

    res.send(`User with the id ${id} has been updated`);
});

export default router;
