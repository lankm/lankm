<?php
# ISO 639-1
abstract class LANGUAGE {
}
enum HTTP_METHOD {
    case GET;
    case HEAD;
    case POST;
    case PUT;
    case DELETE;
    case CONNECT;
    case OPTIONS;
    case TRACE;
    case PATCH;
}

abstract class HTTP_STATUS {
    # Informational
    const Continue            = 100;
    const SWITCHING_PROTOCOLS = 101;
    const Processing          = 102;
    const Early_Hints         = 103;

    # Success
    const OK                            = 200;
    const Created                       = 201;
    const Accepted                      = 202;
    const NON_AUTHORITATIVE_INFORMATION = 203;
    const NO_CONTENT                    = 204;
    const RESET_CONTENT                 = 205;
    const PARTIAL_CONTENT               = 206;
    const MULTI_STATUS                  = 207;
    const ALREADY_REPORTED              = 208;
    const IM_USED                       = 226;

    # Redirection
    const MULTIPLE_CHOICES   = 300;
    const MOVED_PERMANENTLY  = 301;
    const FOUND              = 302;
    const SEE_OTHER          = 303;
    const NOT_MODIFIED       = 304;
    const USE_PROXY          = 305;
    const TEMPORARY_REDIRECT = 307;
    const PERMANENT_REDIRECT = 308;

    # Client Error
    const BAD_REQUEST                     = 400;
    const UNAUTHORIZED                    = 401;
    const PAYMENT_REQUIRED                = 402;
    const FORBIDDEN                       = 403;
    const NOT_FOUND                       = 404;
    const METHOD_NOT_ALLOWED              = 405;
    const NOT_ACCEPTABLE                  = 406;
    const PROXY_AUTHENTICATION_REQUIRED   = 407;
    const REQUEST_TIMEOUT                 = 408;
    const CONFLICT                        = 409;
    const GONE                            = 410;
    const LENGTH_REQUIRED                 = 411;
    const PRECONDITION_FAILED             = 412;
    const CONTENT_TOO_LARGE               = 413;
    const URI_TOO_LONG                    = 414;
    const UNSUPPORTED_MEDIA_TYPE          = 415;
    const RANGE_NOT_SATISFIABLE           = 416;
    const EXPECTATION_FAILED              = 417;
    const MIRSIRECTED_REQUEST             = 421;
    const UNPROCESSABLE_CONTENT           = 422;
    const LOCKED                          = 423;
    const FAILED_DEPENDENCY               = 424;
    const TOO_EARLY                       = 425;
    const UPGRADE_REQUIRED                = 426;
    const PRECONDITION_REQUIRED           = 428;
    const TOO_MANY_REQUESTS               = 429;
    const REQUEST_HEADER_FIELDS_TOO_LARGE = 431;
    const UNAVAILABLE_FOR_LEGAL_REASONS   = 451;

    # Server Error
    const INTERNAL_SERVER_ERROR           = 500;
    const NOT_IMPLEMENTED                 = 501;
    const BAD_GATEWAY                     = 502;
    const SERVICE_UNAVAILABLE             = 503;
    const GATEWAY_TIMEOUT                 = 504;
    const HTTP_VERSION_NOT_SUPPORTED      = 505;
    const VARIANT_ALSO_NEGOTIATES         = 506;
    const INSUFFICIENT_STORAGE            = 507;
    const LOOP_DETECTED                   = 508;
    const NETWORK_AUTHENTICATION_REQUIRED = 511;
}
