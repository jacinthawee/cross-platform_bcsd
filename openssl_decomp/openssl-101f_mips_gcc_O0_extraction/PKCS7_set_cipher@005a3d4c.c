
int PKCS7_set_cipher(PKCS7 *p7,EVP_CIPHER *cipher)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  pkcs7_st *ppVar4;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(p7->type);
  if (iVar1 == 0x17) {
    ppVar4 = (pkcs7_st *)((p7->d).sign)->cert;
    iVar1 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)(cipher);
  }
  else {
    if (iVar1 != 0x18) {
      uVar3 = 0x71;
      uVar2 = 0x25e;
      goto LAB_005a3ddc;
    }
    ppVar4 = ((p7->d).sign)->contents;
    iVar1 = (*(code *)PTR_EVP_CIPHER_type_006a9d90)(cipher);
  }
  if (iVar1 != 0) {
    ppVar4->detached = (int)cipher;
    return 1;
  }
  uVar3 = 0x90;
  uVar2 = 0x265;
LAB_005a3ddc:
  (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x6c,uVar3,"pk7_lib.c",uVar2);
  return 0;
}

