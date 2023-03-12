
void BIO_free_all(BIO *a)

{
  int iVar1;
  bio_st *pbVar2;
  _func_601 *p_Var3;
  int iVar4;
  long lVar5;
  
  if (a != (BIO *)0x0) {
    do {
      iVar1 = a->references;
      pbVar2 = a->next_bio;
      iVar4 = CRYPTO_add_lock(&a->references,-1,0x15,"bio_lib.c",0x75);
      if ((iVar4 < 1) &&
         ((a->callback == (_func_603 *)0x0 ||
          (lVar5 = (*a->callback)(a,1,(char *)0x0,0,0,1), 0 < lVar5)))) {
        CRYPTO_free_ex_data(0,a,&a->ex_data);
        if ((a->method != (BIO_METHOD *)0x0) &&
           (p_Var3 = a->method->destroy, p_Var3 != (_func_601 *)0x0)) {
          (*p_Var3)(a);
          CRYPTO_free(a);
        }
      }
    } while ((iVar1 < 2) && (a = pbVar2, pbVar2 != (bio_st *)0x0));
  }
  return;
}

