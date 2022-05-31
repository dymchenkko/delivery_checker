use std::fs;
use methods::{CHECKER_ID, CHECKER_PATH};
use checker_core::Seller;
use risc0_zkvm_host::Prover;
use risc0_zkvm_serde::{from_slice, to_vec};
use tempfile::tempdir;

fn main() {
    let a: Seller = Seller{
        sales: 12,
        sendings: 13,
    };
    let temp_dir = tempdir().unwrap();
    let id_path = temp_dir
        .path()
        .join("checker.id")
        .to_str()
        .unwrap()
        .to_string();
    fs::write(&id_path, CHECKER_ID).unwrap();

    let mut prover = Prover::new(&CHECKER_PATH, &id_path).unwrap();
    prover.add_input(to_vec(&a).unwrap().as_slice()).unwrap();
    let receipt = prover.run().unwrap();

    let c: bool = from_slice(&receipt.get_journal_vec().unwrap()).unwrap();
    if c {
        println!("This seller is reliable");
    } else {
        println!("This seller is unreliable");
    }
    receipt.verify(&id_path).unwrap();
}
