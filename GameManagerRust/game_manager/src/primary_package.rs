#![allow(non_snake_case)]
#![allow(non_camel_case_types)]

pub mod primary_package
{
    pub trait Weight
    {
        fn lbs (&self, v: f64) -> f64
        {
            let r = v;
            return r;
        }

        fn kg (&self, v: f64) -> f64
        {
            let r = v / 2.205;
            return r;
        }
    }

    pub trait Distance
    {
        fn ft (&self, v: f64) -> f64
        {
            let r = v;
            return r;
        }

        fn r#in (&self, v: f64) -> f64
        {
            let r = v / 12.0;
            return r;
        }

        fn yd (&self, v: f64) -> f64
        {
            let r = v * 3.0;
            return r;
        }

        fn mi (&self, v: f64) -> f64
        {
            let r = v * 5280.0;
            return r;
        }

        fn m (&self, v: f64) -> f64
        {
            let r = v * 0.3048;
            return r;
        }

        fn m_from (&self, v: f64) -> f64
        {
            let r = v / 0.3048;
            return r;
        }
    }

    pub trait Temperature
    {
        fn F (&self, v: f64) -> f64
        {
            let r = v;
            return r;
        }

        fn C (&self, v: f64) -> f64
        {
            let r = (v - 32.0) * 5.0 / 9.0;
            return r;
        }

        fn K (&self, v: f64) -> f64
        {
            let r = (v - 32.0) * 5.0 / 9.0 + 273.15;
            return r;
        }
    }

    pub trait Volume
    {
        fn L (&self, v: f64) -> f64
        {
            let r = v;
            return r;
        }

        fn oz (&self, v: f64) -> f64
        {
            let r = v * 33.814;
            return r;
        }

        fn c (&self, v: f64) -> f64
        {
            let r = v * 33.814 / 8.0;
            return r;
        }
    }

    pub trait Time
    {
        fn hrs (&self, v: f64) -> f64
        {
            let r = v;
            return r;
        }

        fn min (&self, v: f64) -> f64   //consider fsize
        {
            let r = v * 60.0;
            return r;
        }

        fn sec (&self, v: f64) -> f64   //consider fsize
        {
            let r = v * 3600.0;
            return r;
        }

        fn days (&self, v: f64) -> f64
        {
            let r = v / 24.0;
            return r;
        }

        fn years (&self, v: f64) -> f64
        {
            let r = v / 8760.0;
            return r;
        }

        fn min_from (&self, v: f64) -> f64   //consider fsize
        {
            let r = v / 60.0;
            return r;
        }

        fn sec_from (&self, v: f64) -> f64   //consider fsize
        {
            let r = v / 3600.0;
            return r;
        }

        fn days_from (&self, v: f64) -> f64
        {
            let r = v * 24.0;
            return r;
        }

        fn years_from (&self, v: f64) -> f64
        {
            let r = v * 8760.0;
            return r;
        }
    }

    pub struct Object
    {
        pub name: String,
        pub weight: f64,
        pub height: f64,
        pub width: f64,
        pub length: f64,
        pub age: f64,
        pub temperature: f64
    }

    impl Weight for Object {}
    impl Distance for Object {}
    impl Temperature for Object {}
    impl Volume for Object {}
    impl Time for Object {}
}