
int EVP_Digest(void *data,size_t count,uchar *md,uint *size,EVP_MD *type,ENGINE *impl)

{
  uint uVar1;
  int iVar2;
  int in_GS_OFFSET;
  EVP_MD_CTX local_38;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = 0;
  do {
    *(undefined4 *)((int)&local_38.digest + uVar1) = 0;
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0x18);
  EVP_MD_CTX_set_flags(&local_38,1);
  iVar2 = EVP_DigestInit_ex(&local_38,type,impl);
  if (iVar2 == 0) {
LAB_0812515b:
    uVar1 = 0;
  }
  else {
    iVar2 = (*local_38.update)(&local_38,data,count);
    if (iVar2 == 0) goto LAB_0812515b;
    if (0x40 < (local_38.digest)->md_size) {
      OpenSSLDie("digest.c",0x10c,"ctx->digest->md_size <= EVP_MAX_MD_SIZE");
    }
    iVar2 = (*(local_38.digest)->final)(&local_38,md);
    if (size != (uint *)0x0) {
      *size = (local_38.digest)->md_size;
    }
    if ((local_38.digest)->cleanup != (_func_1082 *)0x0) {
      (*(local_38.digest)->cleanup)(&local_38);
      EVP_MD_CTX_set_flags(&local_38,2);
    }
    OPENSSL_cleanse(local_38.md_data,(local_38.digest)->ctx_size);
    uVar1 = (uint)(iVar2 != 0);
  }
  if (local_38.digest != (EVP_MD *)0x0) {
    if ((local_38.digest)->cleanup != (_func_1082 *)0x0) {
      iVar2 = EVP_MD_CTX_test_flags(&local_38,2);
      if (iVar2 == 0) {
        (*(local_38.digest)->cleanup)(&local_38);
      }
      if (local_38.digest == (EVP_MD *)0x0) goto LAB_081251af;
    }
    if (((local_38.digest)->ctx_size != 0) && (local_38.md_data != (void *)0x0)) {
      iVar2 = EVP_MD_CTX_test_flags(&local_38,4);
      if (iVar2 == 0) {
        OPENSSL_cleanse(local_38.md_data,(local_38.digest)->ctx_size);
        CRYPTO_free(local_38.md_data);
      }
    }
  }
LAB_081251af:
  if (local_38.pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(local_38.pctx);
  }
  if (local_38.engine != (ENGINE *)0x0) {
    ENGINE_finish(local_38.engine);
  }
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

