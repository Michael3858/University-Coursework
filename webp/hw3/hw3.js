setInterval("print()", "400");

document.addEventListener('keydown', Del);
var txt = '';

function Del(e) {
    var lastWord = txt.innerHTML.substr(-1);
    if (lastWord == e.key.toUpperCase()) {
        txt.innerHTML = txt.innerHTML.substr(0, txt.innerHTML.length - 1);
    }
}

function print() {
    var result = Math.floor(Math.random() * 26) + 65;   
    var RandomChar = String.fromCharCode(result);

    txt=document.getElementById("mi")
    txt.innerHTML = RandomChar + txt.innerHTML;
}