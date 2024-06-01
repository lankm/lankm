import express, { Express, Request, Response, Router } from "express";

const app: Express = express();
const port = process.env.PORT || 3000;

const userRouter: Router = require('./routes/user')

app.use('/user', userRouter)
app.use('/favicon.ico', express.static('src/favicon.ico'))
app.listen(port, () => {
  console.log(`[server]: Server is running at http://localhost:${port}`);
});
