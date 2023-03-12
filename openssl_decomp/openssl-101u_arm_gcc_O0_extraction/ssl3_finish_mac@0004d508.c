
void ssl3_finish_mac(int param_1,void *param_2,size_t param_3)

{
  EVP_MD_CTX **ppEVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 0x58);
  if (((BIO *)piVar2[0x5e] != (BIO *)0x0) && (-1 < *piVar2 << 0x1a)) {
    BIO_write((BIO *)piVar2[0x5e],param_2,param_3);
    return;
  }
  iVar3 = 0;
  while( true ) {
    ppEVar1 = (EVP_MD_CTX **)(piVar2[0x5f] + iVar3);
    iVar3 = iVar3 + 4;
    if (*ppEVar1 != (EVP_MD_CTX *)0x0) {
      EVP_DigestUpdate(*ppEVar1,param_2,param_3);
    }
    if (iVar3 == 0x18) break;
    piVar2 = *(int **)(param_1 + 0x58);
  }
  return;
}

