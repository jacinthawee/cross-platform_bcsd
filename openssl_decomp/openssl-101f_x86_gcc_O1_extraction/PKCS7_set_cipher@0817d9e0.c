
int PKCS7_set_cipher(PKCS7 *p7,EVP_CIPHER *cipher)

{
  pkcs7_st *ppVar1;
  int iVar2;
  int line;
  
  iVar2 = OBJ_obj2nid(p7->type);
  if (iVar2 == 0x17) {
    ppVar1 = (pkcs7_st *)((p7->d).sign)->cert;
    iVar2 = EVP_CIPHER_type(cipher);
  }
  else {
    if (iVar2 != 0x18) {
      line = 0x25e;
      iVar2 = 0x71;
      goto LAB_0817da3f;
    }
    ppVar1 = ((p7->d).sign)->contents;
    iVar2 = EVP_CIPHER_type(cipher);
  }
  if (iVar2 != 0) {
    ppVar1->detached = (int)cipher;
    return 1;
  }
  line = 0x265;
  iVar2 = 0x90;
LAB_0817da3f:
  ERR_put_error(0x21,0x6c,iVar2,"pk7_lib.c",line);
  return 0;
}

