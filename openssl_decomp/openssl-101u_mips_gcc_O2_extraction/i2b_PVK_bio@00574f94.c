
int i2b_PVK_bio(BIO *out,EVP_PKEY *pk,int enclevel,undefined1 *cb,void *u)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = i2b_PVK_constprop_4(&local_18);
  if (-1 < iVar2) {
    iVar3 = (*(code *)PTR_BIO_write_006a6e14)(out,local_18,iVar2);
    (*(code *)PTR_CRYPTO_free_006a6e88)(local_18);
    if (iVar2 == iVar3) {
      (*(code *)PTR_ERR_put_error_006a7f34)(9,0x8a,0x76,FUN_0066c47c,0x377);
      goto LAB_00575044;
    }
  }
  iVar2 = -1;
LAB_00575044:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  return (int)"/usr/local/openssl101umipso2/private";
}

