
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_STACK * sk_new_null(void)

{
  _STACK *p_Var1;
  char **ppcVar2;
  
  p_Var1 = (_STACK *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x14,"stack.c",0x7d);
  if (p_Var1 == (_STACK *)0x0) {
    return (_STACK *)0x0;
  }
  ppcVar2 = (char **)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x10,"stack.c",0x7f);
  p_Var1->data = ppcVar2;
  if (ppcVar2 != (char **)0x0) {
    *ppcVar2 = (char *)0x0;
    p_Var1->data[1] = (char *)0x0;
    p_Var1->data[2] = (char *)0x0;
    p_Var1->data[3] = (char *)0x0;
    p_Var1->comp = (_func_257 *)0x0;
    p_Var1->num = 0;
    p_Var1->num_alloc = 4;
    p_Var1->sorted = 0;
    return p_Var1;
  }
  (*(code *)PTR_CRYPTO_free_006a7f88)(p_Var1);
  return (_STACK *)0x0;
}

