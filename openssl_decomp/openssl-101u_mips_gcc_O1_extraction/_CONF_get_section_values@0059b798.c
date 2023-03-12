
stack_st_CONF_VALUE * _CONF_get_section_values(CONF *conf,char *section)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  char **ppcVar4;
  char **in_a2;
  char *pcVar5;
  char *local_18;
  undefined4 local_14;
  int local_c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_c = *(int *)PTR___stack_chk_guard_006a9ae8;
  ppcVar4 = (char **)section;
  if ((conf != (CONF *)0x0) && (section != (char *)0x0)) {
    ppcVar4 = &local_18;
    local_14 = 0;
    local_18 = section;
    iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)(conf->data);
    if (iVar2 != 0) {
      psVar3 = *(stack_st_CONF_VALUE **)(iVar2 + 8);
      goto LAB_0059b7f0;
    }
  }
  psVar3 = (stack_st_CONF_VALUE *)0x0;
LAB_0059b7f0:
  if (local_c == *(int *)puVar1) {
    return psVar3;
  }
  iVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR_sk_push_006a6fa8;
  pcVar5 = ppcVar4[2];
  *in_a2 = *ppcVar4;
  psVar3 = (stack_st_CONF_VALUE *)(*(code *)puVar1)(pcVar5,in_a2);
  if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
    iVar2 = (*(code *)PTR_lh_insert_006a7414)(*(undefined4 *)(iVar2 + 8),in_a2);
    if (iVar2 != 0) {
      (*(code *)PTR_sk_delete_ptr_006a8f00)(pcVar5,iVar2);
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar2 + 4));
      (*(code *)PTR_CRYPTO_free_006a6e88)(*(undefined4 *)(iVar2 + 8));
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar2);
      return (stack_st_CONF_VALUE *)0x1;
    }
    psVar3 = (stack_st_CONF_VALUE *)0x1;
  }
  return psVar3;
}

