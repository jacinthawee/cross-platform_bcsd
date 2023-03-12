
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int SSL_library_init(void)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_EVP_des_cbc_006a72a4)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_des_ede3_cbc_006a6e48)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_idea_cbc_006a72ac)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc4_006a8408)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc2_cbc_006a730c)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_rc2_40_cbc_006a7310)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_cbc_006a72a8)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_192_cbc_006a72c0)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_cbc_006a72bc)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_gcm_006a840c)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_gcm_006a8410)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_128_cbc_hmac_sha1_006a8414)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_aes_256_cbc_hmac_sha1_006a8418)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_camellia_128_cbc_006a72b8)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_camellia_256_cbc_006a72c4)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_seed_cbc_006a72b0)();
  (*(code *)PTR_EVP_add_cipher_006a8404)(uVar1);
  uVar1 = (*(code *)PTR_EVP_md5_006a70c8)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  OBJ_NAME_add("ssl2-md5",0x8001,"MD5");
  OBJ_NAME_add("ssl3-md5",0x8001,"MD5");
  uVar1 = (*(code *)PTR_EVP_sha1_006a75d0)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  OBJ_NAME_add("ssl3-sha1",0x8001,"SHA1");
  OBJ_NAME_add("RSA-SHA1-2",0x8001,"RSA-SHA1");
  uVar1 = (*(code *)PTR_EVP_sha224_006a81d8)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha256_006a8000)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha384_006a81dc)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_sha512_006a81d4)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  uVar1 = (*(code *)PTR_EVP_dss1_006a8210)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  OBJ_NAME_add("DSA-SHA1-old",0x8001,"DSA-SHA1");
  OBJ_NAME_add("DSS1",0x8001,"DSA-SHA1");
  OBJ_NAME_add("dss1",0x8001,"DSA-SHA1");
  uVar1 = (*(code *)PTR_EVP_ecdsa_006a8214)();
  (*(code *)PTR_EVP_add_digest_006a841c)(uVar1);
  SSL_COMP_get_compression_methods();
  ssl_load_ciphers();
  return 1;
}

