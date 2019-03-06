#![allow(non_snake_case)]
#![allow(non_camel_case_types)]

use crate::primary_package::primary_package::Thing;
mod primary_package;

use crate::creature::creature::Creature;
mod creature;

use std::collections::HashMap;

fn main()
{
    let rock = Thing{id: String::from("rock"),
        weight: 2.0,
        height: 0.3,
        width: 0.2,
        length: 0.23,
        age: 7.0,
        temperature: 69.0};

    println!("{}", rock.id);
    
    let dogBase = Thing{id: String::from("dog"),
        weight: 12.0,
        height: 1.3,
        width: 0.8,
        length: 1.8,
        age: 7.0,
        temperature: 98.0};
    let dog = Creature{ thing: dogBase, body: HashMap::new() };

    println!("{}", dog.thing.id);
}
