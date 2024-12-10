<?php
include("tags.php");
include("constants.php");

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
                meta_(charset:"UTF-8"),
                title_()("WH40k Helper"),
            ),
            body_()(
                p_()(HTTP_STATUS::OK),
                input_(value: "\"><input value=checked", type: "text>")()
            ),
        );
    }
}

class HomePage extends AbstractPage {
    public function __construct() {
        $this->lang = 'en';
    }
}
