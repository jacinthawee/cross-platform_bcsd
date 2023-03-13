
int __regparm3
tls_decrypt_ticket(int param_1_00,uchar *param_2_00,int param_3_00,void *param_1,size_t param_2,
                  SSL_SESSION **param_3)

{
  int iVar1;
  int iVar2;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  uchar *out;
  SSL_SESSION *pSVar3;
  size_t len;
  uint uVar4;
  int in_GS_OFFSET;
  bool bVar5;
  uchar *local_1c8;
  int local_1c4;
  size_t local_1c0;
  EVP_CIPHER_CTX local_1bc;
  HMAC_CTX local_130;
  uchar local_60 [64];
  int local_20;
  
  iVar1 = *(int *)(param_1_00 + 0x170);
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  HMAC_CTX_init(&local_130);
  EVP_CIPHER_CTX_init(&local_1bc);
  if (*(code **)(iVar1 + 0x138) == (code *)0x0) {
    iVar2 = memcmp(param_2_00,(void *)(iVar1 + 0x108),0x10);
    if (iVar2 == 0) {
      md = EVP_sha256();
      iVar2 = HMAC_Init_ex(&local_130,(void *)(iVar1 + 0x118),0x10,md,(ENGINE *)0x0);
      if (0 < iVar2) {
        cipher = EVP_aes_128_cbc();
        iVar1 = EVP_DecryptInit_ex(&local_1bc,cipher,(ENGINE *)0x0,(uchar *)(iVar1 + 0x128),
                                   param_2_00 + 0x10);
        if (0 < iVar1) {
          bVar5 = false;
          goto LAB_080aa3cc;
        }
      }
LAB_080aa520:
      EVP_CIPHER_CTX_cleanup(&local_1bc);
      HMAC_CTX_cleanup(&local_130);
      iVar1 = -1;
      goto LAB_080aa39e;
    }
  }
  else {
    iVar1 = (**(code **)(iVar1 + 0x138))
                      (param_1_00,param_2_00,param_2_00 + 0x10,&local_1bc,&local_130,0);
    if (iVar1 < 0) {
      iVar1 = -1;
      goto LAB_080aa39e;
    }
    if (iVar1 != 0) {
      bVar5 = iVar1 == 2;
LAB_080aa3cc:
      local_1c0 = EVP_MD_size(local_130.md);
      if (-1 < (int)local_1c0) {
        iVar1 = EVP_CIPHER_CTX_iv_length(&local_1bc);
        if (param_3_00 <= (int)(iVar1 + 0x10 + local_1c0)) {
          HMAC_CTX_cleanup(&local_130);
          EVP_CIPHER_CTX_cleanup(&local_1bc);
          iVar1 = 2;
          goto LAB_080aa39e;
        }
        len = param_3_00 - local_1c0;
        iVar1 = HMAC_Update(&local_130,param_2_00,len);
        if (0 < iVar1) {
          iVar1 = HMAC_Final(&local_130,local_60,(uint *)0x0);
          if (0 < iVar1) {
            HMAC_CTX_cleanup(&local_130);
            iVar1 = CRYPTO_memcmp(local_60,param_2_00 + len,local_1c0);
            if (iVar1 != 0) {
              EVP_CIPHER_CTX_cleanup(&local_1bc);
              iVar1 = 2;
              goto LAB_080aa39e;
            }
            iVar1 = EVP_CIPHER_CTX_iv_length(&local_1bc);
            local_1c8 = param_2_00 + iVar1 + 0x10;
            iVar1 = EVP_CIPHER_CTX_iv_length(&local_1bc);
            iVar1 = len - (iVar1 + 0x10);
            out = (uchar *)CRYPTO_malloc(iVar1,"t1_lib.c",0x926);
            if (out != (uchar *)0x0) {
              iVar1 = EVP_DecryptUpdate(&local_1bc,out,&local_1c4,local_1c8,iVar1);
              if (0 < iVar1) {
                iVar1 = EVP_DecryptFinal(&local_1bc,out + local_1c4,(int *)&local_1c0);
                if (iVar1 < 1) {
                  EVP_CIPHER_CTX_cleanup(&local_1bc);
                  CRYPTO_free(out);
                  iVar1 = 2;
                  goto LAB_080aa39e;
                }
                local_1c4 = local_1c4 + local_1c0;
                EVP_CIPHER_CTX_cleanup(&local_1bc);
                local_1c8 = out;
                pSVar3 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1c8,local_1c4);
                CRYPTO_free(out);
                if (pSVar3 != (SSL_SESSION *)0x0) {
                  uVar4 = 0;
                  if (param_2 != 0) {
                    memcpy(pSVar3->session_id,param_1,param_2);
                    uVar4 = param_2;
                  }
                  pSVar3->session_id_length = uVar4;
                  *param_3 = pSVar3;
                  iVar1 = 4 - (uint)!bVar5;
                  goto LAB_080aa39e;
                }
                ERR_clear_error();
                goto LAB_080aa399;
              }
            }
            EVP_CIPHER_CTX_cleanup(&local_1bc);
            CRYPTO_free(out);
            iVar1 = -1;
            goto LAB_080aa39e;
          }
        }
      }
      goto LAB_080aa520;
    }
  }
LAB_080aa399:
  iVar1 = 2;
LAB_080aa39e:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

