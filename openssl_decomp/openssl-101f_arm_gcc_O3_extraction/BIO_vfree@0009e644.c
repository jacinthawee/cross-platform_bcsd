
void BIO_vfree(BIO *a)

{
  int iVar1;
  long lVar2;
  _func_601 *p_Var3;
  
  if ((a != (BIO *)0x0) &&
     (iVar1 = CRYPTO_add_lock(&a->references,-1,0x15,"bio_lib.c",0x75), iVar1 < 1)) {
    if ((a->callback != (_func_603 *)0x0) &&
       (lVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1), lVar2 < 1)) {
      return;
    }
    CRYPTO_free_ex_data(0,a,&a->ex_data);
    if ((a->method != (BIO_METHOD *)0x0) &&
       (p_Var3 = a->method->destroy, p_Var3 != (_func_601 *)0x0)) {
      (*p_Var3)(a);
      CRYPTO_free(a);
      return;
    }
  }
  return;
}

