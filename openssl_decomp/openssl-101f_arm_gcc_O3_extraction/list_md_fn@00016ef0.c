
void list_md_fn(EVP_MD *param_1,char *param_2,undefined4 param_3,BIO *param_4)

{
  int iVar1;
  char *__s2;
  ulong uVar2;
  char *pcVar3;
  
  if (param_1 == (EVP_MD *)0x0) {
    return;
  }
  iVar1 = EVP_MD_type(param_1);
  __s2 = OBJ_nid2ln(iVar1);
  iVar1 = strcmp(param_2,__s2);
  if ((iVar1 == 0) && (uVar2 = EVP_MD_flags(param_1), -1 < (int)(uVar2 << 0x1e))) {
    pcVar3 = strchr(__s2,0x20);
    if (pcVar3 != (char *)0x0) {
      iVar1 = EVP_MD_type(param_1);
      __s2 = OBJ_nid2sn(iVar1);
    }
    BIO_printf(param_4,"-%-14s to use the %s message digest algorithm\n",__s2,__s2);
    return;
  }
  return;
}

