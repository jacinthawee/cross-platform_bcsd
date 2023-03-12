
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
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppcVar4 = (char **)section;
  if ((conf != (CONF *)0x0) && (section != (char *)0x0)) {
    ppcVar4 = &local_18;
    local_14 = 0;
    local_18 = section;
    iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(conf->data);
    if (iVar2 != 0) {
      psVar3 = *(stack_st_CONF_VALUE **)(iVar2 + 8);
      goto LAB_0059e530;
    }
  }
  psVar3 = (stack_st_CONF_VALUE *)0x0;
LAB_0059e530:
  if (local_c == *(int *)puVar1) {
    return psVar3;
  }
  iVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR_sk_push_006a80a8;
  pcVar5 = ppcVar4[2];
  *in_a2 = *ppcVar4;
  psVar3 = (stack_st_CONF_VALUE *)(*(code *)puVar1)(pcVar5,in_a2);
  if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
    iVar2 = (*(code *)PTR_lh_insert_006a8514)(*(undefined4 *)(iVar2 + 8),in_a2);
    if (iVar2 != 0) {
      (*(code *)PTR_sk_delete_ptr_006aa020)(pcVar5,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 4));
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 8));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
      return (stack_st_CONF_VALUE *)0x1;
    }
    psVar3 = (stack_st_CONF_VALUE *)0x1;
  }
  return psVar3;
}

