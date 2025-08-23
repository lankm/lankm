<?php

enum Attribute {
    case DESCRIPTION;
    case ABILITY;
    case SUMMARY;
}
abstract class WeaponAbility {
    public static array $Assault = [
        Attribute::DESCRIPTION => 
         'Assault weapons fire so indiscriminately
          that they can be shot from the hip as warriors dash forward.',
        Attribute::ABILITY => 
         'Weapons with [ASSAULT] in their profile are 
          known as Assault weapons. If a unit that Advanced this turn contains
          any models equipped with Assault weapons, it is still eligible to
          shoot in this turn\'s Shooting phase. When such a unit is selected
          to shoot, you can only resolve attacks using Assault weapons its 
          models are equipped with.',
        Attribute::SUMMARY =>
         'Can be shot even if the bearer\'s unit Advanced.',
    ];
    public static array $Pistol = [
        Attribute::DESCRIPTION => '',
        Attribute::ABILITY => '',
        Attribute::SUMMARY => '',
    ];
}
