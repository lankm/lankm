import AbstractValidator from "../AbstractValidator";
import ValidationResult from "../ValidationResult";

export default class OptionValidator extends AbstractValidator {
    validate(): ValidationResult {
        throw new Error("Method not implemented.");
    }
}