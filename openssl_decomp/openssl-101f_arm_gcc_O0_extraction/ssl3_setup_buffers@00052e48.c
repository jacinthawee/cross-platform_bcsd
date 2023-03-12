
int ssl3_setup_buffers(SSL *param_1)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  ssl3_state_st *psVar4;
  size_t *psVar5;
  size_t *psVar6;
  size_t num;
  _func_3154 *p_Var7;
  bool bVar8;
  
  iVar1 = SSL_version(param_1);
  if (iVar1 == 0xfeff) {
    sVar2 = 0x8150;
    num = 0x4150;
  }
  else {
    num = 0x4150;
    iVar1 = SSL_version(param_1);
    sVar2 = 0x8150;
    if (iVar1 != 0x100) {
      sVar2 = 0x8148;
      num = 0x4148;
    }
  }
  psVar5 = (size_t *)(param_1->s3->rbuf).buf;
  if (psVar5 == (size_t *)0x0) {
    iVar1 = param_1->references;
    p_Var7 = param_1->psk_server_callback;
    bVar8 = iVar1 << 0x1a < 0;
    sVar3 = sVar2;
    if (bVar8) {
      sVar3 = 1;
      num = sVar2;
    }
    if (bVar8) {
      param_1->s3->init_extra = sVar3;
    }
    if (-1 < iVar1 << 0xe) {
      num = num + 0x400;
    }
    CRYPTO_lock(9,0xc,"s3_both.c",0x2b7);
    psVar6 = *(size_t **)(p_Var7 + 0x160);
    if (((psVar6 == (size_t *)0x0) || (num != *psVar6)) ||
       (psVar5 = (size_t *)psVar6[2], psVar5 == (size_t *)0x0)) {
      CRYPTO_lock(10,0xc,"s3_both.c",0x2c2);
      psVar5 = (size_t *)CRYPTO_malloc(num,"s3_both.c",0x2c4);
      if (psVar5 == (size_t *)0x0) {
        ERR_put_error(0x14,0x9c,0x41,"s3_both.c",0x30c);
        return 0;
      }
    }
    else {
      sVar3 = psVar6[1];
      sVar2 = *psVar5;
      psVar6[1] = sVar3 - 1;
      psVar6[2] = sVar2;
      if (sVar3 - 1 == 0) {
        *psVar6 = 0;
      }
      CRYPTO_lock(10,0xc,"s3_both.c",0x2c2);
    }
    psVar4 = param_1->s3;
    (psVar4->rbuf).buf = (uchar *)psVar5;
    (psVar4->rbuf).len = num;
  }
  param_1->packet = (uchar *)psVar5;
  iVar1 = ssl3_setup_write_buffer(param_1);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

