
void ssl3_init_finished_mac(int param_1)

{
  EVP_MD_CTX **ppEVar1;
  BIO_METHOD *type;
  BIO *pBVar2;
  void *ptr;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x58);
  if (*(BIO **)(iVar3 + 0x178) != (BIO *)0x0) {
    BIO_free(*(BIO **)(iVar3 + 0x178));
    iVar3 = *(int *)(param_1 + 0x58);
  }
  ptr = *(void **)(iVar3 + 0x17c);
  if (ptr != (void *)0x0) {
    iVar3 = 0;
    do {
      ppEVar1 = (EVP_MD_CTX **)((int)ptr + iVar3);
      iVar3 = iVar3 + 4;
      if (*ppEVar1 != (EVP_MD_CTX *)0x0) {
        EVP_MD_CTX_destroy(*ppEVar1);
        ptr = *(void **)(*(int *)(param_1 + 0x58) + 0x17c);
      }
    } while (iVar3 != 0x18);
    CRYPTO_free(ptr);
    iVar3 = *(int *)(param_1 + 0x58);
    *(undefined4 *)(iVar3 + 0x17c) = 0;
  }
  type = BIO_s_mem();
  pBVar2 = BIO_new(type);
  iVar4 = *(int *)(param_1 + 0x58);
  *(BIO **)(iVar3 + 0x178) = pBVar2;
  BIO_ctrl(*(BIO **)(iVar4 + 0x178),9,1,(void *)0x0);
  return;
}

