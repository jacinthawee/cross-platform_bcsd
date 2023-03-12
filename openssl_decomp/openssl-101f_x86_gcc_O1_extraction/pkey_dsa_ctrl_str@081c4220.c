
int pkey_dsa_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  EVP_MD *p2;
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  bool bVar4;
  long p1;
  
  iVar1 = 0x12;
  bVar4 = &stack0x00000000 == &DAT_0000000c;
  pcVar2 = param_2;
  pcVar3 = "dsa_paramgen_bits";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pcVar2 == *pcVar3;
    pcVar2 = pcVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    p1 = strtol(param_3,(char **)0x0,10);
    p2 = (EVP_MD *)0x0;
    iVar1 = 0x1001;
  }
  else {
    iVar1 = 0x14;
    pcVar2 = param_2;
    pcVar3 = "dsa_paramgen_q_bits";
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pcVar2 == *pcVar3;
      pcVar2 = pcVar2 + 1;
      pcVar3 = pcVar3 + 1;
    } while (bVar4);
    if (bVar4) {
      p1 = strtol(param_3,(char **)0x0,10);
      p2 = (EVP_MD *)0x0;
      iVar1 = 0x1002;
    }
    else {
      iVar1 = 0x10;
      pcVar2 = "dsa_paramgen_md";
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
      p2 = EVP_get_digestbyname(param_3);
      p1 = 0;
      iVar1 = 0x1003;
    }
  }
  iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x74,2,iVar1,p1,p2);
  return iVar1;
}

