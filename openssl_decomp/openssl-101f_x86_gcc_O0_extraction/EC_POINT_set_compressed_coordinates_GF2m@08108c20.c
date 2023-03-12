
undefined4 EC_POINT_set_compressed_coordinates_GF2m(byte **param_1,byte **param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = *param_1;
  if (*(code **)(pbVar1 + 0x4c) == (code *)0x0) {
    if ((*pbVar1 & 1) == 0) {
      ERR_put_error(0x10,0xba,0x42,"ec_oct.c",0x6f);
      return 0;
    }
    if (pbVar1 == *param_2) goto LAB_08108c75;
  }
  else if (pbVar1 == *param_2) {
    if ((*pbVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x08108cdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(pbVar1 + 0x4c))();
      return uVar2;
    }
LAB_08108c75:
    if (*(int *)(pbVar1 + 4) != 0x196) {
      uVar2 = ec_GF2m_simple_set_compressed_coordinates();
      return uVar2;
    }
    uVar2 = ec_GFp_simple_set_compressed_coordinates();
    return uVar2;
  }
  ERR_put_error(0x10,0xba,0x65,"ec_oct.c",0x74);
  return 0;
}

