
_STACK * sk_dup(_STACK *st)

{
  _func_257 *p_Var1;
  int iVar2;
  _STACK *ptr;
  char **ppcVar3;
  
  p_Var1 = st->comp;
  ptr = (_STACK *)CRYPTO_malloc(0x14,"stack.c",0x7d);
  if (ptr != (_STACK *)0x0) {
    ppcVar3 = (char **)CRYPTO_malloc(0x10,"stack.c",0x7f);
    ptr->data = ppcVar3;
    if (ppcVar3 != (char **)0x0) {
      *ppcVar3 = (char *)0x0;
      ptr->data[1] = (char *)0x0;
      ptr->data[2] = (char *)0x0;
      ptr->data[3] = (char *)0x0;
      ptr->num_alloc = 4;
      ptr->comp = p_Var1;
      ptr->num = 0;
      ptr->sorted = 0;
      ppcVar3 = (char **)CRYPTO_realloc(ptr->data,st->num_alloc << 2,"stack.c",99);
      if (ppcVar3 != (char **)0x0) {
        iVar2 = st->num;
        ptr->data = ppcVar3;
        ptr->num = iVar2;
        memcpy(ppcVar3,st->data,st->num * 4);
        ptr->sorted = st->sorted;
        ptr->num_alloc = st->num_alloc;
        ptr->comp = st->comp;
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

