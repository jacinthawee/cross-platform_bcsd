
int engine_cleanup_add_last(undefined4 param_1)

{
  _STACK *p_Var1;
  undefined4 *puVar2;
  int iVar3;
  char **ppcVar4;
  int iVar5;
  int iVar6;
  
  if ((cleanup_stack == (_STACK *)0x0) &&
     (cleanup_stack = sk_new_null(), cleanup_stack == (_STACK *)0x0)) {
    return 0;
  }
  puVar2 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a8108)(4,"eng_lib.c",0xa2);
  p_Var1 = cleanup_stack;
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  *puVar2 = param_1;
  iVar6 = p_Var1->num;
  iVar3 = iVar6 + 1;
  if (iVar3 < p_Var1->num_alloc) {
    ppcVar4 = p_Var1->data;
    iVar5 = iVar6;
  }
  else {
    ppcVar4 = (char **)(*(code *)PTR_CRYPTO_realloc_006a8c44)
                                 (p_Var1->data,p_Var1->num_alloc << 3,"stack.c",0x96);
    if (ppcVar4 == (char **)0x0) {
      return 0;
    }
    iVar5 = p_Var1->num;
    p_Var1->data = ppcVar4;
    p_Var1->num_alloc = p_Var1->num_alloc << 1;
    if ((iVar6 < iVar5) && (iVar3 = iVar5 + 1, -1 < iVar6)) {
      (*(code *)PTR_memmove_006aabfc)
                (ppcVar4 + ((iVar5 + 2) - (iVar3 - iVar6)),ppcVar4 + ((iVar5 + 1) - (iVar3 - iVar6))
                );
      p_Var1->data[iVar6] = (char *)puVar2;
      goto LAB_0052e3e8;
    }
    iVar3 = iVar5 + 1;
  }
  ppcVar4[iVar5] = (char *)puVar2;
LAB_0052e3e8:
  p_Var1->num = iVar3;
  p_Var1->sorted = 0;
  return iVar3;
}

