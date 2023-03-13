
int EC_POINT_oct2point(EC_GROUP *group,EC_POINT *p,uchar *buf,size_t len,BN_CTX *ctx)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)group;
  if (*(code **)(pbVar1 + 0x54) == (code *)0x0) {
    if ((*pbVar1 & 1) == 0) {
      ERR_put_error(0x10,0x7a,0x42,"ec_oct.c",0xab);
      return 0;
    }
    if (pbVar1 == *(byte **)p) goto LAB_08107435;
  }
  else if (pbVar1 == *(byte **)p) {
    if ((*pbVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0810749d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(pbVar1 + 0x54))();
      return iVar2;
    }
LAB_08107435:
    if (*(int *)(pbVar1 + 4) != 0x196) {
      iVar2 = ec_GF2m_simple_oct2point();
      return iVar2;
    }
    iVar2 = ec_GFp_simple_oct2point();
    return iVar2;
  }
  ERR_put_error(0x10,0x7a,0x65,"ec_oct.c",0xaf);
  return 0;
}

