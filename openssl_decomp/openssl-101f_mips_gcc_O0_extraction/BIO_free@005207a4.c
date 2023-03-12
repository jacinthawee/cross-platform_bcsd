
int BIO_free(BIO *a)

{
  int iVar1;
  long lVar2;
  _func_601 *p_Var3;
  
  if (a == (BIO *)0x0) {
    return 0;
  }
  iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a9080)(&a->references,0xffffffff,0x15,"bio_lib.c",0x75);
  if (iVar1 < 1) {
    if ((a->callback != (_func_603 *)0x0) &&
       (lVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1), lVar2 < 1)) {
      return lVar2;
    }
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,a,&a->ex_data);
    if ((a->method != (BIO_METHOD *)0x0) &&
       (p_Var3 = a->method->destroy, p_Var3 != (_func_601 *)0x0)) {
      (*p_Var3)(a);
      (*(code *)PTR_CRYPTO_free_006a7f88)(a);
      return 1;
    }
  }
  return 1;
}

