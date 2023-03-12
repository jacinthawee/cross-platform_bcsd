
stack_st_X509 * CMS_get0_signers(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  stack_st_X509 *psVar5;
  undefined4 uVar6;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 == 0x16) {
    uVar6 = 0;
    if (*(int *)(cms + 4) != 0) {
      uVar6 = *(undefined4 *)(*(int *)(cms + 4) + 0x14);
    }
  }
  else {
    uVar6 = 0;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x85,0x6c,"cms_sd.c",0x47);
  }
  psVar5 = (stack_st_X509 *)0x0;
  iVar1 = 0;
  do {
    do {
      iVar2 = (*(code *)PTR_sk_num_006a6e2c)(uVar6);
      iVar4 = iVar1 + 1;
      if (iVar2 <= iVar1) {
        return psVar5;
      }
      iVar2 = (*(code *)PTR_sk_value_006a6e24)(uVar6,iVar1);
      iVar3 = *(int *)(iVar2 + 0x1c);
      iVar1 = iVar4;
    } while (iVar3 == 0);
    if (psVar5 == (stack_st_X509 *)0x0) {
      psVar5 = (stack_st_X509 *)(*(code *)PTR_sk_new_null_006a6fa4)();
      if (psVar5 == (stack_st_X509 *)0x0) {
        return (stack_st_X509 *)0x0;
      }
      iVar3 = *(int *)(iVar2 + 0x1c);
    }
    iVar2 = (*(code *)PTR_sk_push_006a6fa8)(psVar5,iVar3);
  } while (iVar2 != 0);
  (*(code *)PTR_sk_free_006a6e80)(psVar5);
  return (stack_st_X509 *)0x0;
}

