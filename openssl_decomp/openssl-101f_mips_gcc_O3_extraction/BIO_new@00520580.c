
BIO * BIO_new(BIO_METHOD *type)

{
  undefined *puVar1;
  BIO *pBVar2;
  int iVar3;
  
  pBVar2 = (BIO *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x40,"bio_lib.c",0x46);
  puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
  if (pBVar2 == (BIO *)0x0) {
    ERR_put_error(0x20,0x6c,0x41,"bio_lib.c",0x49);
    pBVar2 = (BIO *)0x0;
  }
  else {
    pBVar2->method = type;
    pBVar2->callback = (_func_603 *)0x0;
    pBVar2->cb_arg = (char *)0x0;
    pBVar2->init = 0;
    pBVar2->shutdown = 1;
    pBVar2->flags = 0;
    pBVar2->retry_reason = 0;
    pBVar2->num = 0;
    pBVar2->ptr = (void *)0x0;
    pBVar2->prev_bio = (bio_st *)0x0;
    pBVar2->next_bio = (bio_st *)0x0;
    pBVar2->references = 1;
    pBVar2->num_read = 0;
    pBVar2->num_write = 0;
    (*(code *)puVar1)(0,pBVar2,&pBVar2->ex_data);
    if ((type->create != (_func_600 *)0x0) && (iVar3 = (*type->create)(pBVar2), iVar3 == 0)) {
      (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,pBVar2,&pBVar2->ex_data);
      (*(code *)PTR_CRYPTO_free_006a7f88)(pBVar2);
      return (BIO *)0x0;
    }
  }
  return pBVar2;
}

