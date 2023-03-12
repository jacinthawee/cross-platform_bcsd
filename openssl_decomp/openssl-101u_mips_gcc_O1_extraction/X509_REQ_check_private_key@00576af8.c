
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (x509 == (X509_REQ *)0x0) {
LAB_00576bc4:
    uVar1 = 0;
    iVar2 = (*(code *)PTR_EVP_PKEY_cmp_006a8eb8)(0,pkey);
    if (iVar2 != -1) goto LAB_00576b54;
LAB_00576be4:
    uVar4 = 0x73;
    uVar3 = 0x86;
  }
  else {
    if (x509->req_info == (X509_REQ_INFO *)0x0) goto LAB_00576bc4;
    uVar1 = (*(code *)PTR_X509_PUBKEY_get_006a8d64)(x509->req_info->pubkey);
    iVar2 = (*(code *)PTR_EVP_PKEY_cmp_006a8eb8)(uVar1,pkey);
    if (iVar2 == -1) goto LAB_00576be4;
LAB_00576b54:
    if (iVar2 < 0) {
      if (iVar2 != -2) {
        iVar5 = 0;
        goto LAB_00576b70;
      }
      if (pkey->type == 0x198) {
        uVar4 = 0x10;
        uVar3 = 0x8b;
      }
      else if (pkey->type == 0x1c) {
        uVar4 = 0x72;
        uVar3 = 0x93;
      }
      else {
        uVar4 = 0x75;
        uVar3 = 0x97;
      }
    }
    else {
      if (iVar2 != 0) {
        iVar5 = 0;
        if (iVar2 == 1) {
          iVar5 = 1;
        }
        goto LAB_00576b70;
      }
      uVar4 = 0x74;
      uVar3 = 0x83;
    }
  }
  iVar5 = 0;
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x90,uVar4,"x509_req.c",uVar3);
LAB_00576b70:
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(uVar1);
  return iVar5;
}

