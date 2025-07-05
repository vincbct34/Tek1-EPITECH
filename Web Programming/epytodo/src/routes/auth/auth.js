const bcrypt = require('bcryptjs');
const jwt = require('jsonwebtoken');
const db = require('../../config/db');
require('dotenv').config();

module.exports = {
    register: function(req, res) {
        const { email, firstname, name, password } = req.body;

        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

        if (!emailRegex.test(email)) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }

        if (!email || !firstname || !name || !password) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }

        db.query('SELECT email FROM user WHERE email = ?', email, function(err, result) {
            if (err) {
                return res.status(500).json({ msg: "Internal Server Error" });
            }

            if (result.length > 0) {
                return res.status(409).json({ msg: "Account already exists" });
            } else {
                bcrypt.hash(password, 5, function(err, bcryptedPassword) {
                    if (err) {
                        return res.status(500).json({ msg: "Internal Server Error" });
                    }
                    db.query('INSERT INTO user (email, name, firstname, password) VALUES (?, ?, ?, ?)', [email, name, firstname, bcryptedPassword], function(err, result) {
                        if (err) {
                            return res.status(500).json({ msg: "Internal Server Error" });
                        }
                        const user_id = result.insertId;
                        const token = jwt.sign({ user_id, email, firstname, name }, process.env.SECRET, { expiresIn: '1h' });
                        return res.status(201).json({ token });
                    });
                });
            }
        });
    },

    login: function(req, res) {
        const { email, password } = req.body;

        if (!email || !password) {
            return res.status(400).json({ msg: "Bad Parameter" });
        }

        db.query('SELECT * FROM user WHERE email = ?', email, function(err, result) {
            if (err) {
                return res.status(500).json({ msg: "Internal Server Error" });
            }

            if (result.length === 0) {
                return res.status(401).json({ msg: "Invalid Credentials" });
            } else {
                bcrypt.compare(password, result[0].password, function(err, resCrypt) {
                    if (err) {
                        return res.status(500).json({ msg: "Internal Server Error" });
                    }
                    if (resCrypt) {
                        const { id: user_id, firstname, name } = result[0];
                        const token = jwt.sign({ user_id, email, firstname, name }, process.env.SECRET, { expiresIn: '1h' });
                        return res.status(200).json({ token });
                    } else {
                        return res.status(401).json({ msg: "Invalid Credentials" });
                    }
                });
            }
        });
    }
};
