
void pkey_dsa_verify(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x14);
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x14) == 0) {
    uVar1 = 0x40;
  }
  else {
    uVar1 = (*(code *)PTR_EVP_MD_type_006a84cc)();
  }
  (*(code *)PTR_DSA_verify_006a8b80)(uVar1,param_4,param_5,param_2,param_3,uVar2);
  return;
}

