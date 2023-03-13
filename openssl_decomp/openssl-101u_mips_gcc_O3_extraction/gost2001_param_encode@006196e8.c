
void gost2001_param_encode(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006a95d8)();
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a7690)(uVar1);
  uVar1 = (*(code *)PTR_EC_GROUP_get_curve_name_006a7f7c)(uVar1);
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a7140)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x00619750. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_i2d_ASN1_OBJECT_006a9860)(uVar1,param_2);
  return;
}

