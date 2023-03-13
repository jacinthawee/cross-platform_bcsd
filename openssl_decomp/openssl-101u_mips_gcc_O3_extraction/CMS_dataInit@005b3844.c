
BIO * CMS_dataInit(CMS_ContentInfo *cms,BIO *icont)

{
  undefined4 uVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  BIO *pBVar7;
  code *pcVar8;
  
  pBVar7 = icont;
  if (icont == (BIO *)0x0) {
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
    if (iVar4 == 0x19) {
LAB_005b3ac4:
      iVar4 = *(int *)(*(int *)(cms + 4) + 8);
      goto joined_r0x005b3ad0;
    }
    if (iVar4 < 0x1a) {
      if (iVar4 == 0x16) goto LAB_005b3ac4;
      if (iVar4 == 0x17) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
joined_r0x005b3aec:
        piVar5 = (int *)(iVar4 + 8);
        if (piVar5 == (int *)0x0) goto LAB_005b3a38;
      }
      else {
        piVar5 = (int *)(cms + 4);
        if (iVar4 != 0x15) goto LAB_005b39ec;
      }
LAB_005b3a04:
      puVar6 = (undefined4 *)*piVar5;
      pcVar8 = (code *)PTR_BIO_s_null_006a7908;
      if ((puVar6 == (undefined4 *)0x0) ||
         (pcVar8 = (code *)PTR_BIO_s_mem_006a7c18, puVar6[3] == 0x20)) {
        uVar1 = (*pcVar8)();
        pBVar7 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar1);
      }
      else {
        pBVar7 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006a9148)(puVar6[2],*puVar6);
      }
      if (pBVar7 != (BIO *)0x0) goto LAB_005b3874;
    }
    else if (iVar4 == 0xcd) {
      iVar4 = *(int *)(*(int *)(cms + 4) + 0x14);
joined_r0x005b3ad0:
      piVar5 = (int *)(iVar4 + 4);
      if (piVar5 != (int *)0x0) goto LAB_005b3a04;
    }
    else {
      if (iVar4 == 0x312) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
        goto joined_r0x005b3ad0;
      }
      if (iVar4 == 0x1a) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 4);
        goto joined_r0x005b3aec;
      }
LAB_005b39ec:
      if (**(int **)(cms + 4) == 4) {
        piVar5 = *(int **)(cms + 4) + 1;
        goto LAB_005b3a04;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x81,0x98,"cms_lib.c",0xea);
    }
LAB_005b3a38:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6f,0x7f,"cms_lib.c",0x72);
    pBVar2 = (BIO *)0x0;
  }
  else {
LAB_005b3874:
    uVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
    switch(uVar1) {
    case 0x15:
      return pBVar7;
    case 0x16:
      pBVar3 = (BIO *)cms_SignedData_init_bio(cms);
      break;
    case 0x17:
      pBVar3 = (BIO *)cms_EnvelopedData_init_bio(cms);
      break;
    default:
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x6f,0x9c,"cms_lib.c",0x90);
      return (BIO *)0x0;
    case 0x19:
      pBVar3 = (BIO *)cms_DigestedData_init_bio(cms);
      break;
    case 0x1a:
      pBVar3 = (BIO *)cms_EncryptedData_init_bio(cms);
    }
    if (pBVar3 != (BIO *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005b3900. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pBVar7 = (BIO *)(*(code *)PTR_BIO_push_006a74c4)(pBVar3,pBVar7);
      return pBVar7;
    }
    pBVar2 = (BIO *)0x0;
    if (icont == (BIO *)0x0) {
      (*(code *)PTR_BIO_free_006a6e70)(pBVar7);
      pBVar2 = pBVar3;
    }
  }
  return pBVar2;
}

