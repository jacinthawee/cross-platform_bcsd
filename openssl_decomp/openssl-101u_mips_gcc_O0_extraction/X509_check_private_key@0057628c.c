
int X509_check_private_key(X509 *x509,EVP_PKEY *pkey)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (x509 == (X509 *)0x0) {
LAB_00576358:
    iVar1 = 0;
  }
  else {
    if (x509->cert_info == (X509_CINF *)0x0) goto LAB_00576358;
    iVar1 = (*(code *)PTR_X509_PUBKEY_get_006a8d64)(x509->cert_info->key);
    if (iVar1 == 0) goto LAB_00576358;
    iVar2 = (*(code *)PTR_EVP_PKEY_cmp_006a8eb8)(iVar1,pkey);
    if (iVar2 == -1) {
      uVar4 = 0x73;
      uVar3 = 0x158;
LAB_0057633c:
      uVar5 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x80,uVar4,"x509_cmp.c",uVar3);
      goto LAB_00576304;
    }
    if (iVar2 == 0) {
      uVar4 = 0x74;
      uVar3 = 0x155;
      goto LAB_0057633c;
    }
    if (iVar2 != -2) {
      uVar5 = (uint)(0 < iVar2);
      goto LAB_00576304;
    }
  }
  uVar5 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x80,0x75,"x509_cmp.c",0x15b);
  if (iVar1 == 0) {
    return 0;
  }
LAB_00576304:
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar1);
  return uVar5;
}

