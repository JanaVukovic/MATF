const accountModel = require('../models/account');

module.exports.prikaziTabelu = async function (req, res, next) {
    try {        
      let account = await accountModel.getAccounts();
      res.render('naslovna.ejs', {account:account, list:null});
    } catch (err) {
        next(err);
    }
};

module.exports.dodajNalog = async function (req, res, next) {
  try {        
    let razbi = req.body.ime.split(' ');
    await accountModel.createAccount(razbi[0], razbi[1], req.body.stanje);
    res.redirect('/bank/');
  } catch (err) {
      next(err);
  }
};

module.exports.prikaziBankomat = async function (req, res, next) {
  try {
    let list = await accountModel.getAccounts();
    res.render('naslovna.ejs', {account: null, list:list});
  } catch (err) {
      next(err);
  }
};

module.exports.transakcija = async function (req, res, next) {
  try {        
    await accountModel.executeTransaction(req.body.osoba, req.body.kolicina, req.body.opcija);
    res.redirect('/bank/bankomat');
  } catch (err) {
      next(err);
  }
};