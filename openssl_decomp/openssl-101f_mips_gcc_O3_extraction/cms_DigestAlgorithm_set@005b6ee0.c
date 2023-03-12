
void cms_DigestAlgorithm_set(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((*(uint *)(param_2 + 0xc) & 8) == 0) {
    uVar2 = 5;
  }
  uVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)(param_2);
  uVar1 = (*(code *)PTR_OBJ_nid2obj_006a8240)(uVar1);
                    /* WARNING: Could not recover jumptable at 0x005b6f54. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_X509_ALGOR_set0_006a9e04)(param_1,uVar1,uVar2,0);
  return;
}

