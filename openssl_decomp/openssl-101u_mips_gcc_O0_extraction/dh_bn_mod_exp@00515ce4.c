
void dh_bn_mod_exp(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                  undefined4 param_5)

{
  if ((param_3[1] == 1) && ((*(uint *)(param_1 + 0x1c) & 2) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x00515d54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_BN_mod_exp_mont_word_006a8784)(param_2,*(undefined4 *)*param_3,param_4,param_5);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00515d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BN_mod_exp_mont_006a85d0)(param_2,param_3,param_4,param_5);
  return;
}

