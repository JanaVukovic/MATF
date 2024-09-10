const express = require("express");

const router = express.Router();

const controller = require('../controller/knjige')

router.get('/',controller.prikaziPocetnu);

router.get('/knjiga', controller.dohvatiKnjigu);

router.post('/novaknjiga', controller.unesiKnjigu);

module.exports = router;