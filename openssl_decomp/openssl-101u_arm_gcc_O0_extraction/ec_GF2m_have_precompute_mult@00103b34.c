
int ec_GF2m_have_precompute_mult
              (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = EC_EX_DATA_get_data(*(undefined4 *)(param_1 + 0x44),0x8fb7d,0x8fd39,0x8fd8d,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

