
int EC_POINT_set_compressed_coordinates_GFp
              (EC_GROUP *group,EC_POINT *p,BIGNUM *x,int y_bit,BN_CTX *ctx)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)group;
  if (((code *)piVar2[0x13] == (code *)0x0) && (-1 < *piVar2 << 0x1f)) {
    ERR_put_error(0x10,0x7d,0x42,"ec_oct.c",0x4d);
  }
  else {
    if (piVar2 == *(int **)p) {
      if (-1 < *piVar2 << 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x0009569a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)piVar2[0x13])();
        return iVar1;
      }
      if (piVar2[1] != 0x196) {
        iVar1 = ec_GF2m_simple_set_compressed_coordinates();
        return iVar1;
      }
      iVar1 = ec_GFp_simple_set_compressed_coordinates();
      return iVar1;
    }
    ERR_put_error(0x10,0x7d,0x65,"ec_oct.c",0x52);
  }
  return 0;
}

