<?php
class SafeHtmlElement {
    public function __construct(
        private string $name,
        private string $attributes='',
        private string $content='',
    ) {}
    public function __toString(): string {
        extract(get_object_vars($this));
        if(empty($content))
            return "<$name$attributes>";
        return "<$name$attributes>$content</$name>";
    }
}

class HtmlElement {
    public function __construct(
        private string $name,
        private array $attributes
    ) {}

    private function parseAttributes(array $attributes) {
        $parsedAttributes = '';
        foreach($attributes as $key => $value) {
            $encoded = htmlspecialchars($value);
            $parsedAttributes .= match (is_int($key)) {
                true => " $encoded",
                false => " $key=\"$encoded\""
            };
        }
        return $parsedAttributes;
    }
    private function parseContent(array $content) {
        $parsedContent = '';
        foreach($content as $value) {
            $parsedContent .= match (is_string($value)) {
                true => htmlspecialchars($value),
                false => $value
            };
        }
        return $parsedContent;
    }

    public function __toString(): string {
        $parsedAttributes = $this->parseAttributes($this->attributes);
        return new SafeHtmlElement($this->name, $parsedAttributes);
    }
    public function __invoke(...$content): SafeHtmlElement {
        $parsedAttributes = $this->parseAttributes($this->attributes);
        $parsedContent = $this->parseContent($content);
        return new SafeHtmlElement($this->name, $parsedAttributes, $parsedContent);
    }

    
    private const array TAGS = [
        "!DOCTYPE" => "DOCTYPE_",
        "a"         => "a_",
        "abbr"      => "abbr_",
        "address"   => "address_",
        "area"      => "area_",
        "article"   => "article_",
        "aside"     => "aside_",
        "audio"     => "audio_",
        "b"         => "b_",
        "base"      => "base_",
        "bdi"       => "bdi_",
        "bdo"       => "bdo_",
        "blockquote"=> "blockquote_",
        "body"      => "body_",
        "br"        => "br_",
        "button"    => "button_",
        "canvas"    => "canvas_",
        "caption"   => "caption_",
        "cite"      => "cite_",
        "code"      => "code_",
        "col"       => "col_",
        "colgroup"  => "colgroup_",
        "data"      => "data_",
        "datalist"  => "datalist_",
        "dd"        => "dd_",
        "del"       => "del_",
        "details"   => "details_",
        "dfn"       => "dfn_",
        "dialog"    => "dialog_",
        "div"       => "div_",
        "dl"        => "dl_",
        "dt"        => "dt_",
        "em"        => "em_",
        "embed"     => "embed_",
        "fieldset"  => "fieldset_",
        "figcaption"=> "figcaption_",
        "figure"    => "figure_",
        "footer"    => "footer_",
        "form"      => "form_",
        "h1"        => "h1_",
        "h2"        => "h2_",
        "h3"        => "h3_",
        "h4"        => "h4_",
        "h5"        => "h5_",
        "h6"        => "h6_",
        "head"      => "head_",
        "header"    => "header_",
        "hgroup"    => "hgroup_",
        "hr"        => "hr_",
        "html"      => "html_",
        "i"         => "i_",
        "iframe"    => "iframe_",
        "img"       => "img_",
        "input"     => "input_",
        "ins"       => "ins_",
        "kbd"       => "kbd_",
        "label"     => "label_",
        "legend"    => "legend_",
        "li"        => "li_",
        "link"      => "link_",
        "main"      => "main_",
        "map"       => "map_",
        "mark"      => "mark_",
        "menu"      => "menu_",
        "meta"      => "meta_",
        "meter"     => "meter_",
        "nav"       => "nav_",
        "noscript"  => "noscript_",
        "object"    => "object_",
        "ol"        => "ol_",
        "optgroup"  => "optgroup_",
        "option"    => "option_",
        "p"         => "p_",
        "param"     => "param_",
        "picture"   => "picture_",
        "pre"       => "pre_",
        "progress"  => "progress_",
        "q"         => "q_",
        "rp"        => "rp_",
        "rt"        => "rt_",
        "ruby"      => "ruby_",
        "s"         => "s_",
        "samp"      => "samp_",
        "script"    => "script_",
        "search"    => "search_",
        "section"   => "section_",
        "select"    => "select_",
        "small"     => "small_",
        "source"    => "source_",
        "span"      => "span_",
        "strong"    => "strong_",
        "style"     => "style_",
        "sub"       => "sub_",
        "summary"   => "summary_",
        "sup"       => "sup_",
        "svg"       => "svg_",
        "table"     => "table_",
        "tbody"     => "tbody_",
        "td"        => "td_",
        "template"  => "template_",
        "textarea"  => "textarea_",
        "tfoot"     => "tfoot_",
        "th"        => "th_",
        "thead"     => "thead_",
        "time"      => "time_",
        "title"     => "title_",
        "tr"        => "tr_",
        "track"     => "track_",
        "u"         => "u_",
        "ul"        => "ul_",
        "var"       => "var_",
        "video"     => "video_",
        "wbr"       => "wbr_",
    ];

    public static function loadTags(): void {
        //adding functions to global namespace
        foreach(self::TAGS as $tag => $fn_name) {
            eval("
                function $fn_name(...\$attr) {
                    return new HtmlElement(\"$tag\", \$attr);
                }
            ");
        }
    }
}
HtmlElement::loadTags();
