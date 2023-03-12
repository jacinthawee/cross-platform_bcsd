
char * OBJ_NAME_get(char *name,int type)

{
  void *pvVar1;
  char *pcVar2;
  int iVar3;
  int in_GS_OFFSET;
  uint local_20 [2];
  char *local_18;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (name != (char *)0x0) {
    if (names_lh == (_LHASH *)0x0) {
      CRYPTO_mem_ctrl(3);
      names_lh = lh_new(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
      CRYPTO_mem_ctrl(2);
      if (names_lh == (_LHASH *)0x0) goto LAB_080d5e85;
    }
    local_20[0] = type & 0xffff7fff;
    local_18 = name;
    iVar3 = 0xb;
    while (pvVar1 = lh_retrieve(names_lh,local_20), pvVar1 != (void *)0x0) {
      if ((*(int *)((int)pvVar1 + 4) == 0) || ((type & 0x8000U) != 0)) {
        pcVar2 = *(char **)((int)pvVar1 + 0xc);
        goto LAB_080d5e87;
      }
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) break;
      local_18 = *(char **)((int)pvVar1 + 0xc);
    }
  }
LAB_080d5e85:
  pcVar2 = (char *)0x0;
LAB_080d5e87:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return pcVar2;
}

