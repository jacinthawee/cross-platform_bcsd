
void tls_decrypt_ticket(int param_1,uchar *param_2,int param_3,void *param_4,size_t param_5,
                       SSL_SESSION **param_6)

{
  uchar *out;
  SSL_SESSION *pSVar1;
  int iVar2;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  size_t len;
  int iVar3;
  uchar *local_1d4;
  int local_1d0;
  size_t local_1cc;
  uchar auStack_1c8 [64];
  EVP_CIPHER_CTX EStack_188;
  HMAC_CTX local_fc;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 0x170);
  local_2c = __TMC_END__;
  if (param_3 < 0x30) goto LAB_00055126;
  HMAC_CTX_init(&local_fc);
  EVP_CIPHER_CTX_init(&EStack_188);
  if (*(code **)(iVar3 + 0x138) == (code *)0x0) {
    iVar2 = memcmp(param_2,(void *)(iVar3 + 0x108),0x10);
    if (iVar2 != 0) goto LAB_00055126;
    md = EVP_sha256();
    HMAC_Init_ex(&local_fc,(void *)(iVar3 + 0x118),0x10,md,(ENGINE *)0x0);
    cipher = EVP_aes_128_cbc();
    EVP_DecryptInit_ex(&EStack_188,cipher,(ENGINE *)0x0,(uchar *)(iVar3 + 0x128),param_2 + 0x10);
  }
  else {
    iVar3 = (**(code **)(iVar3 + 0x138))(param_1,param_2,param_2 + 0x10,&EStack_188,&local_fc,0);
    if ((iVar3 < 0) || (iVar3 == 0)) goto LAB_00055126;
    count_leading_zeroes(iVar3 + -2);
  }
  local_1cc = EVP_MD_size(local_fc.md);
  if (-1 < (int)local_1cc) {
    len = param_3 - local_1cc;
    HMAC_Update(&local_fc,param_2,len);
    HMAC_Final(&local_fc,auStack_1c8,(uint *)0x0);
    HMAC_CTX_cleanup(&local_fc);
    iVar3 = CRYPTO_memcmp(auStack_1c8,param_2 + len,local_1cc);
    if (iVar3 != 0) goto LAB_00055126;
    iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_188);
    local_1d4 = param_2 + iVar3 + 0x10;
    iVar3 = EVP_CIPHER_CTX_iv_length(&EStack_188);
    iVar3 = (-0x10 - iVar3) + len;
    out = (uchar *)CRYPTO_malloc(iVar3,"t1_lib.c",0x913);
    if (out != (uchar *)0x0) {
      EVP_DecryptUpdate(&EStack_188,out,&local_1d0,local_1d4,iVar3);
      iVar3 = EVP_DecryptFinal(&EStack_188,out + local_1d0,(int *)&local_1cc);
      if (0 < iVar3) {
        local_1d0 = local_1d0 + local_1cc;
        EVP_CIPHER_CTX_cleanup(&EStack_188);
        local_1d4 = out;
        pSVar1 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1d4,local_1d0);
        CRYPTO_free(out);
        if (pSVar1 == (SSL_SESSION *)0x0) {
          ERR_clear_error();
        }
        else {
          if (param_5 != 0) {
            memcpy(pSVar1->session_id,param_4,param_5);
          }
          pSVar1->session_id_length = param_5;
          *param_6 = pSVar1;
        }
      }
      goto LAB_00055126;
    }
  }
  EVP_CIPHER_CTX_cleanup(&EStack_188);
LAB_00055126:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

