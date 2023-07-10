const express = require('express');
const path = require('path');
const ejs = require('ejs');

const {add} = require('./utils/math');

const app = express();

app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.get('/', (req, res) => {
    const data = {
        name: 'John',
        age: add(17, 1)
    };

    res.render('home', { data });
});

app.listen(3000, () => {
    console.log('Server started on port 3000');
});
