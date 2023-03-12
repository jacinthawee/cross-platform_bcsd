
undefined4 cms_content_bio(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  code *pcVar5;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_1);
  if (iVar1 == 0x19) {
LAB_005b60c8:
    piVar4 = (int *)(*(int *)(param_1[1] + 8) + 4);
LAB_005b60d4:
    if (piVar4 == (int *)0x0) {
      return 0;
    }
  }
  else {
    if (0x19 < iVar1) {
      if (iVar1 == 0xcd) {
        piVar4 = (int *)(*(int *)(param_1[1] + 0x14) + 4);
      }
      else if (iVar1 == 0x312) {
        piVar4 = (int *)(*(int *)(param_1[1] + 0xc) + 4);
      }
      else {
        if (iVar1 != 0x1a) goto LAB_005b608c;
        piVar4 = (int *)(*(int *)(param_1[1] + 4) + 8);
      }
      goto LAB_005b60d4;
    }
    if (iVar1 == 0x16) goto LAB_005b60c8;
    if (iVar1 == 0x17) {
      piVar4 = (int *)(*(int *)(param_1[1] + 0xc) + 8);
      goto LAB_005b60d4;
    }
    if (iVar1 != 0x15) {
LAB_005b608c:
      if (*(int *)param_1[1] != 4) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x2e,0x81,0x98,"cms_lib.c",0xee);
        return 0;
      }
      puVar2 = (undefined4 *)((int *)param_1[1])[1];
      goto LAB_005b60e0;
    }
    piVar4 = param_1 + 1;
  }
  puVar2 = (undefined4 *)*piVar4;
LAB_005b60e0:
  pcVar5 = (code *)PTR_BIO_s_null_006a89ec;
  if ((puVar2 != (undefined4 *)0x0) && (pcVar5 = (code *)PTR_BIO_s_mem_006a8d04, puVar2[3] != 0x20))
  {
                    /* WARNING: Could not recover jumptable at 0x005b6104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (*(code *)PTR_BIO_new_mem_buf_006aa264)(puVar2[2],*puVar2);
    return uVar3;
  }
  uVar3 = (*pcVar5)();
                    /* WARNING: Could not recover jumptable at 0x005b612c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar3);
  return uVar3;
}

