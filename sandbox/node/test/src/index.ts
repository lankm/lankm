import { InputValidatorFactory } from "./utils";

const validator = InputValidatorFactory.Email();
const valid = validator.validate().isValid();
console.log(valid);
