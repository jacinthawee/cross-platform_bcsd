
int BIO_free(BIO *a)

{
  _func_601 *p_Var1;
  int iVar2;
  long lVar3;
  
  lVar3 = 0;
  if (a != (BIO *)0x0) {
    iVar2 = CRYPTO_add_lock(&a->references,-1,0x15,"bio_lib.c",0x72);
    lVar3 = 1;
    if ((iVar2 < 1) &&
       ((a->callback == (_func_603 *)0x0 ||
        (lVar3 = (*a->callback)(a,1,(char *)0x0,0,0,1), 0 < lVar3)))) {
      CRYPTO_free_ex_data(0,a,&a->ex_data);
      if ((a->method != (BIO_METHOD *)0x0) &&
         (p_Var1 = a->method->destroy, p_Var1 != (_func_601 *)0x0)) {
        (*p_Var1)(a);
      }
      CRYPTO_free(a);
      return 1;
    }
  }
  return lVar3;
}

