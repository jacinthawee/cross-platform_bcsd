
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  int iVar1;
  EVP_MD *md;
  long lVar2;
  EVP_CIPHER *type;
  int local_500;
  long local_4fc;
  uchar auStack_4f8 [64];
  EVP_CIPHER_CTX EStack_4b8;
  uchar auStack_42c [1024];
  int local_2c;
  
  lVar2 = *len;
  local_2c = __stack_chk_guard;
  local_500 = 0;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    iVar1 = 1;
    goto LAB_000c1596;
  }
  if (callback == (undefined1 *)0x0) {
    iVar1 = PEM_def_callback((char *)auStack_42c,0x400,0,u);
  }
  else {
    iVar1 = (*(code *)callback)(auStack_42c,0x400);
  }
  if (iVar1 < 1) {
    ERR_put_error(9,0x6a,0x68,"pem_lib.c",0x1c5);
    iVar1 = 0;
    goto LAB_000c1596;
  }
  type = cipher->cipher;
  md = EVP_md5();
  iVar1 = EVP_BytesToKey(type,md,cipher->iv,auStack_42c,iVar1,1,auStack_4f8,(uchar *)0x0);
  if (iVar1 == 0) goto LAB_000c1596;
  local_4fc = lVar2;
  EVP_CIPHER_CTX_init(&EStack_4b8);
  iVar1 = EVP_DecryptInit_ex(&EStack_4b8,cipher->cipher,(ENGINE *)0x0,auStack_4f8,cipher->iv);
  if (iVar1 == 0) {
LAB_000c15c4:
    EVP_CIPHER_CTX_cleanup(&EStack_4b8);
    OPENSSL_cleanse(auStack_42c,0x400);
    OPENSSL_cleanse(auStack_4f8,0x40);
    local_4fc = local_4fc + local_500;
  }
  else {
    iVar1 = EVP_DecryptUpdate(&EStack_4b8,data,&local_500,data,local_4fc);
    if (iVar1 == 0) goto LAB_000c15c4;
    iVar1 = EVP_DecryptFinal_ex(&EStack_4b8,data + local_500,&local_4fc);
    EVP_CIPHER_CTX_cleanup(&EStack_4b8);
    OPENSSL_cleanse(auStack_42c,0x400);
    OPENSSL_cleanse(auStack_4f8,0x40);
    local_4fc = local_4fc + local_500;
    if (iVar1 != 0) {
      *len = local_4fc;
      iVar1 = 1;
      goto LAB_000c1596;
    }
  }
  ERR_put_error(9,0x6a,0x65,"pem_lib.c",0x1dd);
  iVar1 = 0;
LAB_000c1596:
  if (local_2c == __stack_chk_guard) {
    return iVar1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

