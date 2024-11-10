import ValidationResult from "./ValidationResult"

export default abstract class AbstractValidator {
    protected inputName: string = "";
    protected validations = [];

    constructor() {
        
    }

    abstract validate(): ValidationResult;
}
