
char * OBJ_NAME_get(char *name,int type)

{
  undefined *puVar1;
  char *pcVar2;
  int iVar3;
  uint *puVar4;
  int *ptr;
  uint uVar5;
  code *pcVar6;
  uint in_a2;
  int iVar7;
  uint local_2c [2];
  char *local_24;
  uint local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(uint *)PTR___stack_chk_guard_006a9ae8;
  pcVar2 = (char *)0x0;
  if (name == (char *)0x0) goto LAB_004c1c28;
  if (names_lh == 0) {
    CRYPTO_mem_ctrl(3);
    pcVar6 = obj_name_LHASH_COMP;
    names_lh = (*(code *)PTR_lh_new_006a740c)(obj_name_LHASH_HASH);
    CRYPTO_mem_ctrl(2);
    if (names_lh != 0) goto LAB_004c1bcc;
  }
  else {
LAB_004c1bcc:
    local_2c[0] = type & 0xffff7fff;
    local_24 = name;
    if ((type & 0x8000U) == 0) {
      iVar7 = 0xb;
      while (pcVar6 = (code *)local_2c, iVar3 = (*(code *)PTR_lh_retrieve_006a73b0)(names_lh),
            iVar3 != 0) {
        if (*(int *)(iVar3 + 4) == 0) goto LAB_004c1c64;
        iVar7 = iVar7 + -1;
        if (iVar7 == 0) break;
        local_24 = *(char **)(iVar3 + 0xc);
      }
    }
    else {
      pcVar6 = (code *)local_2c;
      iVar3 = (*(code *)PTR_lh_retrieve_006a73b0)();
      if (iVar3 != 0) {
LAB_004c1c64:
        pcVar2 = *(char **)(iVar3 + 0xc);
        type = (int)pcVar6;
        goto LAB_004c1c28;
      }
    }
  }
  pcVar2 = (char *)0x0;
  type = (int)pcVar6;
LAB_004c1c28:
  if (local_1c == *(uint *)puVar1) {
    return pcVar2;
  }
  uVar5 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (names_lh == 0) {
    CRYPTO_mem_ctrl(3);
    names_lh = (*(code *)PTR_lh_new_006a740c)(obj_name_LHASH_HASH,obj_name_LHASH_COMP);
    CRYPTO_mem_ctrl(2);
    if (names_lh == 0) {
      return (char *)0x0;
    }
  }
  puVar4 = (uint *)CRYPTO_malloc(0x10,"o_names.c",0xbf);
  iVar3 = names_lh;
  puVar1 = PTR_lh_insert_006a7414;
  if (puVar4 == (uint *)0x0) {
    return (char *)0x0;
  }
  *puVar4 = type & 0xffff7fff;
  puVar4[2] = uVar5;
  puVar4[1] = type & 0x8000;
  puVar4[3] = in_a2;
  ptr = (int *)(*(code *)puVar1)(iVar3,puVar4);
  if (ptr != (int *)0x0) {
    if ((name_funcs_stack != 0) && (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(), *ptr < iVar3)) {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(name_funcs_stack);
      (**(code **)(iVar3 + 8))(ptr[2],*ptr,ptr[3]);
    }
    CRYPTO_free(ptr);
    return (char *)0x1;
  }
  return (char *)(uint)(*(int *)(names_lh + 0x5c) == 0);
}

