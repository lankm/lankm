import AbstractValidator from "../AbstractValidator";
import ValidationResult from "../ValidationResult";

export default class EmailValidator extends AbstractValidator {
    validate(): ValidationResult {
        return new ValidationResult(["error"]);
    }
}