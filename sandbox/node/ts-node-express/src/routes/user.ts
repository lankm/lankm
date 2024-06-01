import express, { Express, Request, Response, Router } from "express";

const router: Router = express.Router()

router.post("/new", (req: Request, res: Response) => {
  res.status(200).send('New user');
});

router.route('/:id')
.get((req: Request, res: Response) => {
  res.status(200).send(req.params.id);
})
.put((req: Request, res: Response) => {
  res.status(200).send(req.params.id);
})
.delete((req: Request, res: Response) => {
  res.status(200).send(req.params.id);
});

router.param('id', (req, res, next, id) => {
  console.log(id);
  next();
});

module.exports = router;
