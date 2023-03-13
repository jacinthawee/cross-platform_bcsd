
/* WARNING: Could not reconcile some variable overlaps */

undefined4 ssl3_send_newsession_ticket(int param_1)

{
  uchar *data;
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  uchar *in;
  int iVar4;
  SSL_SESSION *in_00;
  int iVar5;
  size_t __n;
  EVP_CIPHER *cipher;
  EVP_MD *md;
  uchar uVar6;
  int in_GS_OFFSET;
  uchar *local_1ac;
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
  if (*(int *)(param_1 + 0x34) != 0x21f0) {
LAB_08098869:
    uVar2 = ssl3_do_write(param_1,0x16);
    goto LAB_08098877;
  }
  iVar5 = *(int *)(param_1 + 0x170);
  iVar3 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),(uchar **)0x0);
  if ((iVar3 != 0) && (iVar3 < 0xff01)) {
    in = (uchar *)CRYPTO_malloc(iVar3,"s3_srvr.c",0xd4c);
    if (in != (uchar *)0x0) {
      EVP_CIPHER_CTX_init(&local_19c);
      HMAC_CTX_init(&local_110);
      local_1ac = in;
      iVar4 = i2d_SSL_SESSION(*(SSL_SESSION **)(param_1 + 0xc0),&local_1ac);
      if (iVar4 != 0) {
        local_1a8 = in;
        in_00 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1a8,iVar3);
        if (in_00 != (SSL_SESSION *)0x0) {
          in_00->session_id_length = 0;
          iVar4 = i2d_SSL_SESSION(in_00,(uchar **)0x0);
          if ((iVar4 != 0) && (iVar4 <= iVar3)) {
            local_1ac = in;
            iVar3 = i2d_SSL_SESSION(in_00,&local_1ac);
            if (iVar3 != 0) {
              SSL_SESSION_free(in_00);
              iVar3 = BUF_MEM_grow(*(BUF_MEM **)(param_1 + 0x3c),iVar4 + 0x8a);
              if (iVar3 != 0) {
                puVar1 = *(undefined **)(*(int *)(param_1 + 0x3c) + 4);
                *puVar1 = 4;
                local_1ac = puVar1 + 4;
                if (*(code **)(iVar5 + 0x138) == (code *)0x0) {
                  iVar3 = RAND_bytes(local_40,0x10);
                  if (0 < iVar3) {
                    cipher = EVP_aes_128_cbc();
                    iVar3 = EVP_EncryptInit_ex(&local_19c,cipher,(ENGINE *)0x0,
                                               (uchar *)(iVar5 + 0x128),local_40);
                    if (iVar3 != 0) {
                      md = EVP_sha256();
                      iVar3 = HMAC_Init_ex(&local_110,(void *)(iVar5 + 0x118),0x10,md,(ENGINE *)0x0)
                      ;
                      if (iVar3 != 0) {
                        local_30 = *(undefined4 *)(iVar5 + 0x108);
                        local_2c = *(undefined4 *)(iVar5 + 0x10c);
                        local_28 = *(undefined4 *)(iVar5 + 0x110);
                        local_24 = *(undefined4 *)(iVar5 + 0x114);
                        goto LAB_08098a17;
                      }
                    }
                  }
                }
                else {
                  iVar5 = (**(code **)(iVar5 + 0x138))
                                    (param_1,&local_30,local_40,&local_19c,&local_110,1);
                  if (-1 < iVar5) {
LAB_08098a17:
                    uVar6 = '\0';
                    if (*(int *)(param_1 + 0x6c) == 0) {
                      uVar6 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xab);
                    }
                    *local_1ac = uVar6;
                    uVar6 = '\0';
                    if (*(int *)(param_1 + 0x6c) == 0) {
                      uVar6 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xaa);
                    }
                    local_1ac[1] = uVar6;
                    uVar6 = '\0';
                    if (*(int *)(param_1 + 0x6c) == 0) {
                      uVar6 = (uchar)((uint)*(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xa8) >> 8);
                    }
                    local_1ac[2] = uVar6;
                    uVar6 = '\0';
                    if (*(int *)(param_1 + 0x6c) == 0) {
                      uVar6 = *(uchar *)(*(int *)(param_1 + 0xc0) + 0xa8);
                    }
                    local_1ac[3] = uVar6;
                    data = local_1ac + 6;
                    *(undefined4 *)(local_1ac + 10) = local_2c;
                    *(undefined4 *)(local_1ac + 6) = local_30;
                    *(undefined4 *)(local_1ac + 0xe) = local_28;
                    *(undefined4 *)(local_1ac + 0x12) = local_24;
                    local_1ac = local_1ac + 0x16;
                    __n = EVP_CIPHER_CTX_iv_length(&local_19c);
                    memcpy(local_1ac,local_40,__n);
                    iVar5 = EVP_CIPHER_CTX_iv_length(&local_19c);
                    local_1ac = local_1ac + iVar5;
                    iVar5 = EVP_EncryptUpdate(&local_19c,local_1ac,(int *)&local_1a4,in,iVar4);
                    if (iVar5 != 0) {
                      local_1ac = local_1ac + (int)local_1a4;
                      iVar5 = EVP_EncryptFinal(&local_19c,local_1ac,(int *)&local_1a4);
                      if (iVar5 != 0) {
                        local_1ac = local_1ac + (int)local_1a4;
                        iVar5 = HMAC_Update(&local_110,data,(int)local_1ac - (int)data);
                        if (iVar5 != 0) {
                          iVar5 = HMAC_Final(&local_110,local_1ac,&local_1a0);
                          if (iVar5 != 0) {
                            EVP_CIPHER_CTX_cleanup(&local_19c);
                            HMAC_CTX_cleanup(&local_110);
                            iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
                            local_1a4 = local_1ac + (local_1a0 - iVar5);
                            *(char *)(iVar5 + 1) = (char)((uint)(local_1a4 + -4) >> 0x10);
                            *(char *)(iVar5 + 2) = (char)((uint)(local_1a4 + -4) >> 8);
                            *(char *)(iVar5 + 3) = (char)local_1a4 + -4;
                            local_1ac = (uchar *)(iVar5 + 10);
                            *(char *)(iVar5 + 8) = (char)((uint)(local_1a4 + -10) >> 8);
                            *(char *)(iVar5 + 9) = (char)local_1a4 + -10;
                            *(uchar **)(param_1 + 0x44) = local_1a4;
                            *(undefined4 *)(param_1 + 0x34) = 0x21f1;
                            *(undefined4 *)(param_1 + 0x48) = 0;
                            CRYPTO_free(in);
                            goto LAB_08098869;
                          }
                        }
                      }
                    }
                  }
                }
              }
              goto LAB_08098c68;
            }
          }
          SSL_SESSION_free(in_00);
        }
      }
LAB_08098c68:
      CRYPTO_free(in);
      EVP_CIPHER_CTX_cleanup(&local_19c);
      HMAC_CTX_cleanup(&local_110);
      *(undefined4 *)(param_1 + 0x34) = 5;
      uVar2 = 0xffffffff;
      goto LAB_08098877;
    }
  }
  *(undefined4 *)(param_1 + 0x34) = 5;
  uVar2 = 0xffffffff;
LAB_08098877:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

