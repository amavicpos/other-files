const questions = document.querySelector('#questions');
const button = document.querySelector('button');

const getSetQuestions = async () => {
    try {
        const config = { headers: { Accept: 'application/json' } };
        const res = await fetch("https://the-trivia-api.com/v2/questions", config);
        const data = await res.json();

        const newLI = document.createElement('LI');
        newLI.append(data[0].question.text);
        questions.append(newLI);

        const options = document.createElement('UL');
        const answers = [data[0].correctAnswer];
        for (let value = 0; value < 3; value++) {
            answers.push(data[0].incorrectAnswers[value]);
        }
        answers.sort();
        answers.forEach(element => {
            const newsubLI = document.createElement('LI');
            newsubLI.append(element);
            options.append(newsubLI);
            if (element === data[0].correctAnswer) {
                newsubLI.addEventListener('click', _ => newsubLI.style.color = 'green');
            } else {
                newsubLI.addEventListener('click', _ => newsubLI.style.color = 'red');
            }
        });
        newLI.append(options);
        // console.log(data);
    } catch (e) {
        console.log("ERROR", e);
    }
}

button.addEventListener('click', getSetQuestions);
console.log(questions);
