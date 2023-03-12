
_STACK * sk_dup(_STACK *st)

{
  undefined *puVar1;
  _STACK *p_Var2;
  char **ppcVar3;
  int iVar4;
  char **ppcVar5;
  _func_257 *p_Var6;
  
  p_Var6 = st->comp;
  p_Var2 = (_STACK *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x14,"stack.c",0x80);
  if (p_Var2 != (_STACK *)0x0) {
    ppcVar3 = (char **)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x10,"stack.c",0x82);
    p_Var2->data = ppcVar3;
    if (ppcVar3 != (char **)0x0) {
      *ppcVar3 = (char *)0x0;
      puVar1 = PTR_CRYPTO_realloc_006a7b58;
      p_Var2->data[1] = (char *)0x0;
      p_Var2->data[2] = (char *)0x0;
      p_Var2->data[3] = (char *)0x0;
      p_Var2->comp = p_Var6;
      p_Var2->num = 0;
      p_Var2->num_alloc = 4;
      p_Var2->sorted = 0;
      ppcVar3 = (char **)(*(code *)puVar1)(p_Var2->data,st->num_alloc << 2,"stack.c",0x65);
      puVar1 = PTR_memcpy_006a9aec;
      if (ppcVar3 != (char **)0x0) {
        iVar4 = st->num;
        p_Var2->data = ppcVar3;
        ppcVar5 = st->data;
        p_Var2->num = iVar4;
        (*(code *)puVar1)(ppcVar3,ppcVar5,st->num << 2);
        iVar4 = st->num_alloc;
        p_Var6 = st->comp;
        p_Var2->sorted = st->sorted;
        p_Var2->num_alloc = iVar4;
        p_Var2->comp = p_Var6;
        return p_Var2;
      }
      if (p_Var2->data != (char **)0x0) {
        (*(code *)PTR_CRYPTO_free_006a6e88)();
      }
    }
    (*(code *)PTR_CRYPTO_free_006a6e88)(p_Var2);
  }
  return (_STACK *)0x0;
}

