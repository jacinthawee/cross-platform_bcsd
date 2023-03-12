
CONF_VALUE * _CONF_get_section(CONF *conf,char *section)

{
  undefined *puVar1;
  CONF_VALUE *pCVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  undefined4 *in_a2;
  undefined4 ***pppuVar5;
  undefined4 ****ppppuStack_48;
  undefined4 uStack_44;
  int iStack_3c;
  undefined *puStack_38;
  code *pcStack_34;
  undefined *local_20;
  undefined4 ***local_18;
  undefined4 local_14;
  int local_c;
  
  puStack_38 = PTR___stack_chk_guard_006aabf0;
  local_20 = &_gp;
  local_c = *(int *)PTR___stack_chk_guard_006aabf0;
  if ((conf == (CONF *)0x0) || (section == (char *)0x0)) {
    pCVar2 = (CONF_VALUE *)0x0;
  }
  else {
    ppppuVar4 = &local_18;
    local_14 = 0;
    local_18 = (undefined4 ***)section;
    pCVar2 = (CONF_VALUE *)(*(code *)PTR_lh_retrieve_006a84b0)(conf->data);
    section = (char *)ppppuVar4;
  }
  if (local_c == *(int *)puStack_38) {
    return pCVar2;
  }
  pcStack_34 = _CONF_get_section_values;
  iVar3 = local_c;
  (**(code **)(local_20 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_3c = *(int *)PTR___stack_chk_guard_006aabf0;
  ppppuVar4 = (undefined4 ****)section;
  if ((iVar3 != 0) && ((undefined4 ****)section != (undefined4 ****)0x0)) {
    ppppuVar4 = &ppppuStack_48;
    uStack_44 = 0;
    ppppuStack_48 = (undefined4 ****)section;
    iVar3 = (*(code *)PTR_lh_retrieve_006a84b0)(*(undefined4 *)(iVar3 + 8));
    if (iVar3 != 0) {
      pCVar2 = *(CONF_VALUE **)(iVar3 + 8);
      goto LAB_0059e530;
    }
  }
  pCVar2 = (CONF_VALUE *)0x0;
LAB_0059e530:
  if (iStack_3c == *(int *)puVar1) {
    return pCVar2;
  }
  iVar3 = iStack_3c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR_sk_push_006a80a8;
  pppuVar5 = ppppuVar4[2];
  *in_a2 = *ppppuVar4;
  pCVar2 = (CONF_VALUE *)(*(code *)puVar1)(pppuVar5,in_a2);
  if (pCVar2 != (CONF_VALUE *)0x0) {
    iVar3 = (*(code *)PTR_lh_insert_006a8514)(*(undefined4 *)(iVar3 + 8),in_a2);
    if (iVar3 != 0) {
      (*(code *)PTR_sk_delete_ptr_006aa020)(pppuVar5,iVar3);
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar3 + 4));
      (*(code *)PTR_CRYPTO_free_006a7f88)(*(undefined4 *)(iVar3 + 8));
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
      return (CONF_VALUE *)0x1;
    }
    pCVar2 = (CONF_VALUE *)0x1;
  }
  return pCVar2;
}

