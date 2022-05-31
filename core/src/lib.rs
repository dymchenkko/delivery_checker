#![no_std]
use serde::{Deserialize, Serialize};

#[derive(Deserialize, Serialize)]
pub struct Seller {
    pub sales: u64,
    pub sendings: u64,
}