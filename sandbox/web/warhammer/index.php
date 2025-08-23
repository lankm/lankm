<?php
include("tags.php");

$data = [
    [],
    []
];

echo DOCTYPE_('html').
html_()(
    head_()(
        meta_(charset:"UTF-8"),
        title_()("WH40k Helper"),
    ),
    body_()(
        h1_()(
            "Warhammer"
        ),
        table_()(
            h2_()(
                "Units"
            ),
            tr_()(
                th_()("Name"),
                th_()("Points"),
                th_()("Description"),
            ),
            tr_()(
                td_()("Cadian Shock Troops"),
                td_()("65"),
                td_()("Cadians"),
            )
        )
    ),
);