
int PKCS7_add_certificate(PKCS7 *p7,X509 *x509)

{
  int iVar1;
  undefined4 uVar2;
  uchar *puVar3;
  undefined4 uVar4;
  uchar **ppuVar5;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if ((iVar1 == 0x16) || (iVar1 == 0x18)) {
    ppuVar5 = &((p7->d).data)->data;
    if (((p7->d).data)->data == (uchar *)0x0) {
      puVar3 = (uchar *)(*(code *)PTR_sk_new_null_006a6fa4)();
      *ppuVar5 = puVar3;
    }
    if (*ppuVar5 != (uchar *)0x0) {
      (*(code *)PTR_CRYPTO_add_lock_006a805c)(&x509->references,1,3,"pk7_lib.c",0x13a);
      iVar1 = (*(code *)PTR_sk_push_006a6fa8)(*ppuVar5,x509);
      if (iVar1 != 0) {
        return 1;
      }
      (*(code *)PTR_X509_free_006a6e90)(x509);
      return 0;
    }
    uVar4 = 0x41;
    uVar2 = 0x137;
  }
  else {
    uVar4 = 0x71;
    uVar2 = 0x130;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,100,uVar4,"pk7_lib.c",uVar2);
  return 0;
}
