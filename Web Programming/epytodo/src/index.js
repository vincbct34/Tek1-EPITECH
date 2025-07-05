var express = require('express');
var bodyParser = require('body-parser');
require('dotenv').config();
var authRoutes = require('./routes/auth/auth');
var userRoutes = require('./routes/user/user');
var todoRoutes = require('./routes/todos/todos');
var auth = require('./middleware/auth');

const app = express();

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.post('/register', authRoutes.register);
app.post('/login', authRoutes.login);
app.get('/user', auth, userRoutes.all_user);
app.get('/user/todos', auth, todoRoutes.all_todo);
app.get('/users/:identifier', auth, userRoutes.user_info);
app.put('/users/:id', auth, userRoutes.update_user);
app.delete('/users/:id', auth, userRoutes.delete_user);
app.get('/todos', auth, todoRoutes.all_todo);
app.get('/todos/:id', auth, todoRoutes.todo_id);
app.post('/todos', auth, todoRoutes.create_todo);
app.put('/todos/:id', auth, todoRoutes.update_task_by_id);
app.delete('/todos/:id', auth, todoRoutes.delete_task_by_id);

app.listen(process.env.PORT, () => {
    console.log(`Server running on port ${process.env.PORT}`);
});