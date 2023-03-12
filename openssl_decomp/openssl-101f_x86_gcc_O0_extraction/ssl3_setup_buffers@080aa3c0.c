
bool ssl3_setup_buffers(SSL *param_1)

{
  ssl3_state_st *psVar1;
  uint mode;
  _func_3154 *p_Var2;
  size_t *mode_00;
  int iVar3;
  size_t *psVar4;
  size_t sVar5;
  size_t num;
  
  iVar3 = SSL_version(param_1);
  if (iVar3 != 0xfeff) {
    num = 0x4148;
    iVar3 = SSL_version(param_1);
    sVar5 = 0x8148;
    if (iVar3 != 0x100) {
      psVar1 = param_1->s3;
      psVar4 = (size_t *)(psVar1->rbuf).buf;
      goto joined_r0x080aa435;
    }
  }
  psVar1 = param_1->s3;
  sVar5 = 0x8150;
  num = 0x4150;
  psVar4 = (size_t *)(psVar1->rbuf).buf;
joined_r0x080aa435:
  if (psVar4 == (size_t *)0x0) {
    mode = param_1->references;
    if ((mode & 0x20) != 0) {
      psVar1->init_extra = 1;
      num = sVar5;
    }
    p_Var2 = param_1->psk_server_callback;
    if ((mode & 0x20000) == 0) {
      num = num + 0x400;
    }
    CRYPTO_lock(mode,9,&DAT_0000000c,(int)"s3_both.c");
    mode_00 = *(size_t **)(p_Var2 + 0x160);
    if (((mode_00 == (size_t *)0x0) || (num != *mode_00)) ||
       (psVar4 = (size_t *)mode_00[2], psVar4 == (size_t *)0x0)) {
      CRYPTO_lock((int)mode_00,10,&DAT_0000000c,(int)"s3_both.c");
      psVar4 = (size_t *)CRYPTO_malloc(num,"s3_both.c",0x2c4);
      if (psVar4 == (size_t *)0x0) {
        ERR_put_error(0x14,0x9c,0x41,"s3_both.c",0x30c);
        return false;
      }
    }
    else {
      sVar5 = mode_00[1];
      mode_00[2] = *psVar4;
      mode_00[1] = sVar5 - 1;
      if (sVar5 - 1 == 0) {
        *mode_00 = 0;
      }
      CRYPTO_lock((int)mode_00,10,&DAT_0000000c,(int)"s3_both.c");
    }
    psVar1 = param_1->s3;
    (psVar1->rbuf).buf = (uchar *)psVar4;
    (psVar1->rbuf).len = num;
  }
  param_1->packet = (uchar *)psVar4;
  iVar3 = ssl3_setup_write_buffer(param_1);
  return iVar3 != 0;
}

