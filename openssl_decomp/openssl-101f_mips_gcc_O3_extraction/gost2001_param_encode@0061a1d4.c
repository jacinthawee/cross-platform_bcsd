
void gost2001_param_encode(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  uVar1 = (*(code *)PTR_EC_KEY_get0_group_006a8780)(uVar1);
  uVar1 = (*(code *)PTR_EC_GROUP_get_curve_name_006a9110)(uVar1);
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x0061a23c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_i2d_ASN1_OBJECT_006aa970)(uVar1,param_2);
  return;
}

