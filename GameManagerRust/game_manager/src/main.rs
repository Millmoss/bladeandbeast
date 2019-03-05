#![allow(non_snake_case)]
#![allow(non_camel_case_types)]

use crate::primary_package::primary_package::Object;

mod primary_package;

fn main()
{
    let rock: Object = Object{name: String::from("bRock"),
        weight: 2.0,
        height: 0.3,
        width: 0.2,
        length: 0.23,
        age: 7.0,
        temperature: 69.0};
}
