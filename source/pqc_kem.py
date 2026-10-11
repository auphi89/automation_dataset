"""CBOM source fixture: post-quantum KEM and signature next to a classical hash."""
import hashlib

import oqs


def encapsulate(public_key: bytes):
    with oqs.KeyEncapsulation("ML-KEM-768") as kem:
        return kem.encap_secret(public_key)


def sign(message: bytes) -> bytes:
    with oqs.Signature("ML-DSA-65") as signer:
        signer.generate_keypair()
        return signer.sign(hashlib.sha3_256(message).digest())
