
undefined4 rsa_pkey_ctrl(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  switch(param_2) {
  default:
    uVar2 = 0xfffffffe;
    goto LAB_005f9880;
  case 1:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_005f9880;
    (*(code *)PTR_PKCS7_SIGNER_INFO_get0_algs_006a96b8)(param_4,0,0,&local_18);
    break;
  case 2:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_005f9880;
    (*(code *)PTR_PKCS7_RECIP_INFO_get0_alg_006a9724)(param_4,&local_18);
    break;
  case 3:
    uVar2 = 1;
    *param_4 = 0x40;
    goto LAB_005f9880;
  case 5:
    uVar2 = 1;
    if (param_3 != 0) goto LAB_005f9880;
    (*(code *)PTR_CMS_SignerInfo_get0_algs_006a9314)(param_4,0,0,0,&local_18);
    break;
  case 7:
    if (param_3 == 0) {
      (*(code *)PTR_CMS_RecipientInfo_ktri_get0_algs_006a9720)(param_4,0,0,&local_18);
      break;
    }
    goto LAB_005f9848;
  }
  iVar3 = local_18;
  if (local_18 == 0) {
LAB_005f9848:
    uVar2 = 1;
  }
  else {
    uVar2 = (*(code *)PTR_OBJ_nid2obj_006a7140)(6);
    (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar3,uVar2,5,0);
    uVar2 = 1;
  }
LAB_005f9880:
  if (local_14 == *(int *)puVar1) {
    return uVar2;
  }
  iVar3 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
                    /* WARNING: Could not recover jumptable at 0x005f9950. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*(code *)PTR_RSA_free_006a7600)(*(undefined4 *)(iVar3 + 0x14));
  return uVar2;
}

