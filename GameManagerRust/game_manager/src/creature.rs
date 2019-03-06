#![allow(non_snake_case)]
#![allow(non_camel_case_types)]

pub mod creature
{
    use crate::primary_package::primary_package::Thing;

    use std::collections::HashMap;
    use std::collections::Map;

    pub trait Life
    {
        fn tmp()
        {
            println!("{}", 1);
        }
    }

    pub struct Creature
    {
        pub thing: Thing,						//Thing object stored at highest level of creature. represents total base physics/classification of creature
        pub body: HashMap<String, Part>,
    }

    pub struct Part
    {
        pub thing: Thing,						//Thing object stored at body part level of creature. represents base physics/classification of body part
        pub organs: Map<String, Organ>,			//
		//pub connected: Vec<Part>,				//represents connections to other body parts. important for limb severance and checking if alive
		pub condition: f64,						//value representing the condition of the body part
		pub blood: f64,							//volume of blood contained in the body part
    }

    pub struct Organ
    {
        pub thing: Thing,						//Thing object stored at organ level of creature/body part. represents base physics/classification of creature
		pub condition: f64,						//value representing the condition of the organ
    }
}
