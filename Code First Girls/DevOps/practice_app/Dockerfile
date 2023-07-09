FROM node:14-alpine

WORKDIR /

COPY app/package.json .
COPY app/package-lock.json .

RUN npm ci --production

COPY . .

EXPOSE 3000

CMD [ "node", "app/app.js" ]
