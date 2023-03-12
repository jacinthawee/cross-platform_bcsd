
int OBJ_add_sigid(int signid,int dig_id,int pkey_id)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  int *ptr;
  int iVar4;
  undefined4 uVar5;
  
  puVar2 = PTR_sig_app_006a84b0;
  if (*(int *)PTR_sig_app_006a84b0 == 0) {
    iVar4 = (*(code *)PTR_sk_new_006a806c)(sig_sk_cmp);
    *(int *)puVar2 = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
  }
  puVar3 = PTR_sigx_app_006a84b4;
  if (*(int *)PTR_sigx_app_006a84b4 == 0) {
    iVar4 = (*(code *)PTR_sk_new_006a806c)(sigx_cmp);
    *(int *)puVar3 = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
  }
  ptr = (int *)CRYPTO_malloc(0xc,"obj_xref.c",0x9f);
  puVar1 = PTR_sk_push_006a6fa8;
  if (ptr != (int *)0x0) {
    uVar5 = *(undefined4 *)puVar2;
    ptr[1] = dig_id;
    *ptr = signid;
    ptr[2] = pkey_id;
    iVar4 = (*(code *)puVar1)(uVar5,ptr);
    if (iVar4 == 0) {
      CRYPTO_free(ptr);
      return 0;
    }
    iVar4 = (*(code *)PTR_sk_push_006a6fa8)(*(undefined4 *)puVar3,ptr);
    if (iVar4 != 0) {
      (*(code *)PTR_sk_sort_006a83bc)(*(undefined4 *)PTR_sig_app_006a84b0);
      (*(code *)PTR_sk_sort_006a83bc)(*(undefined4 *)PTR_sigx_app_006a84b4);
      return 1;
    }
  }
  return 0;
}

