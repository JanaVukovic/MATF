let div = document.getElementById('content');

div.style.width = '208px';
div.style.position = "relative";

let box1 = document.createElement('div');
box1.style.backgroundColor = 'green';
box1.style.width = '100px';
box1.style.height = '306px';
box1.style.float = "left";
box1.style.border = "2px black solid";
box1.style.margin = "0 0 0 0";
div.appendChild(box1);


let div1 = document.createElement('div');
div1.style.float = "right";
div1.style.width = "104px";

let box2 = document.createElement('div');
box2.style.backgroundColor = 'red';
box2.style.width = '100px';
box2.style.height = '100px';

let box3 = document.createElement('div');
box3.style.backgroundColor = 'blue';
box3.style.width = '100px';
box3.style.height = '100px';

let box4 = document.createElement('div');
box4.style.backgroundColor = 'yellow';
box4.style.width = '100px';
box4.style.height = '100px';

box2.style.border = "2px black solid";
box3.style.border = "2px black solid";
box4.style.border = "2px black solid";


div1.appendChild(box2);
div1.appendChild(box3);
div1.appendChild(box4);

div.appendChild(div1);

let box = [];
box.push(box1, box2, box3, box4);

console.log(box);

for(let i = 0; i < 4; i++){
    console.log(box[i].style.backgroundColor);
}

div.addEventListener('click', function(){
    let colorfirst = box4.style.backgroundColor;
    let color = box3.style.backgroundColor;
    box4.style.backgroundColor = color;
    let c2 = box2.style.backgroundColor;
    box3.style.backgroundColor = c2;
    let c3 = box1.style.backgroundColor;
    box2.style.backgroundColor = c3;
    box1.style.backgroundColor = colorfirst;
});