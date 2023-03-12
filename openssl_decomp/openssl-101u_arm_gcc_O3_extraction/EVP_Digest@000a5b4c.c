
int EVP_Digest(void *data,size_t count,uchar *md,uint *size,EVP_MD *type,ENGINE *impl)

{
  int iVar1;
  int iVar2;
  EVP_MD_CTX local_38;
  
  local_38.digest = (EVP_MD *)0x0;
  local_38.engine = (ENGINE *)0x0;
  local_38.flags = 0;
  local_38.md_data = (void *)0x0;
  local_38.pctx = (EVP_PKEY_CTX *)0x0;
  local_38.update = (_func_1088 *)0x0;
  EVP_MD_CTX_set_flags(&local_38,1);
  iVar1 = EVP_DigestInit_ex(&local_38,type,impl);
  if ((iVar1 == 0) || (iVar1 = (*local_38.update)(&local_38,data,count), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    if (0x40 < (local_38.digest)->md_size) {
      OpenSSLDie("digest.c",0x10c,"ctx->digest->md_size <= EVP_MAX_MD_SIZE");
    }
    iVar1 = (*(local_38.digest)->final)(&local_38,md);
    if (size != (uint *)0x0) {
      *size = (local_38.digest)->md_size;
    }
    if ((local_38.digest)->cleanup != (_func_1082 *)0x0) {
      (*(local_38.digest)->cleanup)(&local_38);
      EVP_MD_CTX_set_flags(&local_38,2);
    }
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    OPENSSL_cleanse(local_38.md_data,(local_38.digest)->ctx_size);
  }
  if (local_38.digest != (EVP_MD *)0x0) {
    if ((local_38.digest)->cleanup != (_func_1082 *)0x0) {
      iVar2 = EVP_MD_CTX_test_flags(&local_38,2);
      if (iVar2 == 0) {
        (*(local_38.digest)->cleanup)(&local_38);
      }
      if (local_38.digest == (EVP_MD *)0x0) goto LAB_000a5b9c;
    }
    if ((((local_38.digest)->ctx_size != 0) && (local_38.md_data != (void *)0x0)) &&
       (iVar2 = EVP_MD_CTX_test_flags(&local_38,4), iVar2 == 0)) {
      OPENSSL_cleanse(local_38.md_data,(local_38.digest)->ctx_size);
      CRYPTO_free(local_38.md_data);
    }
  }
LAB_000a5b9c:
  if (local_38.pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(local_38.pctx);
  }
  if (local_38.engine != (ENGINE *)0x0) {
    ENGINE_finish(local_38.engine);
  }
  return iVar1;
}

