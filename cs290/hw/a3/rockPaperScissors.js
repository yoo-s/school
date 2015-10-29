var rockImg = "images/rock.png";
var paperImg = "images/paper.jpg";
var scissorsImg = "images/scissors.png";
var youScore = 0;
var compScore = 0;

function compPic() {
	var computerChoice = Math.random();
	var computerImg;
	if (computerChoice < 0.34) {
		document.getElementById("img2").src = "images/rock.png";
		computerImg = "images/rock.png";
	} else if(computerChoice <= 0.67) {
		document.getElementById("img2").src ="images/paper.jpg";
		computerImg = "images/paper.jpg";
	} else {
		document.getElementById("img2").src ="images/scissors.png";
		computerImg = "images/scissors.png";
	}
	return computerImg;
}

function pic1() {
        document.getElementById("img").src = rockImg;
        var youImg = rockImg;
        compImg = compPic();
        winner(youImg, compImg);
}
function pic2() {
        document.getElementById("img").src = paperImg;
        youImg = paperImg;
        compImg = compPic();
        winner(youImg, compImg);
}
function pic3() {
        document.getElementById("img").src = scissorsImg;
        youImg = scissorsImg;
        compImg = compPic();
        winner(youImg, compImg);
}

function winner(youImg, computerImg) {
    if (youImg === computerImg) {
        document.getElementById("winner").innerHTML = "The result is a tie!";
    } else if (youImg == "images/rock.png") {
        if (computerImg == "images/scissors.png") {
            document.getElementById("winner").innerHTML = "rock wins";
            youScore++;
            document.getElementById("sc1").innerHTML = "" + youScore;
        } else {
            document.getElementById("winner").innerHTML = "paper wins";
            compScore++;
            document.getElementById("sc2").innerHTML = "" + compScore;
        }
    } else if (youImg == "images/paper.jpg") {
        if (computerImg == "images/rock.png") {
        	document.getElementById("winner").innerHTML = "paper wins";
        	youScore++;
            document.getElementById("sc1").innerHTML = "" + youScore;
        } else {
            document.getElementById("winner").innerHTML = "scissors wins";
            compScore++;
            document.getElementById("sc2").innerHTML = "" + compScore;
        }
    } else if (youImg == "images/scissors.png") {
        if (computerImg == "images/rock.png") {
        	document.getElementById("winner").innerHTML = "rock wins";
        	compScore++;
            document.getElementById("sc2").innerHTML = "" + compScore;
        } else {
            document.getElementById("winner").innerHTML = "scissors wins";
            youScore++;
            document.getElementById("sc1").innerHTML = "" + youScore;
        }
    }
}
