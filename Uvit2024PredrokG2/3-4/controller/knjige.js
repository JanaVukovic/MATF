const knjigeModel = require('../model/knjige');


async function prikaziPocetnu(req, res, next) {
    try {
        let knjige = await knjigeModel.dohvatiKnjige();
        knjige.sort((a, b)=>{
            if(a.read == b.read)return b.year-a.year;
            if(!b.read) return 1;
            else return -1;
        });
        res.render('pocetna.ejs', {knjige:knjige});
    } catch(err){
        next(err);
    }
}


async function dohvatiKnjigu(req, res, next) {
    try {
        let knjiga = await knjigeModel.dohvatiKnjigu(req.query.id);
        console.log(knjiga);
        res.render('knjiga.ejs', {knjiga: knjiga});
    } catch(err){
        next(err);
    }
}


async function unesiKnjigu(req, res, next) {
    try {
        await knjigeModel.unesiKnjigu(req.body.title, req.body.author, req.body.year, req.body.pages);
        res.redirect('/');
    } catch(err){
        next(err);
    }
}


module.exports = {
    prikaziPocetnu,
    dohvatiKnjigu,
    unesiKnjigu
};