
void value_free_stack_LHASH_DOALL(void **param_1)

{
  _STACK *p_Var1;
  int iVar2;
  void *ptr;
  int iVar3;
  
  if (param_1[1] == (void *)0x0) {
    p_Var1 = (_STACK *)param_1[2];
    iVar2 = sk_num(p_Var1);
    iVar2 = iVar2 + -1;
    if (-1 < iVar2) {
      do {
        iVar3 = iVar2 + -1;
        ptr = sk_value(p_Var1,iVar2);
        CRYPTO_free(*(void **)((int)ptr + 8));
        CRYPTO_free(*(void **)((int)ptr + 4));
        CRYPTO_free(ptr);
        iVar2 = iVar3;
      } while (iVar3 != -1);
    }
    if (p_Var1 != (_STACK *)0x0) {
      sk_free(p_Var1);
    }
    CRYPTO_free(*param_1);
    CRYPTO_free(param_1);
    return;
  }
  return;
}

