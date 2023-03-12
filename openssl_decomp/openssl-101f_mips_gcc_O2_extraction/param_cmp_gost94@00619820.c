
bool param_cmp_gost94(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)();
  iVar2 = (*(code *)PTR_EVP_PKEY_get0_006aa6e4)(param_2);
  iVar1 = (*(code *)PTR_BN_cmp_006a8a4c)
                    (*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar2 + 0x10));
  return iVar1 == 0;
}

