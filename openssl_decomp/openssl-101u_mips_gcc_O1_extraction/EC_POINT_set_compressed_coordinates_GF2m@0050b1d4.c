
undefined4
EC_POINT_set_compressed_coordinates_GF2m
          (uint **param_1,uint **param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = *param_1;
  if ((code *)puVar1[0x13] == (code *)0x0) {
    if ((*puVar1 & 1) == 0) {
      uVar4 = 0x42;
      uVar2 = 0x72;
      goto LAB_0050b228;
    }
    if (puVar1 == *param_2) {
      uVar3 = puVar1[1];
      goto LAB_0050b25c;
    }
  }
  else if (puVar1 == *param_2) {
    if ((*puVar1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0050b2bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (*(code *)puVar1[0x13])();
      return uVar2;
    }
    uVar3 = puVar1[1];
LAB_0050b25c:
    UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GFp_simple_set_compressed_coordinates_006a86c4;
    if (uVar3 != 0x196) {
      UNRECOVERED_JUMPTABLE = (code *)PTR_ec_GF2m_simple_set_compressed_coordinates_006a86c0;
    }
                    /* WARNING: Could not recover jumptable at 0x0050b284. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  uVar4 = 0x65;
  uVar2 = 0x77;
LAB_0050b228:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x10,0xba,uVar4,"ec_oct.c",uVar2);
  return 0;
}

