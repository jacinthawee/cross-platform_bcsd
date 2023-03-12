
undefined4 cms_EncryptedContent_init(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  param_1[3] = param_2;
  if (param_3 != 0) {
    iVar1 = (*(code *)PTR_CRYPTO_malloc_006a8108)(param_4,"cms_enc.c",0xf6);
    param_1[4] = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    (*(code *)PTR_memcpy_006aabf4)(iVar1,param_3,param_4);
  }
  param_1[5] = param_4;
  if (param_2 != 0) {
    uVar2 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x15);
    *param_1 = uVar2;
    return 1;
  }
  return 1;
}

