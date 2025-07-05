var db = require('../../config/db');

function formatDate(date) {
    const d = new Date(date);
    const year = d.getFullYear();
    const month = String(d.getMonth() + 1).padStart(2, '0');
    const day = String(d.getDate()).padStart(2, '0');
    const hours = String(d.getHours()).padStart(2, '0');
    const minutes = String(d.getMinutes()).padStart(2, '0');
    const seconds = String(d.getSeconds()).padStart(2, '0');
    return `${year}-${month}-${day} ${hours}:${minutes}:${seconds}`;
}

module.exports = {
    all_todo: function(req, res) {
        db.query('SELECT * FROM todo', (err, result) => {
            if (err) {
                console.error('Error fetching todos:', err);
                res.status(500).json({ "msg": "Internal Server Error" });
                return;
            }
            result.due_time = formatDate(result.due_time);
            res.status(200).json(result);
        });
    },

    todo_id: function(req, res) {
        var id = req.params.id;

        db.query('SELECT * FROM todo WHERE id = ?', [id], (err, result) => {
            if (err) {
                console.error(`Error fetching todo with id ${id}:`, err);
                res.status(500).json({ "msg": "Internal Server Error" });
                return;
            }
            if (result.length === 0) {
                res.status(404).json({ "msg": "Not found" });
                return;
            }
            result[0].due_time = formatDate(result[0].due_time);
            res.status(200).json(result[0]);
        });
    },

    create_todo: function(req, res) {
        var title = req.body.title;
        var description = req.body.description;
        var due_time = req.body.due_time;
        var user_id = req.body.user_id;
        var status = req.body.status;

        if (!title || !description || !due_time || !user_id || !status) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }

        db.query('INSERT INTO todo (title, description, due_time, user_id, status) VALUES (?, ?, ?, ?, ?)', [title, description, due_time, user_id, status], function(err, result) {
            if (err) {
                console.error('Error inserting todo:', err);
                res.status(500).json({ "msg": "Internal Server Error" });
                return;
            }
            var id_task = result.insertId;
            db.query('SELECT * FROM todo WHERE id = ?', [id_task], function (err, result) {
                if (err) {
                    console.error(`Error fetching newly created todo with id ${id_task}:`, err);
                    res.status(500).json({ "msg": "Internal Server Error" });
                    return;
                }
                result[0].due_time = formatDate(result[0].due_time);
                res.status(201).json(result[0]);
            });
        });
    },

    delete_task_by_id: function(req, res) {
        var id = req.params.id;

        db.query('DELETE FROM todo WHERE id = ?', [id], function(err, result) {
            if (result.affectedRows === 0) {
                res.status(404).json({ "msg": "Not found" });
                return;
            }
            res.status(200).json({ "msg": `Successfully deleted record number: ${id}` });
        });
    },

    update_task_by_id: function(req, res) {
        var id = req.params.id;
        var { title, description, due_time, user_id, status } = req.body;
    
        if (!title || !description || !due_time || !user_id || !status) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }
    
        db.query('UPDATE todo SET title = ?, description = ?, due_time = ?, user_id = ?, status = ? WHERE id = ?', [title, description, due_time, user_id, status, id], function(err, result) {
            if (err) {
                console.error(`Error updating todo with id ${id}:`, err);
                return res.status(500).json({ "msg": "Internal Server Error" });
            }

            if (result.affectedRows === 0) {
                return res.status(404).json({ "msg": "Not found" });
            }
    
            db.query('SELECT id, title, description, created_at, due_time, user_id, status FROM todo WHERE id = ?', [id], function(err, result) {
                if (err) {
                    console.error(`Error fetching updated todo with id ${id}:`, err);
                    return res.status(500).json({ "msg": "Internal Server Error" });
                }
                result[0].due_time = formatDate(result[0].due_time);
                return res.status(200).json(result[0]);
            });
        });
    }
};
