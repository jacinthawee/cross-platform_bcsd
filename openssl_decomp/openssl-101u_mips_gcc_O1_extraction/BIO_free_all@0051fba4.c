
void BIO_free_all(BIO *a)

{
  int iVar1;
  long lVar2;
  int iVar3;
  bio_st *pbVar4;
  _func_601 *p_Var5;
  
  if (a != (BIO *)0x0) {
    do {
      iVar3 = a->references;
      pbVar4 = a->next_bio;
      iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                        (&a->references,0xffffffff,0x15,"bio_lib.c",0x72);
      if ((iVar1 < 1) &&
         ((a->callback == (_func_603 *)0x0 ||
          (lVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1), 0 < lVar2)))) {
        (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0,a,&a->ex_data);
        if ((a->method != (BIO_METHOD *)0x0) &&
           (p_Var5 = a->method->destroy, p_Var5 != (_func_601 *)0x0)) {
          (*p_Var5)(a);
        }
        (*(code *)PTR_CRYPTO_free_006a6e88)(a);
      }
    } while ((iVar3 < 2) && (a = pbVar4, pbVar4 != (bio_st *)0x0));
  }
  return;
}

