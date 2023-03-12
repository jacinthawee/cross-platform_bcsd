
size_t SSL_get_finished(SSL *s,void *buf,size_t count)

{
  ssl3_state_st *psVar1;
  undefined4 in_a3;
  uint uVar2;
  
  psVar1 = s->s3;
  if (psVar1 != (ssl3_state_st *)0x0) {
    uVar2 = (psVar1->tmp).finish_md_len;
    if (uVar2 <= count) {
      count = uVar2;
    }
    (*(code *)PTR_memcpy_006a9aec)(buf,(psVar1->tmp).finish_md,count,in_a3,&_gp);
    return uVar2;
  }
  return 0;
}

