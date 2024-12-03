<?php
class HtmlTag {
    private static function serializeAttributes(array $attr) {
        $result = '';
        foreach($attr as $key => $value) {
            $encoded = htmlspecialchars($value);
            $result .= match (is_int($key)) {
                true => " $encoded",
                false => " $key=$encoded"
            };
        }
        return $result;
    }
    public static function wrap(string $name, array $attr) {
        $attr = self::serializeAttributes($attr);
        return function($content='') use ($name, $attr) {
            return "<$name$attr>$content</$name>";
        };
    }
    public static function void(string $name, array $attr) {
        $attr = self::serializeAttributes($attr);
        return "<$name$attr/>";
    }
    public static function tag(string $name, array $attr) {
        $attr = self::serializeAttributes($attr);
        return "<$name$attr>";
    }
}

$TAGS = [
    '!DOCTYPE'  => 'tag',
    'a'         => 'wrap',
    'abbr'      => 'wrap',
    'address'   => 'wrap',
    'area'      => 'wrap',
    'article'   => 'wrap',
    'aside'     => 'wrap',
    'audio'     => 'wrap',
    'b'         => 'wrap',
    'base'      => 'wrap',
    'bdi'       => 'wrap',
    'bdo'       => 'wrap',
    'blockquote'=> 'wrap',
    'body'      => 'wrap',
    'br'        => 'wrap',
    'button'    => 'wrap',
    'canvas'    => 'wrap',
    'caption'   => 'wrap',
    'cite'      => 'wrap',
    'code'      => 'wrap',
    'col'       => 'wrap',
    'colgroup'  => 'wrap',
    'data'      => 'wrap',
    'datalist'  => 'wrap',
    'dd'        => 'wrap',
    'del'       => 'wrap',
    'details'   => 'wrap',
    'dfn'       => 'wrap',
    'dialog'    => 'wrap',
    'div'       => 'wrap',
    'dl'        => 'wrap',
    'dt'        => 'wrap',
    'em'        => 'wrap',
    'embed'     => 'wrap',
    'fieldset'  => 'wrap',
    'figcaption'=> 'wrap',
    'figure'    => 'wrap',
    'footer'    => 'wrap',
    'form'      => 'wrap',
    'h1'        => 'wrap',
    'h2'        => 'wrap',
    'h3'        => 'wrap',
    'h4'        => 'wrap',
    'h5'        => 'wrap',
    'h6'        => 'wrap',
    'button'    => 'wrap',
    'head'      => 'wrap',
    'header'    => 'wrap',
    'hgroup'    => 'wrap',
    'hr'        => 'wrap',
    'html'      => 'wrap',
    'i'         => 'wrap',
    'iframe'    => 'wrap',
    'img'       => 'wrap',
    'input'     => 'wrap',
    'ins'       => 'wrap',
    'kbd'       => 'wrap',
    'label'     => 'wrap',
    'legend'    => 'wrap',
    'li'        => 'wrap',
    'link'      => 'tag',
    'main'      => 'wrap',
    'map'       => 'wrap',
    'mark'      => 'wrap',
    'menu'      => 'wrap',
    'meta'      => 'tag',
    'meter'     => 'wrap',
    'nav'       => 'wrap',
    'noscript'  => 'wrap',
    'object'    => 'wrap',
    'ol'        => 'wrap',
    'optgroup'  => 'wrap',
    'option'    => 'wrap',
    'output'    => 'wrap',
    'p'         => 'wrap',
    'param'     => 'wrap',
    'picture'   => 'wrap',
    'pre'       => 'wrap',
    'progress'  => 'wrap',
    'q'         => 'wrap',
    'rp'        => 'wrap',
    'rt'        => 'wrap',
    'ruby'      => 'wrap',
    's'         => 'wrap',
    'samp'      => 'wrap',
    'script'    => 'wrap',
    'search'    => 'wrap',
    'section'   => 'wrap',
    'select'    => 'wrap',
    'small'     => 'wrap',
    'source'    => 'wrap',
    'span'      => 'wrap',
    'strong'    => 'wrap',
    'style'     => 'wrap',
    'sub'       => 'wrap',
    'summary'   => 'wrap',
    'sup'       => 'wrap',
    'svg'       => 'wrap',
    'table'     => 'wrap',
    'tbody'     => 'wrap',
    'td'        => 'wrap',
    'template'  => 'wrap',
    'textarea'  => 'wrap',
    'tfoot'     => 'wrap',
    'th'        => 'wrap',
    'thead'     => 'wrap',
    'time'      => 'wrap',
    'title'     => 'wrap',
    'tr'        => 'wrap',
    'track'     => 'wrap',
    'u'         => 'wrap',
    'ul'        => 'wrap',
    'var'       => 'wrap',
    'video'     => 'wrap',
    'wbr'       => 'wrap',
];

foreach($TAGS as $tag => $type) {
    $function_name = preg_replace('/^[^a-zA-Z]+/','',$tag)."_";
    eval("
        function $function_name(...\$attr) {
            return HtmlTag::$type(\"$tag\", \$attr);
        }
    ");
}
