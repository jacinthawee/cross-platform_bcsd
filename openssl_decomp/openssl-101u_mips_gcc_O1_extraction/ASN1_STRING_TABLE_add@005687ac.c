
int ASN1_STRING_TABLE_add(int param_1,long param_2,long param_3,ulong param_4,ulong param_5)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int local_40 [5];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (stable == 0) {
    stable = (*(code *)PTR_sk_new_006a806c)(sk_table_cmp);
    if (stable == 0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf2);
      iVar4 = 0;
      goto LAB_00568888;
    }
  }
  local_40[0] = param_1;
  piVar3 = (int *)(*(code *)PTR_OBJ_bsearch__006a8368)
                            (local_40,tbl_standard,0x13,0x14,table_cmp_BSEARCH_CMP_FN);
  if (piVar3 == (int *)0x0) {
    if (stable != 0) {
      iVar4 = (*(code *)PTR_sk_find_006a8044)(stable,local_40);
      if (-1 < iVar4) {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(stable,iVar4);
        if (piVar3 != (int *)0x0) goto LAB_0056884c;
      }
    }
    piVar3 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"a_strnid.c",0xf6);
    if (piVar3 == (int *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x81,0x41,"a_strnid.c",0xf8);
      iVar4 = 0;
      goto LAB_00568888;
    }
    *piVar3 = param_1;
    bVar1 = true;
    piVar3[4] = param_5 & 0xfffffffe | 1;
  }
  else {
LAB_0056884c:
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
    (*(code *)PTR_sk_push_006a6fa8)(stable,piVar3);
    iVar4 = 1;
  }
  else {
    iVar4 = 1;
  }
LAB_00568888:
  if (local_2c == *(int *)puVar2) {
    return iVar4;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = stable;
  if (stable != 0) {
    stable = 0;
                    /* WARNING: Could not recover jumptable at 0x005689ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)PTR_sk_pop_free_006a7058)(iVar4,st_free);
    return iVar4;
  }
  return (int)&_gp_1;
}

