<?php
include("tags.php");

class AbstractPage {
    private string $lang;
    private string $title;
    private array $scripts;
    private array $styles;

    public function __construct() {

    }

    public function __invoke(): string {
        return DOCTYPE_().
        html_(
            head_(
                meta_(charset: 'UTF-8').
                link_('/account/index.css', 'stylesheet').
                title_("Hello, World")
            ).
            body_(
                header_( class: "test", content:"header").
                main_("main", class: "test").
                footer_("footer", class: "test").
                script_(src: '/account/index.js')
            )
        );
    }
}
