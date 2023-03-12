
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int local_40 [5];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a91b4)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xdd);
      iVar4 = 0;
      goto LAB_0056c1a8;
    }
  }
  local_40[0] = param_1;
  piVar3 = (int *)(*(code *)PTR_OBJ_bsearch__006a9488)
                            (local_40,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar3 == (int *)0x0) {
    if (stable != 0) {
      iVar4 = (*(code *)PTR_sk_find_006a906c)(stable,local_40);
      if (-1 < iVar4) {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(stable,iVar4);
        if (piVar3 != (int *)0x0) goto LAB_0056c16c;
      }
    }
    piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"a_strnid.c",0xe1);
    if (piVar3 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x81,0x41,"a_strnid.c",0xe4);
      iVar4 = 0;
      goto LAB_0056c1a8;
    }
    *piVar3 = param_1;
    bVar1 = true;
    piVar3[4] = param_5 & 0xfffffffe | 1;
  }
  else {
LAB_0056c16c:
    bVar1 = false;
    piVar3[4] = piVar3[4] & 1U | param_5 & 0xfffffffe;
  }
  if (param_2 != -1) {
    piVar3[1] = param_2;
  }
  if (param_3 != -1) {
    piVar3[2] = param_3;
  }
  piVar3[3] = param_4;
  if (bVar1) {
    (*(code *)PTR_sk_push_006a80a8)(stable,piVar3);
    iVar4 = 1;
  }
  else {
    iVar4 = 1;
  }
LAB_0056c1a8:
  if (local_2c == *(int *)puVar2) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar4 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x0056c30c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_sk_pop_free_006a8158)(iVar4,st_free);
    return iVar4;
  }
  return (int)&_ITM_registerTMCloneTable;
}

