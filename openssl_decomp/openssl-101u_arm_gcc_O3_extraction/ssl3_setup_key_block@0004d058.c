
void ssl3_setup_key_block(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  EVP_MD *pEVar6;
  int iVar7;
  size_t cnt;
  int iVar8;
  uchar *md;
  EVP_CIPHER *local_8c;
  EVP_MD *local_88;
  undefined4 local_84;
  EVP_MD_CTX EStack_80;
  EVP_MD_CTX EStack_68;
  char local_50;
  char local_4f;
  char local_4e;
  char local_4d;
  char local_4c;
  char local_4b;
  char local_4a;
  char local_49;
  char local_48;
  char local_47;
  char local_46;
  char local_45;
  char local_44;
  char local_43;
  char local_42;
  char local_41;
  uchar auStack_40 [20];
  int local_2c;
  
  iVar8 = *(int *)(*(int *)(param_1 + 0x58) + 0x374);
  local_2c = __stack_chk_guard;
  if (iVar8 == 0) {
    iVar2 = ssl_cipher_get_evp(*(undefined4 *)(param_1 + 0xc0),&local_8c,&local_88,0,0,&local_84);
    if (iVar2 == 0) {
      ERR_put_error(0x14,0x9d,0x8a,"s3_enc.c",0x196);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x58);
      *(EVP_CIPHER **)(iVar2 + 0x37c) = local_8c;
      *(undefined4 *)(iVar2 + 0x38c) = local_84;
      *(EVP_MD **)(iVar2 + 0x380) = local_88;
      iVar2 = EVP_MD_size(local_88);
      if (-1 < iVar2) {
        iVar3 = EVP_CIPHER_key_length(local_8c);
        iVar4 = EVP_CIPHER_iv_length(local_8c);
        iVar7 = *(int *)(param_1 + 0x58);
        iVar2 = (iVar4 + iVar2 + iVar3) * 2;
        if (*(void **)(iVar7 + 0x378) != (void *)0x0) {
          OPENSSL_cleanse(*(void **)(iVar7 + 0x378),*(size_t *)(iVar7 + 0x374));
          CRYPTO_free(*(void **)(*(int *)(param_1 + 0x58) + 0x378));
          iVar7 = *(int *)(param_1 + 0x58);
          *(undefined4 *)(iVar7 + 0x378) = 0;
        }
        *(undefined4 *)(iVar7 + 0x374) = 0;
        pvVar5 = CRYPTO_malloc(iVar2,"s3_enc.c",0x1ab);
        if (pvVar5 == (void *)0x0) {
          ERR_put_error(0x14,0x9d,0x41,"s3_enc.c",0x1c8);
        }
        else {
          iVar3 = *(int *)(param_1 + 0x58);
          *(int *)(iVar3 + 0x374) = iVar2;
          *(void **)(iVar3 + 0x378) = pvVar5;
          EVP_MD_CTX_init(&EStack_80);
          EVP_MD_CTX_set_flags(&EStack_80,8);
          EVP_MD_CTX_init(&EStack_68);
          if (iVar2 < 1) {
LAB_0004d2f4:
            OPENSSL_cleanse(auStack_40,0x14);
            EVP_MD_CTX_cleanup(&EStack_80);
            EVP_MD_CTX_cleanup(&EStack_68);
            iVar8 = 1;
          }
          else {
            cnt = 1;
            local_50 = 'A';
            iVar3 = 0;
            while( true ) {
              pEVar6 = EVP_sha1();
              cVar1 = (char)cnt + 'A';
              md = (uchar *)((int)pvVar5 + iVar3);
              iVar3 = iVar3 + 0x10;
              EVP_DigestInit_ex(&EStack_68,pEVar6,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_68,&local_50,cnt);
              EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
              EVP_DigestUpdate(&EStack_68,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
              EVP_DigestFinal_ex(&EStack_68,auStack_40,(uint *)0x0);
              pEVar6 = EVP_md5();
              EVP_DigestInit_ex(&EStack_80,pEVar6,(ENGINE *)0x0);
              EVP_DigestUpdate(&EStack_80,(void *)(*(int *)(param_1 + 0xc0) + 0x14),
                               *(size_t *)(*(int *)(param_1 + 0xc0) + 0x10));
              EVP_DigestUpdate(&EStack_80,auStack_40,0x14);
              if (iVar2 < iVar3) {
                EVP_DigestFinal_ex(&EStack_80,auStack_40,(uint *)0x0);
                memcpy(md,auStack_40,(iVar2 + 0x10) - iVar3);
              }
              else {
                EVP_DigestFinal_ex(&EStack_80,md,(uint *)0x0);
              }
              if (iVar2 <= iVar3) goto LAB_0004d2f4;
              cnt = cnt + 1;
              if (iVar3 == 0x100) break;
              local_50 = cVar1;
              local_4f = cVar1;
              if (((((cnt != 2) && (local_4e = cVar1, cnt != 3)) && (local_4d = cVar1, cnt != 4)) &&
                  ((((local_4c = cVar1, cnt != 5 && (local_4b = cVar1, cnt != 6)) &&
                    ((local_4a = cVar1, cnt != 7 &&
                     ((local_49 = cVar1, cnt != 8 && (local_48 = cVar1, cnt != 9)))))) &&
                   (local_47 = cVar1, cnt != 10)))) &&
                 ((((local_46 = cVar1, cnt != 0xb && (local_45 = cVar1, cnt != 0xc)) &&
                   (local_44 = cVar1, cnt != 0xd)) &&
                  ((local_43 = cVar1, cnt != 0xe && (local_42 = cVar1, cnt == 0x10)))))) {
                local_41 = cVar1;
              }
            }
            ERR_put_error(0x14,0xee,0x44,"s3_enc.c",0xb6);
          }
          if ((*(uint *)(param_1 + 0x100) & 0x800) == 0) {
            iVar2 = *(int *)(param_1 + 0x58);
            iVar3 = *(int *)(*(int *)(param_1 + 0xc0) + 0xb4);
            *(undefined4 *)(iVar2 + 0xe0) = 1;
            if ((iVar3 != 0) && ((iVar3 = *(int *)(iVar3 + 0x14), iVar3 == 0x20 || (iVar3 == 4)))) {
              *(undefined4 *)(iVar2 + 0xe0) = 0;
            }
          }
        }
      }
    }
  }
  else {
    iVar8 = 1;
  }
  if (local_2c != __stack_chk_guard) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar8);
  }
  return;
}

