
undefined4 ec_GFp_simple_is_at_infinity(void)

{
  int iVar1;
  undefined4 unaff_r7;
  undefined4 in_r12;
  undefined4 uVar2;
  char in_NG;
  undefined in_ZR;
  char in_OV;
  undefined in_stack_00000000;
  
  uVar2 = 0x121564;
  iVar1 = func_0xfed3c188();
  if ((bool)in_ZR) {
    *(code **)(iVar1 + -4) = ec_GFp_simple_group_init;
    *(undefined4 *)(iVar1 + -8) = uVar2;
    *(BADSPACEBASE **)(iVar1 + -0xc) = register0x00000054;
    *(undefined4 *)(iVar1 + -0x10) = in_r12;
    *(undefined4 *)(iVar1 + -0x14) = unaff_r7;
  }
  if (in_NG != in_OV) {
    software_interrupt(0x4770);
  }
  BN_init((BIGNUM *)(iVar1 + 0x48));
  BN_init((BIGNUM *)(iVar1 + 0x74));
  BN_init((BIGNUM *)(iVar1 + 0x88));
  *(undefined4 *)(iVar1 + 0x9c) = 0;
  return 1;
}

