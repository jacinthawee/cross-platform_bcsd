
int __regparm3
tls_decrypt_ticket(int param_1_00,uchar *param_2_00,int param_3_00,void *param_1,size_t param_2,
                  SSL_SESSION **param_3)

{
  int iVar1;
  uchar *out;
  SSL_SESSION *pSVar2;
  int iVar3;
  EVP_MD *md;
  EVP_CIPHER *cipher;
  size_t len;
  int in_GS_OFFSET;
  bool bVar4;
  uchar *local_1c8;
  int local_1c4;
  size_t local_1c0;
  EVP_CIPHER_CTX local_1bc;
  HMAC_CTX local_130;
  uchar local_60 [64];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (0x2f < param_3_00) {
    iVar1 = *(int *)(param_1_00 + 0x170);
    HMAC_CTX_init(&local_130);
    EVP_CIPHER_CTX_init(&local_1bc);
    if (*(code **)(iVar1 + 0x138) == (code *)0x0) {
      iVar3 = memcmp(param_2_00,(void *)(iVar1 + 0x108),0x10);
      if (iVar3 == 0) {
        md = EVP_sha256();
        HMAC_Init_ex(&local_130,(void *)(iVar1 + 0x118),0x10,md,(ENGINE *)0x0);
        cipher = EVP_aes_128_cbc();
        EVP_DecryptInit_ex(&local_1bc,cipher,(ENGINE *)0x0,(uchar *)(iVar1 + 0x128),
                           param_2_00 + 0x10);
        bVar4 = false;
LAB_080adc14:
        local_1c0 = EVP_MD_size(local_130.md);
        if ((int)local_1c0 < 0) {
LAB_080ade06:
          EVP_CIPHER_CTX_cleanup(&local_1bc);
          iVar1 = -1;
          goto LAB_080adb74;
        }
        len = param_3_00 - local_1c0;
        HMAC_Update(&local_130,param_2_00,len);
        HMAC_Final(&local_130,local_60,(uint *)0x0);
        HMAC_CTX_cleanup(&local_130);
        iVar1 = CRYPTO_memcmp(local_60,param_2_00 + len,local_1c0);
        if (iVar1 == 0) {
          iVar1 = EVP_CIPHER_CTX_iv_length(&local_1bc);
          local_1c8 = param_2_00 + iVar1 + 0x10;
          iVar1 = EVP_CIPHER_CTX_iv_length(&local_1bc);
          iVar1 = len - (iVar1 + 0x10);
          out = (uchar *)CRYPTO_malloc(iVar1,"t1_lib.c",0x913);
          if (out == (uchar *)0x0) goto LAB_080ade06;
          EVP_DecryptUpdate(&local_1bc,out,&local_1c4,local_1c8,iVar1);
          iVar1 = EVP_DecryptFinal(&local_1bc,out + local_1c4,(int *)&local_1c0);
          if (0 < iVar1) {
            local_1c4 = local_1c4 + local_1c0;
            EVP_CIPHER_CTX_cleanup(&local_1bc);
            local_1c8 = out;
            pSVar2 = d2i_SSL_SESSION((SSL_SESSION **)0x0,&local_1c8,local_1c4);
            CRYPTO_free(out);
            if (pSVar2 != (SSL_SESSION *)0x0) {
              if (param_2 != 0) {
                memcpy(pSVar2->session_id,param_1,param_2);
              }
              pSVar2->session_id_length = param_2;
              *param_3 = pSVar2;
              iVar1 = 4 - (uint)!bVar4;
              goto LAB_080adb74;
            }
            ERR_clear_error();
          }
        }
      }
    }
    else {
      iVar1 = (**(code **)(iVar1 + 0x138))
                        (param_1_00,param_2_00,param_2_00 + 0x10,&local_1bc,&local_130,0);
      if (iVar1 < 0) {
        iVar1 = -1;
        goto LAB_080adb74;
      }
      if (iVar1 != 0) {
        bVar4 = iVar1 == 2;
        goto LAB_080adc14;
      }
    }
  }
  iVar1 = 2;
LAB_080adb74:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

