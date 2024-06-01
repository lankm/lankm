let system = {
    "sol": {
        body: { 
            mass: 1988400e+24,
            radius: 695700e+3,
        },
        orbit: {
            semi_major_axis: 0,
        },
        satellites: {
            "Mercury": {
                satellites: {},
                body: {
                    mass: 0.33010e+24,
                    radius: 2439.7e+3,
                },
                orbit: {
                    semi_major_axis: 57.910e+9,
                },
            },
            "Venus": {
                satellites: {},
                body: {
                    mass: 4.8673e+24,
                    radius: 6051.8e+3,
                },
                orbit: {
                    semi_major_axis: 108.200e+9,
                },
            },
            "Terra": {
                satellites: {},
                body: {
                    mass: 5.9722e+24,
                    radius: 6371.0e+3,
                },
                orbit: {
                    semi_major_axis: 149.598e+9,
                },
                "Luna": {
                    satellites: {},
                    body: {
                        mass: 0.07346e+24,
                        radius: 1737.4e+3,
                    },
                    orbit: {
                        semi_major_axis: 0.3844e+9,
                    },
                },
            },
            "Mars": {
                satellites: {
                    "Phobos": {},
                    "Deimos": {},
                },
                body: {
                    mass: 0.64169e+24,
                    radius: 3376.2e+3,
                },
                orbit: {
                    semi_major_axis: 228.0e+9,
                },
            },
            "Jupiter": {
                satellites: {
                    "Ganymede": {},
                    "Callisto": {},
                    "Io": {},
                    "Europa": {},
                },
                body: {
                    mass: 1898.13e+24,
                    radius: 69911e+3,
                },
                orbit: {
                    semi_major_axis: 778.479e+9,
                },
            },
            "Saturn": {
                satellites: {
                    "Titan": {},
                    "Rhea": {},
                    "Iapetus": {},
                    "Dione": {},
                    "Mimas": {},
                    "Tethys": {},
                    "Enceladus": {},
                },
                body: {
                    mass: 568.32e+24,
                    radius: 58232e+3,
                },
                orbit: {
                    semi_major_axis: 1432.0413+9,
                },
            },
            "Uranus": {
                satellites: {
                    "Titania": {},
                    "Oberon": {},
                    "Umbriel": {},
                    "Ariel": {},
                    "Miranda": {},
                },
                body: {},
                orbit: {
                    semi_major_axis: 1432041000000.0,
                },
            },
            "Neptune": {
                satellites: {
                    "Triton": {},
                },
                body: {},
                orbit: {},
            },
        },
    },
};

console.log('Sol');
console.log('├╴Mercury');
console.log('├╴Venus');
console.log('├╴Terra');
console.log('│ └╴Luna');
console.log('├╴Mars');
console.log('│ ├╴Phobos');
console.log('│ └╴Deimos');
console.log('├╴Jupiter');
console.log('│ ├╴Ganymede');
console.log('│ ├╴Callisto');
console.log('│ ├╴Io');
console.log('│ └╴Europa');
console.log('├╴Saturn');
console.log('│ ├╴Titan');
console.log('│ ├╴Rhea');
console.log('│ ├╴Iapetus');
console.log('│ ├╴Dione');
console.log('│ ├╴Mimas');
console.log('│ ├╴Tethys');
console.log('│ └╴Enceladus');
console.log('├╴Uranus');
console.log('│ ├╴Titania');
console.log('│ ├╴Oberon');
console.log('│ ├╴Umbriel');
console.log('│ ├╴Ariel');
console.log('│ └╴Miranda');
console.log('└╴Neptune');
console.log('  └╴Triton');

let heavy = [[[[' ','╻'],['╸','┓']],[['╹','┃'],['┛','┫']]],[[['╺','┏'],['━','┳']],[['┗','┣'],['┻','╋']]]];
let light = [[[[' ','╷'],['╴','┐']],[['╵','│'],['┘','┤']]],[[['╶','┌'],['─','┬']],[['└','├'],['┴','┼']]]];
