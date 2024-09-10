const mongoose = require('mongoose')

const mojaSchema = new mongoose.Schema({
    _id:{type: mongoose.Schema.Types.ObjectId},
    title:{type: String, required: true},
    author:{type: String},
    pages:{type: Number},
    year:{type: Number},
    read:{type: Boolean, default: false}
},{collection:'knjige'});

const mojmodel = mongoose.model('Knjige', mojaSchema);

async function dohvatiKnjige() {
    let knjige = await mojmodel.find().exec();
    return knjige;
} 


async function unesiKnjigu(naslov, pisac, godina, strane) {
    let id = new mongoose.Types.ObjectId();
    await mojmodel.create({_id:id, title:naslov, author:pisac, pages:strane, year:godina, read:false});
}

async function dohvatiKnjigu(id) {
    let knjiga = await mojmodel.find({_id: id});
    return knjiga[0];
} 

module.exports = {
    dohvatiKnjige, 
    unesiKnjigu,
    dohvatiKnjigu
};