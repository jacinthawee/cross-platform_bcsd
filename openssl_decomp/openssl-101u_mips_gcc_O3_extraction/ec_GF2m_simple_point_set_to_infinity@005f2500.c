
undefined4
ec_GF2m_simple_point_set_to_infinity
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = PTR_BN_set_word_006a7730;
  *(undefined4 *)(param_2 + 0x40) = 0;
  (*(code *)puVar1)(param_2 + 0x2c,0,param_3,param_4,&_gp);
  return 1;
}

