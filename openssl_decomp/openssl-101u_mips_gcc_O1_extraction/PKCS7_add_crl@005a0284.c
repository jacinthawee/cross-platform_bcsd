
int PKCS7_add_crl(PKCS7 *p7,X509_CRL *x509)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 uVar4;
  long *plVar5;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(p7->type);
  if ((iVar1 == 0x16) || (iVar1 == 0x18)) {
    plVar5 = &((p7->d).data)->flags;
    if (((p7->d).data)->flags == 0) {
      lVar3 = (*(code *)PTR_sk_new_null_006a6fa4)();
      *plVar5 = lVar3;
    }
    if (*plVar5 != 0) {
      (*(code *)PTR_CRYPTO_add_lock_006a805c)(&x509->references,1,6,"pk7_lib.c",0x15b);
      iVar1 = (*(code *)PTR_sk_push_006a6fa8)(*plVar5,x509);
      if (iVar1 != 0) {
        return 1;
      }
      (*(code *)PTR_X509_CRL_free_006a7060)(x509);
      return 0;
    }
    uVar4 = 0x41;
    uVar2 = 0x157;
  }
  else {
    uVar4 = 0x71;
    uVar2 = 0x150;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x21,0x65,uVar4,"pk7_lib.c",uVar2);
  return 0;
}

