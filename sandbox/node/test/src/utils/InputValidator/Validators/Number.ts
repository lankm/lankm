import AbstractValidator from "../AbstractValidator";
import ValidationResult from "../ValidationResult";

export default class NumberValidator extends AbstractValidator {
    validate(): ValidationResult {
        throw new Error("Method not implemented.");
    }
}