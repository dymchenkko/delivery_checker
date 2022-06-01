use std::fs;
use methods::{CHECKER_ID, CHECKER_PATH, PACKAGE_PATH, PACKAGE_ID};
use checker_core::{Person, PersonStatus, Package, PackageType};
use risc0_zkvm_host::Prover;
use risc0_zkvm_serde::{from_slice, to_vec};
use tempfile::tempdir;

fn main() {
    let a = Person { status: PersonStatus::Deliveryman };
    let temp_dir = tempdir().unwrap();
    let mut id_path = temp_dir
        .path()
        .join("checker.id")
        .to_str()
        .unwrap()
        .to_string();
    fs::write(&id_path, CHECKER_ID).unwrap();

    let mut prover = Prover::new(&CHECKER_PATH, &id_path).unwrap();
    prover.add_input(to_vec(&a).unwrap().as_slice()).unwrap();
    let receipt = prover.run().unwrap();
    println!("Checking a person's profession:");

    let c: bool = from_slice(&receipt.get_journal_vec().unwrap()).unwrap();
    if c {
        println!("This person can deliver packages.");
    } else {
        println!("This person can't deliver packages.");
    }
    receipt.verify(&id_path).unwrap();

    let b: Package = Package { package_type: PackageType::Forbidden };

    id_path = temp_dir
        .path()
        .join("package.id")
        .to_str()
        .unwrap()
        .to_string();
    fs::write(&id_path, PACKAGE_ID).unwrap();

    let mut prover = Prover::new(&PACKAGE_PATH, &id_path).unwrap();
    prover.add_input(to_vec(&b).unwrap().as_slice()).unwrap();
    let receipt = prover.run().unwrap();

    println!("Checking a package:");

    let c: bool = from_slice(&receipt.get_journal_vec().unwrap()).unwrap();
    if c {
        println!("The delivery service can deliver this package.");
    } else {
        println!("The delivery service cannot deliver this package.");
    }
    receipt.verify(&id_path).unwrap();
}
