
size_t EC_POINT_point2oct(EC_GROUP *group,EC_POINT *p,point_conversion_form_t form,uchar *buf,
                         size_t len,BN_CTX *ctx)

{
  byte *pbVar1;
  size_t sVar2;
  
  pbVar1 = *(byte **)group;
  if (*(code **)(pbVar1 + 0x50) == (code *)0x0) {
    if ((*pbVar1 & 1) == 0) {
      ERR_put_error(0x10,0x7b,0x42,"ec_oct.c",0x8d);
      return 0;
    }
    if (pbVar1 == *(byte **)p) goto LAB_0810733d;
  }
  else if (pbVar1 == *(byte **)p) {
    if ((*pbVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x081073b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      sVar2 = (**(code **)(pbVar1 + 0x50))();
      return sVar2;
    }
LAB_0810733d:
    if (*(int *)(pbVar1 + 4) != 0x196) {
      sVar2 = ec_GF2m_simple_point2oct();
      return sVar2;
    }
    sVar2 = ec_GFp_simple_point2oct();
    return sVar2;
  }
  ERR_put_error(0x10,0x7b,0x65,"ec_oct.c",0x91);
  return 0;
}

