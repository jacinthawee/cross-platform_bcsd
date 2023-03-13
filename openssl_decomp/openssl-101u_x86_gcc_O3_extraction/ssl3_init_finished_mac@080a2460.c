
void ssl3_init_finished_mac(int param_1)

{
  BIO_METHOD *type;
  BIO *pBVar1;
  void *ptr;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x58);
  if (*(BIO **)(iVar2 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar2 + 0x178));
    iVar2 = *(int *)(param_1 + 0x58);
  }
  ptr = *(void **)(iVar2 + 0x17c);
  if (ptr != (void *)0x0) {
    iVar2 = 0;
    do {
      if (*(EVP_MD_CTX **)((int)ptr + iVar2) != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*(EVP_MD_CTX **)((int)ptr + iVar2));
        ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
      iVar2 = iVar2 + 4;
    } while (iVar2 != 0x18);
    CRYPTO_free(ptr);
    iVar2 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar2 + 0x17c) = 0;
  }
  type = BIO_s_mem();
  pBVar1 = BIO_new(type);
  *(BIO **)(iVar2 + 0x178) = pBVar1;
  BIO_ctrl(*(BIO **)(*(int *)(param_1 + 0x58) + 0x178),9,1,(void *)0x0);
  return;
}

