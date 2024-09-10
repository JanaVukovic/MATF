const mongoose = require('mongoose')


const mojaSchema = new mongoose.Schema({
    imePrezime:{
        type: String,
        required:true
    },
    razred:{
        type: Number,
        required:true
    },
    odeljenje:{
        type: Number,
        required:true
    },
    ocene:{
        type:[{predmet:String, ocena:Number}],
        required: true
    },
    slika:{
        type: String,
        required: true
    }
},{collection: 'ucenici'});

const mojModel = mongoose.model('Ucenik', mojaSchema);

async function dohvatiOceneUcenika(imePrezime) {
	let student = await mojModel.find({imePrezime:imePrezime}).exec();
    return student[0];
} 


async function dodajNovuOcenu(imePrezime, predmet, ocena){
    let student1 = await mojModel.find({imePrezime:imePrezime}).exec();
    let student = student1[0];
    let change = -1;
    for(let i = 0; i < student.ocene.length; i++){
        if(predmet == student.ocene[i].predmet){
            change = 1;
            student.ocene[i].ocena = ocena;
        }
    }
    if(change == -1){
        student.ocene.push({predmet:predmet, ocena:ocena});
    }
    await mojModel.updateOne({imePrezime:imePrezime}, {$set:{ocene:student.ocene}}).exec();
}



module.exports = {
    dohvatiOceneUcenika,
    dodajNovuOcenu
};
