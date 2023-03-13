
undefined4 dtls1_send_newsession_ticket(int param_1)

{
  uchar *data;
  undefined4 uVar1;
  int num;
  int iVar2;
  uchar *in;
  int iVar3;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  int in_GS_OFFSET;
  uchar *local_1b8;
  uchar *local_1a8;
  uchar *local_1a4;
  uint local_1a0;
  EVP_CIPHER_CTX local_19c;
  HMAC_CTX local_110;
  uchar local_40 [16];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    iVar3 = *(int *)(param_1 + 0x170);
    num = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    if (num < 0xff01) {
      iVar2 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),num + 0x92);
      if (iVar2 != 0) {
        in = (uchar *)CRYPTO_malloc(num,"d1_srvr.c",0x695);
        if (in != (uchar *)0x0) {
          local_1a8 = in;
          i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1a8);
          local_1a8 = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) + 0xc);
          EVP_CIPHER_CTX_init(&local_19c);
          HMAC_CTX_init(&local_110);
          if (*(code **)(iVar3 + 0x138) == (code *)0x0) {
            iVar2 = RAND_bytes(local_40,0x10);
            if (iVar2 < 1) goto LAB_080b188b;
            cipher = EVP_aes_128_cbc();
            EVP_EncryptInit_ex(&local_19c,cipher,(ENGINE *)0x0,(uchar *)(iVar3 + 0x128),local_40);
            md = EVP_sha256();
            HMAC_Init_ex(&local_110,(void *)(iVar3 + 0x118),0x10,md,(ENGINE *)0x0);
            local_30 = *(undefined4 *)(iVar3 + 0x108);
            local_2c = *(undefined4 *)(iVar3 + 0x10c);
            local_28 = *(undefined4 *)(iVar3 + 0x110);
            local_24 = *(undefined4 *)(iVar3 + 0x114);
          }
          else {
            iVar3 = (**(code **)(iVar3 + 0x138))(param_1,&local_30,local_40,&local_19c,&local_110,1)
            ;
            if (iVar3 < 0) {
LAB_080b188b:
              CRYPTO_free(in);
              goto LAB_080b18a0;
            }
          }
          local_1b8 = local_40;
          *local_1a8 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xef);
          local_1a8[1] = (uchar)*(undefined2 *)(*(int *)(param_1 + 0xc0) + 0xee);
          local_1a8[2] = (uchar)((uint)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec) >> 8);
          local_1a8[3] = (uchar)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xec);
          data = local_1a8 + 6;
          *(undefined4 *)(local_1a8 + 10) = local_2c;
          *(undefined4 *)(local_1a8 + 6) = local_30;
          *(undefined4 *)(local_1a8 + 0xe) = local_28;
          *(undefined4 *)(local_1a8 + 0x12) = local_24;
          local_1a8 = local_1a8 + 0x16;
          __n = EVP_CIPHER_CTX_iv_length(&local_19c);
          memcpy(local_1a8,local_1b8,__n);
          iVar3 = EVP_CIPHER_CTX_iv_length(&local_19c);
          local_1a8 = local_1a8 + iVar3;
          EVP_EncryptUpdate(&local_19c,local_1a8,(int *)&local_1a4,in,num);
          local_1a8 = local_1a8 + (int)local_1a4;
          EVP_EncryptFinal(&local_19c,local_1a8,(int *)&local_1a4);
          local_1a8 = local_1a8 + (int)local_1a4;
          EVP_CIPHER_CTX_cleanup(&local_19c);
          HMAC_Update(&local_110,data,(int)local_1a8 - (int)data);
          HMAC_Final(&local_110,local_1a8,&local_1a0);
          HMAC_CTX_cleanup(&local_110);
          iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
          local_1a4 = local_1a8 + (local_1a0 - iVar3);
          local_1a8 = (uchar *)(iVar3 + 0x12);
          *(char *)(iVar3 + 0x10) = (char)((uint)(local_1a4 + -0x12) >> 8);
          *(char *)(iVar3 + 0x11) = (char)local_1a4 + -0x12;
          *(uchar **)(param_1 + 0x44) = local_1a4;
          *(undefined4 *)(param_1 + 0x34) = 0x21f1;
          *(undefined4 *)(param_1 + 0x48) = 0;
          CRYPTO_free(in);
          iVar3 = *(int *)(param_1 + 0x44) + -0xc;
          dtls1_set_message_header
                    (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3c) + 4),4,iVar3,0,iVar3);
          dtls1_buffer_message(param_1,0);
          goto LAB_080b15b9;
        }
      }
    }
LAB_080b18a0:
    uVar1 = 0xffffffff;
  }
  else {
LAB_080b15b9:
    uVar1 = dtls1_do_write(param_1,0x16);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

