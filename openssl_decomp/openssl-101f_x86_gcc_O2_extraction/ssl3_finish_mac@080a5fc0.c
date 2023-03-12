
void ssl3_finish_mac(int param_1,void *param_2,size_t param_3)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)(param_1 + 0x58);
  if ((*(BIO **)(pbVar1 + 0x178) != (BIO *)0x0) && ((*pbVar1 & 0x20) == 0)) {
    BIO_write(*(BIO **)(pbVar1 + 0x178),param_2,param_3);
    return;
  }
  iVar2 = 0;
  while( true ) {
    if (*(EVP_MD_CTX **)(*(int *)(pbVar1 + 0x17c) + iVar2) != (EVP_MD_CTX *)0x0) {
      EVP_DigestUpdate(*(EVP_MD_CTX **)(*(int *)(pbVar1 + 0x17c) + iVar2),param_2,param_3);
    }
    iVar2 = iVar2 + 4;
    if (iVar2 == 0x18) break;
    pbVar1 = *(byte **)(param_1 + 0x58);
  }
  return;
}

