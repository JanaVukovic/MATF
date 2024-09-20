const express = require('express');

const router = express.Router();

const userListController = require('../controllers/userList');
router.get('/userList', userListController.prikaziPocetnu);
router.get('/user/', userListController.obrisi);
router.post('/starost/', userListController.samo);
module.exports = router;
