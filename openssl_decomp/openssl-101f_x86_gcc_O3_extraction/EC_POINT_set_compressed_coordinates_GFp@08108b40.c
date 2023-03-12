
int EC_POINT_set_compressed_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,int y_bit,BN_CTX *ctx)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = *(byte **)group;
  if (*(code **)(pbVar1 + 0x4c) == (code *)0x0) {
    if ((*pbVar1 & 1) == 0) {
      ERR_put_error(0x10,0x7d,0x42,"ec_oct.c",0x4d);
      return 0;
    }
    if (pbVar1 == *(byte **)p) goto LAB_08108b95;
  }
  else if (pbVar1 == *(byte **)p) {
    if ((*pbVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x08108bfd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (**(code **)(pbVar1 + 0x4c))();
      return iVar2;
    }
LAB_08108b95:
    if (*(int *)(pbVar1 + 4) != 0x196) {
      iVar2 = ec_GF2m_simple_set_compressed_coordinates();
      return iVar2;
    }
    iVar2 = ec_GFp_simple_set_compressed_coordinates();
    return iVar2;
  }
  ERR_put_error(0x10,0x7d,0x65,"ec_oct.c",0x52);
  return 0;
}

