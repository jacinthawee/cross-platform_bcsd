
void ssl3_send_newsession_ticket(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uchar *in;
  SSL_SESSION *in_00;
  int inl;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  uchar uVar3;
  undefined *puVar4;
  uchar *data;
  int iVar5;
  uchar *puVar6;
  uchar *local_1b8;
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
  
  local_2c = __TMC_END__;
  if (*(int *)(param_1 + 0x34) != 0x21f0) {
LAB_0004a0b2:
    uVar1 = ssl3_do_write(param_1,0x16);
    goto LAB_0004a0ba;
  }
  iVar5 = *(int *)(param_1 + 0x170);
  iVar2 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
  if ((iVar2 < 0xff01) && (in = (uchar *)CRYPTO_malloc(iVar2,"s3_srvr.c",0xd31), in != (uchar *)0x0)
     ) {
    local_1b8 = in;
    i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1b8);
    local_1b4 = in;
    in_00 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1b4,iVar2);
    if (in_00 != (SSL_SESSION *)0x0) {
      in_00->session_id_length = 0;
      inl = i2d_SSL_SESSION(in_00,(uchar **)0x0);
      if (inl <= iVar2) {
        local_1b8 = in;
        i2d_SSL_SESSION(in_00,&local_1b8);
        SSL_SESSION_free(in_00);
        iVar2 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),inl + 0x8a);
        if (iVar2 != 0) {
          puVar4 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
          *puVar4 = 4;
          local_1b8 = puVar4 + 4;
          EVP_CIPHER_CTX_init(&EStack_188);
          HMAC_CTX_init(&HStack_fc);
          if (*(code **)(iVar5 + 0x138) == (code *)0x0) {
            RAND_pseudo_bytes(auStack_1a8,0x10);
            cipher = EVP_aes_128_cbc();
            EVP_EncryptInit_ex(&EStack_188,cipher,(ENGINE *)0x0,(uchar *)(iVar5 + 0x128),auStack_1a8
                              );
            md = EVP_sha256();
            HMAC_Init_ex(&HStack_fc,(void *)(iVar5 + 0x118),0x10,md,(ENGINE *)0x0);
            local_198 = *(undefined4 *)(iVar5 + 0x108);
            uStack_194 = *(undefined4 *)(iVar5 + 0x10c);
            uStack_190 = *(undefined4 *)(iVar5 + 0x110);
            uStack_18c = *(undefined4 *)(iVar5 + 0x114);
          }
          else {
            iVar2 = (**(code **)(iVar5 + 0x138))
                              (param_1,&local_198,auStack_1a8,&EStack_188,&HStack_fc,1);
            if (iVar2 < 0) goto LAB_0004a2ec;
          }
          if (*(int *)(param_1 + 0x6c) == 0) {
            uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xab);
          }
          else {
            uVar3 = '\0';
          }
          *local_1b8 = uVar3;
          if (*(int *)(param_1 + 0x6c) == 0) {
            uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xaa);
          }
          else {
            uVar3 = '\0';
          }
          local_1b8[1] = uVar3;
          if (*(int *)(param_1 + 0x6c) == 0) {
            uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa9);
          }
          else {
            uVar3 = '\0';
          }
          local_1b8[2] = uVar3;
          if (*(int *)(param_1 + 0x6c) == 0) {
            uVar3 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa8);
          }
          else {
            uVar3 = '\0';
          }
          local_1b8[3] = uVar3;
          data = local_1b8 + 6;
          *(undefined4 *)(local_1b8 + 6) = local_198;
          *(undefined4 *)(local_1b8 + 10) = uStack_194;
          *(undefined4 *)(local_1b8 + 0xe) = uStack_190;
          *(undefined4 *)(local_1b8 + 0x12) = uStack_18c;
          puVar6 = local_1b8 + 0x16;
          local_1b8 = puVar6;
          __n = EVP_CIPHER_CTX_iv_length(&EStack_188);
          memcpy(puVar6,auStack_1a8,__n);
          puVar6 = local_1b8;
          iVar2 = EVP_CIPHER_CTX_iv_length(&EStack_188);
          local_1b8 = puVar6 + iVar2;
          EVP_EncryptUpdate(&EStack_188,local_1b8,(int *)&local_1b0,in,inl);
          local_1b8 = local_1b8 + (int)local_1b0;
          EVP_EncryptFinal(&EStack_188,local_1b8,(int *)&local_1b0);
          local_1b8 = local_1b8 + (int)local_1b0;
          EVP_CIPHER_CTX_cleanup(&EStack_188);
          HMAC_Update(&HStack_fc,data,(int)local_1b8 - (int)data);
          HMAC_Final(&HStack_fc,local_1b8,&local_1ac);
          HMAC_CTX_cleanup(&HStack_fc);
          iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
          local_1b0 = local_1b8 + (local_1ac - iVar2);
          *(char *)(iVar2 + 1) = (char)((uint)(local_1b0 + -4) >> 0x10);
          *(char *)(iVar2 + 2) = (char)((uint)(local_1b0 + -4) >> 8);
          *(char *)(iVar2 + 3) = (char)local_1b0 + -4;
          local_1b8 = (uchar *)(iVar2 + 10);
          *(char *)(iVar2 + 9) = (char)(local_1b0 + -10);
          *(char *)(iVar2 + 8) = (char)((uint)(local_1b0 + -10) >> 8);
          *(uchar **)(param_1 + 0x44) = local_1b0;
          *(undefined4 *)(param_1 + 0x34) = 0x21f1;
          *(undefined4 *)(param_1 + 0x48) = 0;
          CRYPTO_free(in);
          goto LAB_0004a0b2;
        }
        goto LAB_0004a2f2;
      }
    }
LAB_0004a2ec:
    CRYPTO_free(in);
  }
LAB_0004a2f2:
  uVar1 = 0xffffffff;
LAB_0004a0ba:
  if (local_2c == __TMC_END__) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

