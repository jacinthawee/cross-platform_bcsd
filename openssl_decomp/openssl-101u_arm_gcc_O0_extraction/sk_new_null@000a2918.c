
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

_STACK * sk_new_null(void)

{
  _STACK *ptr;
  char **ppcVar1;
  
  ptr = (_STACK *)CRYPTO_malloc(0x14,"stack.c",0x80);
  if (ptr == (_STACK *)0x0) {
    return (_STACK *)0x0;
  }
  ppcVar1 = (char **)CRYPTO_malloc(0x10,"stack.c",0x82);
  ptr->data = ppcVar1;
  if (ppcVar1 != (char **)0x0) {
    *ppcVar1 = (char *)0x0;
    ptr->data[1] = (char *)0x0;
    ptr->data[2] = (char *)0x0;
    ptr->data[3] = (char *)0x0;
    ptr->comp = (_func_257 *)0x0;
    ptr->num = 0;
    ptr->sorted = 0;
    ptr->num_alloc = 4;
    return ptr;
  }
  CRYPTO_free(ptr);
  return (_STACK *)0x0;
}

