
int CMS_add0_cert(CMS_ContentInfo *cms,X509 *cert)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 == 0x16) {
    puVar5 = (undefined4 *)(*(int *)(cms + 4) + 0xc);
  }
  else {
    if (iVar1 != 0x17) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x80,0x98,"cms_lib.c",0x1a4);
      return 0;
    }
    puVar5 = *(undefined4 **)(*(int *)(cms + 4) + 4);
  }
  iVar1 = 0;
  if (puVar5 != (undefined4 *)0x0) {
    while( true ) {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*puVar5);
      iVar4 = iVar1 + 1;
      if (iVar2 <= iVar1) break;
      piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(*puVar5,iVar1);
      iVar1 = iVar4;
      if ((*piVar3 == 0) && (iVar2 = (*(code *)PTR_X509_cmp_006a8f04)(piVar3[1],cert), iVar2 == 0))
      {
        (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0xa4,0xaf,"cms_lib.c",0x1cc);
        return 0;
      }
    }
    puVar5 = (undefined4 *)CMS_add0_CertificateChoices(cms);
    if (puVar5 != (undefined4 *)0x0) {
      puVar5[1] = cert;
      *puVar5 = 0;
      return 1;
    }
  }
  return 0;
}

