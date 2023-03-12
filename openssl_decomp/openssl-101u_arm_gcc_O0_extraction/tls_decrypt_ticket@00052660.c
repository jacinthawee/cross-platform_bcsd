
void tls_decrypt_ticket(int param_1,uchar *param_2,int param_3,void *param_4,uint param_5,
                       SSL_SESSION **param_6)

{
  int iVar1;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  uchar *out;
  SSL_SESSION *pSVar2;
  int iVar3;
  size_t len;
  uchar *local_1d4;
  int local_1d0;
  size_t local_1cc;
  uchar auStack_1c8 [64];
  EVP_CIPHER_CTX EStack_188;
  HMAC_CTX local_fc;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 0x170);
  local_2c = __stack_chk_guard;
  HMAC_CTX_init(&local_fc);
  EVP_CIPHER_CTX_init(&EStack_188);
  if (*(code **)(iVar3 + 0x138) == (code *)0x0) {
    iVar1 = memcmp(param_2,(void *)(iVar3 + 0x108),0x10);
    if (iVar1 != 0) goto LAB_000526b4;
    md = EVP_sha256();
    iVar1 = HMAC_Init_ex(&local_fc,(void *)(iVar3 + 0x118),0x10,md,(ENGINE *)0x0);
    if (0 < iVar1) {
      cipher = EVP_aes_128_cbc();
      iVar3 = EVP_DecryptInit_ex(&EStack_188,cipher,(ENGINE *)0x0,(uchar *)(iVar3 + 0x128),
                                 param_2 + 0x10);
      if (0 < iVar3) goto LAB_000526ce;
    }
  }
  else {
    iVar3 = (**(code **)(iVar3 + 0x138))(param_1,param_2,param_2 + 0x10,&EStack_188,&local_fc,0);
    if ((iVar3 < 0) || (iVar3 == 0)) goto LAB_000526b4;
    count_leading_zeroes(iVar3 + -2);
LAB_000526ce:
    local_1cc = EVP_MD_size(local_fc.md);
    if (-1 < (int)local_1cc) {
      iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_188);
      if (param_3 <= (int)(iVar3 + 0x10 + local_1cc)) {
        HMAC_CTX_cleanup(&local_fc);
        EVP_CIPHER_CTX_cleanup(&EStack_188);
        goto LAB_000526b4;
      }
      len = param_3 - local_1cc;
      iVar3 = HMAC_Update(&local_fc,param_2,len);
      if ((0 < iVar3) && (iVar3 = HMAC_Final(&local_fc,auStack_1c8,(uint *)0x0), 0 < iVar3)) {
        HMAC_CTX_cleanup(&local_fc);
        iVar3 = CRYPTO_memcmp(auStack_1c8,param_2 + len,local_1cc);
        if (iVar3 == 0) {
          iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_188);
          local_1d4 = param_2 + iVar3 + 0x10;
          iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_188);
          iVar3 = len + (-0x10 - iVar3);
          out = (uchar *)CRYPTO_malloc(iVar3,"t1_lib.c",0x926);
          if ((out == (uchar *)0x0) ||
             (iVar3 = EVP_DecryptUpdate(&EStack_188,out,&local_1d0,local_1d4,iVar3), iVar3 < 1)) {
            EVP_CIPHER_CTX_cleanup(&EStack_188);
            CRYPTO_free(out);
          }
          else {
            iVar3 = EVP_DecryptFinal(&EStack_188,out + local_1d0,(int *)&local_1cc);
            if (iVar3 < 1) {
              EVP_CIPHER_CTX_cleanup(&EStack_188);
              CRYPTO_free(out);
            }
            else {
              local_1d0 = local_1d0 + local_1cc;
              EVP_CIPHER_CTX_cleanup(&EStack_188);
              local_1d4 = out;
              pSVar2 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1d4,local_1d0);
              CRYPTO_free(out);
              if (pSVar2 == (SSL_SESSION *)0x0) {
                ERR_clear_error();
              }
              else {
                if (param_5 == 0) {
                  param_5 = 0;
                }
                else {
                  memcpy(pSVar2->session_id,param_4,param_5);
                }
                pSVar2->session_id_length = param_5;
                *param_6 = pSVar2;
              }
            }
          }
        }
        else {
          EVP_CIPHER_CTX_cleanup(&EStack_188);
        }
        goto LAB_000526b4;
      }
    }
  }
  EVP_CIPHER_CTX_cleanup(&EStack_188);
  HMAC_CTX_cleanup(&local_fc);
LAB_000526b4:
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

