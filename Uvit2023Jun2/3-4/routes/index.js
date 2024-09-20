const express = require("express");

const router = express.Router();

const controller = require('../controller/turniri')

router.get('/', controller.prikaziPocetnu);

router.get('/turnir', controller.prikaziTurnir);
router.get('/unesiturnir', controller.unesiMec);


module.exports = router;