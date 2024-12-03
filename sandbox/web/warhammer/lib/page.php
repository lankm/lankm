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
        return DOCTYPE_('html').
        html_()(
            head_()(
                meta_(charset: 'UTF-8').
                link_(href: '/account/index.css', rel: 'stylesheet').
                title_()("Hello, World")
            ).
            body_()(
                header_(class: 'test')(
                    "Header"
                ).
                main_()(
                    h1_()("List").
                    ul_()(
                        li_()(
                            "1"
                        ).
                        li_()(
                            sup_()("2")
                        ).
                        li_()(
                            "3"
                        )
                    )
                ).
                footer_(class: "test")(
                    "footer"
                ).
                script_(src: '/account/index.js')()
            )
        );
    }
}
