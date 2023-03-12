
X509_VERIFY_PARAM * X509_VERIFY_PARAM_lookup(char *name)

{
  undefined *puVar1;
  int iVar2;
  X509_VERIFY_PARAM *pXVar3;
  char *local_34 [8];
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  local_34[0] = name;
  if ((param_table == 0) ||
     (iVar2 = (*(code *)PTR_sk_find_006a906c)(param_table,local_34), iVar2 == -1)) {
    pXVar3 = (X509_VERIFY_PARAM *)
             (*(code *)PTR_OBJ_bsearch__006a9488)
                       (local_34,default_table,5,0x20,table_cmp_BSEARCH_CMP_FN);
  }
  else {
    pXVar3 = (X509_VERIFY_PARAM *)(*(code *)PTR_sk_value_006a7f24)(param_table,iVar2);
  }
  if (local_14 != *(int *)puVar1) {
    pXVar3 = (X509_VERIFY_PARAM *)(*(code *)PTR___stack_chk_fail_006aabb8)();
    if (param_table != 0) {
      pXVar3 = (X509_VERIFY_PARAM *)
               (*(code *)PTR_sk_pop_free_006a8158)(param_table,X509_VERIFY_PARAM_free);
    }
    param_table = 0;
    return pXVar3;
  }
  return pXVar3;
}

