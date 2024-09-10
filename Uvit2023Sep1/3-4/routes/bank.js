const express = require('express');

const router = express.Router();

const bankController = require('../controllers/bank');

router.get('/bankomat', bankController.prikaziBankomat);

router.post('/dodaj', bankController.dodajNalog);

router.post('/transakcija/', bankController.transakcija)

router.get('/', bankController.prikaziTabelu);


module.exports = router;
