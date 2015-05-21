/*passed jslint 11/21/13 browser: true, passfail: true, white: true */
function searchKeyPress(e) {
    'use strict';
    // look for window.event in case event isn't passed in
    if (e === 'undefined' && window.event) { e = window.event; }
    if (e.keyCode === 13) {
        document.getElementById('guess').click();
    }
}
//Create object literal to hold key properities (variables) for game
var Game = {
    level: 1,
    playerGuess: 0,
    totalGuesses: 0,
    Picture: new Image(400, 250),
    gameImage2: new Image(400, 250),
    gameImage3: new Image(400, 250),
    gameImage4: new Image(400, 250),
    randArray: [20, 50, 100],
    userInput: document.getElementById("input"),
    output: document.getElementById("output"),
    startButton: document.getElementById("guess"),
    gamePicture: document.getElementById("PictureObject"),
    roundText: document.getElementById("round"),
    compNumber: 0,
    hide: document.getElementById('playArea'),
    numberCheck: false,
    
       
    randNumber: function () {
        'use strict';

        return Math.ceil(Math.random() * Game.randArray[Game.level - 1]);
    }
    
};

//preloading images below
Game.Picture.src = "image/Plain.jpg";
Game.gameImage2.src = "image/Mountain.jpg";
Game.gameImage3.src = "image/Valley.jpg";
Game.gameImage4.src = 'image/ThumbsUp.jpg';

function playGame() {
    "use strict";
    //convert userInput to a decimal number
    
    
       
    //Guess Counter
    Game.totalGuesses = Game.totalGuesses + 1;
    Game.roundText.innerHTML = "Round " + Game.level + " Guesses used: "
        + Game.totalGuesses + " Upper Limit: " + Game.randArray[Game.level - 1];
    //Evaluate player guess and return appropriate response

    if (Game.playerGuess === Game.compNumber && Game.totalGuesses < 6) {
        Game.output.innerHTML = "you were right the number was " + Game.compNumber +
        " you got it right in " + (Game.totalGuesses) + " tries.\n\n" +
        "Please Guess a number between 1 and " + Game.randArray[Game.level] + ".";
        document.getElementById("pictureObject").src = "images/ThumbsUp.jpg";
        document.getElementById("pictureObject").alt = "just right";
        Game.level = Game.level + 1;
        Game.totalGuesses = Game.totalGuesses - Game.totalGuesses;
    }

    else if (Game.playerGuess > Game.compNumber && Game.totalGuesses < 5) {
        Game.output.innerHTML = "the your answer is too high" + "\n\n"
        + "you have " + (5 - Game.totalGuesses) + " tries left.";
        document.getElementById("pictureObject").src = "images/Mountain.jpg";
        document.getElementById("pictureObject").alt = "too high";
    }

    else if (Game.playerGuess < Game.compNumber && Game.totalGuesses < 5) {
        Game.output.innerHTML = "the your answer is too low" + "\n\n"
        + "you have " + (5 - Game.totalGuesses) + " tries left.";
        document.getElementById("pictureObject").src = "images/Valley.jpg";
        document.getElementById("pictureObject").alt = "too low";

    }
    else {
        Game.output.innerHTML = "you are out of guesses please refresh the page to restart.\n\n" +
        "The answer was " + Game.compNumber;
        Game.hide.style.visibility = "hidden";
        document.getElementById("pictureObject").src = "images/sadfacesmiley.jpg";
        document.getElementById("pictureObject").alt = "too low";
    }
    
}

//Call the Game function and create a new number
function Main() {
    "use strict";
    if (Game.totalGuesses === 0) {
        Game.compNumber = Game.randNumber();

    }
    Game.playerGuess = parseInt(Game.userInput.value, 10);
    /*
    If Game.playerGuesses is Not a Number (NaN) then let them know to type a number between 1-20
    */
    if (isNaN(Game.playerGuess) || Game.playerGuess < 1 || Game.playerGuess > (Game.randArray[Game.level-1])) {
        document.getElementById("output").innerHTML = "<br />Type a Number Between 1 and " + Game.randArray[Game.level-1]+" please";
        return false;
    }
    
    //var tmOut = setInterval(function () {
    //   document.getElementById("playSpace").style.display="none";
        
    //    /*The timeout is cleared once the game area is displayed and the game begins */
        
    //   document.getElementById('playSpace').style.display = 'block'; setInterval(tmOut);
      
    //}, 2500);
   
      playGame();
}
Game.startButton.addEventListener("click", Main, false);