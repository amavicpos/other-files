const question = document.querySelector('#question');
const answers = document.querySelectorAll('.answer');
var correctAns;

const getSetQuestion = async () => {
    try {
        const config = { headers: { Accept: 'application/json' } };
        const res = await fetch("https://the-trivia-api.com/v2/questions", config);
        const data = await res.json();

        document.removeEventListener("click", handler, true);
        answers.forEach(element => element.style.color = `rgb(254, 250, 224)`);
        question.textContent = data[0].question.text;
        const answers_text = [data[0].correctAnswer];
        for (let value = 0; value < 3; value++) {
            answers_text.push(data[0].incorrectAnswers[value]);
        }
        answers_text.sort();
        answers.forEach((element, index) => { element.textContent = answers_text[index]; });
        correctAns = Array.from(answers).find(element => element.textContent === data[0].correctAnswer);
        // console.log(data);
    } catch (e) {
        console.log("ERROR", e);
    }
}

function handler(e) {
    e.stopPropagation();
    e.preventDefault();
}

const condition = () => {
    answers.forEach(element => {
        if (element === correctAns) {
            element.addEventListener('click', _ => element.style.color = 'green');
            element.addEventListener('click', _ => { document.addEventListener("click", handler, true) });
            element.addEventListener('click', _ => {
                ++counterCorrect;
                ++counterTotal;
                document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
            });
        } else {
            element.addEventListener('click', _ => {
                element.style.color = 'red';
                document.addEventListener("click", handler, true);
                setTimeout(() => correctAns.style.color = 'green', 1000);
                setTimeout(() => {
                    ++counterTotal;
                    document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
                }, 2000);
            });
        }
    });
}

const colour = (element) => {
    if (element === correctAns) {
        element.style.color = 'green';
        document.addEventListener("click", handler, true);
        ++counterCorrect;
        ++counterTotal;
        document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
        // setTimeout(() => {setValue(true)}, 1000);
    } else {
        element.style.color = 'red';
        document.addEventListener("click", handler, true);
        setTimeout(() => correctAns.style.color = 'green', 1000);
        setTimeout(() => {
            ++counterTotal;
            document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
        }, 2000);
    }
}

let counterCorrect = 0;
let counterTotal = 0;

getSetQuestion();
answers.forEach(element => element.addEventListener('click', _ => {
    colour(element);
    setTimeout(() => getSetQuestion(), 1000);
}))
