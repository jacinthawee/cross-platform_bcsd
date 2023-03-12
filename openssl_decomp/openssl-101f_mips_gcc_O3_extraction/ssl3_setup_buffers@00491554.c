
bool ssl3_setup_buffers(SSL *param_1)

{
  int iVar1;
  ssl3_state_st *psVar2;
  size_t *psVar3;
  uint uVar4;
  size_t *psVar5;
  size_t sVar6;
  size_t sVar7;
  _func_3154 *p_Var8;
  code *pcVar9;
  
  iVar1 = SSL_version(param_1);
  if ((iVar1 == 0xfeff) || (iVar1 = SSL_version(param_1), iVar1 == 0x100)) {
    psVar2 = param_1->s3;
    sVar6 = 0x8150;
    psVar3 = (size_t *)(psVar2->rbuf).buf;
    sVar7 = 0x4150;
  }
  else {
    psVar2 = param_1->s3;
    sVar6 = 0x8148;
    psVar3 = (size_t *)(psVar2->rbuf).buf;
    sVar7 = 0x4148;
  }
  if (psVar3 == (size_t *)0x0) {
    uVar4 = param_1->references;
    if ((uVar4 & 0x20) != 0) {
      psVar2->init_extra = 1;
      sVar7 = sVar6;
    }
    p_Var8 = param_1->psk_server_callback;
    if (-1 < (int)(uVar4 << 0xe)) {
      sVar7 = sVar7 + 0x400;
    }
    (*(code *)PTR_CRYPTO_lock_006a926c)(9,0xc,"s3_both.c",0x2b7);
    pcVar9 = (code *)PTR_CRYPTO_lock_006a926c;
    psVar5 = *(size_t **)(p_Var8 + 0x160);
    if (((psVar5 == (size_t *)0x0) || (sVar7 != *psVar5)) ||
       (psVar3 = (size_t *)psVar5[2], psVar3 == (size_t *)0x0)) {
      (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xc,"s3_both.c",0x2c2);
      psVar3 = (size_t *)(*(code *)PTR_CRYPTO_malloc_006a8108)(sVar7,"s3_both.c",0x2c4);
      if (psVar3 == (size_t *)0x0) {
        (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x9c,0x41,"s3_both.c",0x30c);
        return false;
      }
    }
    else {
      sVar6 = psVar5[1];
      psVar5[2] = *psVar3;
      psVar5[1] = sVar6 - 1;
      if (sVar6 - 1 == 0) {
        *psVar5 = 0;
        pcVar9 = (code *)PTR_CRYPTO_lock_006a926c;
      }
      (*pcVar9)(10,0xc,"s3_both.c",0x2c2);
    }
    psVar2 = param_1->s3;
    (psVar2->rbuf).buf = (uchar *)psVar3;
    (psVar2->rbuf).len = sVar7;
  }
  param_1->packet = (uchar *)psVar3;
  iVar1 = ssl3_setup_write_buffer(param_1);
  return iVar1 != 0;
}

