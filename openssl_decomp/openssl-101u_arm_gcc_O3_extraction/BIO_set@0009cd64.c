
int BIO_set(BIO *a,BIO_METHOD *type)

{
  int iVar1;
  
  a->method = type;
  a->callback = (_func_603 *)0x0;
  a->cb_arg = (char *)0x0;
  a->init = 0;
  a->flags = 0;
  a->retry_reason = 0;
  a->num = 0;
  a->ptr = (void *)0x0;
  a->prev_bio = (bio_st *)0x0;
  a->next_bio = (bio_st *)0x0;
  a->num_read = 0;
  a->num_write = 0;
  a->shutdown = 1;
  a->references = 1;
  CRYPTO_new_ex_data(0,a,&a->ex_data);
  if ((type->create != (_func_600 *)0x0) && (iVar1 = (*type->create)(a), iVar1 == 0)) {
    CRYPTO_free_ex_data(0,a,&a->ex_data);
    return 0;
  }
  return 1;
}

