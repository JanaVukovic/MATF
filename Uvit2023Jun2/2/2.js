let flags = [
    {
        country: 'Italy',
        colors: ['green', 'white', 'red'],
        vertical: true
    },
    {
        country: 'Serbia',
        colors: ['red', 'blue', 'white'],
        vertical: false
    },
    {
        country: 'Afghanistan',
        colors: ['black', 'red', 'green'],
        vertical: true
    },
    {
        country: 'Austria',
        colors: ['red', 'white', 'red'],
        vertical: false
    },
    {
        country: 'Armenia',
        colors: ['darkred', 'darkblue', 'gold'],
        vertical: false
    },
    {
        country: 'Bolivia',
        colors: ['red', 'yellow', 'green'],
        vertical: false
    },
    {
        country: 'Croatia',
        colors: ['red', 'white', 'blue'],
        vertical: false
    },
    {
        country: 'Bulgaria',
        colors: ['white', 'green', 'red'],
        vertical: false
    },
    {
        country: 'Chad',
        colors: ['blue', 'yellow', 'red'],
        vertical: false
    },
    {
        country: 'Egypt',
        colors: ['darkred', 'white', 'yellow'],
        vertical: false
    },
    {
        country: 'Gabon',
        colors: ['green', 'yellow', 'blue'],
        vertical: false
    },
    {
        country: 'Germany',
        colors: ['black', 'red', 'yellow'],
        vertical: false
    },
    {
        country: 'Ghana',
        colors: ['red', 'yellow', 'green'],
        vertical: false
    },
    {
        country: 'Guinea',
        colors: ['red', 'yellow', 'green'],
        vertical: true
    },
    {
        country: 'Hungary',
        colors: ['red', 'white', 'green'],
        vertical: false
    },
    {
        country: 'Ireland',
        colors: ['green', 'white', 'orange'],
        vertical: true
    },
    {
        country: 'Luxembourg',
        colors: ['red', 'white', 'lightblue'],
        vertical: false
    },
    {
        country: 'Libya',
        colors: ['red', 'black', 'green'],
        vertical: false
    },
    {
        country: 'Mexico',
        colors: ['green', 'white', 'red'],
        vertical: true
    },
    {
        country: 'Romania',
        colors: ['blue', 'yellow', 'red'],
        vertical: true
    },
    {
        country: 'Senegal',
        colors: ['green', 'yellow', 'red'],
        vertical: true
    },
    {
        country: 'Spain',
        colors: ['red', 'gold', 'red'],
        vertical: false
    },
    {
        country: 'Slovenia',
        colors: ['white', 'blue', 'red'],
        vertical: false
    },
    {
        country: 'Yemen',
        colors: ['red', 'white', 'black'],
        vertical: false
    },
    {
        country: 'Estonia',
        colors: ['blue', 'black', 'white'],
        vertical: false
    }
]

let div = document.getElementById('show');
for(let flag of flags){
    if(!flag.vertical){
        let zastava = document.createElement('div');
        let text = document.createTextNode(flag.country);
        zastava.appendChild(text);
        let mojString = "linear-gradient(to bottom,";
        let n = flag.colors.length;
        for(let i = 0; i < n; i++){
            if(i == 0) mojString += flag.colors[i] +" "+ Math.round((i+1)*100/n)+"%,";
            else if(i != n-1){
                mojString += flag.colors[i] +" "+ Math.round((i)*100/n)+"% "+ Math.round((i+1)*100/n)+"%,";
            }else if(i == n-1){
                mojString += flag.colors[i] +" "+ Math.round((n-1)*100/n) +"%)";
            }
        }
        zastava.style.width = "150px";
        zastava.style.height = "80px";
        zastava.style.color = 'rgba(0,0,0,0)';
        zastava.style.display = "inline-block";
        zastava.style.marginRight = "50px";
        zastava.style.marginBottom = "50px";
        zastava.style.border = "solid 1px black";
//        mojString = "linear-gradient(to bottom, red 20%, blue 20% 40%, green 40%)";
        zastava.style.backgroundImage = mojString;
        zastava.addEventListener('click', function(){
            showText = zastava.textContent;
            window.alert(showText);
        });
        div.appendChild(zastava);
    }
}