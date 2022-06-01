#![no_main]
#![no_std]
use risc0_zkvm_guest::env;
use checker_core::{Package, PackageType};
risc0_zkvm_guest::entry!(main);

pub fn main() {
    let a:Package = env::read();
    let c:bool = a.package_type != PackageType::Forbidden;
    env::commit(&c);
}
