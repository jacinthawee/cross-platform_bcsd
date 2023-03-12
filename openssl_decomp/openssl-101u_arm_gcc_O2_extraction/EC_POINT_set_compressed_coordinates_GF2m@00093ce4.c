
undefined4 EC_POINT_set_compressed_coordinates_GF2m(int **param_1,int **param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = *param_1;
  if (((code *)piVar2[0x13] == (code *)0x0) && (-1 < *piVar2 << 0x1f)) {
    ERR_put_error(0x10,0xba,0x42,"ec_oct.c",0x72);
  }
  else {
    if (piVar2 == *param_2) {
      if (-1 < *piVar2 << 0x1f) {
                    /* WARNING: Could not recover jumptable at 0x00093d5e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)piVar2[0x13])();
        return uVar1;
      }
      if (piVar2[1] != 0x196) {
        uVar1 = ec_GF2m_simple_set_compressed_coordinates();
        return uVar1;
      }
      uVar1 = ec_GFp_simple_set_compressed_coordinates();
      return uVar1;
    }
    ERR_put_error(0x10,0xba,0x65,"ec_oct.c",0x77);
  }
  return 0;
}

