
void BIO_vfree(BIO *a)

{
  int iVar1;
  long lVar2;
  _func_601 *p_Var3;
  
  if (((a != (BIO *)0x0) &&
      (iVar1 = (*(code *)PTR_CRYPTO_add_lock_006a805c)
                         (&a->references,0xffffffff,0x15,"bio_lib.c",0x72), iVar1 < 1)) &&
     ((a->callback == (_func_603 *)0x0 || (lVar2 = (*a->callback)(a,1,(char *)0x0,0,0,1), 0 < lVar2)
      ))) {
    (*(code *)PTR_CRYPTO_free_ex_data_006a82f8)(0,a,&a->ex_data);
    if ((a->method != (BIO_METHOD *)0x0) &&
       (p_Var3 = a->method->destroy, p_Var3 != (_func_601 *)0x0)) {
      (*p_Var3)(a);
    }
                    /* WARNING: Could not recover jumptable at 0x0051ea4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CRYPTO_free_006a6e88)(a);
    return;
  }
  return;
}

