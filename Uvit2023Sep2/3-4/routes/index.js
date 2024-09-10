const express = require("express");

const router = express.Router();

const controller = require('../controller/ucenik');

router.post('/unos', controller.unesiOcenu);
router.get('/ucenikoveOcene', controller.prikaziOcene);
router.get('/', controller.prikaziPocetnu);

module.exports = router;
