
int i2b_PVK_bio(BIO *out,EVP_PKEY *pk,int enclevel,undefined1 *cb,void *u)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_18;
  int local_14;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = i2b_PVK_constprop_4(&local_18);
  if (-1 < iVar2) {
    iVar3 = (*(code *)PTR_BIO_write_006a7f14)(out,local_18,iVar2);
    (*(code *)PTR_CRYPTO_free_006a7f88)(local_18);
    if (iVar2 == iVar3) {
      (*(code *)PTR_ERR_put_error_006a9030)(9,0x8a,0x76,FUN_0066ce6c,0x3ae);
      goto LAB_00578864;
    }
  }
  iVar2 = -1;
LAB_00578864:
  if (local_14 == *(int *)puVar1) {
    return iVar2;
  }
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  return (int)"/usr/local/openssl101fmipso3/private";
}

