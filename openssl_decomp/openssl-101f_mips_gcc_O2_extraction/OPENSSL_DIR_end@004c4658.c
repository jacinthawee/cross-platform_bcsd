
undefined4 OPENSSL_DIR_end(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if ((param_1 != (int *)0x0) && ((undefined4 *)*param_1 != (undefined4 *)0x0)) {
    iVar1 = (*(code *)PTR_closedir_006aaa58)(*(undefined4 *)*param_1);
    (*(code *)PTR_free_006aabf8)(*param_1);
    if (iVar1 == -1) {
      return 0;
    }
    if (iVar1 == 0) {
      return 1;
    }
  }
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_006aaaf4)();
  *puVar2 = 0x16;
  return 0;
}

