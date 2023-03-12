
stack_st_CONF_VALUE * NCONF_get_section(CONF *conf,char *section)

{
  undefined *puVar1;
  int iVar2;
  stack_st_CONF_VALUE *psVar3;
  char **ppcVar4;
  char **in_a2;
  undefined4 uVar5;
  char *pcVar6;
  char *local_18;
  undefined4 uStack_14;
  undefined *local_10;
  int iStack_c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_10 = &_gp;
  if (conf == (CONF *)0x0) {
    uVar5 = 0x69;
    local_18 = (char *)0x133;
LAB_0059dcfc:
    (*(code *)PTR_ERR_put_error_006a9030)(0xe,0x6c,uVar5,"conf_lib.c");
    return (stack_st_CONF_VALUE *)0x0;
  }
  if (section == (char *)0x0) {
    uVar5 = 0x6b;
    local_18 = (char *)0x139;
    goto LAB_0059dcfc;
  }
  iStack_c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppcVar4 = (char **)section;
  if ((conf != (CONF *)0x0) && (section != (char *)0x0)) {
    ppcVar4 = &local_18;
    uStack_14 = 0;
    local_18 = section;
    iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(conf->data);
    if (iVar2 != 0) {
      psVar3 = *(stack_st_CONF_VALUE **)(iVar2 + 8);
      goto LAB_0059e530;
    }
  }
  psVar3 = (stack_st_CONF_VALUE *)0x0;
LAB_0059e530:
  if (iStack_c == *(int *)puVar1) {
    return psVar3;
  }
  iVar2 = iStack_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR_sk_push_006a80a8;
  pcVar6 = ppcVar4[2];
  *in_a2 = *ppcVar4;
  psVar3 = (stack_st_CONF_VALUE *)(*(code *)puVar1)(pcVar6,in_a2);
  if (psVar3 != (stack_st_CONF_VALUE *)0x0) {
    iVar2 = (*(code *)PTR_lh_insert_006a8514)(*(undefined4 *)(iVar2 + 8),in_a2);
    if (iVar2 != 0) {
      (*(code *)PTR_sk_delete_ptr_006aa020)(pcVar6,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 4));
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar2 + 8));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar2);
      return (stack_st_CONF_VALUE *)0x1;
    }
    psVar3 = (stack_st_CONF_VALUE *)0x1;
  }
  return psVar3;
}

