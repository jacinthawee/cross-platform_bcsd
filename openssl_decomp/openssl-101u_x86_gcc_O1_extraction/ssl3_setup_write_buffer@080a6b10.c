
undefined4 ssl3_setup_write_buffer(SSL *param_1)

{
  size_t sVar1;
  _func_3154 *p_Var2;
  size_t *psVar3;
  size_t mode;
  ssl3_state_st *psVar4;
  int iVar5;
  uint mode_00;
  size_t *psVar6;
  int iVar7;
  int iVar8;
  size_t num;
  
  iVar5 = SSL_version(param_1);
  if (iVar5 != 0xfeff) {
    iVar5 = SSL_version(param_1);
    iVar7 = 0x58;
    iVar8 = 5;
    if (iVar5 != 0x100) goto LAB_080a6b47;
  }
  iVar7 = 0x61;
  iVar8 = 0xe;
LAB_080a6b47:
  if ((param_1->s3->wbuf).buf != (uchar *)0x0) {
    return 1;
  }
  iVar8 = iVar8 + param_1->client_version;
  mode_00 = param_1->references;
  p_Var2 = param_1->psk_server_callback;
  num = iVar8 + 0x53;
  if ((mode_00 & 0x20000) == 0) {
    num = iVar8 + 0x453;
  }
  if ((mode_00 & 0x800) == 0) {
    num = iVar7 + num;
  }
  CRYPTO_lock(mode_00,9,&DAT_0000000c,(int)"s3_both.c");
  psVar3 = *(size_t **)(p_Var2 + 0x15c);
  if (((psVar3 == (size_t *)0x0) || (num != *psVar3)) ||
     (psVar6 = (size_t *)psVar3[2], psVar6 == (size_t *)0x0)) {
    CRYPTO_lock(mode_00,10,&DAT_0000000c,(int)"s3_both.c");
    psVar6 = (size_t *)CRYPTO_malloc(num,"s3_both.c",0x2b6);
    if (psVar6 == (size_t *)0x0) {
      ERR_put_error(0x14,0x123,0x41,"s3_both.c",0x31d);
      return 0;
    }
  }
  else {
    psVar3[2] = *psVar6;
    mode = psVar3[1];
    sVar1 = mode - 1;
    psVar3[1] = sVar1;
    if (sVar1 == 0) {
      *psVar3 = 0;
    }
    CRYPTO_lock(mode,10,&DAT_0000000c,(int)"s3_both.c");
  }
  psVar4 = param_1->s3;
  (psVar4->wbuf).buf = (uchar *)psVar6;
  (psVar4->wbuf).len = num;
  return 1;
}

