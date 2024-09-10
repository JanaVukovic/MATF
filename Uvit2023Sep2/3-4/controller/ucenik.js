const mongoose = require('mongoose');
const ucenikModel = require('../model/ucenik');


async function prikaziPocetnu(req, res, next) {
    try {
        res.render('pocetna.ejs');
    } catch(err){
        next(err);
    }
}


async function prikaziOcene(req, res, next) {
    try {
        let student = await ucenikModel.dohvatiOceneUcenika(req.query.imePrezime);
        if(student == null)res.render('pocetna.ejs');
        else{res.render('ocene.ejs', {student: student, fix:""})};
    } catch(err){
        next(err);
    }
}


async function unesiOcenu(req, res, next){
	try {
        let student = await ucenikModel.dohvatiOceneUcenika(req.body.imePrezime);
        let ocena = -1;
        for(let i = 0; i < student.ocene.length; i++){
            if(student.ocene[i].predmet == req.body.predmet){
                ocena = student.ocene[i].ocena;
                break;
            }
        }
        await ucenikModel.dodajNovuOcenu(req.body.imePrezime, req.body.predmet, req.body.ocena);
        let student2 = await ucenikModel.dohvatiOceneUcenika(req.body.imePrezime);
        let poruka = "";
        console.log(ocena);
        if(ocena != -1 && ocena > req.body.ocena) poruka = poruka+"Popravila/o ocenu";
        if(ocena != -1 && ocena < req.body.ocena) poruka = poruka+"Pokvarila/o ocenu";
        console.log(poruka);
        res.render('ocene.ejs', {student:student2, fix:poruka});
    } catch(err){
        next(err);
    }
}




module.exports = {
    prikaziPocetnu,
    prikaziOcene,
    unesiOcenu
};
