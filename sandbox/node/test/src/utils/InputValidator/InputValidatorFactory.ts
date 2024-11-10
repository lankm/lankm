import {
    AddressValidator,
    CSVValidator,
    DatetimeValidator,
    EmailValidator,
    JSONValidator,
    NumberValidator,
    OptionValidator,
    TextValidator
} from "./Validators"

export default class InputValidatorFactory {
    public static Datetime() {return new DatetimeValidator();}
    public static Text()     {return new TextValidator();}
    public static Address()  {return new AddressValidator();}
    public static CSV()      {return new CSVValidator();}
    public static JSON()     {return new JSONValidator();}
    public static Option()   {return new OptionValidator();}
    public static Email()    {return new EmailValidator();}
    public static Number()   {return new NumberValidator();}
}
