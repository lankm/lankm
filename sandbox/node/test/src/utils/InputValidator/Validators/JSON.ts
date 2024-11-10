import AbstractValidator from "../AbstractValidator";
import ValidationResult from "../ValidationResult";

export default class JSONValidator extends AbstractValidator {
    validate(): ValidationResult {
        throw new Error("Method not implemented.");
    }
}