
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
    iVar4 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
    if (iVar4 == 0x19) {
LAB_005b6434:
      iVar4 = *(int *)(*(int *)(cms + 4) + 8);
      goto joined_r0x005b6440;
    }
    if (iVar4 < 0x1a) {
      if (iVar4 == 0x16) goto LAB_005b6434;
      if (iVar4 == 0x17) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
joined_r0x005b645c:
        piVar5 = (int *)(iVar4 + 8);
        if (piVar5 == (int *)0x0) goto LAB_005b63a8;
      }
      else {
        piVar5 = (int *)(cms + 4);
        if (iVar4 != 0x15) goto LAB_005b635c;
      }
LAB_005b6374:
      puVar6 = (undefined4 *)*piVar5;
      pcVar8 = (code *)PTR_BIO_s_null_006a89ec;
      if ((puVar6 == (undefined4 *)0x0) ||
         (pcVar8 = (code *)PTR_BIO_s_mem_006a8d04, puVar6[3] == 0x20)) {
        uVar1 = (*pcVar8)();
        pBVar7 = (BIO *)(*(code *)PTR_BIO_new_006a7fa4)(uVar1);
      }
      else {
        pBVar7 = (BIO *)(*(code *)PTR_BIO_new_mem_buf_006aa264)(puVar6[2],*puVar6);
      }
      if (pBVar7 != (BIO *)0x0) goto LAB_005b61e4;
    }
    else if (iVar4 == 0xcd) {
      iVar4 = *(int *)(*(int *)(cms + 4) + 0x14);
joined_r0x005b6440:
      piVar5 = (int *)(iVar4 + 4);
      if (piVar5 != (int *)0x0) goto LAB_005b6374;
    }
    else {
      if (iVar4 == 0x312) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 0xc);
        goto joined_r0x005b6440;
      }
      if (iVar4 == 0x1a) {
        iVar4 = *(int *)(*(int *)(cms + 4) + 4);
        goto joined_r0x005b645c;
      }
LAB_005b635c:
      if (**(int **)(cms + 4) == 4) {
        piVar5 = *(int **)(cms + 4) + 1;
        goto LAB_005b6374;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x81,0x98,"cms_lib.c",0xee);
    }
LAB_005b63a8:
    (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x6f,0x7f,"cms_lib.c",0x72);
    pBVar2 = (BIO *)0x0;
  }
  else {
LAB_005b61e4:
    uVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)cms);
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
      (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x6f,0x9c,"cms_lib.c",0x91);
      return (BIO *)0x0;
    case 0x19:
      pBVar3 = (BIO *)cms_DigestedData_init_bio(cms);
      break;
    case 0x1a:
      pBVar3 = (BIO *)cms_EncryptedData_init_bio(cms);
    }
    if (pBVar3 != (BIO *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005b6270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      pBVar7 = (BIO *)(*(code *)PTR_BIO_push_006a85c0)(pBVar3,pBVar7);
      return pBVar7;
    }
    pBVar2 = (BIO *)0x0;
    if (icont == (BIO *)0x0) {
      (*(code *)PTR_BIO_free_006a7f70)(pBVar7);
      pBVar2 = pBVar3;
    }
  }
  return pBVar2;
}

