<?php
abstract class HtmlTag {
    public static function serializeAttributes(array $attr) {
        $result = '';
        foreach($attr as $key => $value) {
            if(empty($value)) continue;
            $encoded = htmlspecialchars($value);
            if(is_int($key))
                $result .= " $encoded";
            else
                $result .= " $key=$encoded";
        }
        return $result;
    }
    public static function wrap(string $name, array $attr, string $content) {
        $attr = self::serializeAttributes($attr);

        return "<$name$attr>$content</$name>";
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



function DOCTYPE_() {
    return HtmlTag::tag('!DOCTYPE', ['html']);
}
function a_() {
    return '';
}
function abbr_() {
    return '';
}
function address_() {
    return '';
}
function area_() {
    return '';
}
function article_() {
    return '';
}
function aside_() {
    return '';
}
function audio_() {
    return '';
}
function b_() {
    return '';
}
function base_() {
    return '';
}
function bdi_() {
    return '';
}
function bdo_() {
    return '';
}
function blockquote_() {
    return '';
}
function body_($content) {
    return HtmlTag::wrap("body", [], $content);
}
function br_() {
    return '';
}
function button_() {
    return '';
}
function canvas_() {
    return '';
}
function caption_() {
    return '';
}
function cite_() {
    return '';
}
function code_() {
    return '';
}
function col_() {
    return '';
}
function colgroup_() {
    return '';
}
function data_() {
    return '';
}
function datalist_() {
    return '';
}
function dd_() {
    return '';
}
function del_() {
    return '';
}
function details_() {
    return '';
}
function dfn_() {
    return '';
}
function dialog_() {
    return '';
}
function div_($content, $class='') {
    return HtmlTag::wrap('div', [
        'class' => $class,
    ], $content);
}
function dl_() {
    return '';
}
function dt_() {
    return '';
}
function em_() {
    return '';
}
function embed_() {
    return '';
}
function fieldset_() {
    return '';
}
function figcaption_() {
    return '';
}
function figure_() {
    return '';
}
function footer_($content, $class='') {
    return HtmlTag::wrap('div', [
        'class' => $class,
    ], $content);
}
function form_() {
    return '';
}
function h1_($content) {
    return HtmlTag::wrap("h1", [], $content);
}
function h2_($content) {
    return HtmlTag::wrap("h2", [], $content);
}
function h3_($content) {
    return HtmlTag::wrap("h3", [], $content);
}
function h4_($content) {
    return HtmlTag::wrap("h4", [], $content);
}
function h5_($content) {
    return HtmlTag::wrap("h5", [], $content);
}
function h6_($content) {
    return HtmlTag::wrap("h6", [], $content);
}
function head_($content) {
    return HtmlTag::wrap("head", [], $content);
}
function header_($class='', $content='') {
    return HtmlTag::wrap('header', [
        'class' => $class,
    ], $content);
}
function hgroup_($content) {
    return '';
}
function hr_($content) {
    return '';
}
function html_($content, $lang='en') {
    return HtmlTag::wrap("html", ["lang"=>$lang], $content);
}
function i_($content) {
    return '';
}
function iframe_($content) {
    return '';
}
function img_($content) {
    return '';
}
function input_($content) {
    return '';
}
function ins_($content) {
    return '';
}
function kbd_($content) {
    return '';
}
function label_($content) {
    return '';
}
function legend_($content) {
    return '';
}
function li_($content) {
    return '';
}
function link_($href, $rel) {
    return HtmlTag::tag("link", [
        'href' => $href,
        'rel' => $rel
    ]);
}
function main_($content, $class='') {
    return HtmlTag::wrap('main', [
        'class' => $class,
    ], $content);
}
function map_($content) {
    return '';
}
function mark_($content) {
    return '';
}
function menu_($content) {
    return '';
}
function meta_($charset='', $name='', $content='') {
    return HtmlTag::tag("meta", [
        'charset' => $charset,
        'name' => $name,
        'content' => $content
    ]);
}
function meter_($content) {
    return '';
}
function nav_($content) {
    return '';
}
function noscript_($content, ) {
    return '';
}
function object_($content) {
    return '';
}
function ol_($content) {
    return '';
}
function optgroup_($content) {
    return '';
}
function option_($content) {
    return '';
}
function output_($content) {
    return '';
}
function p_($content) {
    return '';
}
function param_($content) {
    return '';
}
function picture_($content) {
    return '';
}
function pre_($content) {
    return '';
}
function progress_($content) {
    return '';
}
function q_($content) {
    return '';
}
function rp_($content) {
    return '';
}
function rt_($content) {
    return '';
}
function ruby_($content) {
    return '';
}
function s_($content) {
    return '';
}
function samp_($content) {
    return '';
}
function script_($src) {
    return HtmlTag::wrap('script', [
        'src' => $src,
    ], '');
}
function search_($content) {
    return '';
}
function section_($content) {
    return '';
}
function select_($content) {
    return '';
}
function small_($content) {
    return '';
}
function source_($content) {
    return '';
}
function span_($content) {
    return '';
}
function strong_($content) {
    return '';
}
function style_($content) {
    return '';
}
function sub_($content) {
    return '';
}
function summary_($content) {
    return '';
}
function sup_($content) {
    return '';
}
function svg_($content) {
    return '';
}
function table_($content) {
    return '';
}
function tbody_($content) {
    return '';
}
function td_($content) {
    return '';
}
function template_($content) {
    return '';
}
function textarea_($content) {
    return '';
}
function tfoot_($content) {
    return '';
}
function th_($content) {
    return '';
}
function thead_($content) {
    return '';
}
function time_($content) {
    return '';
}
function title_($content) {
    return HtmlTag::wrap("title", [], $content);
}
function tr_($content) {
    return '';
}
function track_($content) {
    return '';
}
function u_($content) {
    return '';
}
function ul_($content) {
    return '';
}
function var__($content) {
    return '';
}
function video__($content) {
    return '';
}
function wbr_($content) {
    return '';
}
