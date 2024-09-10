const mongoose = require('mongoose');

const mojaSchema = new mongoose.Schema({
    ime: {type:String, required:true},
    prezime: {type:String, required:true},
    stanje:{type:Number, required:true, default:0}
},{collection:'accounts'});

const mojModel = mongoose.model('Account', mojaSchema);

module.exports.getAccounts = async function () {
    let acc = await mojModel.find().exec();
    acc.sort((a, b)=>{
        if(b.ime < a.ime)return 1;
        else if(b.ime == a.ime){
            if(b.prezime < a.prezime)return 1;
            return -1;
        }return -1;
    })
    return acc;
};

module.exports.createAccount = async function (ime, prezime, stanje) {
    await mojModel.create({ime:ime, prezime:prezime, stanje:stanje});
};

module.exports.executeTransaction = async function (_id, kolicina, tip) {
    let user = _id.split(' ');
    let iznos = kolicina;
    if(tip == "podigni")iznos*=-1;
    let a = await mojModel.find({ime:user[0], prezime:user[1]});
    console.log("ovde je ok", a);
    await mojModel.updateOne({ime:user[0], prezime:user[1]}, {$inc:{stanje:iznos}}, {upsert:false});
};