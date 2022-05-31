#![no_main]
#![no_std]
use risc0_zkvm_guest::env;
use checker_core::Seller;
risc0_zkvm_guest::entry!(main);

pub fn main() {
    let a:Seller = env::read();
    let c:bool = a.sendings == a.sales;
    env::commit(&c);
}
