#![no_main]
#![no_std]
use risc0_zkvm_guest::env;
use checker_core::{Person, PersonStatus};
risc0_zkvm_guest::entry!(main);

pub fn main() {
    let a:Person = env::read();
    let c:bool = a.status == PersonStatus::Deliveryman;
    env::commit(&c);
}
