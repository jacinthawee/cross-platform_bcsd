
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *__s;
  size_t len;
  uchar *out;
  EVP_MD *md;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  uint uVar11;
  int in_GS_OFFSET;
  bool bVar12;
  uchar *local_520;
  uint *local_51c;
  uint *local_514;
  long local_508;
  int local_504;
  uchar *local_500;
  EVP_CIPHER_CTX local_4fc;
  byte local_470 [16];
  uchar local_460 [64];
  uint local_420 [256];
  int local_20;
  
  local_51c = (uint *)kstr;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (enc == (EVP_CIPHER *)0x0) {
    __s = (char *)0x0;
LAB_08153f82:
    len = (*(code *)i2d)(x,0);
    if ((int)len < 0) {
      ERR_put_error(9,0x69,0xd,"pem_lib.c",0x162);
    }
    else {
      out = (uchar *)CRYPTO_malloc(len + 0x14,"pem_lib.c",0x168);
      if (out != (uchar *)0x0) {
        local_500 = out;
        local_508 = (*(code *)i2d)(x,&local_500);
        if (enc == (EVP_CIPHER *)0x0) {
          local_420[0]._0_1_ = 0;
LAB_081543fb:
          local_514 = (uint *)((char *)((int)register0x00000010 + -0x423) + 3);
          local_508 = PEM_write_bio(bp,name,(char *)local_514,out,local_508);
          uVar11 = (uint)(0 < local_508);
        }
        else if (kstr == (uchar *)0x0) {
          if (cb == (undefined1 *)0x0) {
            klen = PEM_def_callback((char *)((int)register0x00000010 + -0x423) + 3,0x400,1,u);
          }
          else {
            klen = (*(code *)cb)((char *)((int)register0x00000010 + -0x423) + 3,0x400,1,u);
          }
          local_514 = (uint *)((char *)((int)register0x00000010 + -0x423) + 3);
          if (0 < klen) {
            local_51c = local_514;
            goto LAB_0815400a;
          }
          uVar11 = 0;
          ERR_put_error(9,0x69,0x6f,"pem_lib.c",0x177);
        }
        else {
LAB_0815400a:
          local_514 = (uint *)((char *)((int)register0x00000010 + -0x423) + 3);
          RAND_add(out,local_508,0.0);
          iVar4 = enc->iv_len;
          if (0x10 < iVar4) {
            OpenSSLDie("pem_lib.c",0x181,"enc->iv_len <= (int)sizeof(iv)");
            iVar4 = enc->iv_len;
          }
          iVar4 = RAND_bytes(local_470,iVar4);
          if (0 < iVar4) {
            md = EVP_md5();
            iVar4 = EVP_BytesToKey(enc,md,local_470,(uchar *)local_51c,klen,1,local_460,(uchar *)0x0
                                  );
            if (iVar4 != 0) {
              if (local_51c == local_514) {
                OPENSSL_cleanse(local_514,0x400);
              }
              local_520 = local_460;
              sVar5 = strlen(__s);
              if (0x400 < sVar5 + 0x24 + enc->iv_len * 2) {
                OpenSSLDie("pem_lib.c",399,
                           "strlen(objstr) + 23 + 2 * enc->iv_len + 13 <= sizeof buf");
              }
              local_420[0]._0_1_ = 0;
              BUF_strlcat((char *)local_514,"Proc-Type: 4,",0x400);
              BUF_strlcat((char *)local_514,"ENCRYPTED",0x400);
              BUF_strlcat((char *)local_514,"\n",0x400);
              iVar4 = enc->iv_len;
              BUF_strlcat((char *)local_514,"DEK-Info: ",0x400);
              BUF_strlcat((char *)local_514,__s,0x400);
              BUF_strlcat((char *)local_514,",",0x400);
              puVar10 = local_514;
              do {
                puVar9 = puVar10;
                uVar6 = *puVar9 + 0xfefefeff & ~*puVar9;
                uVar11 = uVar6 & 0x80808080;
                puVar10 = puVar9 + 1;
              } while (uVar11 == 0);
              bVar12 = (uVar6 & 0x8080) == 0;
              if (bVar12) {
                uVar11 = uVar11 >> 0x10;
              }
              puVar10 = (uint *)((int)puVar9 + 6);
              if (!bVar12) {
                puVar10 = puVar9 + 1;
              }
              iVar3 = (-3 - (uint)CARRY1((byte)uVar11,(byte)uVar11)) - (int)local_514;
              if ((int)puVar10 + iVar4 * 2 + iVar3 < 0x400) {
                iVar7 = 0;
                iVar8 = iVar7;
                if (0 < iVar4) {
                  do {
                    bVar1 = local_470[iVar7];
                    cVar2 = "0123456789ABCDEF"[(char)(bVar1 >> 4)];
                    *(char *)((int)puVar10 +
                             (int)((char *)((int)register0x00000010 + -0x423) +
                                  iVar7 * 2 + iVar3 + 4)) = "0123456789ABCDEF"[bVar1 & 0xf];
                    *(char *)((int)local_514 + (int)puVar10 + iVar7 * 2 + iVar3) = cVar2;
                    iVar7 = iVar7 + 1;
                    iVar8 = iVar4 * 2;
                  } while (iVar4 != iVar7);
                }
                *(char *)((int)puVar10 +
                         (int)((char *)((int)register0x00000010 + -0x423) + iVar8 + iVar3 + 3)) =
                     '\n';
                *(char *)((int)puVar10 +
                         (int)((char *)((int)register0x00000010 + -0x423) + iVar8 + iVar3 + 4)) =
                     '\0';
              }
              EVP_CIPHER_CTX_init(&local_4fc);
              iVar4 = EVP_EncryptInit_ex(&local_4fc,enc,(ENGINE *)0x0,local_520,local_470);
              if (((iVar4 != 0) &&
                  (iVar4 = EVP_EncryptUpdate(&local_4fc,out,&local_504,out,local_508), iVar4 != 0))
                 && (iVar4 = EVP_EncryptFinal_ex(&local_4fc,out + local_504,&local_508), iVar4 != 0)
                 ) {
                EVP_CIPHER_CTX_cleanup(&local_4fc);
                local_508 = local_504 + local_508;
                goto LAB_081543fb;
              }
              uVar11 = 0;
              EVP_CIPHER_CTX_cleanup(&local_4fc);
              goto LAB_081542a4;
            }
          }
          uVar11 = 0;
        }
LAB_081542a4:
        local_514 = (uint *)((char *)((int)register0x00000010 + -0x423) + 3);
        local_520 = local_460;
        OPENSSL_cleanse(local_520,0x40);
        OPENSSL_cleanse(local_470,0x10);
        OPENSSL_cleanse(&local_4fc,0x8c);
        OPENSSL_cleanse(local_514,0x400);
        OPENSSL_cleanse(out,len);
        CRYPTO_free(out);
        goto LAB_08153f60;
      }
      ERR_put_error(9,0x69,0x41,"pem_lib.c",0x16a);
    }
  }
  else {
    iVar4 = EVP_CIPHER_nid(enc);
    __s = OBJ_nid2sn(iVar4);
    if ((__s != (char *)0x0) && (iVar4 = EVP_CIPHER_iv_length(enc), iVar4 != 0)) goto LAB_08153f82;
    ERR_put_error(9,0x69,0x71,"pem_lib.c",0x15c);
  }
  OPENSSL_cleanse(local_460,0x40);
  OPENSSL_cleanse(local_470,0x10);
  uVar11 = 0;
  OPENSSL_cleanse(&local_4fc,0x8c);
  OPENSSL_cleanse((char *)((int)register0x00000010 + -0x423) + 3,0x400);
LAB_08153f60:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar11;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

