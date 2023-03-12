
void list_md_fn(EVP_MD *param_1,char *param_2,undefined4 param_3,BIO *param_4)

{
  int iVar1;
  char *pcVar2;
  ulong uVar3;
  
  if (param_1 == (EVP_MD *)0x0) {
    return;
  }
  iVar1 = EVP_MD_type(param_1);
  pcVar2 = OBJ_nid2ln(iVar1);
  iVar1 = strcmp(param_2,pcVar2);
  if ((iVar1 == 0) && (uVar3 = EVP_MD_flags(param_1), -1 < (int)(uVar3 << 0x1e))) {
    pcVar2 = strchr(pcVar2,0x20);
    if (pcVar2 != (char *)0x0) {
      iVar1 = EVP_MD_type(param_1);
      OBJ_nid2sn(iVar1);
    }
    BIO_vprintf(param_4,"-%-14s to use the %s message digest algorithm\n",&stack0xfffffff8);
    return;
  }
  return;
}

