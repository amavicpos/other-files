const question = document.querySelector('#question');
const answers = document.querySelectorAll('.answer');

const getSetQuestion = async () => {
    try {
        const config = { headers: { Accept: 'application/json' } };
        const res = await fetch("https://the-trivia-api.com/v2/questions", config);
        const data = await res.json();

        answers.forEach(element => element.style.color = `rgb(254, 250, 224)`);
        question.textContent = data[0].question.text;
        const answers_text = [data[0].correctAnswer];
        for (let value = 0; value < 3; value++) {
            answers_text.push(data[0].incorrectAnswers[value]);
        }
        answers_text.sort();
        answers.forEach((element, index) => { element.textContent = answers_text[index]; });
        // console.log(data);
    } catch (e) {
        console.log("ERROR", e);
    }
}

const main = async () => {
    try {
        const config = { headers: { Accept: 'application/json' } };
        const res = await fetch("https://the-trivia-api.com/v2/questions", config);
        const data = await res.json();

        question.textContent = data[0].question.text;
        const answers_text = [data[0].correctAnswer];
        for (let value = 0; value < 3; value++) {
            answers_text.push(data[0].incorrectAnswers[value]);
        }
        answers_text.sort();
        answers.forEach((element, index) => { element.textContent = answers_text[index]; });
        correctAns = Array.from(answers).find(element => element.textContent === data[0].correctAnswer);
        answers.forEach((element, index) => {
            if (answers_text[index] === data[0].correctAnswer) {
                element.addEventListener('click', _ => element.style.color = 'green');
                element.addEventListener('click', _ => setTimeout(() => getSetQuestion(), 1000));
                element.addEventListener('click', _ => {
                    ++counterCorrect;
                    ++counterTotal;
                    document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
                });
            } else {
                element.addEventListener('click', _ => {
                    element.style.color = 'red';
                    setTimeout(() => correctAns.style.color = 'green', 1000);
                    setTimeout(() => {
                        getSetQuestion();
                        ++counterTotal;
                        document.querySelector('p').textContent = `Correct answers: ${counterCorrect}/${counterTotal}`;
                    }, 2000);
                });
            }
        });
        // console.log(data);
    } catch (e) {
        console.log("ERROR", e);
    }
}

let counterCorrect = 0;
let counterTotal = 0;
main();
