
int PEM_do_header(EVP_CIPHER_INFO *cipher,uchar *data,long *len,undefined1 *callback,void *u)

{
  long lVar1;
  int iVar2;
  EVP_MD *md;
  int in_GS_OFFSET;
  int local_4f4;
  int local_4f0;
  EVP_CIPHER_CTX local_4ec;
  uchar local_460 [64];
  uchar local_420 [1024];
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  lVar1 = *len;
  local_4f4 = 0;
  if (cipher->cipher == (EVP_CIPHER *)0x0) {
    iVar2 = 1;
    goto LAB_0815340d;
  }
  if (callback == (undefined1 *)0x0) {
    iVar2 = PEM_def_callback((char *)local_420,0x400,0,u);
  }
  else {
    iVar2 = (*(code *)callback)(local_420,0x400,0,u);
  }
  if (iVar2 < 1) {
    ERR_put_error(9,0x6a,0x68,"pem_lib.c",0x1c5);
    iVar2 = 0;
    goto LAB_0815340d;
  }
  md = EVP_md5();
  iVar2 = EVP_BytesToKey(cipher->cipher,md,cipher->iv,local_420,iVar2,1,local_460,(uchar *)0x0);
  if (iVar2 == 0) goto LAB_0815340d;
  local_4f0 = lVar1;
  EVP_CIPHER_CTX_init(&local_4ec);
  iVar2 = EVP_DecryptInit_ex(&local_4ec,cipher->cipher,(ENGINE *)0x0,local_460,cipher->iv);
  if (iVar2 == 0) {
LAB_08153467:
    EVP_CIPHER_CTX_cleanup(&local_4ec);
    OPENSSL_cleanse(local_420,0x400);
    OPENSSL_cleanse(local_460,0x40);
    local_4f0 = local_4f0 + local_4f4;
  }
  else {
    iVar2 = EVP_DecryptUpdate(&local_4ec,data,&local_4f4,data,local_4f0);
    if (iVar2 == 0) goto LAB_08153467;
    iVar2 = EVP_DecryptFinal_ex(&local_4ec,data + local_4f4,&local_4f0);
    EVP_CIPHER_CTX_cleanup(&local_4ec);
    OPENSSL_cleanse(local_420,0x400);
    OPENSSL_cleanse(local_460,0x40);
    local_4f0 = local_4f4 + local_4f0;
    if (iVar2 != 0) {
      *len = local_4f0;
      iVar2 = 1;
      goto LAB_0815340d;
    }
  }
  ERR_put_error(9,0x6a,0x65,"pem_lib.c",0x1dd);
  iVar2 = 0;
LAB_0815340d:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

