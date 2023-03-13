
int pkey_dh_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  long p1;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  
  iVar1 = 0x16;
  bVar4 = &stack0x00000000 == &DAT_0000000c;
  pcVar2 = param_2;
  pcVar3 = "dh_paramgen_prime_len";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    p1 = strtol(param_3,(char **)0x0,10);
    iVar1 = 0x1001;
  }
  else {
    iVar1 = 0x16;
    pcVar2 = "dh_paramgen_generator";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *param_2 == *pcVar2;
      param_2 = param_2 + 1;
      pcVar2 = pcVar2 + 1;
    } while (bVar4);
    if (!bVar4) {
      return -2;
    }
    p1 = strtol(param_3,(char **)0x0,10);
    iVar1 = 0x1002;
  }
  iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x1c,2,iVar1,p1,(void *)0x0);
  return iVar1;
}

