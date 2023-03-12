
void dtls1_send_newsession_ticket(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uchar *in;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  uchar *data;
  int iVar4;
  uchar *puVar5;
  uchar *local_1b4;
  uchar *local_1b0;
  uint local_1ac;
  uchar auStack_1a8 [16];
  undefined4 local_198;
  undefined4 uStack_194;
  undefined4 uStack_190;
  undefined4 uStack_18c;
  EVP_CIPHER_CTX EStack_188;
  HMAC_CTX HStack_fc;
  int local_2c;
  
  local_2c = __stack_chk_guard;
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    iVar4 = *(int *)(param_1 + 0x170);
    iVar2 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    if (((0xff00 < iVar2) ||
        (iVar3 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),iVar2 + 0x92), iVar3 == 0)) ||
       (in = (uchar *)CRYPTO_malloc(iVar2,"d1_srvr.c",0x695), in == (uchar *)0x0)) {
LAB_0005712e:
      uVar1 = 0xffffffff;
      goto LAB_00056f66;
    }
    local_1b4 = in;
    i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1b4);
    local_1b4 = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) + 0xc);
    EVP_CIPHER_CTX_init(&EStack_188);
    HMAC_CTX_init(&HStack_fc);
    if (*(code **)(iVar4 + 0x138) == (code *)0x0) {
      iVar3 = RAND_bytes(auStack_1a8,0x10);
      if (iVar3 < 1) goto LAB_00057128;
      cipher = EVP_aes_128_cbc();
      EVP_EncryptInit_ex(&EStack_188,cipher,(ENGINE *)0x0,(uchar *)(iVar4 + 0x128),auStack_1a8);
      md = EVP_sha256();
      HMAC_Init_ex(&HStack_fc,(void *)(iVar4 + 0x118),0x10,md,(ENGINE *)0x0);
      local_198 = *(undefined4 *)(iVar4 + 0x108);
      uStack_194 = *(undefined4 *)(iVar4 + 0x10c);
      uStack_190 = *(undefined4 *)(iVar4 + 0x110);
      uStack_18c = *(undefined4 *)(iVar4 + 0x114);
    }
    else {
      iVar4 = (**(code **)(iVar4 + 0x138))(param_1,&local_198,auStack_1a8,&EStack_188,&HStack_fc,1);
      if (iVar4 < 0) {
LAB_00057128:
        CRYPTO_free(in);
        goto LAB_0005712e;
      }
    }
    *local_1b4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xef);
    local_1b4[1] = (uchar)*(undefined2 *)(*(int *)(param_1 + 0xc0) + 0xee);
    local_1b4[2] = (uchar)((uint)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec) >> 8);
    local_1b4[3] = (uchar)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec);
    data = local_1b4 + 6;
    *(undefined4 *)(local_1b4 + 6) = local_198;
    *(undefined4 *)(local_1b4 + 0xe) = uStack_190;
    *(undefined4 *)(local_1b4 + 10) = uStack_194;
    *(undefined4 *)(local_1b4 + 0x12) = uStack_18c;
    puVar5 = local_1b4 + 0x16;
    local_1b4 = puVar5;
    __n = EVP_CIPHER_CTX_iv_length(&EStack_188);
    memcpy(puVar5,auStack_1a8,__n);
    puVar5 = local_1b4;
    iVar4 = EVP_CIPHER_CTX_iv_length(&EStack_188);
    local_1b4 = puVar5 + iVar4;
    EVP_EncryptUpdate(&EStack_188,local_1b4,(int *)&local_1b0,in,iVar2);
    local_1b4 = local_1b4 + (int)local_1b0;
    EVP_EncryptFinal(&EStack_188,local_1b4,(int *)&local_1b0);
    local_1b4 = local_1b4 + (int)local_1b0;
    EVP_CIPHER_CTX_cleanup(&EStack_188);
    HMAC_Update(&HStack_fc,data,(int)local_1b4 - (int)data);
    HMAC_Final(&HStack_fc,local_1b4,&local_1ac);
    HMAC_CTX_cleanup(&HStack_fc);
    iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    local_1b0 = local_1b4 + (local_1ac - iVar2);
    local_1b4 = (uchar *)(iVar2 + 0x12);
    *(char *)(iVar2 + 0x11) = (char)(local_1b0 + -0x12);
    *(char *)(iVar2 + 0x10) = (char)((uint)(local_1b0 + -0x12) >> 8);
    *(uchar **)(param_1 + 0x44) = local_1b0;
    *(undefined4 *)(param_1 + 0x34) = 0x21f1;
    *(undefined4 *)(param_1 + 0x48) = 0;
    CRYPTO_free(in);
    iVar2 = *(int *)(param_1 + 0x44) + -0xc;
    dtls1_set_message_header(param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),4,iVar2,0,iVar2);
    dtls1_buffer_message(param_1,0);
  }
  uVar1 = dtls1_do_write(param_1,0x16);
LAB_00056f66:
  if (local_2c == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

