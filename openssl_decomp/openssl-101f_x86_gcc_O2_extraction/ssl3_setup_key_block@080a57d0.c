
int ssl3_setup_key_block(int param_1)

{
  size_t num;
  int iVar1;
  int iVar2;
  int iVar3;
  EVP_MD *pEVar4;
  char cVar5;
  size_t cnt;
  int in_GS_OFFSET;
  uchar *local_a8;
  size_t local_a4;
  int local_a0;
  uchar *local_9c;
  EVP_CIPHER *local_80;
  EVP_MD *local_7c;
  undefined4 local_78;
  EVP_MD_CTX local_74;
  EVP_MD_CTX local_5c;
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  char local_40;
  char local_3f;
  char local_3e;
  char local_3d;
  char local_3c;
  char local_3b;
  char local_3a;
  char local_39;
  char local_38;
  char local_37;
  char local_36;
  char local_35;
  uchar local_34 [20];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_a0 = *(int *)(*(int *)(param_1 + 0x58) + 0x374);
  if (local_a0 == 0) {
    iVar1 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_80,&local_7c,0,0,&local_78);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x9d,0x8a,"s3_enc.c",0x192);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x58);
      *(EVP_CIPHER **)(iVar1 + 0x37c) = local_80;
      *(undefined4 *)(iVar1 + 0x38c) = local_78;
      *(EVP_MD **)(iVar1 + 0x380) = local_7c;
      iVar1 = EVP_MD_size(local_7c);
      if (-1 < iVar1) {
        iVar2 = EVP_CIPHER_key_length(local_80);
        iVar3 = EVP_CIPHER_iv_length(local_80);
        num = (iVar3 + iVar1 + iVar2) * 2;
        iVar1 = *(int *)(param_1 + 0x58);
        if (*(void **)(iVar1 + 0x378) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar1 + 0x378),*(size_t *)(iVar1 + 0x374));
          CRYPTO_free(*(void **)(*(int *)(param_1 + 0x58) + 0x378));
          iVar1 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar1 + 0x378) = 0;
        }
        *(undefined4 *)(iVar1 + 0x374) = 0;
        local_9c = (uchar *)CRYPTO_malloc(num,"s3_enc.c",0x1a7);
        if (local_9c == (uchar *)0x0) {
          ERR_put_error(0x14,0x9d,0x41,"s3_enc.c",0x1c5);
        }
        else {
          iVar1 = *(int *)(param_1 + 0x58);
          *(uchar **)(iVar1 + 0x378) = local_9c;
          *(size_t *)(iVar1 + 0x374) = num;
          EVP_MD_CTX_init(&local_74);
          EVP_MD_CTX_set_flags(&local_74,8);
          EVP_MD_CTX_init(&local_5c);
          if ((int)num < 1) {
LAB_080a5bf8:
            local_a8 = local_34;
            OPENSSL_cleanse(local_a8,0x14);
            EVP_MD_CTX_cleanup(&local_74);
            EVP_MD_CTX_cleanup(&local_5c);
            local_a0 = 1;
          }
          else {
            local_44 = 'A';
            cnt = 1;
            local_a4 = num;
            while( true ) {
              cVar5 = (char)cnt + 'A';
              pEVar4 = EVP_sha1();
              EVP_DigestInit_ex(&local_5c,pEVar4,(ENGINE *)0x0);
              EVP_DigestUpdate(&local_5c,&local_44,cnt);
              EVP_DigestUpdate(&local_5c,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&local_5c,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
              EVP_DigestUpdate(&local_5c,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
              EVP_DigestFinal_ex(&local_5c,local_34,(uint *)0x0);
              pEVar4 = EVP_md5();
              EVP_DigestInit_ex(&local_74,pEVar4,(ENGINE *)0x0);
              EVP_DigestUpdate(&local_74,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&local_74,local_34,0x14);
              if ((int)num < (int)(cnt * 0x10)) {
                EVP_DigestFinal_ex(&local_74,local_34,(uint *)0x0);
                memcpy(local_9c,local_34,local_a4);
              }
              else {
                EVP_DigestFinal_ex(&local_74,local_9c,(uint *)0x0);
              }
              local_9c = local_9c + 0x10;
              if (cnt == (num - 1 >> 4) + 1) goto LAB_080a5bf8;
              cnt = cnt + 1;
              if (cnt == 0x11) break;
              if (((((cnt != 1) && (local_43 = cVar5, cnt != 2)) && (local_42 = cVar5, cnt != 3)) &&
                  (((local_41 = cVar5, cnt != 4 && (local_40 = cVar5, cnt != 5)) &&
                   ((local_3f = cVar5, cnt != 6 &&
                    ((local_3e = cVar5, cnt != 7 && (local_3d = cVar5, cnt != 8)))))))) &&
                 ((local_3c = cVar5, cnt != 9 &&
                  (((((local_3b = cVar5, cnt != 10 && (local_3a = cVar5, cnt != 0xb)) &&
                     (local_39 = cVar5, cnt != 0xc)) &&
                    ((local_38 = cVar5, cnt != 0xd && (local_37 = cVar5, cnt != 0xe)))) &&
                   (local_36 = cVar5, cnt == 0x10)))))) {
                local_35 = cVar5;
              }
              local_a4 = local_a4 - 0x10;
              local_44 = cVar5;
            }
            ERR_put_error(0x14,0xee,0x44,"s3_enc.c",0xb5);
          }
          if ((*(byte *)(param_1 + 0x101) & 8) == 0) {
            iVar1 = *(int *)(param_1 + 0x58);
            iVar2 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar1 + 0xe0) = 1;
            if ((iVar2 != 0) && ((iVar2 = *(int *)(iVar2 + 0x14), iVar2 == 0x20 || (iVar2 == 4)))) {
              *(undefined4 *)(iVar1 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  else {
    local_a0 = 1;
  }
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_a0;
}

