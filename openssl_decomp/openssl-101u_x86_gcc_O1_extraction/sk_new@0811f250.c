
_STACK * sk_new(cmp *cmp)

{
  _STACK *ptr;
  char **ppcVar1;
  _STACK *p_Var2;
  
  ptr = (_STACK *)CRYPTO_malloc(0x14,"stack.c",0x80);
  p_Var2 = (_STACK *)0x0;
  if (ptr != (_STACK *)0x0) {
    ppcVar1 = (char **)CRYPTO_malloc(0x10,"stack.c",0x82);
    ptr->data = ppcVar1;
    if (ppcVar1 == (char **)0x0) {
      CRYPTO_free(ptr);
      return (_STACK *)0x0;
    }
    *ppcVar1 = (char *)0x0;
    ptr->data[1] = (char *)0x0;
    ptr->data[2] = (char *)0x0;
    ptr->data[3] = (char *)0x0;
    ptr->num_alloc = 4;
    ptr->num = 0;
    ptr->sorted = 0;
    ptr->comp = (_func_257 *)cmp;
    p_Var2 = ptr;
  }
  return p_Var2;
}
