const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const db = require('../../config/db');

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
    all_user: function(req, res) {
        const userId = req.user.user_id;

        db.query('SELECT * FROM user WHERE id = ?', [userId], (err, result) => {
            if (err) {
                console.error('Error fetching user:', err);
                res.status(500).json({ "msg": "Internal Server Error" });
                return;
            }

            if (result.length === 0) {
                res.status(404).json({ "msg": "Not found" });
                return;
            }
            result[0].created_at = formatDate(result[0].created_at);
            res.status(200).json(result[0]);
        });
    },

    user_info: function(req, res) {
        const identifier = req.params.identifier;

        const isEmail = /^[^\s@]+@[^\s@]+\.[^\s@]+$/.test(identifier);
        const isId = !isNaN(identifier);

        if (isEmail) {
            db.query('SELECT * FROM user WHERE email = ?', [identifier], (err, result) => {
                if (err) {
                    console.error(`Error fetching user with email ${identifier}:`, err);
                    res.status(500).json({ "msg": "Internal Server Error" });
                    return;
                }
                if (result.length === 0) {
                    res.status(404).json({ "msg": "Not found" });
                    return;
                }
                result[0].created_at = formatDate(result[0].created_at);
                res.status(200).json(result[0]);
            });
        } else if (isId) {
            db.query('SELECT * FROM user WHERE id = ?', [identifier], (err, result) => {
                if (err) {
                    console.error(`Error fetching user with id ${identifier}:`, err);
                    res.status(500).json({ "msg": "Internal Server Error" });
                    return;
                }
                if (result.length === 0) {
                    res.status(404).json({ "msg": "Not found" });
                    return;
                }
                result[0].created_at = formatDate(result[0].created_at);
                res.status(200).json(result[0]);
            });
        } else {
            res.status(400).json({ "msg": "Bad Parameter" });
        }
    },

    update_user: function(req, res) {
        const id = req.params.id;

        const { email, name, firstname, password } = req.body;

        if (!email || !name || !firstname || !password) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }

        bcrypt.hash(password, 5, function(err, bcryptedPassword) {
            if (err) {
                return res.status(500).json({ msg: "Internal Server Error" });
            }

            db.query('UPDATE user SET email = ?, name = ?, firstname = ?, password = ? WHERE id = ?', [email, name, firstname, bcryptedPassword, id], (err, result) => {
				if (id != req.user.user_id) {
					return res.status(403).json({ "msg": "Forbidden" });
				}

                if (err) {
                    console.error(`Error updating user with id ${id}:`, err);
                    res.status(500).json({ "msg": "Internal Server Error" });
                    return;
                }
				db.query('SELECT * FROM user WHERE id = ?', [id], (err, result) => {
                    result[0].created_at = formatDate(result[0].created_at);
					res.status(200).json(result[0]);
				});
            });
        });
    },

    delete_user: function(req, res) {
        const id = req.params.id;

        db.query('DELETE FROM user WHERE id = ?', [id], (err, result) => {
            if (err) {
                console.error(`Error deleting user with id ${id}:`, err);
                res.status(500).json({ "msg": "Internal Server Error" });
                return;
            }
            if (result.affectedRows === 0) {
                res.status(404).json({ "msg": "Not found" });
                return;
            }
			res.status(200).json({ "msg": `Successfully deleted record number: ${id}` });
        });
    },
};
