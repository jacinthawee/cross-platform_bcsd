
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_library_init(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_EVP_des_cbc_006a83a4)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_des_ede3_cbc_006a7f48)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_idea_cbc_006a83a8)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc4_006a9528)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc2_cbc_006a840c)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc2_40_cbc_006a8410)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_cbc_006a83b4)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_192_cbc_006a83b0)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_cbc_006a83ac)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_gcm_006a952c)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_gcm_006a9530)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_cbc_hmac_sha1_006a9534)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_cbc_hmac_sha1_006a9538)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_camellia_128_cbc_006a83c0)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_camellia_256_cbc_006a83c4)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_seed_cbc_006a83b8)();
  (*(code *)PTR_EVP_add_cipher_006a9524)(uVar1);
  uVar1 = (*(code *)PTR_EVP_md5_006a81c8)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  OBJ_NAME_add("ssl2-md5",0x8001,"MD5");
  OBJ_NAME_add("ssl3-md5",0x8001,"MD5");
  uVar1 = (*(code *)PTR_EVP_sha1_006a86c4)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  OBJ_NAME_add("ssl3-sha1",0x8001,"SHA1");
  OBJ_NAME_add("RSA-SHA1-2",0x8001,"RSA-SHA1");
  uVar1 = (*(code *)PTR_EVP_sha224_006a9304)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha256_006a916c)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha384_006a9308)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha512_006a9300)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_dss1_006a9338)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  OBJ_NAME_add("DSA-SHA1-old",0x8001,"DSA-SHA1");
  OBJ_NAME_add("DSS1",0x8001,"DSA-SHA1");
  OBJ_NAME_add("dss1",0x8001,"DSA-SHA1");
  uVar1 = (*(code *)PTR_EVP_ecdsa_006a933c)();
  (*(code *)PTR_EVP_add_digest_006a953c)(uVar1);
  SSL_COMP_get_compression_methods();
  ssl_load_ciphers();
  return 1;
}

