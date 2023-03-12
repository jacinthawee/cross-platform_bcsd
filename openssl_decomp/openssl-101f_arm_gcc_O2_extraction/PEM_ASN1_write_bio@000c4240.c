
int PEM_ASN1_write_bio(undefined1 *i2d,char *name,BIO *bp,void *x,EVP_CIPHER *enc,uchar *kstr,
                      int klen,undefined1 *cb,void *u)

{
  uchar uVar1;
  int iVar2;
  EVP_CIPHER *__s;
  size_t len;
  uchar *out;
  EVP_MD *md;
  size_t sVar3;
  byte *pbVar4;
  uchar *puVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  undefined4 in_stack_fffffac8;
  undefined4 in_stack_fffffacc;
  long local_518;
  int local_514;
  undefined4 local_510;
  byte local_50c [16];
  uchar auStack_4fc [64];
  EVP_CIPHER_CTX EStack_4bc;
  uchar local_430 [1028];
  int local_2c;
  
  local_2c = __TMC_END__;
  __s = enc;
  if (enc == (EVP_CIPHER *)0x0) {
LAB_000c4288:
    len = (*(code *)i2d)(x,0);
    if ((int)len < 0) {
      ERR_put_error(9,0x69,0xd,"pem_lib.c",0x165);
    }
    else {
      out = (uchar *)CRYPTO_malloc(len + 0x14,"pem_lib.c",0x16b);
      if (out != (uchar *)0x0) {
        local_510 = out;
        local_518 = (*(code *)i2d)(x,&local_510);
        if (enc == (EVP_CIPHER *)0x0) {
          local_430[0] = '\0';
LAB_000c44ce:
          local_518 = PEM_write_bio(bp,name,(char *)local_430,out,local_518);
          uVar6 = (uint)(0 < local_518);
        }
        else if (kstr == (uchar *)0x0) {
          if (cb == (undefined1 *)0x0) {
            klen = PEM_def_callback((char *)local_430,0x400,1,u);
          }
          else {
            klen = (*(code *)cb)();
          }
          kstr = local_430;
          if (0 < klen) goto LAB_000c42ce;
          uVar6 = 0;
          ERR_put_error(9,0x69,0x6f,"pem_lib.c",0x17e);
        }
        else {
LAB_000c42ce:
          RAND_add(out,local_518,(double)CONCAT44(in_stack_fffffacc,in_stack_fffffac8));
          iVar2 = enc->iv_len;
          if (0x10 < iVar2) {
            OpenSSLDie("pem_lib.c",0x188,"enc->iv_len <= (int)sizeof(iv)");
            iVar2 = enc->iv_len;
          }
          iVar2 = RAND_pseudo_bytes(local_50c,iVar2);
          if (-1 < iVar2) {
            md = EVP_md5();
            iVar2 = EVP_BytesToKey(enc,md,local_50c,kstr,klen,1,auStack_4fc,(uchar *)0x0);
            if (iVar2 != 0) {
              if (kstr == local_430) {
                OPENSSL_cleanse(local_430,0x400);
              }
              sVar3 = strlen((char *)__s);
              if (0x400 < sVar3 + enc->iv_len * 2 + 0x24) {
                OpenSSLDie("pem_lib.c",0x192,"strlen(objstr)+23+2*enc->iv_len+13 <= sizeof buf");
              }
              local_430[0] = '\0';
              BUF_strlcat((char *)local_430,"Proc-Type: 4,",0x400);
              BUF_strlcat((char *)local_430,"ENCRYPTED",0x400);
              BUF_strlcat((char *)local_430,"\n",0x400);
              iVar7 = enc->iv_len;
              BUF_strlcat((char *)local_430,"DEK-Info: ",0x400);
              BUF_strlcat((char *)local_430,(char *)__s,0x400);
              iVar2 = iVar7 * 2;
              BUF_strlcat((char *)local_430,",",0x400);
              sVar3 = strlen((char *)local_430);
              if ((int)(sVar3 + iVar2) < 0x400) {
                if (iVar7 < 1) {
                  iVar2 = 0;
                }
                else {
                  pbVar4 = (byte *)((int)&local_510 + 3);
                  pbVar8 = pbVar4 + iVar7;
                  puVar5 = local_430 + sVar3;
                  do {
                    pbVar4 = pbVar4 + 1;
                    uVar1 = "0123456789ABCDEF"[*pbVar4 >> 4];
                    puVar5[1] = "0123456789ABCDEF"[*pbVar4 & 0xf];
                    *puVar5 = uVar1;
                    puVar5 = puVar5 + 2;
                  } while (pbVar4 != pbVar8);
                }
                local_430[sVar3 + iVar2] = '\n';
                local_430[sVar3 + iVar2 + 1] = '\0';
              }
              EVP_CIPHER_CTX_init(&EStack_4bc);
              iVar2 = EVP_EncryptInit_ex(&EStack_4bc,enc,(ENGINE *)0x0,auStack_4fc,local_50c);
              if (((iVar2 != 0) &&
                  (iVar2 = EVP_EncryptUpdate(&EStack_4bc,out,&local_514,out,local_518), iVar2 != 0))
                 && (iVar2 = EVP_EncryptFinal_ex(&EStack_4bc,out + local_514,&local_518), iVar2 != 0
                    )) {
                EVP_CIPHER_CTX_cleanup(&EStack_4bc);
                local_518 = local_514 + local_518;
                goto LAB_000c44ce;
              }
              uVar6 = 0;
              EVP_CIPHER_CTX_cleanup(&EStack_4bc);
              goto LAB_000c443e;
            }
          }
          uVar6 = 0;
        }
LAB_000c443e:
        OPENSSL_cleanse(auStack_4fc,0x40);
        OPENSSL_cleanse(local_50c,0x10);
        OPENSSL_cleanse(&EStack_4bc,0x8c);
        OPENSSL_cleanse(local_430,0x400);
        OPENSSL_cleanse(out,len);
        CRYPTO_free(out);
        goto LAB_000c446e;
      }
      ERR_put_error(9,0x69,0x41,"pem_lib.c",0x16e);
    }
  }
  else {
    iVar2 = EVP_CIPHER_nid(enc);
    __s = (EVP_CIPHER *)OBJ_nid2sn(iVar2);
    if (__s != (EVP_CIPHER *)0x0) goto LAB_000c4288;
    ERR_put_error(9,0x69,0x71,"pem_lib.c",0x15e);
  }
  OPENSSL_cleanse(auStack_4fc,0x40);
  uVar6 = 0;
  OPENSSL_cleanse(local_50c,0x10);
  OPENSSL_cleanse(&EStack_4bc,0x8c);
  OPENSSL_cleanse(local_430,0x400);
LAB_000c446e:
  if (local_2c != __TMC_END__) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}

