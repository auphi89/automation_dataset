package com.opswat.mdssc.fixture;

import java.security.KeyPairGenerator;
import java.security.MessageDigest;
import java.security.Signature;
import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.net.ssl.SSLContext;

/** CBOM source fixture: JCA algorithm names in getInstance calls. */
public class CryptoService {
    public byte[] sealGcm(byte[] data) throws Exception {
        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(256);
        Cipher cipher = Cipher.getInstance("AES/GCM/NoPadding");
        cipher.init(Cipher.ENCRYPT_MODE, kg.generateKey());
        return cipher.doFinal(data);
    }

    public byte[] legacyEcb(byte[] data) throws Exception {
        Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
        return cipher.getIV();
    }

    public byte[] sha1(byte[] data) throws Exception {
        return MessageDigest.getInstance("SHA-1").digest(data);
    }

    public void weakRsa() throws Exception {
        KeyPairGenerator kpg = KeyPairGenerator.getInstance("RSA");
        kpg.initialize(1024);
        kpg.generateKeyPair();
    }

    public Signature ecdsa() throws Exception {
        return Signature.getInstance("SHA256withECDSA");
    }

    public SSLContext tls() throws Exception {
        return SSLContext.getInstance("TLSv1.3");
    }
}
