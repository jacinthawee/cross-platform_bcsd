
int PKCS7_set_cipher(PKCS7 *p7,EVP_CIPHER *cipher)

{
  int iVar1;
  pkcs7_st *ppVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if (iVar1 == 0x17) {
    ppVar2 = (pkcs7_st *)((p7->d).sign)->cert;
    iVar1 = EVP_CIPHER_type(cipher);
  }
  else {
    if (iVar1 != 0x18) {
      ERR_put_error(0x21,0x6c,0x71,"pk7_lib.c",0x25e);
      return 0;
    }
    ppVar2 = ((p7->d).sign)->contents;
    iVar1 = EVP_CIPHER_type(cipher);
  }
  if (iVar1 != 0) {
    ppVar2->detached = (int)cipher;
    return 1;
  }
  ERR_put_error(0x21,0x6c,0x90,"pk7_lib.c",0x265);
  return 0;
}

