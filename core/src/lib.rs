#![no_std]
use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize)]
pub struct Person {
    pub status: PersonStatus,
}

#[derive(Deserialize, Serialize, PartialEq)]
pub enum PersonStatus {
    Deliveryman,
    Unemployed,
    Seller,
    Programmer,
    Driver,
    Economist,
}

#[derive(Deserialize, Serialize)]
pub struct Package {
    pub package_type: PackageType,
}

#[derive(Deserialize, Serialize, PartialEq)]
pub enum PackageType {
    Alcohol,
    Forbidden,
    Gadget,
    Jewelery,
    SportEquipment,
    Food,
}