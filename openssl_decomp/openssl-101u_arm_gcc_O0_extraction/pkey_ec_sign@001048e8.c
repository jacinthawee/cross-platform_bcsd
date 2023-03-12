
int pkey_ec_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  uint uVar1;
  EVP_MD *md;
  EC_KEY *eckey;
  uint uVar2;
  int iVar3;
  uint auStack_24 [2];
  
  iVar3 = *(int *)(param_1 + 0x14);
  eckey = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  if (param_2 == (uchar *)0x0) {
    uVar1 = ECDSA_size(eckey);
    *param_3 = uVar1;
    return 1;
  }
  uVar2 = *param_3;
  uVar1 = ECDSA_size(eckey);
  if (uVar1 <= uVar2) {
    md = *(EVP_MD **)(iVar3 + 4);
    if (md == (EVP_MD *)0x0) {
      iVar3 = 0x40;
    }
    else {
      iVar3 = EVP_MD_type(md);
    }
    iVar3 = ECDSA_sign(iVar3,param_4,param_5,param_2,auStack_24,eckey);
    if (0 < iVar3) {
      iVar3 = 1;
      *param_3 = auStack_24[0];
    }
    return iVar3;
  }
  ERR_put_error(0x10,0xda,100,"ec_pmeth.c",0x81);
  return 0;
}

