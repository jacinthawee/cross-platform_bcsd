
int BIO_set(BIO *a,BIO_METHOD *type)

{
  undefined *puVar1;
  int iVar2;
  
  a->callback = (_func_603 *)0x0;
  a->cb_arg = (char *)0x0;
  a->init = 0;
  a->method = type;
  a->shutdown = 1;
  a->flags = 0;
  a->retry_reason = 0;
  a->num = 0;
  a->ptr = (void *)0x0;
  a->prev_bio = (bio_st *)0x0;
  a->next_bio = (bio_st *)0x0;
  a->references = 1;
  a->num_read = 0;
  puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
  a->num_write = 0;
  (*(code *)puVar1)(0,a,&a->ex_data);
  if ((type->create != (_func_600 *)0x0) && (iVar2 = (*type->create)(a), iVar2 == 0)) {
    (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(0,a,&a->ex_data);
    return 0;
  }
  return 1;
}

