
void ssl3_send_newsession_ticket(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uchar *in;
  int iVar3;
  SSL_SESSION *in_00;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  uchar uVar4;
  undefined *puVar5;
  uchar *puVar6;
  uint uVar7;
  int iVar8;
  uchar *data;
  uchar *local_1b0;
  uchar *local_1ac;
  uchar *local_1a8;
  uint local_1a4;
  uchar auStack_1a0 [16];
  undefined4 local_190;
  undefined4 uStack_18c;
  undefined4 uStack_188;
  undefined4 uStack_184;
  EVP_CIPHER_CTX EStack_180;
  HMAC_CTX HStack_f4;
  int local_24;
  
  local_24 = __stack_chk_guard;
  if (*(int *)(param_1 + 0x34) == 0x21f0) {
    iVar8 = *(int *)(param_1 + 0x170);
    iVar2 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
    uVar7 = count_leading_zeroes(iVar2);
    uVar7 = uVar7 >> 5;
    if (0xff00 < iVar2) {
      uVar7 = uVar7 | 1;
    }
    if ((uVar7 == 0) && (in = (uchar *)CRYPTO_malloc(iVar2,"s3_srvr.c",0xd4c), in != (uchar *)0x0))
    {
      EVP_CIPHER_CTX_init(&EStack_180);
      HMAC_CTX_init(&HStack_f4);
      local_1b0 = in;
      iVar3 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1b0);
      if ((iVar3 != 0) &&
         (local_1ac = in, in_00 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1ac,iVar2),
         in_00 != (SSL_SESSION *)0x0)) {
        in_00->session_id_length = 0;
        iVar3 = i2d_SSL_SESSION(in_00,(uchar **)0x0);
        uVar7 = count_leading_zeroes(iVar3);
        uVar7 = uVar7 >> 5;
        if (iVar2 < iVar3) {
          uVar7 = uVar7 | 1;
        }
        if ((uVar7 == 0) && (local_1b0 = in, iVar2 = i2d_SSL_SESSION(in_00,&local_1b0), iVar2 != 0))
        {
          SSL_SESSION_free(in_00);
          iVar2 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),iVar3 + 0x8a);
          if (iVar2 != 0) {
            puVar5 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
            *puVar5 = 4;
            local_1b0 = puVar5 + 4;
            if (*(code **)(iVar8 + 0x138) == (code *)0x0) {
              iVar2 = RAND_bytes(auStack_1a0,0x10);
              if (0 < iVar2) {
                cipher = EVP_aes_128_cbc();
                iVar2 = EVP_EncryptInit_ex(&EStack_180,cipher,(ENGINE *)0x0,(uchar *)(iVar8 + 0x128)
                                           ,auStack_1a0);
                if (iVar2 != 0) {
                  md = EVP_sha256();
                  iVar2 = HMAC_Init_ex(&HStack_f4,(void *)(iVar8 + 0x118),0x10,md,(ENGINE *)0x0);
                  if (iVar2 != 0) {
                    local_190 = *(undefined4 *)(iVar8 + 0x108);
                    uStack_18c = *(undefined4 *)(iVar8 + 0x10c);
                    uStack_188 = *(undefined4 *)(iVar8 + 0x110);
                    uStack_184 = *(undefined4 *)(iVar8 + 0x114);
                    goto LAB_00046df6;
                  }
                }
              }
            }
            else {
              iVar2 = (**(code **)(iVar8 + 0x138))
                                (param_1,&local_190,auStack_1a0,&EStack_180,&HStack_f4,1);
              if (-1 < iVar2) {
LAB_00046df6:
                if (*(int *)(param_1 + 0x6c) == 0) {
                  uVar4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xab);
                }
                else {
                  uVar4 = '\0';
                }
                *local_1b0 = uVar4;
                if (*(int *)(param_1 + 0x6c) == 0) {
                  uVar4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xaa);
                }
                else {
                  uVar4 = '\0';
                }
                local_1b0[1] = uVar4;
                if (*(int *)(param_1 + 0x6c) == 0) {
                  uVar4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa9);
                }
                else {
                  uVar4 = '\0';
                }
                local_1b0[2] = uVar4;
                if (*(int *)(param_1 + 0x6c) == 0) {
                  uVar4 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa8);
                }
                else {
                  uVar4 = '\0';
                }
                local_1b0[3] = uVar4;
                data = local_1b0 + 6;
                *(undefined4 *)(local_1b0 + 6) = local_190;
                *(undefined4 *)(local_1b0 + 0x12) = uStack_184;
                *(undefined4 *)(local_1b0 + 10) = uStack_18c;
                puVar6 = local_1b0 + 0x16;
                *(undefined4 *)(local_1b0 + 0xe) = uStack_188;
                local_1b0 = puVar6;
                __n = EVP_CIPHER_CTX_iv_length(&EStack_180);
                memcpy(puVar6,auStack_1a0,__n);
                puVar6 = local_1b0;
                iVar2 = EVP_CIPHER_CTX_iv_length(&EStack_180);
                local_1b0 = puVar6 + iVar2;
                iVar2 = EVP_EncryptUpdate(&EStack_180,local_1b0,(int *)&local_1a8,in,iVar3);
                if (iVar2 != 0) {
                  local_1b0 = local_1b0 + (int)local_1a8;
                  iVar2 = EVP_EncryptFinal(&EStack_180,local_1b0,(int *)&local_1a8);
                  if (iVar2 != 0) {
                    local_1b0 = local_1b0 + (int)local_1a8;
                    iVar2 = HMAC_Update(&HStack_f4,data,(int)local_1b0 - (int)data);
                    if ((iVar2 != 0) &&
                       (iVar2 = HMAC_Final(&HStack_f4,local_1b0,&local_1a4), iVar2 != 0)) {
                      EVP_CIPHER_CTX_cleanup(&EStack_180);
                      HMAC_CTX_cleanup(&HStack_f4);
                      iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
                      local_1a8 = local_1b0 + (local_1a4 - iVar2);
                      *(char *)(iVar2 + 1) = (char)((uint)(local_1a8 + -4) >> 0x10);
                      *(char *)(iVar2 + 2) = (char)((uint)(local_1a8 + -4) >> 8);
                      *(char *)(iVar2 + 3) = (char)local_1a8 + -4;
                      local_1b0 = (uchar *)(iVar2 + 10);
                      *(char *)(iVar2 + 9) = (char)(local_1a8 + -10);
                      *(char *)(iVar2 + 8) = (char)((uint)(local_1a8 + -10) >> 8);
                      *(uchar **)(param_1 + 0x44) = local_1a8;
                      *(undefined4 *)(param_1 + 0x34) = 0x21f1;
                      *(undefined4 *)(param_1 + 0x48) = 0;
                      CRYPTO_free(in);
                      goto LAB_00046ce6;
                    }
                  }
                }
              }
            }
          }
        }
        else {
          SSL_SESSION_free(in_00);
        }
      }
      CRYPTO_free(in);
      EVP_CIPHER_CTX_cleanup(&EStack_180);
      HMAC_CTX_cleanup(&HStack_f4);
    }
    uVar1 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x34) = 5;
  }
  else {
LAB_00046ce6:
    uVar1 = ssl3_do_write(param_1,0x16);
  }
  if (local_24 == __stack_chk_guard) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar1);
}

