const jwt = require('jsonwebtoken');
require('dotenv').config();

module.exports = function(req, res, next) {
	if (req.header('Authorization') === undefined) {
		return res.status(401).json({ msg: 'No token, authorization denied' });
	}

    const token = req.header('Authorization').replace('Bearer ', '');

    if (!token) {
        return res.status(401).json({ msg: 'No token, authorization denied' });
    }

    try {
        const decoded = jwt.verify(token, process.env.SECRET);

        req.user = decoded;
        next();
    } catch (e) {
        res.status(401).json({ msg: 'Token is not valid' });
    }
};
