
int X509_REQ_check_private_key(X509_REQ *x509,EVP_PKEY *pkey)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (x509 == (X509_REQ *)0x0) {
LAB_0057a340:
    uVar1 = 0;
    iVar2 = (*(code *)PTR_EVP_PKEY_cmp_006a9fd4)(0,pkey);
    if (iVar2 != -1) goto LAB_0057a2d0;
LAB_0057a360:
    uVar4 = 0x73;
    uVar3 = 0x84;
  }
  else {
    if (x509->req_info == (X509_REQ_INFO *)0x0) goto LAB_0057a340;
    uVar1 = (*(code *)PTR_X509_PUBKEY_get_006a9e84)(x509->req_info->pubkey);
    iVar2 = (*(code *)PTR_EVP_PKEY_cmp_006a9fd4)(uVar1,pkey);
    if (iVar2 == -1) goto LAB_0057a360;
LAB_0057a2d0:
    if (iVar2 < 0) {
      if (iVar2 != -2) {
        iVar5 = 0;
        goto LAB_0057a2ec;
      }
      if (pkey->type == 0x198) {
        uVar4 = 0x10;
        uVar3 = 0x8a;
      }
      else if (pkey->type == 0x1c) {
        uVar4 = 0x72;
        uVar3 = 0x92;
      }
      else {
        uVar4 = 0x75;
        uVar3 = 0x96;
      }
    }
    else {
      if (iVar2 != 0) {
        iVar5 = 0;
        if (iVar2 == 1) {
          iVar5 = 1;
        }
        goto LAB_0057a2ec;
      }
      uVar4 = 0x74;
      uVar3 = 0x81;
    }
  }
  iVar5 = 0;
  (*(code *)PTR_ERR_put_error_006a9030)(0xb,0x90,uVar4,"x509_req.c",uVar3);
LAB_0057a2ec:
  (*(code *)PTR_EVP_PKEY_free_006a7f78)(uVar1);
  return iVar5;
}

