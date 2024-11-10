export default class ValidationResult {
    private errors: string[];

    constructor(errors: string[]) {
        this.errors = errors;
    }

    public isValid(): boolean {
        return this.errors.length === 0;
    }
    public isInvalid(): boolean {
        return this.errors.length !== 0;
    }
    public getErrors(): string[] {
        return this.errors;
    }
}