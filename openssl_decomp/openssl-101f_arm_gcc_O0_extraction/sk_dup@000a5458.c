
_STACK * sk_dup(_STACK *st)

{
  _STACK *ptr;
  char **ppcVar1;
  int iVar2;
  char **__src;
  _func_257 *p_Var3;
  
  p_Var3 = st->comp;
  ptr = (_STACK *)CRYPTO_malloc(0x14,"stack.c",0x7d);
  if (ptr != (_STACK *)0x0) {
    ppcVar1 = (char **)CRYPTO_malloc(0x10,"stack.c",0x7f);
    ptr->data = ppcVar1;
    if (ppcVar1 != (char **)0x0) {
      *ppcVar1 = (char *)0x0;
      ptr->data[1] = (char *)0x0;
      ptr->data[2] = (char *)0x0;
      ptr->data[3] = (char *)0x0;
      ptr->num_alloc = 4;
      iVar2 = st->num_alloc;
      ptr->num = 0;
      ptr->sorted = 0;
      ptr->comp = p_Var3;
      ppcVar1 = (char **)CRYPTO_realloc(ptr->data,iVar2 << 2,"stack.c",99);
      if (ppcVar1 != (char **)0x0) {
        iVar2 = st->num;
        ptr->data = ppcVar1;
        __src = st->data;
        ptr->num = iVar2;
        memcpy(ppcVar1,__src,st->num << 2);
        iVar2 = st->num_alloc;
        p_Var3 = st->comp;
        ptr->sorted = st->sorted;
        ptr->num_alloc = iVar2;
        ptr->comp = p_Var3;
        return ptr;
      }
      if (ptr->data != (char **)0x0) {
        CRYPTO_free(ptr->data);
      }
    }
    CRYPTO_free(ptr);
  }
  return (_STACK *)0x0;
}

