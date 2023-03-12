
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uint *buf;
  byte bVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  size_t len;
  uchar *out;
  EVP_MD *md;
  size_t sVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  int in_GS_OFFSET;
  char *local_524;
  uchar *local_520;
  uint *local_51c;
  char *local_518;
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
    local_524 = (char *)0x0;
LAB_08156457:
    len = (*(code *)i2d)(x,0);
    if ((int)len < 0) {
      ERR_put_error(9,0x69,0xd,"pem_lib.c",0x165);
    }
    else {
      out = (uchar *)CRYPTO_malloc(len + 0x14,"pem_lib.c",0x16b);
      if (out != (uchar *)0x0) {
        local_500 = out;
        local_508 = (*(code *)i2d)(x,&local_500);
        if (enc == (EVP_CIPHER *)0x0) {
          local_420[0]._0_1_ = 0;
LAB_0815684b:
          local_518 = (char *)((int)register0x00000010 + -0x423) + 3;
          local_508 = PEM_write_bio(bp,name,local_518,out,local_508);
          uVar6 = (uint)(0 < local_508);
        }
        else {
          buf = (uint *)((char *)((int)register0x00000010 + -0x423) + 3);
          if (kstr == (uchar *)0x0) {
            if (cb == (undefined1 *)0x0) {
              klen = PEM_def_callback((char *)buf,0x400,1,u);
            }
            else {
              klen = (*(code *)cb)(buf,0x400,1,u);
            }
            local_51c = buf;
            if (0 < klen) goto LAB_081564d5;
            uVar6 = 0;
            ERR_put_error(9,0x69,0x6f,"pem_lib.c",0x17e);
          }
          else {
LAB_081564d5:
            RAND_add(out,local_508,0.0);
            iVar4 = enc->iv_len;
            if (0x10 < iVar4) {
              OpenSSLDie("pem_lib.c",0x188,"enc->iv_len <= (int)sizeof(iv)");
              iVar4 = enc->iv_len;
            }
            iVar4 = RAND_pseudo_bytes(local_470,iVar4);
            if (-1 < iVar4) {
              md = EVP_md5();
              iVar4 = EVP_BytesToKey(enc,md,local_470,(uchar *)local_51c,klen,1,local_460,
                                     (uchar *)0x0);
              if (iVar4 != 0) {
                if (local_51c == buf) {
                  OPENSSL_cleanse(buf,0x400);
                }
                local_520 = local_460;
                sVar5 = strlen(local_524);
                if (0x400 < sVar5 + 0x24 + enc->iv_len * 2) {
                  OpenSSLDie("pem_lib.c",0x192,"strlen(objstr)+23+2*enc->iv_len+13 <= sizeof buf");
                }
                local_420[0]._0_1_ = 0;
                BUF_strlcat((char *)buf,"Proc-Type: 4,",0x400);
                BUF_strlcat((char *)buf,"ENCRYPTED",0x400);
                BUF_strlcat((char *)buf,"\n",0x400);
                iVar4 = enc->iv_len;
                BUF_strlcat((char *)buf,"DEK-Info: ",0x400);
                BUF_strlcat((char *)buf,local_524,0x400);
                BUF_strlcat((char *)buf,",",0x400);
                puVar11 = buf;
                do {
                  puVar10 = puVar11;
                  uVar6 = *puVar10 + 0xfefefeff & ~*puVar10;
                  uVar7 = uVar6 & 0x80808080;
                  puVar11 = puVar10 + 1;
                } while (uVar7 == 0);
                puVar11 = (uint *)((int)puVar10 + 6);
                uVar12 = uVar7 >> 0x10;
                if ((uVar6 & 0x8080) != 0) {
                  puVar11 = puVar10 + 1;
                  uVar12 = uVar7;
                }
                iVar3 = (-3 - (uint)CARRY1((byte)uVar12,(byte)uVar12)) - (int)buf;
                if ((int)((int)puVar11 + iVar4 * 2 + iVar3) < 0x400) {
                  iVar8 = 0;
                  iVar9 = iVar8;
                  if (0 < iVar4) {
                    do {
                      bVar1 = local_470[iVar8];
                      cVar2 = "0123456789ABCDEF"[(char)(bVar1 >> 4)];
                      *(char *)((int)puVar11 +
                               (int)((char *)((int)register0x00000010 + -0x423) +
                                    iVar8 * 2 + iVar3 + 4)) = "0123456789ABCDEF"[bVar1 & 0xf];
                      *(char *)((int)buf + (int)((int)puVar11 + iVar8 * 2 + iVar3)) = cVar2;
                      iVar8 = iVar8 + 1;
                      iVar9 = iVar4 * 2;
                    } while (iVar4 != iVar8);
                  }
                  *(char *)((int)puVar11 +
                           (int)((char *)((int)register0x00000010 + -0x423) + iVar9 + iVar3 + 3)) =
                       '\n';
                  *(char *)((int)puVar11 +
                           (int)((char *)((int)register0x00000010 + -0x423) + iVar9 + iVar3 + 4)) =
                       '\0';
                }
                EVP_CIPHER_CTX_init(&local_4fc);
                iVar4 = EVP_EncryptInit_ex(&local_4fc,enc,(ENGINE *)0x0,local_520,local_470);
                if (((iVar4 != 0) &&
                    (iVar4 = EVP_EncryptUpdate(&local_4fc,out,&local_504,out,local_508), iVar4 != 0)
                    ) && (iVar4 = EVP_EncryptFinal_ex(&local_4fc,out + local_504,&local_508),
                         iVar4 != 0)) {
                  EVP_CIPHER_CTX_cleanup(&local_4fc);
                  local_508 = local_504 + local_508;
                  goto LAB_0815684b;
                }
                uVar6 = 0;
                EVP_CIPHER_CTX_cleanup(&local_4fc);
                goto LAB_0815673c;
              }
            }
            uVar6 = 0;
          }
        }
LAB_0815673c:
        local_518 = (char *)((int)register0x00000010 + -0x423) + 3;
        local_520 = local_460;
        OPENSSL_cleanse(local_520,0x40);
        OPENSSL_cleanse(local_470,0x10);
        OPENSSL_cleanse(&local_4fc,0x8c);
        OPENSSL_cleanse(local_518,0x400);
        OPENSSL_cleanse(out,len);
        CRYPTO_free(out);
        goto LAB_08156794;
      }
      ERR_put_error(9,0x69,0x41,"pem_lib.c",0x16e);
    }
  }
  else {
    iVar4 = EVP_CIPHER_nid(enc);
    local_524 = OBJ_nid2sn(iVar4);
    if (local_524 != (char *)0x0) goto LAB_08156457;
    ERR_put_error(9,0x69,0x71,"pem_lib.c",0x15e);
  }
  OPENSSL_cleanse(local_460,0x40);
  OPENSSL_cleanse(local_470,0x10);
  uVar6 = 0;
  OPENSSL_cleanse(&local_4fc,0x8c);
  OPENSSL_cleanse((char *)((int)register0x00000010 + -0x423) + 3,0x400);
LAB_08156794:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}

