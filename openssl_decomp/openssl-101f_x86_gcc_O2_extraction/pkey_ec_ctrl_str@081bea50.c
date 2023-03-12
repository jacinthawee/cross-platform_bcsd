
int pkey_ec_ctrl_str(EVP_PKEY_CTX *param_1,byte *param_2,char *param_3)

{
  int iVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  
  iVar1 = 0x12;
  bVar3 = &stack0xfffffff0 < &DAT_0000000c;
  bVar4 = &stack0x00000000 == (undefined *)0x1c;
  pbVar2 = (byte *)"ec_paramgen_curve";
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar3 = *param_2 < *pbVar2;
    bVar4 = *param_2 == *pbVar2;
    param_2 = param_2 + 1;
    pbVar2 = pbVar2 + 1;
  } while (bVar4);
  if ((!bVar3 && !bVar4) == bVar3) {
    iVar1 = OBJ_sn2nid(param_3);
    if (iVar1 == 0) {
      iVar1 = OBJ_ln2nid(param_3);
      if (iVar1 == 0) {
        ERR_put_error(0x10,0xc6,0x8d,"ec_pmeth.c",0x104);
        return 0;
      }
    }
    iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x198,2,0x1001,iVar1,(void *)0x0);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}

