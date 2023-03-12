
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void OpenSSL_add_all_digests(void)

{
  EVP_MD *pEVar1;
  
  pEVar1 = EVP_md4();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_md5();
  EVP_add_digest(pEVar1);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("ssl2-md5",0x8001,&DAT_006463d0);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("ssl3-md5",0x8001,&DAT_006463d0);
  pEVar1 = (EVP_MD *)(*(code *)PTR_EVP_sha_006a8c30)();
  EVP_add_digest(pEVar1);
  pEVar1 = (EVP_MD *)(*(code *)PTR_EVP_dss_006a8c34)();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha1();
  EVP_add_digest(pEVar1);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("ssl3-sha1",0x8001,&DAT_0064d80c);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("RSA-SHA1-2",0x8001,"RSA-SHA1");
  pEVar1 = EVP_dss1();
  EVP_add_digest(pEVar1);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("DSA-SHA1-old",0x8001,"DSA-SHA1");
  (*(code *)PTR_OBJ_NAME_add_006a8420)(&DAT_006496a0,0x8001,"DSA-SHA1");
  (*(code *)PTR_OBJ_NAME_add_006a8420)(&DAT_006496a8,0x8001,"DSA-SHA1");
  pEVar1 = EVP_ecdsa();
  EVP_add_digest(pEVar1);
  pEVar1 = (EVP_MD *)EVP_mdc2();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_ripemd160();
  EVP_add_digest(pEVar1);
  (*(code *)PTR_OBJ_NAME_add_006a8420)("ripemd",0x8001,"RIPEMD160");
  (*(code *)PTR_OBJ_NAME_add_006a8420)("rmd160",0x8001,"RIPEMD160");
  pEVar1 = EVP_sha224();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha256();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha384();
  EVP_add_digest(pEVar1);
  pEVar1 = EVP_sha512();
  EVP_add_digest(pEVar1);
  pEVar1 = (EVP_MD *)(*(code *)PTR_EVP_whirlpool_006a8c38)();
  EVP_add_digest(pEVar1);
  return;
}

