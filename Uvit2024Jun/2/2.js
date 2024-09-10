let niz = {0:"1.jpeg", 1:"2.webp",2:"1.jpeg", 3:"5.webp", 4:"7.webp", 5:"3.jpeg", 6:"2.webp", 7:"4.jpg", 8:"6.jpeg", 9:"5.webp",10:"8.jpg",
11:"4.jpg",12:"6.jpeg",13:"3.jpeg",
14:"8.jpg", 15:"7.webp"};

let prevselect = -1;

let slike = document.querySelectorAll('td');
if(slike != null){
    for(let i = 0; i < slike.length; i++){
        slike[i].addEventListener('click', prikazi);
    }
}
function prikazi(event){
    let num = Number.parseInt(event.target.id.slice(2, event.target.id.length))-1;
    console.log(num + " " + prevselect);
    slike[num].style.backgroundImage = "url('"+ niz[num] +"')";
    if(prevselect == -1){
        console.log("Prvi");
        prevselect = num;
    }else if(prevselect != num){
        console.log("Drugi");
        let pogodili = false;
        if(num == 0 && prevselect == 2){
            pogodili = true;
        }else if(num == 2 && prevselect == 0){
            pogodili = true;
        }else if(num == 1 && prevselect == 6){
            pogodili = true;
        }else if(num == 6 && prevselect == 1){
            pogodili = true;
        }else if(num == 3 && prevselect == 9){
            pogodili = true;
        }else if(num == 9 && prevselect == 3){
            pogodili = true;
        }else if(num == 4 && prevselect == 15){
            pogodili = true;
        }else if(num == 15 && prevselect == 4){
            pogodili = true;
        }else if(num == 5 && prevselect == 13){
            pogodili = true;
        }else if(num == 13 && prevselect == 5){
            pogodili = true;
        }else if(num == 7 && prevselect == 11){
            pogodili = true;
        }else if(num == 11 && prevselect == 7){
            pogodili = true;
        }else if(num == 8 && prevselect == 12){
            pogodili = true;
        }else if(num == 12 && prevselect == 8){
            pogodili = true;
        }else if(num == 0 && prevselect == 1){
            pogodili = true;
        }else if(num == 10 && prevselect == 14){
            pogodili = true;
        }else if(num == 14 && prevselect == 10){
            pogodili = true;
        }
        setTimeout(function(){
        if(pogodili){
            console.log("Pogodak");
            slike[num].style.visibility = "hidden";
            slike[prevselect].style.visibility = "hidden";
            slike[prevselect].removeEventListener("click", prikazi, true);
            prevselect = -1;
            slike[num].removeEventListener("click", prikazi, true);
        }else{
            console.log("Rip");
            slike[num].style.backgroundImage = "";
            slike[prevselect].style.backgroundImage = "";
            prevselect = -1;
        }
    }, 1000);
    }
}