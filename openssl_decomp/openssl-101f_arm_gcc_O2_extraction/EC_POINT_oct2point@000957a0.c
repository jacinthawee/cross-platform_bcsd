
int EC_POINT_oct2point(EC_GROUP *group,EC_POINT *p,uchar *buf,size_t len,BN_CTX *ctx)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)group;
  if (((code *)piVar2[0x15] == (code *)0x0) && (-1 < *piVar2 << 0x1f)) {
    ERR_put_error(0x10,0x7a,0x42,"ec_oct.c",0xad);
  }
  else {
    if (piVar2 == *(int **)p) {
      if (-1 < *piVar2 << 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x0009581a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)piVar2[0x15])();
        return iVar1;
      }
      if (piVar2[1] != 0x196) {
        iVar1 = ec_GF2m_simple_oct2point();
        return iVar1;
      }
      iVar1 = ec_GFp_simple_oct2point();
      return iVar1;
    }
    ERR_put_error(0x10,0x7a,0x65,"ec_oct.c",0xb2);
  }
  return 0;
}

