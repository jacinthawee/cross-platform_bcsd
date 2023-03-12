
undefined4 ssl3_setup_write_buffer(SSL *param_1)

{
  int iVar1;
  uchar *puVar2;
  size_t *psVar3;
  size_t *psVar4;
  ssl3_state_st *psVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  _func_3154 *p_Var9;
  code *pcVar10;
  
  iVar1 = SSL_version(param_1);
  if ((iVar1 == 0xfeff) || (iVar1 = SSL_version(param_1), iVar1 == 0x100)) {
    iVar1 = 0x61;
    puVar2 = (param_1->s3->wbuf).buf;
    iVar6 = 0xe;
  }
  else {
    iVar1 = 0x58;
    puVar2 = (param_1->s3->wbuf).buf;
    iVar6 = 5;
  }
  if (puVar2 != (uchar *)0x0) {
    return 1;
  }
  iVar6 = iVar6 + param_1->client_version;
  if (param_1->references << 0xe < 0) {
    sVar8 = iVar6 + 0x53;
  }
  else {
    sVar8 = iVar6 + 0x453;
  }
  p_Var9 = param_1->psk_server_callback;
  if ((param_1->references & 0x800U) == 0) {
    sVar8 = sVar8 + iVar1;
  }
  (*(code *)PTR_CRYPTO_lock_006a926c)(9,0xc,"s3_both.c",0x2b7);
  pcVar10 = (code *)PTR_CRYPTO_lock_006a926c;
  psVar4 = *(size_t **)(p_Var9 + 0x15c);
  if (((psVar4 == (size_t *)0x0) || (sVar8 != *psVar4)) ||
     (psVar3 = (size_t *)psVar4[2], psVar3 == (size_t *)0x0)) {
    (*(code *)PTR_CRYPTO_lock_006a926c)(10,0xc,"s3_both.c",0x2c2);
    psVar3 = (size_t *)(*(code *)PTR_CRYPTO_malloc_006a8108)(sVar8,"s3_both.c",0x2c4);
    if (psVar3 == (size_t *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x123,0x41,"s3_both.c",0x334);
      return 0;
    }
  }
  else {
    sVar7 = psVar4[1];
    psVar4[2] = *psVar3;
    psVar4[1] = sVar7 - 1;
    if (sVar7 - 1 == 0) {
      *psVar4 = 0;
      pcVar10 = (code *)PTR_CRYPTO_lock_006a926c;
    }
    (*pcVar10)(10,0xc,"s3_both.c",0x2c2);
  }
  psVar5 = param_1->s3;
  (psVar5->wbuf).buf = (uchar *)psVar3;
  (psVar5->wbuf).len = sVar8;
  return 1;
}

